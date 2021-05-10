#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_LINE,       //Line item in menu
	ITM_TRIA,       //Triangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_DRAWCOL,	//Change Draw color in menu
	ITM_FILL,		//Change fill color in menu
	ITM_BKCOL,		//Change background color in menu
	ITM_MOVE,		//Move item in the drawing area in menu
	ITM_RESIZE,		//Resize a drawing area item in menu
	ITM_ROTATE,		//Rotate an item by 90/180/270 degrees in menu
	ITM_STOB,		//Send item to back
	ITM_STOF,		//Send item to front
	ITM_DEL,		//Delete an item
	ITM_COPY,       //Copy item in menu
	ITM_PASTE,      //Paste item in menu
	ITM_CUT,        //Cut item in menu
	ITM_SAVE,       //Save item in menu
	ITM_PLAY,       //Go to Play toolbar in menu
	ITM_EXIT,		//Exit item
	

	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_PBYS,           //pick by shape play mode
	ITM_PBYC,			//pick by color
	ITM_PBYB,			//pick by both
	ITM_DRAW,           //Go to Draw toolbar in menu
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif