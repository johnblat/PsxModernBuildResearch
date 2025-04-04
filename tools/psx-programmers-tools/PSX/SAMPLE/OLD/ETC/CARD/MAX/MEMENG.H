/* $PSLibId: Run-time Library Release 4.4$ */
#ifndef _MEMENG_H_
#define _MEMENG_H_

/*****************************************************************
 *
 * file: memeng.h
 *
 * 	Copyright (C) 1995 by Sony Computer Entertainment Inc.
 *				          All Rights Reserved.
 *
 *	Sony Computer Entertainment Inc. Development Department
 *
 *****************************************************************/

unsigned long _TITLE[] = {
	0x00000010,
	0x00000008,
	0x0000002c,
	0x01e00000,
	0x00010010,
	0x1c417fff,
	0x44a348c4,
	0x50c46106,
	0x24412862,
	0x3c833883,
	0x14212c62,
	0x0c001000,
	0x00000800,
	0x00000e1c,
	0x00000280,
	0x00240032,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0xf4444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0xf4444444,
	0xeeeeee44,
	0xddddeeee,
	0xbbcccccd,
	0xbbbbbbbb,
	0x11111111,
	0x67777711,
	0xaaaa6666,
	0x8aaaaaaa,
	0x88888888,
	0x39999998,
	0x33333333,
	0x22333333,
	0x22222222,
	0x33322222,
	0x33333333,
	0x99993333,
	0x88888899,
	0xaaaa8888,
	0x6aaaaaaa,
	0x77776666,
	0x11111117,
	0xbbbbb111,
	0xcccbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbcccccd,
	0xbbbbbbbb,
	0x11111111,
	0x67777711,
	0xaaaa6666,
	0x88aaaaaa,
	0x88888888,
	0x33999998,
	0x33333333,
	0x22223333,
	0x22222222,
	0x32222222,
	0x33333333,
	0x99933333,
	0x88888899,
	0xaaa88888,
	0x6aaaaaaa,
	0x77776666,
	0x11111117,
	0xbbbbb111,
	0xcccbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbcccccd,
	0xbbbbbbbb,
	0x11111111,
	0x67777711,
	0xaaaa6666,
	0x88aaaaaa,
	0x88888888,
	0x33999999,
	0x33333333,
	0x22222233,
	0x22222222,
	0x22222222,
	0x33333332,
	0x99933333,
	0x88888999,
	0xaaa88888,
	0x6aaaaaaa,
	0x77776666,
	0x11111117,
	0xbbbbb111,
	0xcccbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbcccccd,
	0xbbbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x888aaaaa,
	0x88888888,
	0x33399999,
	0x33333333,
	0x22222223,
	0x22222222,
	0x22222222,
	0x33333322,
	0x99333333,
	0x88888999,
	0xaa888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbbb111,
	0xcccbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbcccccd,
	0x1bbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x888aaaaa,
	0x98888888,
	0x33399999,
	0x33333333,
	0x22222222,
	0x22222222,
	0x22222222,
	0x33333222,
	0x99333333,
	0x88889999,
	0xaa888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbb1111,
	0xcccbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbbccccd,
	0x1bbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x888aaaaa,
	0x98888888,
	0x33339999,
	0x23333333,
	0x22222222,
	0x22222222,
	0x22222222,
	0x33332222,
	0x93333333,
	0x88889999,
	0xaa888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbb1111,
	0xccbbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbbccccc,
	0x1bbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x888aaaaa,
	0x98888888,
	0x33339999,
	0x23333333,
	0x22222222,
	0x22222222,
	0x22222222,
	0x33332222,
	0x93333333,
	0x88889999,
	0xaa888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbb1111,
	0xccbbbbbb,
	0xeddddccc,
	0xf44eeeee,
	0xeeeeee44,
	0xd0000000,
	0x00bccccc,
	0x0bb00000,
	0x00000000,
	0x00007770,
	0xaaaaa000,
	0x000000aa,
	0x99888880,
	0x33300099,
	0x00333333,
	0x00000000,
	0x22222220,
	0x22220002,
	0x33322002,
	0x33333333,
	0x00009999,
	0xa8888888,
	0xa00000aa,
	0x07766666,
	0x00000000,
	0x0bbb1100,
	0x00000000,
	0xdddddcc0,
	0xf44eeeee,
	0xeeeeee44,
	0x00000000,
	0x00bccccc,
	0x0bb00000,
	0x00000000,
	0x00007770,
	0xaaaa0000,
	0x000000aa,
	0x09888880,
	0x00000000,
	0x00333333,
	0x00000000,
	0x00552000,
	0x22220000,
	0x33300000,
	0x33333333,
	0x00000009,
	0xa8888000,
	0xa00000aa,
	0x0766666a,
	0x00000000,
	0x0bbb0000,
	0x00000000,
	0xddddd000,
	0xf44eeeee,
	0xeeeeee44,
	0x00000000,
	0x000ccccc,
	0x0bb00000,
	0x00000000,
	0x00007770,
	0xaaaa0000,
	0x0000000a,
	0x00888880,
	0x00000000,
	0x00233330,
	0x00000000,
	0x05550000,
	0x22220000,
	0x33220000,
	0x33333333,
	0x00000000,
	0xa8888800,
	0x000000aa,
	0x0766666a,
	0x00000000,
	0x0bb00000,
	0x00000000,
	0xddd00000,
	0xf44eeeee,
	0xeeeeee44,
	0x00000000,
	0x000ccccc,
	0x0bb00000,
	0x11110000,
	0x00007777,
	0xaaaa0000,
	0x0000000a,
	0x00088880,
	0x00000000,
	0x00233300,
	0x00222000,
	0x05550000,
	0x22200000,
	0x33220000,
	0x03333333,
	0x00000000,
	0xa8888800,
	0x0000000a,
	0x0766666a,
	0x01110000,
	0x0bb00000,
	0xccbb0000,
	0xdd000000,
	0xf44eeeee,
	0xeeeeee44,
	0x00000000,
	0x000cccc0,
	0x0bb00000,
	0x11110000,
	0x00007777,
	0xaaa00000,
	0x0000000a,
	0x00008880,
	0x00333390,
	0x00223000,
	0x02222000,
	0x55550000,
	0x02200000,
	0x32222000,
	0x00333333,
	0x88890000,
	0xa8888888,
	0x0000000a,
	0x0766666a,
	0x11110000,
	0x0bb00000,
	0xccbb0000,
	0xdd00000c,
	0xf44eeeee,
	0xeeeeee44,
	0x00000000,
	0x0000ccc0,
	0x0bb00000,
	0x11110000,
	0x00007777,
	0xaaa00000,
	0x00000000,
	0x00008880,
	0x00333390,
	0x00223000,
	0x05222000,
	0x55550000,
	0x02200005,
	0x32222000,
	0x00333333,
	0x88999000,
	0xa8888888,
	0x0000000a,
	0x07666660,
	0x11110000,
	0x0bb00000,
	0xccbb0000,
	0xd000000c,
	0xf44eeeee,
	0xeeeeee44,
	0x00000000,
	0x0000ccc0,
	0x01b00000,
	0x11110000,
	0x00007777,
	0xaaa00000,
	0x00000000,
	0x00000880,
	0x03333399,
	0x00220000,
	0x05222000,
	0x55555000,
	0x00000005,
	0x32222200,
	0x00033333,
	0x88999900,
	0xa8888888,
	0x000aa000,
	0x07666660,
	0x11110000,
	0x0bb10000,
	0xccbb0000,
	0xd00000cc,
	0xf44eeeee,
	0xeeeeee44,
	0x000d0000,
	0xb000cc00,
	0x01b00000,
	0x00000000,
	0x00007770,
	0xaa000006,
	0x00008000,
	0x00000880,
	0x03333399,
	0x00220000,
	0x00222000,
	0x55555000,
	0x00000055,
	0x32222220,
	0x00033333,
	0x88999900,
	0x88888888,
	0x000aa000,
	0x07666660,
	0x01110000,
	0x0bb10000,
	0xccbb0000,
	0xd00000cc,
	0xf44eeeee,
	0xeeeeee44,
	0x000d0000,
	0xb0000c00,
	0x01b00000,
	0x00000000,
	0x00007770,
	0x0a000006,
	0x00008000,
	0x00000880,
	0x03333399,
	0x00220000,
	0x00000000,
	0x55555500,
	0x00000055,
	0x32222220,
	0x00033333,
	0x88999900,
	0x08888888,
	0x000aa000,
	0x07666600,
	0x00000000,
	0x0bb11000,
	0xccbb0000,
	0xd00000cc,
	0xf44eeeee,
	0xeeeeee44,
	0x00dd0000,
	0xb0000c00,
	0x01b00000,
	0x00000000,
	0x00007770,
	0x0a000066,
	0x00008000,
	0x00000880,
	0x03333399,
	0x00220000,
	0x00000000,
	0x55555550,
	0x00000555,
	0x32222222,
	0x00033333,
	0x88999900,
	0x08888888,
	0x000aaa00,
	0x07666600,
	0x00000000,
	0x0bb11100,
	0xccbb0000,
	0xd00000cc,
	0xf44eeeee,
	0xeeeeee44,
	0x00dd0000,
	0xbb000000,
	0x01b00000,
	0x11110000,
	0x00007777,
	0x00000066,
	0x00008a00,
	0x00000880,
	0x03333399,
	0x00220000,
	0x00000000,
	0x55555500,
	0x00000555,
	0x32222222,
	0x00333333,
	0x88999900,
	0x08888888,
	0x00000000,
	0x07666000,
	0x00000000,
	0x0bb11000,
	0xccbb0000,
	0xdd0000cc,
	0xf44eeeee,
	0xeeeeee44,
	0x00dd0000,
	0xbb000000,
	0x01b00000,
	0x11110000,
	0x00007777,
	0x00000066,
	0x00008a00,
	0x00008880,
	0x00333390,
	0x00223000,
	0x00022000,
	0x55555500,
	0x00000555,
	0x32222222,
	0x00333333,
	0x88999000,
	0x00888888,
	0x00000000,
	0x07666000,
	0x00110000,
	0x0bb11000,
	0xccbb0000,
	0xdd00000c,
	0xf44eeeee,
	0xeeeeee44,
	0x0ddd0000,
	0xbbb00000,
	0x01b00000,
	0x11110000,
	0x00007777,
	0x00000a66,
	0x0000aaa0,
	0x00008880,
	0x00033300,
	0x00223000,
	0x00022000,
	0x55555000,
	0x00000555,
	0x32222222,
	0x00333333,
	0x88990000,
	0x00888888,
	0x00000000,
	0x07666000,
	0x00110000,
	0x0bb10000,
	0xccbb0000,
	0xdd00000c,
	0xf44eeeee,
	0xeeeeee44,
	0x0ddd0000,
	0xbbb00000,
	0x0bb00000,
	0x11110000,
	0x00007777,
	0x00000a66,
	0x0000aaa0,
	0x00088880,
	0x00000000,
	0x00223300,
	0x00222000,
	0x55550000,
	0x00000555,
	0x32222222,
	0x03333333,
	0x00000000,
	0x00088800,
	0x0aaaaaa0,
	0x07660000,
	0x01110000,
	0x0bb00000,
	0xccbb0000,
	0xddd00000,
	0xf44eeeee,
	0xeeeeee44,
	0x0ddd0000,
	0xbbb00000,
	0x0bb00000,
	0x00000000,
	0x00007700,
	0x00000a66,
	0x0000aaa0,
	0x00888880,
	0x00000000,
	0x00223330,
	0x00222000,
	0x55550000,
	0x00000555,
	0x32222222,
	0x33333333,
	0x00000000,
	0x00088800,
	0x0aaaaaa0,
	0x07660000,
	0x01110000,
	0x0bb00000,
	0x00000000,
	0xdddd0000,
	0xf44eeeee,
	0xeeeeee44,
	0xdddd0000,
	0xbbbc0000,
	0x0bb00000,
	0x00000000,
	0x00007700,
	0x0000aa66,
	0x0000aaaa,
	0x09888880,
	0x00000000,
	0x00233333,
	0x02222000,
	0x55500000,
	0x00000555,
	0x33222222,
	0x33333333,
	0x00000099,
	0x00088000,
	0x0aaaaaaa,
	0x07660000,
	0x11110000,
	0x0b000000,
	0x00000000,
	0xddddd000,
	0xf44eeeee,
	0xeeeeee44,
	0xdddd0000,
	0xbbbc0000,
	0x0bb00000,
	0x00000000,
	0x00007700,
	0x0000aa66,
	0x0000aaaa,
	0x99888880,
	0x33300099,
	0x00233333,
	0x02222000,
	0x55555500,
	0x00000255,
	0x33222222,
	0x33333333,
	0x00099999,
	0x00008880,
	0xaaaaaaaa,
	0x07600000,
	0x11110000,
	0x0bbb1000,
	0x00000000,
	0xdddddcc0,
	0xf44eeeee,
	0xeeeeee44,
	0xdddddeee,
	0xbbbccccc,
	0x1bbbbbbb,
	0x11111111,
	0x66677771,
	0xaaaaaa66,
	0x8888aaaa,
	0x99888888,
	0x33333999,
	0x22333333,
	0x22222222,
	0x25552222,
	0x22222222,
	0x33322222,
	0x33333333,
	0x88899999,
	0xa8888888,
	0xaaaaaaaa,
	0x7766666a,
	0x11111177,
	0xbbbb1111,
	0xccbbbbbb,
	0xdddddccc,
	0xf44eeeee,
	0xeeeeee44,
	0xdddddeee,
	0xbbbccccc,
	0x1bbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x8888aaaa,
	0x99888888,
	0x33333999,
	0x22333333,
	0x22222222,
	0x22222222,
	0x22222222,
	0x33322222,
	0x33333333,
	0x88899999,
	0xa8888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbb1111,
	0xccbbbbbb,
	0xdddddccc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbbccccc,
	0x1bbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x888aaaaa,
	0x98888888,
	0x33339999,
	0x23333333,
	0x22222222,
	0x22222222,
	0x22222222,
	0x33332222,
	0x93333333,
	0x88889999,
	0xaa888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbb1111,
	0xccbbbbbb,
	0xeddddccc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbbccccd,
	0x1bbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x888aaaaa,
	0x98888888,
	0x33339999,
	0x23333333,
	0x22222222,
	0x22222222,
	0x22222222,
	0x33332222,
	0x93333333,
	0x88889999,
	0xaa888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbb1111,
	0xccbbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbcccccd,
	0x1bbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x888aaaaa,
	0x98888888,
	0x33399999,
	0x33333333,
	0x22222222,
	0x22222222,
	0x22222222,
	0x33333222,
	0x99333333,
	0x88889999,
	0xaa888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbb1111,
	0xcccbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbcccccd,
	0xbbbbbbbb,
	0x11111111,
	0x66777771,
	0xaaaaa666,
	0x888aaaaa,
	0x88888888,
	0x33399999,
	0x33333333,
	0x22222223,
	0x22222222,
	0x22222222,
	0x33333322,
	0x99333333,
	0x88888999,
	0xaa888888,
	0xaaaaaaaa,
	0x77766666,
	0x11111177,
	0xbbbbb111,
	0xcccbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0xeeeeee44,
	0xddddeeee,
	0xbbcccccd,
	0xbbbbbbbb,
	0x11111111,
	0x67777711,
	0xaaaa6666,
	0x88aaaaaa,
	0x88888888,
	0x33999999,
	0x33333333,
	0x22222233,
	0x22222222,
	0x22222222,
	0x33333332,
	0x99933333,
	0x88888999,
	0xaaa88888,
	0x6aaaaaaa,
	0x77776666,
	0x11111117,
	0xbbbbb111,
	0xcccbbbbb,
	0xedddddcc,
	0xf44eeeee,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0xf4444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0x44444444,
	0xf4444444,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
	0xffffffff,
};

