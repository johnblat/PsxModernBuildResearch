/* $PSLibId: Run-time Library Release 4.4$ */

/* 
 *	Copyright(C) 1998 Sony Computer Entertainment Inc.
 *  	All rights reserved. 
 */


#include <r3000.h>
#include <asm.h>
#include <inline_s.h>
#include <gtereg_s.h>

	.globl	GsU_00300209		/* */

	

	.text


/************************************************************************
* Tile Back Facing Semi-Trans Flat/Texture Triangle with lighting
*
*	a0: (GsARGUNIT *)sp
*
*	typedef struct {
*		u_long	*primp;		// 0(a0)
*		GsOT 	*tagp;		// 4(a0)
*		int	shift;		// 8(a0)
*		int	offset;		// 12(a0)
*		PACKET	*out_packetp;	// 16(a0)
		u_long	*primtop;	// 20(a0)
*		SVECTOR	*vertop;	// 24(a0)
*		SVECTOR	*nortop;	// 28(a0)
*	}	GsARGUNIT;
*	num:				// (*primtop) >> 16
*************************************************************************/

GsU_00300209:

	.set    noreorder

	lw	a3,0(a0)		/* a3: sp->primp */
	lw	t9,4(a0)		/* sp->tagp */
	lw	t8,0(a3)		/* *(sp->primp) */
	lw	t7,8(a0)		/* sp->shift */
	addu	a3,a3,4			/* skip size, num */
	lw	a2,0(a3)		/* prim idx:*(sp->primp) */
	lw	a1,20(a0)		/* sp->primtop */
	sll	a2,a2,2			/* idx*4 */
	srl	t8,t8,16		/* t8: num */
	beq	t8,0,TF3L_3		/* if(n==0) goto TF3L_3: */
	addu	a3,a1,a2		/* primtop: sp->primtop+idx */

	li	v0,0x26808080		/* v0: RGBcd */
	lw	t0,4(t9)		/* t0: otp->org */
	mtc2 	v0,C2_RGB		/* v0 -> C2_RGB */

	lw	t1,12(a0)		/* t1: otp->offset */
	addu	v0,a0,16
	lw	t2,16(a3)		/* t2: primtop->v0,n0 */
	lw	t3,20(a3)		/* t3: primtop->v1,v2 */
	lw	t9,0(v0)		/* t9: out_packetp */

	lw	a1,24(a0)		/* a1: vertop */
	lw	a2,28(a0)		/* a2: nortop */
	srl	t4,t2,16		/* t4: v0 */
	sll	t4,t4,3			/* t4: v0*8 */
	addu	t4,t4,a1		/* t4: (vertop+primtop->v0) */


