/* $PSLibId: Run-time Library Release 4.4$ */
/*
 *	"tuto0.c" HMD ANIMATION viewer (including VIEW point control)
 *
 *		Copyright (C) 1997  Sony Computer Entertainment
 *		All rights Reserved
 *
 *	This program works with data/hmd/scei/anim/tri4/tri.hmd
 *
 */

/* #define DEBUG		/**/

/*
/* #define INTER		/* Interlace mode */

#include <sys/types.h>

#include <libetc.h>		/* PADを使うためにインクルードする必要あり */
#include <libgte.h>		/* LIGSを使うためにインクルードする必要あり*/
#include <libgpu.h>		/* LIGSを使うためにインクルードする必要あり */
#include <libgs.h>		/* グラフィックライブラリ を使うための
				   構造体などが定義されている */
#include <libhmd.h>             /* for LIBHMD */
#include "../common/scan.h"

#define OBJECTMAX 100		/* ３Dのモデルは論理的なオブジェクトに
                                   分けられるこの最大数 を定義する */

#define MODEL_ADDR (u_long *)0x80010000
				/* モデリングデータ（HMDフォーマット）
				   がおかれるアドレス */

#define OT_LENGTH 10		/* オーダリングテーブルの解像度 */

/*#define PACKETMAX (10000*24)*/
#define PACKETMAX (8000*24)


GsOT            Wot[2];		/* オーダリングテーブルハンドラ
				   ダブルバッファのため２つ必要 */

GsOT_TAG	zsorttable[2][1<<OT_LENGTH];
				/* オーダリングテーブル実体 */

GsUNIT		object[OBJECTMAX];
				/* オブジェクトハンドラ
				   オブジェクトの数だけ必要 */

u_long		bnum;		/* モデリングデータのオブジェクトの数を
				   保持する */
long            anum;           /* アニメーションがつけられている
				   シーケンスの数 */

GsCOORDUNIT	*DModel = NULL;	/* オブジェクトごとの座標系 */

SVECTOR         PModel;

/* オブジェクトごとの座標系を作るための元データ */

GsVIEWUNIT      view;

GsF_LIGHT	pslt[3];	/* 平行光源を設定するための構造体 */
u_long		padd;		/* コントローラのデータを保持する */

PACKET          out_packet[2][PACKETMAX];
				/* GPU PACKETS AREA */

GsSEQ  *seq[64];

/* 
 * prototype
 */
void init_all(void);
int  obj_interactive(void);
void set_coordinate(GsCOORDUNIT *coor);
void model_init(void);
void view_init(void);
void light_init(void);
void init_anim(void);
void animation_scan(void);


/************* MAIN START ******************************************/
main()
{
	GsUNIT	*op;		/* オブジェクトハンドラへのポインタ */
	int	outbuf_idx;
	MATRIX	tmpls,tmplw;
	int	i;
	
	ResetCallback();
	init_all();

	FntLoad(960, 256);
	FntOpen(16-160, 16-120, 256, 200, 0, 512); 

	GsInitVcount();
	while(1) {
		/* パッドデータから動きのパラメータを入れる */
		if(obj_interactive() == 0) {
			common_PadStop();
			ResetGraph(3);
			StopCallback();
			return 0;
		}
		view.view = DModel[bnum-3].matrix; /* the last matrixe is ready forVIEW matrix  */
		view.super = DModel[bnum-3].super; /* view matrix has the super */
		GsSetViewUnit(&view);	/* ワールドスクリーンマトリックス計算 */
		outbuf_idx=GsGetActiveBuff();
					/* ダブルバッファのどちらかを得る */
		GsSetWorkBase((PACKET*)out_packet[outbuf_idx]);
			
		GsClearOt(0, 0, &Wot[outbuf_idx]);
					/* オーダリングテーブルをクリアする */
		for(i=0,op=object; i<bnum; i++,op++) {
			if (op->primtop == NULL)
				continue;
			if (op->coord) {
				/* スクリーン／ローカルマトリックスを計算する */
				GsGetLwUnit(op->coord, &tmpls);
	
				/* ライトマトリックスをGTEにセットする */
				GsSetLightMatrix(&tmpls);
	
				/* スクリーン／ローカルマトリックスをGTEに
				   セットする */
				GsGetLsUnit(op->coord, &tmpls);
	
				/* ライトマトリックスをGTEにセットする */
				GsSetLsMatrix(&tmpls);
			}

			/* オブジェクトを透視変換しオーダリングテーブルに
			   登録する */
			GsSortUnit(op, &Wot[outbuf_idx], getScratchAddr(0));
		}
		padd = common_PadRead();/* パッドのデータを読み込む */
		FntPrint("Hcount = %d\n", GsGetVcount()); /**/
#ifndef INTER
		DrawSync(0);
#endif /* !INTER */
		VSync(0);		/* Vブランクを待つ */
		GsClearVcount();
#ifdef INTER
		ResetGraph(1);		/* Reset GPU */
#endif /* INTER */
		GsSwapDispBuff();	/* ダブルバッファを切替える */
		/* 画面のクリアをオーダリングテーブルの最初に登録する */
		GsSortClear(0x0, 0x0, 0x0, &Wot[outbuf_idx]);

		/* オーダリングテーブルに登録されているパケットの描画を
		   開始する */
		GsDrawOt(&Wot[outbuf_idx]);

		FntFlush(-1);
	}
}