unsigned long univ_mem[] = {
	0x00000010,
	0x00000008,
	0x0000002c,
	0x01e00000,
	0x00010010,
	0x0c637fff,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00003f04,
	0x00000280,
	0x0082003e,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa00000a0,
	0xaa08a008,
	0xaa0000a2,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa0820aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a2aaaa,
	0x00a0aaaa,
	0xa008a000,
	0x00a2aa08,
	0xaaaaaa00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a2aaaa,
	0xaaaaaa08,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa2aaaaaa,
	0xaa080000,
	0x500000a0,
	0x9a049004,
	0x590000a2,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a040000,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x0000a0aa,
	0x00a0aa00,
	0x90045000,
	0x00a29a04,
	0xaaaa5900,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x0000aaaa,
	0xaaaa9a04,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x20aaaaaa,
	0x9a000000,
	0x505504a0,
	0x9a049004,
	0x595500a2,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa2aa8a20,
	0x00aaaa00,
	0x00aa0800,
	0xaaaa0a00,
	0x9a041020,
	0xaa08a2aa,
	0xaa0a20aa,
	0x8a0000a0,
	0xaa0000a0,
	0x1005a0aa,
	0x04a04a00,
	0x90045055,
	0x00a29a04,
	0xaaaa5955,
	0xaaaaaaaa,
	0x0000a0aa,
	0xaa00a2aa,
	0x000000aa,
	0x0000008a,
	0x10a5aaaa,
	0x00aa9a04,
	0x20aa0a00,
	0x00a0aa0a,
	0x00a00800,
	0xa2aa0a00,
	0x4a005055,
	0xa09a04a0,
	0x9a049004,
	0xaa0000a2,
	0xaaaaaaaa,
	0x20aaaaaa,
	0xa2aa0800,
	0x00aa4a00,
	0x000a0000,
	0xaa0a0000,
	0x9a0410a6,
	0x8a0000a2,
	0xaa0420aa,
	0x000000a0,
	0x000000a0,
	0xa055aaaa,
	0x00a04900,
	0x9004a000,
	0x00a29a04,
	0xaaaaaa00,
	0xaaaaaaaa,
	0x040000aa,
	0x4a00a05a,
	0x004500aa,
	0x10450009,
	0x20aaaa08,
	0x00a09a04,
	0x00aa4500,
	0x04a0aa04,
	0x04900050,
	0xaa8a0051,
	0x4900a06a,
	0xa00000a0,
	0x9a049004,
	0x590000a2,
	0xaaaaaaaa,
	0x00a2aaaa,
	0xa09a5545,
	0x00aa4900,
	0x00051045,
	0xaa045045,
	0x9a0420aa,
	0x59550420,
	0x9a0400aa,
	0x005104a0,
	0x00550450,
	0x20aaaa4a,
	0x00a05900,
	0x90045000,
	0x00a29a04,
	0xaaaa5955,
	0xaaaaaaaa,
	0x555500a2,
	0x0900a09a,
	0x204900aa,
	0xa0490005,
	0x20aa9a00,
	0x05209a04,
	0x00aa5955,
	0x04a09a00,
	0x04500092,
	0xaa09009a,
	0x590020aa,
	0x500000a0,
	0x9a049004,
	0x595500a2,
	0xaaaaaaaa,
	0x04a0aaaa,
	0x20aaaa59,
	0x00aa0950,
	0x00452049,
	0x9a00a249,
	0x9a0420aa,
	0xaa9a4500,
	0x9a0005a2,
	0x049204a0,
	0x209a0450,
	0x00aaaa09,
	0x04a05a04,
	0x90045055,
	0x00a29a04,
	0xaaaa5955,
	0xaaaaaaaa,
	0xaa5a04a0,
	0x055020aa,
	0x004900aa,
	0xa2490045,
	0x20aa5a00,
	0x45009a04,
	0x05a2aaaa,
	0x04a05a00,
	0x04500490,
	0xaa05209a,
	0x5a0500a2,
	0x505504a0,
	0x9a049004,
	0xaa5a00a2,
	0xaaaaaaaa,
	0x04a0aaaa,
	0x00aaaa9a,
	0x00aa0450,
	0x00590000,
	0x5a00a249,
	0x9a0420aa,
	0xaaaa4900,
	0x4a0005a0,
	0x050000a0,
	0x209a0490,
	0x00a0aa05,
	0x04a09a45,
	0x9004a09a,
	0x00820000,
	0xaaaa0a00,
	0xaaaaaaaa,
	0xaa9a04a0,
	0x045004aa,
	0x040000aa,
	0xa2490059,
	0x20aa5a00,
	0x49009a04,
	0x45a0aaaa,
	0x00a04a00,
	0x04904500,
	0xaa05209a,
	0xaa550020,
	0xa09a04a0,
	0x00009004,
	0x0a000082,
	0xaaaaaaaa,
	0x04a2aaaa,
	0x00aaaa9a,
	0x009a0000,
	0x005a0000,
	0x5a04a249,
	0x9a0420aa,
	0xaaaa4920,
	0x090000a0,
	0x050000a0,
	0x209a04a0,
	0x0400aa45,
	0x04a0aa59,
	0x9004a09a,
	0x00410000,
	0xaaaa0500,
	0xaaaaaaaa,
	0xaa9a00a2,
	0x000000a2,
	0x0041009a,
	0xa049009a,
	0x20aa5a04,
	0x09209a04,
	0x0020aaaa,
	0x04a00900,
	0x04a00910,
	0xa245009a,
	0xaa5a0500,
	0xa09a04a0,
	0x00009004,
	0x05000041,
	0xaaaaaaaa,
	0x00a2aaaa,
	0x00a2aa8a,
	0x005a0000,
	0x004a0041,
	0x9a04a049,
	0x9a0420aa,
	0xaaaa0820,
	0x05000020,
	0x041004a0,
	0x009a04a0,
	0x4500a049,
	0x65aaaa9a,
	0x9a55aa9a,
	0x65595555,
	0xaaaa5555,
	0xaaaaaaaa,
	0x080000aa,
	0x005505a0,
	0x0049004a,
	0x2049000a,
	0x20aa9a05,
	0x00a09a04,
	0x55008a00,
	0x04a00450,
	0x04a00090,
	0x20590092,
	0x8a000000,
	0xaa9a65aa,
	0x55559a55,
	0x55556559,
	0xaaaaaaaa,
	0x20aaaaaa,
	0x05a00800,
	0x004a0055,
	0x00090049,
	0x9a450000,
	0x9a0420aa,
	0x8a0000a2,
	0x04505500,
	0x009004a0,
	0x04000090,
	0x00000059,
	0xaaaa8a00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x0000a1aa,
	0x00aa4590,
	0x20490049,
	0x00000004,
	0x20aaaa55,
	0x10aa9a04,
	0x5a040900,
	0x049004a0,
	0x00400092,
	0x005a0500,
	0x49000000,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa6aaaaaa,
	0x45100550,
	0x000920aa,
	0x00552049,
	0xaa590500,
	0x9a0420aa,
	0x510065aa,
	0x00a25a04,
	0x05920490,
	0x55000050,
	0x0000009a,
	0xaaaa4900,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x5565aaaa,
	0xa5aa595a,
	0xa659a559,
	0x55559555,
	0xa6aaaa5a,
	0xa6aa9a55,
	0x9aa55555,
	0x559a55aa,
	0x5559659a,
	0xa5aa5555,
	0x59555555,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x59a655aa,
	0xa555a6aa,
	0xa55aa659,
	0xaaaa5555,
	0x9a55a6aa,
	0x5aa5aaaa,
	0x65aa9a65,
	0x659a555a,
	0x5a5555aa,
	0x5555a5aa,
	0xaaaa5955,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa080020,
	0xaa088aa0,
	0x00008200,
	0xaaaa0a00,
	0xaaaa08a2,
	0xa0aa0aa2,
	0xaaaa0000,
	0xaa28aa20,
	0x8a20aaaa,
	0xaa20aaaa,
	0x0a0000aa,
	0xa20aa2aa,
	0xaaaaaa8a,
	0xa0aa0a20,
	0x00a2aa08,
	0x0020aaaa,
	0x8a00a208,
	0x82008a00,
	0x0a000000,
	0x0000aaaa,
	0x0000aa0a,
	0x0000a08a,
	0xaa00a00a,
	0xa0aa8a00,
	0xa0aa0000,
	0x00aa0800,
	0x00aa0000,
	0xaa08a00a,
	0x0a20aaaa,
	0xaa08a0aa,
	0xaaaa00a2,
	0x9a040020,
	0x9a004100,
	0x00004100,
	0xa2aa0500,
	0xa28a0000,
	0xa00a0000,
	0xa2080000,
	0x9a005a00,
	0x080020aa,
	0x000020aa,
	0x000000aa,
	0xa005208a,
	0xaaaaaa09,
	0xa0aa0420,
	0x00a29a04,
	0x0520aa5a,
	0x01209a55,
	0x49005904,
	0x55450065,
	0x0000a0aa,
	0x0000a045,
	0x5004a008,
	0x4a00a200,
	0x00aa5900,
	0x005a0400,
	0x008a0000,
	0x200a0045,
	0x9a05a004,
	0x0400aaaa,
	0x9a04a0aa,
	0xaa5a00a2,
	0x9a550520,
	0x5a040020,
	0x00654900,
	0x20aa5545,
	0x20595504,
	0xa0005105,
	0x9a005104,
	0x5a044200,
	0x554500a2,
	0x10550092,
	0x1045000a,
	0x2004a009,
	0xaaaaaa45,
	0xa09a0400,
	0x00a29a04,
	0x0520aa5a,
	0x00a0aaaa,
	0x49009a05,
	0xaa4900aa,
	0x550520aa,
	0x51052059,
	0x92049000,
	0x41205a00,
	0x00a25a04,
	0x00925555,
	0x00091055,
	0xa2052049,
	0xaa451004,
	0x0000aaaa,
	0x9a04a09a,
	0xaa5a00a2,
	0xaaaa0520,
	0x9a4500a2,
	0x00aa4900,
	0x00aaaa49,
	0x00aa9a45,
	0x4000aa45,
	0x5a009004,
	0x9a050020,
	0xaa5904a0,
	0xa05a04a0,
	0x00490004,
	0x0000a205,
	0xa2aaaa59,
	0xa09a0005,
	0x00a29a04,
	0x0020aa5a,
	0x00a2aa08,
	0x4900aa55,
	0xaa4900aa,
	0xaa4500aa,
	0xaa4500aa,
	0x90044000,
	0x00a05a04,
	0x04a09a45,
	0x04a0aa5a,
	0x0004a05a,
	0xaa450049,
	0xaa590400,
	0x0005a2aa,
	0x9a04a05a,
	0xaa5a00a2,
	0xaa080020,
	0xaa4900a2,
	0x00aa4900,
	0x00aaaa49,
	0x00aaaa49,
	0x4000aa49,
	0x5a050004,
	0xaa4500a0,
	0xaa9a04a0,
	0xa09a04a0,
	0x00400004,
	0x0400aa55,
	0xa0aaaa5a,
	0xa04a0005,
	0x00a29a04,
	0x0020aa5a,
	0x00a09a04,
	0x4900aa0a,
	0xaa4900aa,
	0xaa4900aa,
	0xaa4900aa,
	0x00044000,
	0x00a29a45,
	0x04a0aa59,
	0x04a0aa9a,
	0x0004a09a,
	0xaa590440,
	0xaa9a0520,
	0x0045a0aa,
	0x9a04a04a,
	0xaa5a00a2,
	0x9a550520,
	0xaa0900a0,
	0x00aa4900,
	0x20aaaa49,
	0x00aaaa49,
	0x4000aa49,
	0xaa550404,
	0xaa5900a2,
	0xaa9a04a2,
	0xa09a04a0,
	0x45400004,
	0x0520aa5a,
	0xa0aaaa9a,
	0xa0090000,
	0x00a29a04,
	0x0520aa5a,
	0x00209a55,
	0x4900aa04,
	0xaa4900aa,
	0xaa0920aa,
	0xa20920aa,
	0x95045000,
	0x00a2aa59,
	0x00a2aa5a,
	0x00a2aa9a,
	0x0005209a,
	0xaa9a5549,
	0xaaaa0520,
	0x000020aa,
	0x9a04a009,
	0xaa5a00a2,
	0xaaaa0520,
	0xaa004000,
	0x00aa4900,
	0x20aaaa49,
	0x20aaaa08,
	0x5000a008,
	0xaa9a9504,
	0xaa5a00a2,
	0xaa8a00a2,
	0x008a00a2,
	0x59490005,
	0x0520aaaa,
	0x20aaaaaa,
	0xa0050000,
	0x00a29a04,
	0x0520aa5a,
	0x5100aaaa,
	0x49009a00,
	0xaa4900aa,
	0x0000a0aa,
	0x0000a08a,
	0x9a045004,
	0x00a2aaaa,
	0x00aaaa5a,
	0x00aa0800,
	0x00450000,
	0xaaaaaa49,
	0xaaaa0520,
	0x505500aa,
	0x9a04a004,
	0xaa5a00a2,
	0xa2000020,
	0x4a005100,
	0x00aa4900,
	0xa2aaaa49,
	0xa28a0000,
	0x50050000,
	0xaaaa9a04,
	0xaa5a00a2,
	0x080020aa,
	0x000020aa,
	0xaa490055,
	0x0520aaaa,
	0x00aaaaaa,
	0xa0045055,
	0x00820000,
	0x00200a00,
	0x5a04a000,
	0x49000a00,
	0xaa4900aa,
	0x0010aaaa,
	0x0000aa09,
	0x9a049045,
	0x00a2aaaa,
	0xa1aaaa5a,
	0xa09a0000,
	0x00590400,
	0xaaaaaa49,
	0xaaaa0520,
	0xa05a04aa,
	0x00009004,
	0x0a000082,
	0x5a000020,
	0x59045a04,
	0x00aa4900,
	0xaaaaaa49,
	0xaa590065,
	0xa0550561,
	0xaaaa9a04,
	0xaa5a00a2,
	0x0550a6aa,
	0x5510a69a,
	0xaa49005a,
	0x0520aaaa,
	0x04a2aaaa,
	0x9000a25a,
	0x00410000,
	0x55a60500,
	0x9a555a55,
	0x59a555a5,
	0xaa59a5aa,
	0x55a6aaaa,
	0x55a5aa55,
	0x9a55aa59,
	0x65aaaaaa,
	0xaaaaaa5a,
	0xaa5a5565,
	0xa59a5555,
	0xaaaaaa59,
	0xaaaa55a6,
	0xaa9aa5aa,
	0x55559a55,
	0x55556559,
	0x5a5555a6,
	0x9aa59aa5,
	0xa5aa59a5,
	0xaaaaaa59,
	0xaa5aa5aa,
	0xaaaa65aa,
	0xaaaa9a55,
	0xaa5a65aa,
	0x55aaaaaa,
	0x5aa6aaaa,
	0xaa59a5aa,
	0x55a6aaaa,
	0x65aaaaaa,
	0x5a65aa9a,
	0x65595555,
	0x00a05555,
	0x00aaaa00,
	0x0a200a00,
	0x0000a2aa,
	0x00000082,
	0x8a000002,
	0x0aaa20aa,
	0xaa8a0020,
	0xa0aaaa08,
	0xaa08aa8a,
	0xaaaa0aa0,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x0a0000a0,
	0x0a0000aa,
	0xa2aa0a20,
	0x00820000,
	0x00020000,
	0x00a28a00,
	0x002008a2,
	0x8a00a08a,
	0xaa0aa0aa,
	0x0000aa08,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a0aaaa,
	0x00aa0000,
	0x05200500,
	0x0000a2aa,
	0x00000041,
	0x49000001,
	0x055200aa,
	0x20490020,
	0xa0aa9a00,
	0x9204aa08,
	0xaa8a0000,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x005104a0,
	0x5545008a,
	0xa2aa0520,
	0x65595500,
	0x00514500,
	0x00aa5955,
	0x45100542,
	0x59452059,
	0xaa00a0aa,
	0x50059004,
	0xaaaaaa0a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x04a0aaaa,
	0x004a0055,
	0x05205545,
	0x5500a2aa,
	0x45006559,
	0x59550051,
	0x454020aa,
	0x20594520,
	0xa0aa5a05,
	0x10048a00,
	0xaa085005,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x009a04a0,
	0xaa490009,
	0xa2aa0520,
	0xaaaa5a00,
	0x00a24900,
	0x20aaaa5a,
	0x00204540,
	0xaa08208a,
	0x0a00a0aa,
	0xa2451004,
	0xaaaaaa04,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x04a0aaaa,
	0x0009209a,
	0x0520aa49,
	0x5a00a2aa,
	0x4900aaaa,
	0xaa5a00a2,
	0x5900a0aa,
	0xa08a0020,
	0xa0aaaa00,
	0x10040840,
	0x9a04a245,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x209a04a0,
	0x0a000005,
	0xa2aa0520,
	0xaa8a0000,
	0x00a24900,
	0xa2aa8a00,
	0x00205900,
	0x9a00a249,
	0x0040a0aa,
	0xa2491004,
	0xaaaa9a04,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x04a0aaaa,
	0x0005209a,
	0x05200a00,
	0x0000a2aa,
	0x4900aa8a,
	0x8a0000a2,
	0x5a04a2aa,
	0xaa594520,
	0xa0aa4a00,
	0x10040041,
	0x9a04a249,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x209a04a0,
	0x05000005,
	0xa2aa0520,
	0xaa490000,
	0x00a24900,
	0xa2aa4900,
	0x45205a04,
	0x4a20aa59,
	0x0049a0aa,
	0xa0091004,
	0xaaaa9a04,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x04a0aaaa,
	0x0045209a,
	0x05205545,
	0x5500a2aa,
	0x4900aa59,
	0x595500a2,
	0x9a04a2aa,
	0x2aaa4920,
	0xa0aa4920,
	0x90042049,
	0x9a05a009,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x009a04a0,
	0x55450045,
	0xa2aa0520,
	0xaa595500,
	0x00a24900,
	0xa2aa5955,
	0x00209a04,
	0x5900000a,
	0xa049a0aa,
	0x00009204,
	0xaaaa9a45,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x04a0aaaa,
	0x0049009a,
	0x0520aa49,
	0x5a00a2aa,
	0x4900aaaa,
	0xaa5a00a2,
	0x9a04a2aa,
	0x000a0020,
	0xa0aa5900,
	0x9a04a249,
	0xaa550000,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x009204a0,
	0xaa490059,
	0xa2aa0520,
	0xaaaa5a00,
	0x00a24900,
	0xa2aaaa5a,
	0x00209a04,
	0x5a05a005,
	0xaa49a0aa,
	0x05609a04,
	0xaaaaaa59,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a0aaaa,
	0x00590400,
	0x00200800,
	0x0000a200,
	0x4900aa0a,
	0x0a0000a2,
	0x9a65aaaa,
	0xa55555a6,
	0xaaaa5a55,
	0x9a65aa59,
	0xaa5a55a5,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x050000a0,
	0x0800005a,
	0xa2000020,
	0xaa0a0000,
	0x00a24900,
	0xaaaa0a00,
	0x55a69a65,
	0xaa55aa55,
	0xaa59aaaa,
	0x55aa9aa5,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a0aaaa,
	0x009a5500,
	0x00100400,
	0x00005200,
	0x4900aa05,
	0x050000a2,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x555555aa,
	0x5555a5aa,
	0x5a555596,
	0xaa555565,
	0x65aa59a5,
	0xaaaa5555,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x55aaaaaa,
	0xa5aa5a55,
	0x55965555,
	0x55655a55,
	0x59a5aa55,
	0x555565aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaa20aa,
	0xaa08aaaa,
	0x8a20aaaa,
	0xaa28aaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa08aaaa,
	0xaaaaaaaa,
	0x0aa2aaaa,
	0xaaaaaaaa,
	0x2028aaaa,
	0x20aa0a00,
	0xaaaaaaaa,
	0xaaaaaa08,
	0xaa0a0020,
	0x0a002028,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa0aaaa08,
	0x0a000000,
	0xaaaa0aa2,
	0xaaaaaaaa,
	0x0a002028,
	0xaa5a00aa,
	0x9a04aaaa,
	0x0000aaaa,
	0x1024aa8a,
	0xaaaa0a00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a04aaaa,
	0x0000a0aa,
	0x00000a00,
	0xaaaaaa00,
	0x1004aaaa,
	0x04aa0500,
	0xaaaaaa5a,
	0xaaaa9a04,
	0xaa4555a6,
	0x05001004,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa0aa9a04,
	0x05000000,
	0xaa000000,
	0xaaaaaaaa,
	0x55109604,
	0xaa5a04aa,
	0x9204aaaa,
	0x00a0aa8a,
	0x9604aa59,
	0xaaaa5555,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a04aaaa,
	0x1055aaaa,
	0x00005505,
	0xaaaa5a00,
	0x0004aaaa,
	0x04a20500,
	0xaaaaaa9a,
	0xa08a0000,
	0xaa090000,
	0x55559604,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaa9a04,
	0x55550055,
	0x5a5505a1,
	0xaaaaaaaa,
	0x0a000004,
	0xaa8a00a2,
	0x0020aaaa,
	0x0000a209,
	0x9a04aa0a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a04aaaa,
	0x04a2aaaa,
	0x05a1aa55,
	0xaaaa5855,
	0x0004aaaa,
	0x00a20500,
	0xa2aaa80a,
	0xa2590500,
	0xaa045545,
	0xaaaa1a04,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaa9a04,
	0xaa5a05a2,
	0x08080000,
	0xaaaaaaaa,
	0x55109504,
	0xa00800a0,
	0x5504208a,
	0x5565aa55,
	0x1004aa04,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a04aaaa,
	0x45a00aa2,
	0x0000aa9a,
	0xaa9a2000,
	0x9004aaaa,
	0x05a05500,
	0x208aa004,
	0xaaaa5565,
	0x9a04aa69,
	0xaaaa0404,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x8aa09a04,
	0xaaaa45a0,
	0x10050000,
	0xaaaaaa9a,
	0x5a001004,
	0x900445a0,
	0x9a550449,
	0xaaaaaaaa,
	0x04049a04,
	0xaaaaaa5a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a04aaaa,
	0x49a045a0,
	0x05a1aaaa,
	0xaa5a1055,
	0x0804aaaa,
	0x45a00a10,
	0x04591004,
	0xaaaaaa5a,
	0x9a05a2aa,
	0xaa9a0004,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x49209a24,
	0xaaaa49a0,
	0x205505a1,
	0xaaaaaa5a,
	0x0a100404,
	0x10045920,
	0xaa9a0059,
	0x20aaaaaa,
	0x10049a05,
	0xaaaa0a00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a20aaaa,
	0x08a25900,
	0x05a2aaaa,
	0xaa5a00aa,
	0x0004aaaa,
	0x59200504,
	0x205a0020,
	0xaa0a0000,
	0xaa450000,
	0x0a001004,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x59040020,
	0x8a0000a2,
	0x040000aa,
	0xaaaaaa5a,
	0x45061004,
	0x04205a20,
	0x0000a05a,
	0x0020aa0a,
	0x9204aa55,
	0xaaaa0500,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a0aaaa,
	0x00aa5a05,
	0x00aaaa00,
	0xaa5a0500,
	0x9124aaaa,
	0x5a809505,
	0xa65a45a0,
	0xaa050000,
	0xaa595520,
	0x55559624,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a5500a6,
	0x590061aa,
	0x5500a0aa,
	0xaaaaaa9a,
	0xa95596a5,
	0x55a65aa6,
	0x5555aa9a,
	0x55a6aa55,
	0x9aa5aa5a,
	0xaaaa5565,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x55aaaaaa,
	0xa5aaaa55,
	0xa5aa5a55,
	0xaaaa5555,
	0x9aa6aaaa,
	0x5aa9aa65,
	0xaaaa59aa,
	0xaa5555a5,
	0xaaaa5aa6,
	0xaaaa9aa6,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa5aa5aa,
	0x5a65aaaa,
	0x5a55aaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa0a20aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaa08aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa0aaaaaa,
	0x0aa2aa8a,
	0x00a2aaaa,
	0xaaaaaa00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00aaaa08,
	0x08aa0800,
	0xaaaaaaaa,
	0x00aaaaaa,
	0xaa000000,
	0xaa8aa0aa,
	0xaaaa0aa2,
	0x8a0086a2,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa08aaaa,
	0x080000aa,
	0xaa9a04aa,
	0xa0aa0aa2,
	0x000000aa,
	0x0000a000,
	0x05a20a00,
	0x65aa0aaa,
	0xaaaa4a00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x008a0000,
	0x049a0400,
	0x0aa2aa9a,
	0x00aa20aa,
	0x50000000,
	0x0a000000,
	0x0a0a0000,
	0x590069aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x0000aaaa,
	0x4550a58a,
	0xaa9a049a,
	0xa0aa05a2,
	0x0051a54a,
	0x00005055,
	0x00000500,
	0xa2aa0408,
	0xaaaa5900,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa5490000,
	0x049a0400,
	0x05a2aa9a,
	0xa50aa0aa,
	0x5a140550,
	0x55455055,
	0x24040000,
	0x5a04a2aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x5504aaaa,
	0x0000a259,
	0xaa9a048a,
	0xa2aa05a2,
	0x4120aa09,
	0x0051aa40,
	0x45a05545,
	0xa09a1414,
	0xaaaa5a05,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa0595504,
	0x048a0000,
	0x05a2aa9a,
	0xaa05a2aa,
	0x9a805120,
	0xaa4900a0,
	0x101045a0,
	0x9a45a09a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a0420aa,
	0x504520aa,
	0xa29a0409,
	0xa2aa0502,
	0x5904aa05,
	0x60205a09,
	0x49a0aa49,
	0x209a1020,
	0xaaaaaa55,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a2aaaa,
	0x00a29a00,
	0x04095155,
	0x0582a09a,
	0xaa04aaaa,
	0x5a695a04,
	0xaa495020,
	0x10205920,
	0xaa59205a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x0a0000a2,
	0xa25906a2,
	0xa09a0405,
	0xaa280541,
	0x9a04aa04,
	0x5020aaa5,
	0x5920aa49,
	0xa65a5620,
	0xaaaaaa5a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x45a0aaaa,
	0x45aa0000,
	0x2405a25a,
	0x0549209a,
	0x9a04aa20,
	0xaaaa9a00,
	0xaa4900a0,
	0x56005a20,
	0xaa5a245a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x000445a0,
	0x20aa658a,
	0x009a2045,
	0x9a040459,
	0x0a209a04,
	0x00a6aaaa,
	0x5a00aa49,
	0x00aa5a04,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a2aaaa,
	0xa04a1004,
	0x20450000,
	0x00590400,
	0x9a045a04,
	0xaa080020,
	0xaa4910aa,
	0x5a040004,
	0xaa9a00aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x900500a2,
	0x0400a059,
	0x0500a059,
	0x9a05205a,
	0x00a09aa5,
	0x0020aa0a,
	0x0004a259,
	0x24aa9a04,
	0xaaaaaa5a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x20aaaaaa,
	0xa0599645,
	0xa6594500,
	0xa09a5500,
	0x9aa59a45,
	0x9a0510a6,
	0xaa590420,
	0x9a050025,
	0xaa5aa5aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa5565aa,
	0x5555aa5a,
	0x5555aa9a,
	0xaa55a6aa,
	0x55aaaaaa,
	0x45a0aa55,
	0x9565aa5a,
	0xa6aa9a55,
	0xaaaaaa9a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa6aaaaaa,
	0xaaaaaa59,
	0xaaaa5955,
	0xaaaa5aa5,
	0xaaaaaa59,
	0xaa55a6aa,
	0xaa9a55a6,
	0xaa55a5a6,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa0aaaaaa,
	0xaaaaaa8a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa2aaaaaa,
	0xaaaaaa00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa0000a2,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa00a2aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a0aaaa,
	0xaaaa8a00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa2aaaaaa,
	0xaaaa4a00,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x4a0045a2,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x4a00a0aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x55aaaaaa,
	0xaaaa4900,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa0aaaaaa,
	0xaaaa4900,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x590069aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x0900a0aa,
	0x8a8200aa,
	0xaaaa00a2,
	0x0aaaa0aa,
	0xaa0820aa,
	0x8a008a00,
	0x0aa0aaaa,
	0x08a008a0,
	0xaa0a0a20,
	0xa2aa8a00,
	0xaaaa5900,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x20aaaaaa,
	0x00aa0950,
	0x00200a80,
	0x00a2aa8a,
	0x00a200aa,
	0x8a008a00,
	0xaaaa8a00,
	0x08a00800,
	0x022008a0,
	0x0a00a008,
	0x5a04a2aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x055020aa,
	0x490000aa,
	0xaa0a4000,
	0x044a00aa,
	0x0a1004a0,
	0x49004900,
	0x5500a2aa,
	0x049004a0,
	0x20050010,
	0xa0aa0801,
	0xaaaa5a05,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00aaaaaa,
	0x00aa0450,
	0x51004500,
	0x00aaaa08,
	0x05500442,
	0x49000950,
	0xa2aa4900,
	0x04905500,
	0x00100490,
	0x00451005,
	0x9a05a0aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x045004aa,
	0x510500aa,
	0xaa045100,
	0x054120aa,
	0x04900510,
	0x49004900,
	0x0a00a2aa,
	0x049004a0,
	0x00550410,
	0x209a0045,
	0xaaaaaa45,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00aaaaaa,
	0x009a0000,
	0x00005145,
	0x20aa9a04,
	0x05100541,
	0x490004a0,
	0xaaaa4900,
	0x04a00800,
	0x05100490,
	0x00000055,
	0xaa45205a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x000000a2,
	0xa245009a,
	0x9a040000,
	0x050020aa,
	0x04a00520,
	0x49004900,
	0x0060aaaa,
	0x049004a0,
	0x009a0510,
	0xa65a0000,
	0xaaaaaa59,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a2aaaa,
	0x005a0000,
	0x5500a249,
	0xa0aa9a55,
	0x05204500,
	0x490004a0,
	0xaaaa4900,
	0x049000a1,
	0x05100490,
	0x554500aa,
	0xaa59a45a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x005505a0,
	0xaa49004a,
	0x9a154500,
	0x4500a0aa,
	0x05a005a0,
	0x49004900,
	0x0082a2aa,
	0x04900450,
	0x20aa0510,
	0x205a5405,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x05a0aaaa,
	0x004a0055,
	0x0020aa49,
	0xa2aaaa0a,
	0x04a05900,
	0x00000520,
	0xa2aa4900,
	0x00500000,
	0x05100400,
	0x0800a0aa,
	0xaa8a00aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00aa45a0,
	0xaa490049,
	0xaa0400a0,
	0x5900a2aa,
	0x450000a2,
	0x49000020,
	0x0400a2aa,
	0x04000052,
	0xa2aa0510,
	0x209a0000,
	0xaaaaaa5a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x4520aaaa,
	0x000920aa,
	0x00a2aa49,
	0xa2aaaa55,
	0x10aa5a04,
	0x05a05504,
	0xaaaa4900,
	0x005a4520,
	0x05100450,
	0x4500aaaa,
	0xaa59a49a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xa5aa59aa,
	0xaa59a559,
	0x9a5555aa,
	0x5a04a2aa,
	0x595565aa,
	0x595555a6,
	0x5565aaaa,
	0x5555659a,
	0xaaaa5596,
	0xa65a5565,
	0xaaaaaa5a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x59a6aaaa,
	0xa555a6aa,
	0x65aaaa59,
	0xa2aaaa5a,
	0xa6aa9a05,
	0x55aa9a55,
	0xaaaa59a5,
	0xa5aa59a6,
	0x5596555a,
	0x59a5aaaa,
	0xaa9aaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x9a05a0aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x00a2aaaa,
	0xaaaaaa45,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa5500a2,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x04a2aaaa,
	0xaaaaaa59,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaa5a65aa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0x65aaaaaa,
	0xaaaaaa9a,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
	0xaaaaaaaa,
};

#endif /* _MEMENG_H_ */
/* DON'T ADD STUFF AFTER THIS */