TF3L_1:
	lwc2	C2_VXY0,(t4)		/* Vector 0 <--(vertop+primtop->v0) */
	lwc2	C2_VZ0,4(t4)

	sll	t5,t3,16		/* t5: v1 */
	srl	t5,t5,13		/* t5: v1*8 */
	addu	t5,t5,a1		/* t5: (vertop+primtop->v1) */
	lwc2	C2_VXY1,(t5)		/* Vector 1 <--(vertop+primtop->v1) */
	lwc2	C2_VZ1,4(t5)

	nop
	srl	t5,t3,16		/* t5: v2 */
	sll	t5,t5,3			/* t5: v2*8 */
	addu	t5,t5,a1		/* t5: (vertop+primtop->v2) */
	lwc2	C2_VXY2,(t5)		/* Vector 2 <--(vertop+primtop->v2) */
	lwc2	C2_VZ2,4(t5)
	sll	t5,t2,16		/* t5: n0<<16 */
	srl	t5,t5,13		/* t5: n0*8 */

	/****/
        RTPT				
	/****/

	addu	t5,t5,a2		/* t5: (nortop+primtop->n0) */

	lw	v0, 0(a3)		/* tw */
	lw	t2, 4(a3)		/* t2: primtop->uv0 */
	lw	t3, 8(a3)		/* t3: primtop->uv1 */
	lw	t4, 12(a3)		/* t4: primtop->uv2 */
	sw	v0, 4(t9)		/* tw */
	sw	t2, 16(t9)		/* t2: out_packetp->uv0 */
	sw	t3, 24(t9)		/* t3: out_packetp->uv1 */
	sw	t4, 32(t9)		/* t4: out_packetp->uv2 */

	addu	a3,a3,24		/* primtop++ */
	lw	t2,16(a3)		/* t2: primtop->v0,n0 */
	lw	t3,20(a3)		/* t3: primtop->v1,v2 */

	srl	t4,t2,16		/* t4: v0 */
	sll	t4,t4,3			/* t4: v0*8 */
	addu	t4,t4,a1		/* t4: (vertop+primtop->v0) */

	cfc2	v0,C2_FLAG		/* v0: flag */
	nop
	blt	v0,0,TF3L_2		/* clip if flag <0 */
	nop

	/****/
        NCLIP				
	/****/


	mfc2	v0,C2_MAC0		/* opz read */
	nop
	nop

	/****/
	AVSZ3				
	/****/

	bge	v0,0,BACKF_0		/* if MAC0(OPZ)>=0 */
	nop

	lw	t6,0(t5)		/* back facing */
	lw	v0,4(t5)
	negu	t6,t6
	sll	t5,t6,16
	negu	t5,t5
	srl	t5,t5,16
	and	t6,t6,0xffff0000
	or	t6,t6,t5
	sll	v0,v0,16
	negu	v0,v0
	srl	v0,v0,16
	mtc2	t6,C2_VXY0		/* NX0,NY0,NZ0 <--(nortop+primtop->n0) */
	mtc2	v0,C2_VZ0
	j	BACKF_1
	nop

BACKF_0:
	lwc2	C2_VXY0,(t5)		/* NX0,NY0,NZ0 <--(nortop+primtop->n0) */
	lwc2	C2_VZ0,4(t5)

BACKF_1:
	mfc2	t6,C2_OTZ		/* t6: otz */
	nop
	nop

	/****/
        NCCS				
	/****/
	
	subu 	t6,t6,t1		/* sz = sz(otz) - otp->offset */
	srl 	t6,t6,t7		/* sz = (sz(otz) - otp->offset)>>shift; */
	and	t6,t6,0x0ffff		/* mask ? */
	sll	t6,t6,2			/* sz*4 */
	addu	t6,t6,t0		/* t6: &(tagp->org[sz]) */
	lw	t5,0(t6)		/* t5: table[sz].p */

	li	v0,0x9000000		/* (sizeof(POLY_FT3)/4-1)<<24)+2 */
	sll	v1,t5,8			
	srl	v1,v1,8			/* v1: clear (31..24) of table[sz].p */
	or	v0,v0,v1		/* v0: (table[sz].p)| */
					/* (sizeof(POLY_FT3)/4-1)<<24)+2 */
	sw	v0,0(t9) 		/* *(long *)pkt_base = v0 */
	
	.set noat
	li	AT,0xe2000000		/* tw reset */
	xor	v0,t9,t5		/* v0 : pkt_base xor table[sz].p */
	sw	AT,36(t9)		/* tw reset */
	.set at

	sll	v1,v0,8			
	srl	v0,v1,8			/* v0: clear (31..24) of v0 */
	xor	v1,v0,t5		/* v1: v0 xor table[sz].p */
	sw	v1,0(t6)		/* table[sz].p = pkt_base; */

    	swc2    C2_SXY0,12(t9)		/* sxy0 -->12(pkt_base) */
    	swc2    C2_SXY1,20(t9)		/* sxy1 -->20(pkt_base) */
	swc2    C2_SXY2,28(t9) 		/* sxy2 -->28(pkt_base) */
	swc2	C2_RGB2,8(t9)		/* R2,G2,B2,cd -->8(pkt_base) */

	addu	t9,t9,40		/* pkt_base++; */

TF3L_2:
	subu	t8,t8,1
	bne	t8,0,TF3L_1		/* if(primtop != primtop+n) goto TF3L_1 */
	nop

TF3L_3:
	lw	v0,0(a0)		/* sp->primp */
	sw	t9,GsOUT_PACKET_P
	addu	v0,v0,8			/* sp->primp+2 */

    	.set    reorder
    	j       ra			/* return(primtop) */
