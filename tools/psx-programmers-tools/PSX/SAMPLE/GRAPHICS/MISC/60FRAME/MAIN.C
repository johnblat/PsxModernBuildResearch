/*
 * $PSLibId: Run-time Library Release 4.4$
 */
/*				60frame
 *
 *         Copyright (C) 1995 by Sony Computer Entertainment
 *			All rights Reserved
 *
 *	 Version	Date		Design
 *	--------------------------------------------------------
 *	1.00		Nov,11,1995	sachiko
 *	1.01		Mar, 6,1997	sachiko	(added autopad)
 */
/* 60フレームと30フレームの違い */

#include <sys/types.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>

#define OT_LENGTH	12		/* OTの解像度 */
#define	OT_SIZE		(1<<OT_LENGTH)	/* OTの大きさ */
#define	SCR_Z		1000	/* 視点からスクリーンまでの距離 */

#define OBJECTMAX 100		/* ３Dのモデルは論理的なオブジェクトに
                                   分けられるこの最大数 を定義する */

#define PACKETMAX  10000		/* Max GPU packets */
#define PACKETMAX2 (PACKETMAX*24)	/* size of PACKETMAX (byte)
                                    	   paket size may be 24 byte(6 word) */
#define	FRAME_30	0
#define	FRAME_60	1

/* テクスチャデータ（TIMフォーマット）がおかれるアドレス */
#define TEX_ADDR1	0x80010000
#define TEX_ADDR2	0x80020000
#define TEX_ADDR3	0x80030000
#define TEX_ADDR4	0x80040000
#define TEX_ADDR5	0x80050000
#define TEX_ADDR6	0x80060000
#define TEX_ADDR7	0x80070000

/* モデリングデータ（TMDフォーマット）がおかれるアドレス */
#define MODEL_ADDR	0x80080000

typedef struct {
	GsOT		gsot;
	GsOT_TAG	ot[OT_SIZE];
	PACKET		packet[PACKETMAX2];
} DB;

static int init_system(DB *db);
static void init_coordinate(GsCOORDINATE2 *objWorld,SVECTOR *rotate);
static void init_view();
static void init_light();
static void init_model(GsCOORDINATE2 *objWorld,GsDOBJ2 *object,int *objcnt);
static void init_texture();
static void load_texture(u_long addr);
static int  pad_read(GsCOORDINATE2 *objWorld,SVECTOR *rotate,int *frame);
static void move_object(GsCOORDINATE2 *objWorld,SVECTOR *rotate);
static void draw_object(DB *db,GsDOBJ2 *object,int objcnt,int frame);
static void opening(GsCOORDINATE2 *objWorld,SVECTOR *rotate
			,DB *db,GsDOBJ2 *object,int objcnt);

extern MATRIX	GsIDMATRIX;

main()
{
	GsCOORDINATE2	objWorld;	/* オブジェクト座標系 */
	int		objcnt;
	DB		db[2];		/* packet double buffer */
	int		idx;		/* 現在の db のインデックス */
	SVECTOR		rotate;		/* オブジェクトの回転ベクトル */
	GsDOBJ2		object[OBJECTMAX];	/* オブジェクトハンドラ
						   オブジェクトの数だけ必要 */
	static int	frame=FRAME_60;
	/*MATRIX		fnt;*/

	/* 初期設定 */
	if ( init_system(db) ) return;
	init_coordinate(&objWorld,&rotate);
	init_view();
	init_light();
	init_model(&objWorld,object,&objcnt);
	init_texture();

	FntLoad(960,256);
	SetDumpFnt(FntOpen(32,32,640,240,0,30));

	opening(&objWorld,&rotate,db,object,objcnt);

	while ( pad_read(&objWorld,&rotate,&frame)==NULL ) {

		/* オブジェクトの回転・平行移動を計算する */
		move_object(&objWorld,&rotate);

		/* ダブルバッファのどちらかを得る */
		idx = GsGetActiveBuff();

		/* オブジェクトの描画 */
		draw_object(&db[idx],object,objcnt,frame);

	}
	PadStop();
	ResetGraph(3);
	StopCallback();
	return 0;
}

static int init_system(DB *db)
{
	/* コールバックの初期化 */
	ResetCallback();

	GsInitVcount();

	/* コントローラの初期化*/
	PadInit(0);

	/* GPU の初期化 */
	GsInitGraph(640,240,GsINTER|GsOFSGPU,0,0);
	GsDefDispBuff(0,0,0,240);

	/* OT の初期化 */
	db[0].gsot.length = db[1].gsot.length = OT_LENGTH;
	db[0].gsot.point  = db[1].gsot.point  = 0;
	db[0].gsot.offset = db[1].gsot.offset = 0;
	db[0].gsot.org    = db[0].ot;
	db[1].gsot.org    = db[1].ot;

	/* 3Dシステムの初期化 */
	GsInit3D();
	
	return(0);
}

