TARGET = main
TYPE = ps-exe

SRCS = src/main.c

LDFLAGS += -Wl,--start-group
LDFLAGS += -lapi
LDFLAGS += -lc
LDFLAGS += -lc2
LDFLAGS += -lcard
LDFLAGS += -lcomb
LDFLAGS += -lds
LDFLAGS += -letc
LDFLAGS += -lgpu
LDFLAGS += -lgs
LDFLAGS += -lgte
LDFLAGS += -lgpu
LDFLAGS += -lgun
LDFLAGS += -lhmd
LDFLAGS += -lmath
LDFLAGS += -lmcrd
LDFLAGS += -lmcx
LDFLAGS += -lpad
LDFLAGS += -lpress
LDFLAGS += -lsio
LDFLAGS += -lsnd
LDFLAGS += -lspu
LDFLAGS += -ltap
LDFLAGS += -lcd # only needed for cd-rom access
LDFLAGS += -Wl,--end-group

BUILD ?= Debug

HAS_LINUX_MIPS_GCC = $(shell which mipsel-linux-gnu-gcc > /dev/null 2> /dev/null && echo true || echo false)

ifeq ($(HAS_LINUX_MIPS_GCC),true)
PREFIX ?= mipsel-linux-gnu
FORMAT ?= elf32-tradlittlemips
else
PREFIX ?= ./tools/mips/mips/bin/mipsel-none-elf
FORMAT ?= elf32-littlemips
endif

ROOTDIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CC  = $(PREFIX)-gcc

TYPE ?= cpe

LDSCRIPT ?= $(ROOTDIR)/$(TYPE).ld
ifneq ($(strip $(OVERLAYSCRIPT)),)
LDSCRIPT := $(addprefix $(OVERLAYSCRIPT) , -T$(LDSCRIPT))
else
LDSCRIPT := $(addprefix $(ROOTDIR)/default.ld , -T$(LDSCRIPT))
endif

USE_FUNCTION_SECTIONS ?= true

ARCHFLAGS = -march=mips1 -mabi=32 -EL -fno-pic -mno-shared -mno-abicalls -mfp32
ARCHFLAGS += -fno-stack-protector -nostdlib -ffreestanding

ifeq ($(USE_FUNCTION_SECTIONS),true)
CFLAGS += -ffunction-sections
endif
CFLAGS += -mno-gpopt -fomit-frame-pointer
CFLAGS += -fno-builtin -fno-strict-aliasing -Wno-attributes
CFLAGS += $(ARCHFLAGS)
CFLAGS += -I$(ROOTDIR)

LDFLAGS += -Wl,-Map=$(BINDIR)$(TARGET).map -nostdlib -T$(LDSCRIPT) -static -Wl,--gc-sections
LDFLAGS += $(ARCHFLAGS) -Wl,--oformat=$(FORMAT)

CFLAGS_Release += -Os
LDFLAGS_Release += -Os

CFLAGS_Debug += -O0
CFLAGS_Coverage += -O0

LDFLAGS += -g
CFLAGS += -g

CFLAGS += $(CFLAGS_$(BUILD))
LDFLAGS += $(LDFLAGS_$(BUILD))


THISDIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

SRCS += $(THISDIR)thirdparty/nugget/common/crt0/crt0.s
SRCS += $(THISDIR)thirdparty/nugget/common/syscalls/printf.s 

CFLAGS += -I$(THISDIR)thirdparty/nugget/psyq/include -I$(THISDIR)thirdparty/nugget/common -I$(THISDIR)thirdparty/nugget
LDFLAGS += -L$(THISDIR)thirdparty/nugget/psyq/lib 


OBJS += $(addsuffix .o, $(basename $(SRCS)))


$(BINDIR)$(TARGET).$(TYPE): $(BINDIR)$(TARGET).elf
	$(PREFIX)-objcopy $(addprefix -R , $(OVERLAYSECTION)) -O binary $< $@
	$(foreach ovl, $(OVERLAYSECTION), $(PREFIX)-objcopy -j $(ovl) -O binary $< $(BINDIR)Overlay$(ovl);)

$(BINDIR)$(TARGET).elf: $(OBJS)
ifneq ($(strip $(BINDIR)),)
	mkdir -p $(BINDIR)
endif
	$(CC) -g -o $(BINDIR)$(TARGET).elf $(OBJS) $(LDFLAGS)

define OBJCOPYME
$(PREFIX)-objcopy -I binary --set-section-alignment .data=4 --rename-section .data=.rodata,alloc,load,readonly,data,contents -O $(FORMAT) -B mips $< $@
endef


%.o: %.s
	$(CC) $(ARCHFLAGS) -I$(THISDIR)thirdparty/nugget -g -c -o $@ $<

# convert TIM file to bin
%.o: %.tim
	$(call OBJCOPYME) 

%.dep: %.c
	$(CC) $(CFLAGS) -M -MT $(addsuffix .o, $(basename $@)) -MF $@ $<


# A bit broken, but that'll do in most cases.
%.dep: %.s
	tools/mips/mips/bin/touch.exe $@

DEPS +=	$(patsubst %.c,   %.dep,$(filter %.c,$(SRCS)))
DEPS += $(patsubst %.s,   %.dep,$(filter %.s,$(SRCS)))

dep: $(DEPS)

cd_rom: CFLAGS += -DCD_ROM_BUILD

cd_rom: all $(BINDIR)$(TARGET).$(TYPE)
	@echo "Building CD-ROM..."
	tools/mkpsxiso-2.04-win64/bin/mkpsxiso.exe -y isoconfig.xml

all: dep $(BINDIR)$(TARGET).$(TYPE)

clean:
	tools/mips/mips/bin/rm.exe -f $(OBJS) $(BINDIR)Overlay.* $(BINDIR)*.elf $(BINDIR)*.ps-exe $(BINDIR)*.map $(DEPS)



ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), deepclean)
-include $(DEPS)
endif
endif

.PHONY: clean dep all cd_rom