int obj_interactive()
{
	static int num = 0;
	static u_long opadd = 0;
	int cnum;
	
	if (padd != opadd) {
	        if (padd & PADR2)	{num++;}
	        if (padd & PADL2)	{num--;}
		if (padd & PADstart)	seq[num]->sid++;
		if (padd & PADselect)	seq[num]->sid--;
		limitRange(num, 0, anum);
	}
	
	cnum = (((seq[num]->rewrite_idx-1)&0xffff)*4)/sizeof(GsCOORDUNIT);

	FntPrint("SEQ/COD=%d/%d  Sid = %d\n",num,cnum,seq[num]->sid);
	
	if (padd & PADRleft)	DModel[cnum].rot.vy += 5*ONE/360;
	if (padd & PADRright)	DModel[cnum].rot.vy -= 5*ONE/360;
	if (padd & PADRup)	DModel[cnum].rot.vx += 5*ONE/360;
	if (padd & PADRdown)	DModel[cnum].rot.vx -= 5*ONE/360;
	
	if (padd & PADLleft)	DModel[cnum].matrix.t[0] -= 10;
	if (padd & PADLright)	DModel[cnum].matrix.t[0] += 10;
	
	if (padd & PADLdown)	DModel[cnum].matrix.t[1] += 10;
	if (padd & PADLup)	DModel[cnum].matrix.t[1] -= 10;
	
	if (padd & PADL1)	DModel[cnum].matrix.t[2] += 50;
	if (padd & PADR1)	DModel[cnum].matrix.t[2] -= 50;
	
	if ((padd & PADselect) && (padd & PADstart)) {
		return(0);
	}
	
	
	
	set_coordinate(&DModel[cnum]);
	
	opadd = padd;
	return(1);
}


void init_all(void)		/* 初期化ルーチン群 */
{
	ResetGraph(0);		/* reset GPU */
	common_PadInit();	/* コントローラ初期化 */
	padd = 0;		/* コントローラ値初期化 */
#ifdef INTER
	GsInitGraph(640, 480, GsINTER|GsOFSGPU, 1, 0);
				/* 解像度設定（インターレースモード） */
	GsDefDispBuff(0, 0, 0, 0);
				/* ダブルバッファ指定 */
#else /* INTER */
	GsInitGraph(320, 240, GsNONINTER|GsOFSGPU, 1, 0);
				/* 解像度設定（ノンインターレースモード） */
	GsDefDispBuff(0, 0, 0, 240);
				/* ダブルバッファ指定 */
#endif /* INTER */

	GsInit3D();		/* ３Dシステム初期化 */
	
	Wot[0].length = OT_LENGTH;/* オーダリングテーブルハンドラに解像度設定 */
	Wot[0].org = zsorttable[0];
				/* オーダリングテーブルハンドラに
				   オーダリングテーブルの実体設定 */
	/* ダブルバッファのためもう一方にも同じ設定 */
	Wot[1].length = OT_LENGTH;
	Wot[1].org = zsorttable[1];

	model_init();		/* モデリングデータ読み込み */
	view_init();		/* 視点設定 */
	light_init();		/* 平行光源設定 */
	init_anim();
}

void view_init(void)		/* 視点設定 */
{
	/*---- Set projection,view ----*/
	GsSetProjection(1000);	/* プロジェクション設定 */
}


void light_init(void)		/* 平行光源設定 */
{
	/* ライトID０ 設定 */	
	/* 平行光源方向パラメータ設定 */
	pslt[0].vx = 100; pslt[0].vy = 100; pslt[0].vz = 100;

	/* 平行光源色パラメータ設定 */
	pslt[0].r = 0xd0; pslt[0].g = 0xd0; pslt[0].b = 0xd0;

	/* 光源パラメータから光源設定 */
	GsSetFlatLight(0, &pslt[0]);
	
	/* ライトID１ 設定 */
	pslt[1].vx = 20; pslt[1].vy = -50; pslt[1].vz = -100;
	pslt[1].r = 0x80; pslt[1].g = 0x80; pslt[1].b = 0x80;
	GsSetFlatLight(1, &pslt[1]);
	
	/* ライトID２ 設定 */
	pslt[2].vx = -20; pslt[2].vy = 20; pslt[2].vz = 100;
	pslt[2].r = 0x60; pslt[2].g = 0x60; pslt[2].b = 0x60;
	GsSetFlatLight(2, &pslt[2]);
	
	/* アンビエント設定 */
	GsSetAmbient(0, 0, 0);
	
	/* 光源計算のデフォルトの方式設定 */	
	GsSetLightMode(0);
}