static void init_coordinate(GsCOORDINATE2 *objWorld,SVECTOR *rotate)
{

	memset(objWorld,0,sizeof(GsCOORDINATE2));
	memset(rotate,0,sizeof(SVECTOR));
	/* 一番親になる座標系の指定 */
	GsInitCoordinate2(WORLD,objWorld);

	/*objWorld->coord.t[2] = -500;*/
}

static void init_view()
{
	GsRVIEW2	view;

	/* 投影面の位置設定 */
	GsSetProjection(SCR_Z);

	/* 視点位置の設定 */
	view.vpx = 0; view.vpy = 0; view.vpz = 1000;
	view.vrx = 0; view.vry = 0; view.vrz = 0;
	view.rz  = 0;
	view.super = WORLD;
	GsSetRefView2(&view);

	/* Ｚクリップ値を設定 */
	GsSetNearClip(100);
}

static void init_light()
{
	GsF_LIGHT	light;

	/* 光源 #0 の設定 */
	light.vx = 20;   light.vy = -100;  light.vz = -100;
	light.r  = 0xd0; light.g  = 0xd0; light.b  = 0xd0;
	GsSetFlatLight(0,&light);

	/* アンビエント（周辺光）の設定 */
	GsSetAmbient(ONE/2,ONE/2,ONE/2);

	/* 光源モードの設定（通常光源/FOGなし） */
	GsSetLightMode(0);
}

/* モデリングデータの読み込み */
static void init_model(GsCOORDINATE2 *objWorld,GsDOBJ2 *object,int *objcnt)
{
	u_long	*dop;
	GsDOBJ2	*objp;		/* モデリングデータハンドラ */
	int i;

	/* モデリングデータが格納されているアドレス */
	dop=(u_long *)MODEL_ADDR;
	dop++;	/* hedder skip */

	/* モデリングデータ（TMDフォーマット）を実アドレスにマップする */
	GsMapModelingData(dop);

	dop++;
	*objcnt = *dop;		/* オブジェクト数をTMDのヘッダから得る */

	dop++;			/* GsLinkObject4でリンクするためにTMDの
				   オブジェクトの先頭にもってくる */

	/* TMDデータとオブジェクトハンドラを接続する */
	for(i=0;i<*objcnt;i++)
		GsLinkObject4((u_long)dop,&object[i],i);

	objp = object;
	i = *objcnt;
	while ( i-- ) {
		/* デフォルトのオブジェクトの座標系の設定 */
		objp->coord2 =  objWorld;

		objp->attribute = 0;
		objp++;
	}
}

static void init_texture()
{
	load_texture(TEX_ADDR1);
	load_texture(TEX_ADDR2);
	load_texture(TEX_ADDR3);
	load_texture(TEX_ADDR4);
	load_texture(TEX_ADDR5);
	load_texture(TEX_ADDR6);
	load_texture(TEX_ADDR7);
}

/* テクスチャデータをVRAMにロードする */
static void load_texture(u_long addr)
{
	RECT	rect;
	GsIMAGE	tim;

	/* TIMデータのヘッダからテクスチャのデータタイプの情報を得る */  
	GsGetTimInfo((u_long *)(addr+4),&tim);

	/* テクスチャ左上のVRAMでのXY座標 */
	rect.x = tim.px;
	rect.y = tim.py;

	/* テクスチャの幅と高さ */
	rect.w = tim.pw;
	rect.h = tim.ph;

	/* VRAMにテクスチャをロードする */
	LoadImage(&rect,tim.pixel);

	/* カラールックアップテーブルが存在する */
	if((tim.pmode>>3)&0x01)
	{
		/* クラット左上のVRAMでのXY座標 */
		rect.x = tim.cx;
		rect.y = tim.cy;

		/* クラットの幅と高さ */
		rect.w = tim.cw;
		rect.h = tim.ch;

		/* VRAMにクラットをロードする */
		LoadImage(&rect,tim.clut);
	}
}

