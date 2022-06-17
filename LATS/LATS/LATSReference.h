#pragma once

/*
	Define
*/

///size

//CapTionSize
#define CTS_HEIGHT			30
#define CTS_BTNWIDTH		35
#define CTS_ICONWIDTH		120
#define CTS_STATICYPOS		7
#define CTS_STATICHEIGHT	20

//MainFrameSize
#define MFS_WIDTH			800
#define MFS_HEIGHT			600

//Strategyize
#define SGS_FRAME_WIDTH			300
#define SGS_MAIN_WIDTH			290
#define SGS_SCROLL_WIDTH		10
#define SGS_INFO_HEIGHT			100
#define SGS_SAVER_HEIGHT		100


///Color Reference

//background
#define BKC_CAPTION			RGB(50, 50, 50)
#define BKC_STRATEGY_INFO	RGB(40, 40, 40)
#define BKC_STRATEGY_MAIN	RGB(90, 90, 90)
#define BKC_STRATEGY_SCROLL	RGB(90, 90, 90)
#define BKC_STRATEGY_SAVER	RGB(30, 30, 30)

//font
#define FTC_CAPTION			RGB(62, 210, 173)

//Dialog Border Line
#define BLC_BORDER			RGB(100, 100, 100)

/*
	Const
*/

///Border
const int LATS_BORDER_SIZE_Y = GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CXPADDEDBORDER) ;