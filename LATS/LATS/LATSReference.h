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
#define MFS_WIDTH			900
#define MFS_HEIGHT			600

//StrategySize
#define SGS_FRAME_WIDTH			300
#define SGS_MAIN_WIDTH			290
#define SGS_SCROLL_WIDTH		10
#define SGS_INFO_HEIGHT			130
#define SGS_SAVER_HEIGHT		130

//UserInfoSize
#define UIS_HEIGHT				210

///Color Reference

//background
#define BKC_CAPTION			RGB(50, 50, 50)
#define BKC_STRATEGY_INFO	RGB(64, 57, 64)
#define BKC_STRATEGY_MAIN	RGB(74, 68, 67)
#define BKC_STRATEGY_SAVER	RGB(64, 57, 64)
#define BKC_USERIFO			RGB(74, 67, 70)

//font
#define FTC_CAPTION			RGB(62, 210, 173)

//Dialog Border Line
#define BLC_BORDER			RGB(100, 100, 100)

/*
	Const
*/

///Border
const int LATS_BORDER_SIZE_Y = GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CXPADDEDBORDER) ;