void init_anim()
{
  int i;
  
  /* update sequence to GsSEQ */
  for(i=0;i<anum;i++){
    seq[i]->ii     = 0xffff;
    seq[i]->ti     = seq[i]->start;
    seq[i]->aframe = 0xffff; /* endless loop */
    seq[i]->sid    = seq[i]->start_sid;
    if (seq[i]->speed == 0)
	seq[i]->speed  = 0x10;	/* normal play back */
  }
}



/* マトリックス計算ワークからマトリックスを作成し座標系にセットする */
void set_coordinate(GsCOORDUNIT *coor)
{
	/* マトリックスにローテーションベクタを作用させる */
	RotMatrix(&coor->rot, &coor->matrix);

	/* マトリックスキャッシュをフラッシュする */
	coor->flg = 0;
}

/* モデリングデータの読み込み */
void model_init(void)
{
	u_long	*dop;
	int	i,ret;
	u_long	*oppp;
	
	dop = (u_long *)MODEL_ADDR;
				/* モデリングデータが格納されているアドレス */
	GsMapUnit(dop);		/* モデリングデータ（HMDフォーマット）を
				   実アドレスにマップする */
	dop++;			/* ID skip */
	dop++;			/* flag skip */
	dop++;			/* headder top skip */
	bnum = *dop;		/* ブロック数を HMD のヘッダから得る */
	dop++;			/* skip block number */

	for (i = 0; i < bnum; i++) {
		GsTYPEUNIT	ut;

		object[i].primtop = (u_long *)dop[i];
		if (object[i].primtop == NULL)
			continue;

		GsScanUnit(object[i].primtop, 0, 0, 0);
		while (GsScanUnit(0, &ut, &Wot[0], getScratchAddr(0))) {
			if (((ut.type >> 24 == 0x00)	/* CTG 0: POLY */
			|| (ut.type >> 24 == 0x01)	/* CTG 1: SHARED */
			|| (ut.type >> 24 == 0x05)	/* CTG 5: GROUND */
			|| (ut.type >> 24 == 0x06)	/* CTG 6: ENVMAP(beta) */
			) && (ut.type & 0x00800000)) {	/* check INI bit */
				DModel = GsMapCoordUnit(MODEL_ADDR, ut.ptr);
				/* clear INI bit */
				ut.type &= (~0x00800000);
			}

			*ut.ptr = NULL;
			switch (ut.type >> 24) {
			case 0x00:	/* CTG 0: POLY or NULL */
				*ut.ptr = scan_poly(ut.type);
				break;
			case 0x01:	/* CTG 1: SHARED */
				*ut.ptr = scan_shared(ut.type);
				break;
#ifdef notdef
			case 0x02:	/* CTG 2: IMAGE */
				*ut.ptr = scan_image(ut.type);
				/*
					The image is loaded only one time
					in this application.
				*/
				((GsUNIT_Funcp)(*ut.ptr))
					((GsARGUNIT *)getScratchAddr(0));
				*ut.ptr = (u_long)GsU_00000000;
				break;
#endif /* notdef */
			case 0x03:	/* CTG 3: ANIMATION */
				*ut.ptr = scan_anim(ut.type);
				if (*ut.ptr != NULL
				&& *ut.ptr != (u_long)GsU_00000000) {
					anum = GsLinkAnim(seq, ut.ptr);
					if (GsScanAnim(ut.ptr, 0) == 0) {
						printf("ScanAnim failed!!\n\n");
					} else {
						scan_interp();
					}
				}
				break;
#ifdef notdef
			case 0x04:	/* CTG 4: MIMe */
				*ut.ptr = scan_mime(ut.type);
				switch (ut.type) {
				case GsVtxMIMe:
				case GsNrmMIMe:
				case GsJntAxesMIMe:
				case GsJntRPYMIMe:
					/*
						This application has
						no area for MIMePr.
					*/
					/*
					set_mimepr(ut.type, GsGetHeadpUnit());
					*/
					break;
				case GsRstVtxMIMe:
					GsInitRstVtxMIMe(
						ut.ptr, GsGetHeadpUnit());
					break;
				case GsRstNrmMIMe:
					GsInitRstNrmMIMe(
						ut.ptr, GsGetHeadpUnit());
					break;
				default:
					/* do nothing */;
				}
				break;
			case 0x05:	/* CTG 5: GROUND */
				*ut.ptr = scan_gnd(ut.type);
				break;
			case 0x06:	/* CTG 6: ENVMAP(beta) */
				*ut.ptr = scan_envmap(ut.type);
				break;
#endif /* notdef */
			default:
				/* do nothing */;
			}
			if (*ut.ptr == NULL) {
				printf("unsupported type 0x%08x\n", ut.type);
				*ut.ptr = (u_long)GsU_00000000;
			}

#ifdef DEBUG
			printf("DEBUG:block:%d, Code:0x%08x\n", i, ut.type);
#endif /* DEBUG */
		}
		object[i].coord = NULL;
	}

	if (DModel != NULL) {
		for(i = 1; i < bnum - 1; i++) {
			object[i].coord = &DModel[i - 1];
		}
	}
}
