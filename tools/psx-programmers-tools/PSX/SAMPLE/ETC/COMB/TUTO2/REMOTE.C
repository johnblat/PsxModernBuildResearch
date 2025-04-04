/* $PSLibId: Run-time Library Release 4.4$ */
/*
 * Remote controller driver
 */
#include <stdio.h>
#include <stdlib.h>
#include <libapi.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <strings.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libcomb.h>

#define	BUFSIZE		(64)
/**************************************************************************/
static long fr,fw;			/* file descriptor */
static unsigned long ev_r, ev_e;	/* read/error event descriptor */
static unsigned char recbuf[BUFSIZE];	/* receive buffer */
static unsigned char senbuf[BUFSIZE];	/* send buffer */
static volatile long errcnt1, errcnt2;	/* error counter */
static long re_flg = 0;			/* rec error recovery */
/**************************************************************************/

long _error_remote(void)
{
	errcnt1++;
	re_flg = 0;
	return(0);
}

int _init_remote(void)
{
	/* 受信完了通知イベント */
	ev_r = OpenEvent(HwSIO,EvSpIOER,EvMdNOINTR,NULL);

	/* エラー通知イベント */
	ev_e = OpenEvent(HwSIO,EvSpERROR,EvMdINTR,_error_remote);

	/* 対戦ケーブルドライバ初期化 */
	AddCOMB();

	/* 送信ファイルディスクリプタ定義 */
	fw = open("sio:",O_WRONLY);

	/* 受信ファイルディスクリプタ定義 */
	fr = open("sio:",O_RDONLY|O_NOWAIT);

	return(0);
}

void _start_remote(long baud)
{

	CombSetBPS( baud );		/* 通信速度設定 */
	CombSetPacketSize( 4 );		/* 受信単位文字数 */

	CombSetControl( COMB_BIT_RTS );	/* RTS on, DTR off */
	while( CombCTS()==0 );		/* Wait for CTS enable */
	VSync(0);			/* Wait for V-BLANK */
	CombSetControl(0);		/* RTS off, DTR off */
	VSync(0);

	/* enable an event to detect the error */
	EnableEvent(ev_e);

	/* enable an event to detect the end of read operation */
	EnableEvent(ev_r);
}

int _send_remote(void)
{
	int	i;
	unsigned char sum;

	if (CombCTS()==0) return(0);

	for( i=1, sum=0; i<BUFSIZE; i++ ) {
		sum += (unsigned char)i;
		senbuf[i] = i;
	}
	senbuf[0] = sum;

	write( fw, senbuf, BUFSIZE );
	return(1);
}

int _rec_remote(void)
{
	int	i;
	unsigned char sum;

	if ( TestEvent(ev_r)==1 ) {
		for( i=1, sum=0; i<BUFSIZE; i++ ) {
			sum += recbuf[i];
		}
		if ( recbuf[0] != sum ) {
			errcnt2++;
			re_flg = 0;
			return(0);
		}
		read( fr, recbuf, BUFSIZE );
		return(1);
	}
	if ( re_flg==0 ) {
		CombReset();			/* reset driver */
		read( fr, recbuf, BUFSIZE );
		re_flg = 1;
	}
	return(0);
}

int _get_error_count1(void)
{
	return( errcnt1 );
}

int _get_error_count2(void)
{
	return( errcnt2 );
}

