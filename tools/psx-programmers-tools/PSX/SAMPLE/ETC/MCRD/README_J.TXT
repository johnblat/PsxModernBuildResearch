$PSDocId: Document Release 1.0 for Run-time Library Release 4.4$

libmcrd チュートリアル

                      Copyright(C) 1997 Sony Computer Entertainment Inc.
                                                    All Rights Reserved.


TUTO0:
======

＜サンプルの解説＞
	スロット１（向かって左）のカードに
	以下の形式のカードデータを生成します。

	ファイル名「HAND」
	使用ブロック数：１
	アニメーション：３枚（グー・チョキ・パー）

＜起動方法＞
	>psymake	コンパイル
	>run main	実行


TUTO1:
======

＜サンプルの解説＞
	スロット１のカードのファイル情報を表示します。
	常にカードの存在確認を行い、カードの抜き差しに対応しています。

＜起動方法＞
	>psymake	コンパイル
	>run main	実行

＜備考＞
	スロット１にカードを入れると、直ちに認識しファイル一覧を表示します。


TUTO2:
======

＜サンプルの解説＞
	スロット１からスロット２へカードデータを選択コピーします。
	以下の特徴があります。

	・両スロットの抜き挿しに対応しています。
	・コピー先が未フォーマットカードだった場合、ユーザへ問い合わせの後、
	  フォーマットを実行します。
	・コピー先の空き容量をチェックします。
	・コピー先に既に同名ファイルがあった場合、ユーザへ問い合わせの後、
	  上書きコピーします。

＜起動方法＞
	>psymake	コンパイル
	>run main	実行

＜コントローラの操作方法＞
	↑,↓	：コピーするファイルを選択
	○,×	：コピー実行
	←,→	：YES, NO の選択

＜備考＞
	通常のカードの他に、未フォーマットのカードや満杯のカードを挿して、
	動作を確認してください。

