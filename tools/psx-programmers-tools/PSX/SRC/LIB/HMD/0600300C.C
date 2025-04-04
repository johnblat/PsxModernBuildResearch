/* $PSLibId: Run-time Library Release 4.4$ */

/* 
 *	Copyright(C) 1998 Sony Computer Entertainment Inc.
 *  	All rights reserved. 
 */


#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>
#include <inline_c.h>
#include <gtemac.h>
#include <asm.h>
#include <libgs.h>
#include <libhmd.h>
#include "envmap.h"

/*
 * Gouraud Triangle -> Gouraud Texture Triangle
 * for HMD-ENV (2D-ENV (refraction) for G3)
 */
u_long *GsU_0600300c(GsARGUNIT *sp)
{
	register GsENV		*ifo;
	register HMD_P_G3	*tp;
	GsARGUNIT_ENVMAP	*ap = (GsARGUNIT_ENVMAP *)sp;
	SVECTOR			*vp = ap->vertop;
	SVECTOR			*np = ap->nortop;
	u_long			*scratch = (u_long *)(ap+1);
	int			i;
	int			num;
	/* added variable */
	volatile POLY_GT3 *si_org;
	volatile POLY_GT3 *si_env;
	VECTOR lv;
	int uu, vv;
	int ddx, ddy;
	GsARGUNIT_ENVMAP	*ep = (GsARGUNIT_ENVMAP *)sp;
	u_short			tpage_env; /* to scratch */
	u_short			tpage_org; /* to scratch */
	u_short			clut_env; /* to scratch */
	u_short			clut_org; /* to scratch */
	u_char			reflect2;
	u_char			refract;
	u_char			org_r, org_g, org_b;

	num = *(ap->primp)>>16;
	ap->primp++;
	tp = (HMD_P_G3 *)(ap->primtop+(*(ap->primp)&0x00ffffff));

	tpage_org = GetTPage(ep->p20, ep->p21, ((u_short *)(ep->tex3))[4],
	                    ((u_short *)(ep->tex3))[5]);
	if(ep->p20 != 2) {
		clut_org = GetClut(((u_short *)(ep->clut3))[4],((u_short *)(ep->clut3))[5]);
	}

	refract = ep->p22;
	org_r = ep->p25;
	org_g = ep->p26;
	org_b = ep->p27;

	/* parameters write to scratch pad (initilaize) */
	ifo = (GsENV *)scratch;
	scratch += sizeof(GsENV)/4;
	ifo->pk = (u_long *)ap->out_packetp;
	ifo->org = (u_long *)ap->tagp->org;
	ifo->shift = ap->shift;

	si_org = (POLY_GT3 *) ifo->pk;

	for (i = 0; i < num; i++, tp++) {
		gte_ldv3(&vp[tp->v0], &vp[tp->v1], &vp[tp->v2]);
		gte_rtpt();			/* RotTransPers3 */
		gte_stflg(&ifo->flg);
		if (ifo->flg & 0x80000000)
			continue;
		gte_nclip();		/* NormalClip */
		gte_stopz(&ifo->otz);	/* back clip */
		if (ifo->otz <= 0)
			continue;

		gte_avsz3();
		gte_stotz(&ifo->otz);

		/* Original polygon */
		si_org->code = 0x34;	/* GT3, ABE=off, TGE=off */
		gte_stsxy3_gt3((u_long *) si_org);
		si_org->tpage = tpage_org;
		if(ep->p20 != 2) si_org->clut = clut_org;

		/* 1st vertex */
		gte_ApplyRotMatrix(&np[tp->n0], &lv);   /* normal->screen coord */
		ddx = lv.vx>0?((lv.vx*lv.vx)*refract>>24):-((lv.vx*lv.vx)*refract>>24);
		ddy = lv.vy>0?((lv.vy*lv.vy)*refract>>24):-((lv.vy*lv.vy)*refract>>24);
		uu = 128+((int)si_org->x0>>1)+ddx;
		vv = 128+((int)si_org->y0)-ddy;
		if(uu < 0) uu = 0;
		if(uu > 255) uu = 255;
		if(vv < 0) vv = 0;
		if(vv > 255) vv = 255;
		si_org->u0 = uu;
		si_org->v0 = vv;
		si_org->r0 = org_r;
		si_org->g0 = org_g;
		si_org->b0 = org_b;

		/* 2nd vertex */
		gte_ApplyRotMatrix(&np[tp->n1], &lv);   /* normal->screen coord */
		ddx = lv.vx>0?((lv.vx*lv.vx)*refract>>24):-((lv.vx*lv.vx)*refract>>24);
		ddy = lv.vy>0?((lv.vy*lv.vy)*refract>>24):-((lv.vy*lv.vy)*refract>>24);
		uu = 128+((int)si_org->x1>>1)+ddx;
		vv = 128+((int)si_org->y1)-ddy;
		if(uu < 0) uu = 0;
		if(uu > 255) uu = 255;
		if(vv < 0) vv = 0;
		if(vv > 255) vv = 255;
		si_org->u1 = uu;
		si_org->v1 = vv;
		si_org->r1 = org_r;
		si_org->g1 = org_g;
		si_org->b1 = org_b;

		/* 3rd vertex */
		gte_ApplyRotMatrix(&np[tp->n2], &lv);   /* normal->screen coord */
		ddx = lv.vx>0?((lv.vx*lv.vx)*refract>>24):-((lv.vx*lv.vx)*refract>>24);
		ddy = lv.vy>0?((lv.vy*lv.vy)*refract>>24):-((lv.vy*lv.vy)*refract>>24);
		uu = 128+((int)si_org->x2>>1)+ddx;
		vv = 128+((int)si_org->y2)-ddy;
		if(uu < 0) uu = 0;
		if(uu > 255) uu = 255;
		if(vv < 0) vv = 0;
		if(vv > 255) vv = 255;
		si_org->u2 = uu;
		si_org->v2 = vv;
		si_org->r2 = org_r;
		si_org->g2 = org_g;
		si_org->b2 = org_b;

		ifo->tag = (u_long *) (ifo->org + (ifo->otz >> ifo->shift));
		*(u_long *) si_org = (u_long)((*ifo->tag & 0x00ffffff) | 0x09000000);
		*ifo->tag = (u_long) si_org & 0x00ffffff;
		si_org++;
	}

	GsOUT_PACKET_P = (PACKET *)si_org;
	return(ap->primp+1);
}
