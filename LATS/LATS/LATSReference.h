#pragma once

namespace LATS
{
	//Size
	const int SIZE_HEIGHT_BORDER = GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CXPADDEDBORDER);

	//Color
	const COLORREF COLOR_BORDER = RGB(100, 100, 100);
}

namespace CAPTION
{
	//Size
	const int SIZE_HEIGHT = 30;
	const int SIZE_WIDTH_BTN = 35;
	const int SIZE_WIDTH_ICON = 120;
	const int SIZE_HEIGHT_STC = 20;
	
	//Pos
	const int POS_STC_Y = 7;

	//Color
	const COLORREF COLOR_BKGROUND = RGB(50, 50, 50);
	const COLORREF COLOR_FONT = RGB(62, 210, 173);
}

namespace MAIN_FRAME
{
	const int SIZE_WIDTH = 1000;
	const int SIZE_HEIGHT = 600;
}

namespace STRATEGY
{
	//Size
	const int SIZE_WIDTH_FRAME = 302;
	const int SIZE_WIDTH_MAIN = 292;
	const int SIZE_WIDTH_SCROLL = 10;
	const int SIZE_HEIGHT_INFO = 130;
	const int SIZE_HEIGHT_SAVE = 130;

	//Color
	const COLORREF COLOR_BKGROUND_INFO = RGB(64, 57, 64);
	const COLORREF COLOR_BKGROUND_MAIN = RGB(74, 68, 67);
	const COLORREF COLOR_BKGROUND_SAVE = RGB(64, 57, 64);
	const COLORREF COLOR_FONT_INFO = RGB(88, 204, 255);

}

namespace USER_INFO
{
	//Size
	const int SIZE_HEIGHT = 210;

	//Color
	const COLORREF COLOR_BKGROUND = RGB(74, 67, 70);
}

namespace STRATEGY_MENU
{
	enum ENUM
	{
		BUY, CELL, MONEY
	};
}