static int pad_read(GsCOORDINATE2 *objWorld,SVECTOR *rotate,int *frame)
{
	u_long		padd;
	static int	rot_speed[2]={4*ONE/360,2*ONE/360};
	static int	tra_speed[2]={20,10};
	static u_long	padd_old;

	padd = PadRead(0);

	/* 終了 */
	if ( padd & PADselect )
		return(-1);

	/* 描画速度の切替え */
	if ( padd & PADstart ) {
		if ( padd != padd_old )
			*frame ^= 1;
	}

	/* Y軸回転 */
	if ( padd & PADRleft  ) rotate->vy -= rot_speed[*frame];
	if ( padd & PADRright ) rotate->vy += rot_speed[*frame];

	/* X軸回転 */
	if ( padd & PADRup    ) rotate->vx += rot_speed[*frame];
	if ( padd & PADRdown  ) rotate->vx -= rot_speed[*frame];

	/* Z軸にそって移動 */
	if ( padd & PADL1 ) {
		if ( objWorld->coord.t[2] < 500 )
			objWorld->coord.t[2] += tra_speed[*frame];
	}
	if ( padd & PADL2 ) objWorld->coord.t[2] -= tra_speed[*frame];

	/* Y軸にそって移動 */
	if ( padd & PADLdown ) objWorld->coord.t[1] += tra_speed[*frame];
	if ( padd & PADLup   ) objWorld->coord.t[1] -= tra_speed[*frame];

	/* X軸にそって移動 */
	if ( padd & PADLleft  ) objWorld->coord.t[0] += tra_speed[*frame];
	if ( padd & PADLright ) objWorld->coord.t[0] -= tra_speed[*frame];

	rotate->vy += rot_speed[*frame]/2;

	padd_old = padd;

	return(0);
}

static void opening(GsCOORDINATE2 *objWorld,SVECTOR *rotate,DB *db,
			GsDOBJ2 *object,int objcnt)
{
	int	idx;
	int	i;

	objWorld->coord.t[0] = -930;
	objWorld->coord.t[1] = 60;
	objWorld->coord.t[2] = -6050;
	rotate->vy = +110;

	for ( i=0; i<470; i++ ) {

		objWorld->coord.t[0] += 2;
		objWorld->coord.t[2] += (1+i*.05);

		move_object(objWorld,rotate);
		idx = GsGetActiveBuff();
		draw_object(&db[idx],object,objcnt,FRAME_60);

	}
}


static void move_object(GsCOORDINATE2 *objWorld,SVECTOR *rotate)
{
	MATRIX		tmpmat;
	SVECTOR		tmpvec;

	/* 単位行列から出発する */
	tmpmat = GsIDMATRIX;

	/* 平行移動をセットする */
	tmpmat.t[0] = objWorld->coord.t[0];
	tmpmat.t[1] = objWorld->coord.t[1];
	tmpmat.t[2] = objWorld->coord.t[2];

	/* 回転ベクトルをセットする */
	tmpvec = *rotate;

	/* マトリックスに回転ベクトルを作用させる */
	RotMatrix(&tmpvec,&tmpmat);

	/* 求めたマトリックスを座標系にセットする */
	objWorld->coord = tmpmat;

	/* 再計算のためのフラグをクリアする */
	objWorld->flg = 0;
}

static void draw_object(DB *db,GsDOBJ2 *object,int objcnt,int frame)
{
	GsDOBJ2		*op;
	MATRIX		tmpmat;

	/* Set top address of Packet Area for output of GPU PACKETS */
	GsSetWorkBase(db->packet);

	/* オーダリングテーブルをクリアする */
	GsClearOt(0,0,&db->gsot);

	op = object;
	while ( objcnt-- ) {

		/* オブジェクトを透視変換し OT に登録する */
		GsGetLw(op->coord2,&tmpmat);
		GsSetLightMatrix(&tmpmat);
		GsGetLs(op->coord2,&tmpmat);
		GsSetLsMatrix(&tmpmat);
		GsSortObject4(op,&db->gsot,14-OT_LENGTH,getScratchAddr(0));

		op++;
	}

	DrawSync(0);
	switch (frame) {
	case FRAME_30:		/* 30 frame */
		VSync(2);
		break;
	case FRAME_60:		/* 60 frame */
		VSync(0);
		break;
	}

	FntPrint("speed = %d frame/sec\n",30*(frame+1));

	FntFlush(-1);

	/* ダブルバッファを切替える */
	GsSwapDispBuff();

	/* 画面のクリアをオーダリングテーブルの最初に登録する */
	GsSortClear(0x0,0x0,0x0,&db->gsot);

	/* OT に登録されているパケットの描画を開始する */
	GsDrawOt(&db->gsot);
}
