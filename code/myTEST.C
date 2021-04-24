/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.32 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only  be used  in accordance  with  a license  and should  not be  re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : DIALOG_MenuStructure.c
Purpose     : Shows how to achieve a menu structure with dialogs
Requirements: WindowManager - (X)
              MemoryDevices - ( )
              AntiAliasing  - ( )
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )
---------------------------END-OF-HEADER------------------------------
*/
#define  MYTEST_TYPE_CLYLE

#include <stddef.h>
#include <string.h>
#include "Dialog.h"
//#include "myTEST.h"
#include "LISTWHEEL.h"
#include "pngphoto.h"
#include "bmpconst.h"
#include "mytestcost.h"
#include "Public.h"

//#define RECOMMENDED_MEMORY (1024L * 700)

extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_31;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_61;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh20;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_pm2_5;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_set;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_dingshi;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_gaojiset;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfong_yh_time;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfong_yh_save;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_inpassword;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_record;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_wifi;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_wifibutton12;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_padsym;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontfont_yh_wifisure;

static void _cbDialogTimeOffSetPage1(WM_MESSAGE * pMsg);
static void _cbDialogSetPage1(WM_MESSAGE * pMsg);
static void _cbDialogCkTimeSet(WM_MESSAGE * pMsg);
//static void _cbDialogSetPasswordPage(WM_MESSAGE * pMsg);
static void _cbDialogSetTimePage(WM_MESSAGE * pMsg);
static void _cbDialogBackRoundSetPage(WM_MESSAGE * pMsg);

static void _cbDialogSensorSetPage(WM_MESSAGE * pMsg);
static void _cbDialogNumPadPage(WM_MESSAGE * pMsg);
static void _cbDialogPasswordPage(WM_MESSAGE * pMsg);
static void _cbDialogSetTimeOnPage(WM_MESSAGE * pMsg);
static void _cbDialogSetTimeOffPage(WM_MESSAGE * pMsg);
static void _cbDialogRecordPage(WM_MESSAGE * pMsg);
static void _cbDialogPM2_5Page(WM_MESSAGE * pMsg);

static void _cbDialogWifiPasswordMinPage(WM_MESSAGE * pMsg);
static void _cbDialogWifiPasswordSymPage(WM_MESSAGE * pMsg);
static void _cbDialogWifiPasswordNumPage(WM_MESSAGE * pMsg);
static void _cbDialogWifiPasswordPage(WM_MESSAGE * pMsg);

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
// 页面1
// 资源表
static const GUI_WIDGET_CREATE_INFO _aDialogCreatePage1[] = {
  { WINDOW_CreateIndirect, "",      ID_WINDOW_MY,    0,  0,  480, 800,0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_1,     0,  340,  118,  118, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_2,     0,  460,  118,  118, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_3,     0,  580,  118,  118, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_4,     0,  700,  118,  100, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_5,     120,  700,  360,  100, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_6,     120,  340,  360,  358, 0, 0x0,0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_1,       0,    175, 120,  22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_2,       120, 175, 120,  22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_3,       240, 175, 120,  22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_5,       0,    294, 120,  22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_6,       120, 294, 120,  22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_7,       240, 294, 120,  22, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_8,       360, 294, 120,  22, 0, 0x64, 0 },
};

// 定时开关机设置界面 
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateTimeOffSetPage1[] = {
  { WINDOW_CreateIndirect, "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  //{ WINDOW_CreateIndirect, "",      ID_WINDOW_HEAD,  0,     0,    480,  90,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_3,     318,   213,  100,  50, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_4,     318,   263,  100,  50, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_5,     318,   353,  100,  50, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_6,     318,   403,  100,  50, 0, 0x0,0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_1,       60,  128, 140,  42, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_2,       72,  213, 85,  25, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_3,       72,  352, 85,  25, 0, 0x64, 0 },
};

// 定时开关机时间设置界面 
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateTmSetOnOff[] = {
  { WINDOW_CreateIndirect, "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_3,     105,   545,  97,   38,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_4,     279,   545,  97,   38,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_1,       57,    127,  140,  45,  0, 0x64, 0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_2,       215,   330,  30,  25,  0, 0x64, 0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_3,       305,   330,  30,  25,  0, 0x64, 0 },
  { LISTWHEEL_CreateIndirect, "",   ID_LISTWHEEL_0,  150,   210,  50,   270, 1, 0, 2 },
  { LISTWHEEL_CreateIndirect, "",   ID_LISTWHEEL_1,  245,   210,  50,   270, 1, 0, 2 },
};


// 高级设置界面
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateSetPage1[] = {
  { WINDOW_CreateIndirect, "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_3,     104,   328,  270,  57, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_4,     104,   406,  270,  57, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_5,     104,   484,  270,  57, 0, 0x0,  0 },
  //{ BUTTON_CreateIndirect, "",      ID_BUTTON_6,     390,   0,    480,  90, 0, 0x0,0 },
  { TEXT_CreateIndirect, "",   ID_TEXT_1,       150,  230, 180,  45, 0, 0x64, 0 },
};

// 参数密码界面
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreatePasswordPage[] = {
  { WINDOW_CreateIndirect, "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_1,       57,    127,  140,  45,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_2,       160,   315,  160,  30,  0, 0x0,  0 },
  { EDIT_CreateIndirect, "",        ID_EDIT_0,       115,   376,  253,  39,  0, 0x0,  0 },
};

// 数字键盘界面
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateNumPadPage[] = {
  { WINDOW_CreateIndirect, "",       ID_WINDOW_MY,    0,     440,  480,  360, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "down",   ID_BUTTON_7,     400,   1,    80,   58,  0, 0x0,  0 },  // 向下按钮
  { BUTTON_CreateIndirect, "1",      ID_BUTTON_8,     1,     61,   118,  73,  0, 0x0,  0 },  // 1
  { BUTTON_CreateIndirect, "2",      ID_BUTTON_9,     121,   61,   118,  73,  0, 0x0,  0 },  // 2
  { BUTTON_CreateIndirect, "3",      ID_BUTTON_10,    241,   61,   118,  73,  0, 0x0,  0 },  // 3
  { BUTTON_CreateIndirect, "4",      ID_BUTTON_11,    1,     136,  118,  73,  0, 0x0,  0 },  // 4
  { BUTTON_CreateIndirect, "5",      ID_BUTTON_12,    121,   136,  118,  73,  0, 0x0,  0 },  // 5
  { BUTTON_CreateIndirect, "6",      ID_BUTTON_13,    241,   136,  118,  73,  0, 0x0,  0 },  // 6
  { BUTTON_CreateIndirect, "7",      ID_BUTTON_14,    1,     211,  118,  73,  0, 0x0,  0 },  // 7
  { BUTTON_CreateIndirect, "8",      ID_BUTTON_15,    121,   211,  118,  73,  0, 0x0,  0 },  // 8
  { BUTTON_CreateIndirect, "9",      ID_BUTTON_16,    241,   211,  118,  73,  0, 0x0,  0 },  // 9
  { BUTTON_CreateIndirect, "0",      ID_BUTTON_17,    121,   286,  118,  73,  0, 0x0,  0 },  // 0
  { BUTTON_CreateIndirect, ".",      ID_BUTTON_18,    241,   286,  118,  73,  0, 0x0,  0 },  // .
  { BUTTON_CreateIndirect, "delete", ID_BUTTON_19,    361,   61,   118,  148, 0, 0x0,  0 },  // 删除按钮
  { BUTTON_CreateIndirect, "enter",  ID_BUTTON_20,    361,   211,  118,  148, 0, 0x0,  0 },  // 回车按钮
};

// 参数设置界面
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateSensorSetPage[] = {
  { WINDOW_CreateIndirect, "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_3,     105,   602,  97,   38,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_4,     279,   602,  97,   38,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_1,       57,    127,  140,  45,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_2,       113,   211,  90,  35,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_3,       113,   261,  90,  35,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_4,       113,   311,  90,  35,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_5,       113,   361,  90,  35,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_6,       113,   411,  90,  35,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_7,       113,   461,  90,  35,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_8,       113,   511,  90,  35,  0, 0x0,  0 },
  { EDIT_CreateIndirect, "",        ID_EDIT_0,       235,   210,  130,  40,  0, 0x0,  0 },
  { EDIT_CreateIndirect, "",        ID_EDIT_1,       235,   260,  130,  40,  0, 0x0,  0 },
  { EDIT_CreateIndirect, "",        ID_EDIT_2,       235,   310,  130,  40,  0, 0x0,  0 },
  { EDIT_CreateIndirect, "",        ID_EDIT_3,       235,   360,  130,  40,  0, 0x0,  0 },
  { EDIT_CreateIndirect, "",        ID_EDIT_4,       235,   410,  130,  40,  0, 0x0,  0 },
  { EDIT_CreateIndirect, "",        ID_EDIT_5,       235,   460,  130,  40,  0, 0x0,  0 },
  { EDIT_CreateIndirect, "",        ID_EDIT_6,       235,   510,  130,  40,  0, 0x0,  0 },
}; 

// 时间设置界面 
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateSetTimePage[] = {
  { WINDOW_CreateIndirect, "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_3,     105,   545,  97,   38,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_4,     279,   545,  97,   38,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_1,       57,    127,  140,  45,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_2,       104,   330,  160,  32,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_3,       182,   330,  160,  32,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_4,       261,   330,  160,  32,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_5,       341,   330,  160,  32,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_6,       413,   330,  160,  32,  0, 0x0,  0 },
  { LISTWHEEL_CreateIndirect, "",   ID_LISTWHEEL_0,  50,    210,  50,   270, 1, 0,    2 },
  { LISTWHEEL_CreateIndirect, "",   ID_LISTWHEEL_1,  130,   210,  40,   270, 1, 0,    2 },
  { LISTWHEEL_CreateIndirect, "",   ID_LISTWHEEL_2,  210,   210,  40,   270, 1, 0,    2 },
  { LISTWHEEL_CreateIndirect, "",   ID_LISTWHEEL_3,  290,   210,  40,   270, 1, 0,    2 },
  { LISTWHEEL_CreateIndirect, "",   ID_LISTWHEEL_4,  370,   210,  40,   270, 1, 0,    2 },
};

// 背景设置界面
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateBackRoundSetPage[] = {
  { WINDOW_CreateIndirect,  "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { CHECKBOX_CreateIndirect,"",      ID_CHCKBOX_1,    86,    206,  64,   64,  0, 0X0,  0 },
  { CHECKBOX_CreateIndirect,"",      ID_CHCKBOX_2,    209,   206,  64,   64,  0, 0X0,  0 },
  { CHECKBOX_CreateIndirect,"",      ID_CHCKBOX_3,    332,   206,  64,   64,  0, 0X0,  0 },
  { SLIDER_CreateIndirect, "",       ID_SLIDER_1,     75,    372,  330,  40 , 0, 0X0,  2 },
  { SLIDER_CreateIndirect, "",       ID_SLIDER_2,     75,    502,  330,  40 , 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_3,     105,   614,  97,   38,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_4,     279,   614,  97,   38,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",         ID_TEXT_1,       57,    127,  70,  45,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",         ID_TEXT_2,       57,    305,  70,  45,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",         ID_TEXT_3,       57,    434,  140,  45,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",         ID_TEXT_4,       79,    544,  320,  32,  0, 0x0,  0 },
};

// 检测时间设置界面
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateCkTmSet[] = {
  { WINDOW_CreateIndirect, "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_3,     105,   545,  97,   38,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",      ID_BUTTON_4,     279,   545,  97,   38,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_1,       57,    127,  140,  45,  0, 0x64, 0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_2,       94,    328,  30,  25,  0, 0x64, 0 },
  { TEXT_CreateIndirect, "",        ID_TEXT_3,       232,   328,  150,  32,  0, 0x64, 0 },
  { LISTWHEEL_CreateIndirect, "",   ID_LISTWHEEL_0,  135,   210,  80,   270, 1, 0, 2 },
};

// 历史数据列表设置界面
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateRecordPage[] = {
  { WINDOW_CreateIndirect,  "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { LISTVIEW_CreateIndirect, "",     ID_LISTVIEW_1,   15,    155,  450,  530, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",         ID_TEXT_1,       170,    105,  140,  45,  0, 0x0,  0 },
};

// PM2.5界面  
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreatePm2_5Page[] = {
  { WINDOW_CreateIndirect,  "",      ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },
  { BUTTON_CreateIndirect, "",       ID_BUTTON_3,     160,   710,  160,  80,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",         ID_TEXT_1,       116,   301,  250,  40,  0, 0x0,  0 },
  { TEXT_CreateIndirect, "",         ID_TEXT_2,       162,   613,  158,  40,  0, 0x0,  0 },
};

// wifi 密码输入界面（大写）
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateWifiPasswordPage[] = {
  { WINDOW_CreateIndirect,  "",        ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
//  { TEXT_CreateIndirect,        "",         ID_TEXT_1,       115,    155,  200,  45,  0, 0x0,  0 },    // wifi 名称
  { EDIT_CreateIndirect,         "",        ID_EDIT_1,       115,    155,  250,  40,  0, 0x0,  0 },    //  wifi 名称
  { EDIT_CreateIndirect,         "",        ID_EDIT_0,       115,    205,  250,  40,  0, 0x0,  0 },    // 密码输入框
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },    // 取消
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },   // 连接

  { BUTTON_CreateIndirect,   "abc",        ID_BUTTON_3,     215,     350,  88,  50,  0, 0x0,  0 },    // abc
  { BUTTON_CreateIndirect,   "123",        ID_BUTTON_4,     303,   350,  88,  50,  0, 0x0,  0 },  // 123
  { BUTTON_CreateIndirect,   "符号",        ID_BUTTON_5,     391,   350,  88,  50,  0, 0x0,  0 },  // 符号

  { BUTTON_CreateIndirect,   "Q",        ID_BUTTON_6,       4,   420,  40,  56,  0, 0x0,  0 },  // Q
  { BUTTON_CreateIndirect,   "W",        ID_BUTTON_7,       52,   420,  40,  56,  0, 0x0,  0 },  // W
  { BUTTON_CreateIndirect,   "E",        ID_BUTTON_8,       100,   420,  40,  56,  0, 0x0,  0 },  // E
  { BUTTON_CreateIndirect,   "R",        ID_BUTTON_9,       148,   420,  40,  56,  0, 0x0,  0 },  // R
  { BUTTON_CreateIndirect,   "T",        ID_BUTTON_10,     196,   420,  40,  56,  0, 0x0,  0 },  // T
  { BUTTON_CreateIndirect,   "Y",        ID_BUTTON_11,     244,   420,  40,  56,  0, 0x0,  0 },  // Y
  { BUTTON_CreateIndirect,   "U",        ID_BUTTON_12,     292,   420,  40,  56,  0, 0x0,  0 },  // U
  { BUTTON_CreateIndirect,   "I",        ID_BUTTON_13,     340,   420,  40,  56,  0, 0x0,  0 },  // I
  { BUTTON_CreateIndirect,   "O",        ID_BUTTON_14,     388,   420,  40,  56,  0, 0x0,  0 },  // O
  { BUTTON_CreateIndirect,   "P",        ID_BUTTON_15,     436,   420,  40,  56,  0, 0x0,  0 },  // P

  { BUTTON_CreateIndirect,   "A",        ID_BUTTON_16,     28,   490,  40,  56,  0, 0x0,  0 },  // A
  { BUTTON_CreateIndirect,   "S",        ID_BUTTON_17,     76,   490,  40,  56,  0, 0x0,  0 },  // S
  { BUTTON_CreateIndirect,   "D",        ID_BUTTON_18,     124,   490,  40,  56,  0, 0x0,  0 },  // D
  { BUTTON_CreateIndirect,   "F",        ID_BUTTON_19,     172,   490,  40,  56,  0, 0x0,  0 },  // F
  { BUTTON_CreateIndirect,   "G",        ID_BUTTON_20,     220,   490,  40,  56,  0, 0x0,  0 },  // G
  { BUTTON_CreateIndirect,   "H",        ID_BUTTON_21,     268,   490,  40,  56,  0, 0x0,  0 },  // H
  { BUTTON_CreateIndirect,   "J",        ID_BUTTON_22,     316,   490,  40,  56,  0, 0x0,  0 },  // J
  { BUTTON_CreateIndirect,   "K",        ID_BUTTON_23,     364,   490,  40,  56,  0, 0x0,  0 },  // K
  { BUTTON_CreateIndirect,   "L",        ID_BUTTON_24,     412,   490,  40,  56,  0, 0x0,  0 },  // L

  { BUTTON_CreateIndirect,   "",         ID_BUTTON_25,     4,    560,  54,  56,  0, 0x0,  0 },  // 大小写转换
  { BUTTON_CreateIndirect,   "Z",        ID_BUTTON_26,     76,   560,  40,  56,  0, 0x0,  0 },  // Z
  { BUTTON_CreateIndirect,   "X",        ID_BUTTON_27,     124,   560,  40,  56,  0, 0x0,  0 },  // X
  { BUTTON_CreateIndirect,   "C",        ID_BUTTON_28,     172,   560,  40,  56,  0, 0x0,  0 },  // C
  { BUTTON_CreateIndirect,   "V",        ID_BUTTON_29,     220,   560,  40,  56,  0, 0x0,  0 },  // V
  { BUTTON_CreateIndirect,   "B",        ID_BUTTON_30,     268,   560,  40,  56,  0, 0x0,  0 },  // B
  { BUTTON_CreateIndirect,   "N",        ID_BUTTON_31,     316,   560,  40,  56,  0, 0x0,  0 },  // N
  { BUTTON_CreateIndirect,   "M",        ID_BUTTON_32,     364,   560,  40,  56,  0, 0x0,  0 },  // M
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_33,     423,   560,  54,  56,  0, 0x0,  0 },  // 删除

  { BUTTON_CreateIndirect,   "空格",        ID_BUTTON_34,     4,   630,  365,  56,  0, 0x0,  0 },  // 空格
  { BUTTON_CreateIndirect,   "确认",        ID_BUTTON_35,     375,   630,  100,  56,  0, 0x0,  0 },  // 确认
};

// wifi 密码输入界面（小写）
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateWifiPasswordMinPage[] = {
  { WINDOW_CreateIndirect,  "",        ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
//  { TEXT_CreateIndirect,        "",         ID_TEXT_1,       115,    155,  200,  45,  0, 0x0,  0 },    // wifi 名称
  { EDIT_CreateIndirect,         "",        ID_EDIT_1,       115,    155,  250,  40,  0, 0x0,  0 },    //  wifi 名称
  { EDIT_CreateIndirect,         "",        ID_EDIT_0,       115,    205,  250,  40,  0, 0x0,  0 },    // 密码输入框
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },    // 取消
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },   // 连接

  { BUTTON_CreateIndirect,   "abc",        ID_BUTTON_3,     215,     350,  88,  50,  0, 0x0,  0 },    // abc
  { BUTTON_CreateIndirect,   "123",        ID_BUTTON_4,     303,   350,  88,  50,  0, 0x0,  0 },  // 123
  { BUTTON_CreateIndirect,   "符号",        ID_BUTTON_5,     391,   350,  88,  50,  0, 0x0,  0 },  // 符号

  { BUTTON_CreateIndirect,   "q",        ID_BUTTON_6,       4,   420,  40,  56,  0, 0x0,  0 },  // Q
  { BUTTON_CreateIndirect,   "w",        ID_BUTTON_7,       52,   420,  40,  56,  0, 0x0,  0 },  // W
  { BUTTON_CreateIndirect,   "e",        ID_BUTTON_8,       100,   420,  40,  56,  0, 0x0,  0 },  // E
  { BUTTON_CreateIndirect,   "r",        ID_BUTTON_9,       148,   420,  40,  56,  0, 0x0,  0 },  // R
  { BUTTON_CreateIndirect,   "t",        ID_BUTTON_10,     196,   420,  40,  56,  0, 0x0,  0 },  // T
  { BUTTON_CreateIndirect,   "y",        ID_BUTTON_11,     244,   420,  40,  56,  0, 0x0,  0 },  // Y
  { BUTTON_CreateIndirect,   "u",        ID_BUTTON_12,     292,   420,  40,  56,  0, 0x0,  0 },  // U
  { BUTTON_CreateIndirect,   "i",        ID_BUTTON_13,     340,   420,  40,  56,  0, 0x0,  0 },  // I
  { BUTTON_CreateIndirect,   "o",        ID_BUTTON_14,     388,   420,  40,  56,  0, 0x0,  0 },  // O
  { BUTTON_CreateIndirect,   "p",        ID_BUTTON_15,     436,   420,  40,  56,  0, 0x0,  0 },  // P

  { BUTTON_CreateIndirect,   "a",        ID_BUTTON_16,     28,   490,  40,  56,  0, 0x0,  0 },  // A
  { BUTTON_CreateIndirect,   "s",        ID_BUTTON_17,     76,   490,  40,  56,  0, 0x0,  0 },  // S
  { BUTTON_CreateIndirect,   "d",        ID_BUTTON_18,     124,   490,  40,  56,  0, 0x0,  0 },  // D
  { BUTTON_CreateIndirect,   "f",        ID_BUTTON_19,     172,   490,  40,  56,  0, 0x0,  0 },  // F
  { BUTTON_CreateIndirect,   "g",        ID_BUTTON_20,     220,   490,  40,  56,  0, 0x0,  0 },  // G
  { BUTTON_CreateIndirect,   "h",        ID_BUTTON_21,     268,   490,  40,  56,  0, 0x0,  0 },  // H
  { BUTTON_CreateIndirect,   "j",        ID_BUTTON_22,     316,   490,  40,  56,  0, 0x0,  0 },  // J
  { BUTTON_CreateIndirect,   "k",        ID_BUTTON_23,     364,   490,  40,  56,  0, 0x0,  0 },  // K
  { BUTTON_CreateIndirect,   "l",        ID_BUTTON_24,     412,   490,  40,  56,  0, 0x0,  0 },  // L

  { BUTTON_CreateIndirect,   "",        ID_BUTTON_25,     4,    560,  54,  56,  0, 0x0,  0 },  // 大小写转换
  { BUTTON_CreateIndirect,   "z",        ID_BUTTON_26,     76,   560,  40,  56,  0, 0x0,  0 },  // Z
  { BUTTON_CreateIndirect,   "x",        ID_BUTTON_27,     124,   560,  40,  56,  0, 0x0,  0 },  // X
  { BUTTON_CreateIndirect,   "c",        ID_BUTTON_28,     172,   560,  40,  56,  0, 0x0,  0 },  // C
  { BUTTON_CreateIndirect,   "v",        ID_BUTTON_29,     220,   560,  40,  56,  0, 0x0,  0 },  // V
  { BUTTON_CreateIndirect,   "b",        ID_BUTTON_30,     268,   560,  40,  56,  0, 0x0,  0 },  // B
  { BUTTON_CreateIndirect,   "n",        ID_BUTTON_31,     316,   560,  40,  56,  0, 0x0,  0 },  // N
  { BUTTON_CreateIndirect,   "m",        ID_BUTTON_32,     364,   560,  40,  56,  0, 0x0,  0 },  // M
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_33,     423,   560,  54,  56,  0, 0x0,  0 },  // 删除

  { BUTTON_CreateIndirect,   "空格",        ID_BUTTON_34,     4,   630,  365,  56,  0, 0x0,  0 },  // 空格
  { BUTTON_CreateIndirect,   "确认",        ID_BUTTON_35,     375,   630,  100,  56,  0, 0x0,  0 },  // 确认
};



// wifi 密码输入数字键盘
// 资源列表  
static const GUI_WIDGET_CREATE_INFO _aDialogCreateWifiPasswordNumPage[] = {
  { WINDOW_CreateIndirect,   "",        ID_WINDOW_MY,    0,     0,    480,  800, 0, 0x0,  0 },
//  { TEXT_CreateIndirect,     "",        ID_TEXT_1,       115,    155,  200,  45,  0, 0x0,  0 },    // wifi 名称
  { EDIT_CreateIndirect,         "",        ID_EDIT_1,       115,    155,  250,  40,  0, 0x0,  0 },    //  wifi 名称
  { EDIT_CreateIndirect,     "",        ID_EDIT_0,       115,    205,  250,  40,  0, 0x0,  0 },    // 密码输入框
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_1,     0,     710,  160,  80,  0, 0x0,  0 },    // 取消
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_2,     320,   710,  160,  80,  0, 0x0,  0 },   // 连接

  { BUTTON_CreateIndirect,   "abc",        ID_BUTTON_3,     215,     350,  88,  50,  0, 0x0,  0 },    // abc
  { BUTTON_CreateIndirect,   "123",        ID_BUTTON_4,     303,   350,  88,  50,  0, 0x0,  0 },  // 123
  { BUTTON_CreateIndirect,   "符号",        ID_BUTTON_5,     391,   350,  88,  50,  0, 0x0,  0 },  // 符号

  { BUTTON_CreateIndirect,   "1",        ID_BUTTON_6,      8,     420,  115,  80,  0, 0x0,  0 },  // 1
  { BUTTON_CreateIndirect,   "2",        ID_BUTTON_7,      127,   420,  115,  80,  0, 0x0,  0 },  // 2
  { BUTTON_CreateIndirect,   "3",        ID_BUTTON_8,      246,   420,  115,  80,  0, 0x0,  0 },  // 3
  { BUTTON_CreateIndirect,   "",         ID_BUTTON_9,      365,   420,  115,  80,  0, 0x0,  0 },  // 删除

  { BUTTON_CreateIndirect,   "4",        ID_BUTTON_10,     8,     510,  115,  80,  0, 0x0,  0 },  // 4
  { BUTTON_CreateIndirect,   "5",        ID_BUTTON_11,     127,   510,  115,  80,  0, 0x0,  0 },  // 5
  { BUTTON_CreateIndirect,   "6",        ID_BUTTON_12,     246,   510,  115,  80,  0, 0x0,  0 },  // 6
  { BUTTON_CreateIndirect,   "0",        ID_BUTTON_13,     365,   510,  115,  80,  0, 0x0,  0 },  // 0

  { BUTTON_CreateIndirect,   "7",        ID_BUTTON_14,     8,     600,  115,  80,  0, 0x0,  0 },  // 7
  { BUTTON_CreateIndirect,   "8",        ID_BUTTON_15,     127,   600,  115,  80,  0, 0x0,  0 },  // 8
  { BUTTON_CreateIndirect,   "9",        ID_BUTTON_16,     246,   600,  115,  80,  0, 0x0,  0 },  // 9
  { BUTTON_CreateIndirect,   "确认",         ID_BUTTON_17,     365,   600,  115,  80,  0, 0x0,  0 },  // 确认
};

// wifi 密码输入符号键盘 
// 资源列表
static const GUI_WIDGET_CREATE_INFO _aDialogCreateWifiPasswordSymPage[] = {
  { WINDOW_CreateIndirect,   "",        ID_WINDOW_MY,    0,      0,    480,  800, 0, 0x0,  0 },
//  { TEXT_CreateIndirect,     "",         ID_TEXT_1,      115,    155,  200,  45,  0, 0x0,  0 },    // wifi 名称
  { EDIT_CreateIndirect,         "",        ID_EDIT_1,       115,    155,  250,  40,  0, 0x0,  0 },    //  wifi 名称
  { EDIT_CreateIndirect,     "",        ID_EDIT_0,       115,    205,  250,  40,  0, 0x0,  0 },    // 密码输入框
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_1,     0,      710,  160,  80,  0, 0x0,  0 },    // 取消
  { BUTTON_CreateIndirect,   "",        ID_BUTTON_2,     320,    710,  160,  80,  0, 0x0,  0 },   // 连接

  { BUTTON_CreateIndirect,   "abc",        ID_BUTTON_3,     215,     350,  88,  50,  0, 0x0,  0 },    // abc
  { BUTTON_CreateIndirect,   "123",        ID_BUTTON_4,     303,     350,  88,  50,  0, 0x0,  0 },  // 123
  { BUTTON_CreateIndirect,   "符号",        ID_BUTTON_5,     391,     350,  88,  50,  0, 0x0,  0 },  // 符号

  { BUTTON_CreateIndirect,   "[",        ID_BUTTON_6,      4,     420,  40,  56,  0, 0x0,  0 },  // [
  { BUTTON_CreateIndirect,   "]",        ID_BUTTON_7,      52,    420,  40,  56,  0, 0x0,  0 },  // ]
  { BUTTON_CreateIndirect,   "{",        ID_BUTTON_8,      100,   420,  40,  56,  0, 0x0,  0 },  // {
  { BUTTON_CreateIndirect,   "}",        ID_BUTTON_9,      148,   420,  40,  56,  0, 0x0,  0 },  // }
  { BUTTON_CreateIndirect,   "#",        ID_BUTTON_10,     196,   420,  40,  56,  0, 0x0,  0 },  // #
  { BUTTON_CreateIndirect,   "%",        ID_BUTTON_11,     244,   420,  40,  56,  0, 0x0,  0 },  // %
  { BUTTON_CreateIndirect,   "^",        ID_BUTTON_12,     292,   420,  40,  56,  0, 0x0,  0 },  // ^
  { BUTTON_CreateIndirect,   "*",        ID_BUTTON_13,     340,   420,  40,  56,  0, 0x0,  0 },  // *
  { BUTTON_CreateIndirect,   "+",        ID_BUTTON_14,     388,   420,  40,  56,  0, 0x0,  0 },  // +
  { BUTTON_CreateIndirect,   "=",        ID_BUTTON_15,     436,   420,  40,  56,  0, 0x0,  0 },  // =

  { BUTTON_CreateIndirect,   "_",        ID_BUTTON_16,     4,     490,  40,  56,  0, 0x0,  0 },  // _
  { BUTTON_CreateIndirect,   "-",        ID_BUTTON_17,     52,    490,  40,  56,  0, 0x0,  0 },  // -
  { BUTTON_CreateIndirect,   "/",        ID_BUTTON_18,     100,   490,  40,  56,  0, 0x0,  0 },  // /
  { BUTTON_CreateIndirect,   "\\",       ID_BUTTON_19,     148,   490,  40,  56,  0, 0x0,  0 },  // \ 
  { BUTTON_CreateIndirect,   "|",        ID_BUTTON_20,     196,   490,  40,  56,  0, 0x0,  0 },  // |
  { BUTTON_CreateIndirect,   ":",        ID_BUTTON_21,     244,   490,  40,  56,  0, 0x0,  0 },  // :
  { BUTTON_CreateIndirect,   ";",        ID_BUTTON_22,     292,   490,  40,  56,  0, 0x0,  0 },  // ;
  { BUTTON_CreateIndirect,   "(",        ID_BUTTON_23,     340,   490,  40,  56,  0, 0x0,  0 },  // (
  { BUTTON_CreateIndirect,   ")",        ID_BUTTON_24,     388,   490,  40,  56,  0, 0x0,  0 },  // )
  { BUTTON_CreateIndirect,   "~",        ID_BUTTON_25,     436,   490,  40,  56,  0, 0x0,  0 },  // ~

  { BUTTON_CreateIndirect,   ".",        ID_BUTTON_26,     4,     560,  40,  56,  0, 0x0,  0 },  // .
  { BUTTON_CreateIndirect,   ",",        ID_BUTTON_27,     52,    560,  40,  56,  0, 0x0,  0 },  // ,
  { BUTTON_CreateIndirect,   "`",        ID_BUTTON_28,     100,   560,  40,  56,  0, 0x0,  0 },  // `
  { BUTTON_CreateIndirect,   "?",        ID_BUTTON_29,     148,   560,  40,  56,  0, 0x0,  0 },  // ?
  { BUTTON_CreateIndirect,   "!",        ID_BUTTON_30,     196,   560,  40,  56,  0, 0x0,  0 },  // !
  { BUTTON_CreateIndirect,   "&",        ID_BUTTON_31,     244,   560,  40,  56,  0, 0x0,  0 },  // &
  { BUTTON_CreateIndirect,   "@",        ID_BUTTON_32,     292,   560,  40,  56,  0, 0x0,  0 },  // @
  { BUTTON_CreateIndirect,   "",         ID_BUTTON_33,     340,   560,  132, 56,  0, 0x0,  0 },  // 删除


  { BUTTON_CreateIndirect,   "<",        ID_BUTTON_34,     4,     630,  40,  56,  0, 0x0,  0 },  // <
  { BUTTON_CreateIndirect,   ">",        ID_BUTTON_35,     52,    630,  40,  56,  0, 0x0,  0 },  // >
  { BUTTON_CreateIndirect,   "\"",       ID_BUTTON_36,     100,   630,  40,  56,  0, 0x0,  0 },  // "
  { BUTTON_CreateIndirect,   "\"",       ID_BUTTON_37,     148,   630,  40,  56,  0, 0x0,  0 },  // "
  { BUTTON_CreateIndirect,   "$",        ID_BUTTON_38,     196,   630,  40,  56,  0, 0x0,  0 },  // $
  { BUTTON_CreateIndirect,   "空格",         ID_BUTTON_39,     244,   630,  132, 56,  0, 0x0,  0 },  // 空格
  { BUTTON_CreateIndirect,   "确认",         ID_BUTTON_40,     388,   630,  88,  56,  0, 0x0,  0 },  // 确认
};

// 定时开关设置按键回调函数
static void _cbButtonTimeOffSet(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
				
			}
			else
			{
				GUI_SetBkColor(0X00717171);
				GUI_Clear();
				GUI_DrawBitmap(&bmtimeoffsetkey,38,38);				
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 检测时间设置按键回调函数
static void _cbButtonCkTimeSet(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
				
			}
			else
			{
				GUI_SetBkColor(0X00717171);
				GUI_Clear();
				GUI_DrawBitmap(&bmtimeset,38,38);				
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}
// 查看记录按键回调函数
static void _cbButtonCkRecord(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
				
			}
			else
			{
				GUI_SetBkColor(0X00717171);
				GUI_Clear();
				GUI_DrawBitmap(&bmrecord,38,38);				
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}
// 高级设置按键回调函数
static void _cbButtonSet(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
				
			}
			else
			{
				GUI_SetBkColor(0X00717171);
				GUI_Clear();
				GUI_DrawBitmap(&bmset,38,38);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}
// 开始按键回调函数
static void _cbButtonStart(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
				
			}
			else
			{
				GUI_SetBkColor(0X0057565a);
				GUI_Clear();
				if(SysParameterCur.nCkSensorStatus == 0)
				{
					GUI_DrawBitmap(&bmstart,160,24);    // 开始
				}
				else
				{
					GUI_DrawBitmap(&bmstopkey,155,30);  // 停止
				}
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}


// AQI 绘制函数
void f_DrawAqiPhoto(unsigned char sensorstepbuf)
{
	switch(sensorstepbuf)
	{
     		case 0:
		case 1:
			GUI_SetBkColor(SENSOR_STEP1_COLOR);
			
			break;
		case 2:
		case 3:
		case 4:
			GUI_SetBkColor(SENSOR_STEP2_COLOR);
			break;
		case 5:
		case 6:
		case 7:
			GUI_SetBkColor(SENSOR_STEP3_COLOR);
			break;
		case 8:
		case 9:
		case 10:
			GUI_SetBkColor(SENSOR_STEP4_COLOR);
			break;
		case 11:
		case 12:
		case 13:
			GUI_SetBkColor(SENSOR_STEP5_COLOR);
			break;
		case 14:
		case 15:
		case 16:
			GUI_SetBkColor(SENSOR_STEP6_COLOR);
			break;
	}
	GUI_Clear();

	GUI_SetColor(GUI_WHITE);
	GUI_AA_FillRoundedRect(126,301,234,332,5);

	switch(sensorstepbuf)
	{
     		case 0:
		case 1:
			GUI_DrawBitmap(&bmAQIyou,167,302);
			break;
		case 2:
		case 3:
		case 4:
			GUI_DrawBitmap(&bmAQIliang,167,302);
			break;
		case 5:
		case 6:
		case 7:
			GUI_DrawBitmap(&bmAQIqingdu,130,302);
			GUI_DrawBitmap(&bmAQIwuran,180,302);
			break;
		case 8:
		case 9:
		case 10:
			GUI_DrawBitmap(&bmAQIzhongdu,130,302);
			GUI_DrawBitmap(&bmAQIwuran,180,302);
			break;
		case 11:
		case 12:
		case 13:
			GUI_DrawBitmap(&bmAQIzhongdu1,130,302);
			GUI_DrawBitmap(&bmAQIwuran,180,302);
			break;
		case 14:
		case 15:
		case 16:
			GUI_DrawBitmap(&bmAQIyanzhong,130,302);
			GUI_DrawBitmap(&bmAQIwuran,180,302);
			break;
	}
	

	//GUI_AA_EnableHiRes();
	GUI_AA_SetFactor(4);

	GUI_SetPenSize(2);                // 设置汇笔大小

	// 优 1
	GUI_SetColor(GUI_WHITE);
	GUI_AA_DrawLine(85,265,95,256);

	GUI_SetColor(0x00fbfcfd);    
	GUI_AA_DrawLine(79,258,90,250);        

	GUI_SetColor(0x00f3f8fb);    
	GUI_AA_DrawLine(74,251,85,243);     

	GUI_SetColor(0x00eef3f9);   
	GUI_AA_DrawLine(69,243,80,236); 
	
	// 优 2
	if(sensorstepbuf < 1)
	{
		GUI_SetColor(0x008b8889);
		GUI_AA_DrawLine(64,235,76,229);
		GUI_AA_DrawLine(60,227,72,222);
		GUI_AA_DrawLine(56,218,69,214);
	}
	else
	{
		GUI_SetColor(0x00DEE8F5);
		GUI_AA_DrawLine(64,235,76,229);   
		GUI_SetColor(0x00DFE9F6);
		GUI_AA_DrawLine(60,227,72,222); 
		GUI_SetColor(0x00DEE8F5);
		GUI_AA_DrawLine(56,218,69,214); 
	}
		

	// 良 1
	if(sensorstepbuf < 2)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(54,209,66,206);
		GUI_AA_DrawLine(52,201,64,198);
		GUI_AA_DrawLine(50,191,63,189);
		GUI_AA_DrawLine(48,182,62,181);
	}
	else
	{
		GUI_SetColor(0x00D2DFF1);
		GUI_AA_DrawLine(54,209,66,206);   
		GUI_AA_DrawLine(52,201,64,198); 
		GUI_AA_DrawLine(50,191,63,189); 
		GUI_SetColor(0x00A6BEE4);
		GUI_AA_DrawLine(48,182,62,181); 
	}

	// 良 2
	if(sensorstepbuf < 3)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(49,173,62,173);
		GUI_AA_DrawLine(49,164,62,165);
		GUI_AA_DrawLine(50,154,63,156);
	}
	else
	{
		GUI_SetColor(0x00A6BEE4);     
		GUI_AA_DrawLine(49,173,62,173);   
		GUI_AA_DrawLine(49,164,62,165); 
		GUI_AA_DrawLine(50,154,63,156);
	}

	// 良 3
	if(sensorstepbuf < 4)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(52,145,64,148);
		GUI_AA_DrawLine(54,136,66,140);
		GUI_AA_DrawLine(57,127,69,132);
	}
	else
	{
		GUI_SetColor(0x0095B0DF);     
		GUI_AA_DrawLine(52,145,64,148);
		GUI_AA_DrawLine(54,136,66,140);
		GUI_AA_DrawLine(57,127,69,132);
	}

	// 轻度污染 1
	if(sensorstepbuf < 5)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(60,119,72,124);   
		
		GUI_AA_DrawLine(64,110,76,117); 

		GUI_AA_DrawLine(69,102,80,109); 

		GUI_AA_DrawLine(74,95,84,102);   
		
		GUI_AA_DrawLine(80,88,90,96); 

		GUI_AA_DrawLine(86,81,95,89); 
	}
	else
	{
		GUI_SetColor(0x008DAADD);     
		GUI_AA_DrawLine(60,119,72,124);   
		GUI_AA_DrawLine(64,110,76,117); 
		GUI_AA_DrawLine(69,102,80,109); 
		GUI_SetColor(0x007595D6);
		GUI_AA_DrawLine(74,95,84,102);
		GUI_AA_DrawLine(80,88,90,96);
		GUI_AA_DrawLine(86,81,95,89);
	}

	// 轻度污染 2
	if(sensorstepbuf < 6)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(93,74,101,83);
		GUI_AA_DrawLine(100,68,108,78);
		GUI_AA_DrawLine(108,63,115,74);
	}
	else
	{
		GUI_SetColor(0x006789D2);     
		GUI_AA_DrawLine(93,74,101,83);
		GUI_AA_DrawLine(100,68,108,78);
		GUI_AA_DrawLine(108,63,115,74);
	}

	// 轻度污染 3
	if(sensorstepbuf < 7)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(116,58,122,69);
		GUI_AA_DrawLine(124,54,129,65);
		GUI_AA_DrawLine(132,50,137,62);
	}
	else
	{
		GUI_SetColor(0x006385D0);     
		GUI_AA_DrawLine(116,58,122,69);
		GUI_AA_DrawLine(124,54,129,65);
		GUI_AA_DrawLine(132,50,137,62);
	}

	// 中度污染 1
	if(sensorstepbuf < 8)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(140,47,144,59);
		GUI_AA_DrawLine(149,44,152,57);
		GUI_AA_DrawLine(158,42,160,55);
	}
	else
	{
		GUI_SetColor(0x005274CA);     
		GUI_AA_DrawLine(140,47,144,59);
		GUI_AA_DrawLine(149,44,152,57);
		GUI_AA_DrawLine(158,42,160,55);
	}

	// 中度污染 2
	if(sensorstepbuf < 9)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(167,41,169,54);
		GUI_AA_DrawLine(176,39,177,53);
		GUI_AA_DrawLine(185,39,185,52);
		GUI_AA_DrawLine(195,40,194,53);
	}
	else
	{
		GUI_SetColor(0x004664BF);     
		GUI_AA_DrawLine(167,41,169,54);
		GUI_AA_DrawLine(176,39,177,53);
		GUI_AA_DrawLine(185,39,185,52);
		GUI_AA_DrawLine(195,40,194,53);
	}

	// 中度污染 3
	if(sensorstepbuf < 10)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(204,42,202,55);
		GUI_AA_DrawLine(213,44,210,56);
		GUI_AA_DrawLine(222,47,218,58);
		GUI_AA_DrawLine(231,50,226,61);
		GUI_AA_DrawLine(239,54,233,65);
	}
	else
	{
		GUI_SetColor(0x004664BF);    
		GUI_AA_DrawLine(204,42,202,55);
		GUI_AA_DrawLine(213,44,210,56);
		GUI_AA_DrawLine(222,47,218,58);
		GUI_AA_DrawLine(231,50,226,61);
		GUI_AA_DrawLine(239,54,233,65);
	}

	// 重度污染 1
	if(sensorstepbuf < 11)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(248,58,241,69);
		GUI_AA_DrawLine(255,63,248,73);
		GUI_AA_DrawLine(262,68,255,78);
	}
	else
	{
		GUI_SetColor(0x003A54B5);     
		GUI_AA_DrawLine(248,58,241,69);
		GUI_AA_DrawLine(255,63,248,73);
		GUI_AA_DrawLine(262,68,255,78);
	}

	// 重度污染 2
	if(sensorstepbuf < 12)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(269,74,261,83);
		GUI_AA_DrawLine(276,81,267,89); 
		GUI_AA_DrawLine(282,88,272,95);
	}
	else
	{
		GUI_SetColor(0x003A54B5);     
		GUI_AA_DrawLine(269,74,261,83);
		GUI_AA_DrawLine(276,81,267,89);
		GUI_AA_DrawLine(282,88,272,95);
	}

	// 重度污染 3
	if(sensorstepbuf < 13)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(288,94,278,102);
		GUI_AA_DrawLine(293,102,282,109);
		GUI_AA_DrawLine(298,110,287,116);
		GUI_AA_DrawLine(302,118,290,124);
		GUI_AA_DrawLine(305,127,293,131);
		GUI_AA_DrawLine(308,136,296,139);
		GUI_AA_DrawLine(310,145,298,146);
		GUI_AA_DrawLine(312,154,299,155);
	}
	else
	{
		GUI_SetColor(0x00344AA7);    
		GUI_AA_DrawLine(288,94,278,102);
		GUI_AA_DrawLine(293,102,282,109);
		GUI_AA_DrawLine(298,110,287,116);
		GUI_AA_DrawLine(302,118,290,124);
		GUI_AA_DrawLine(305,127,293,131);
		GUI_AA_DrawLine(308,136,296,139);
		GUI_AA_DrawLine(310,145,298,146);
		GUI_AA_DrawLine(312,154,299,155);
	}

	// 严重污染 1
	if(sensorstepbuf < 14)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(313,163,300,164);
		GUI_AA_DrawLine(313,172,300,172);
		GUI_AA_DrawLine(313,181,300,180);
		GUI_AA_DrawLine(312,190,299,188);
		GUI_AA_DrawLine(310,200,298,197);
	}
	else
	{
		GUI_SetColor(0x00263A9C);     
		GUI_AA_DrawLine(313,163,300,164);
		GUI_SetColor(0x002A318F); 
		GUI_AA_DrawLine(313,172,300,172);
		GUI_AA_DrawLine(313,181,300,180);
		GUI_AA_DrawLine(312,190,299,188);
		GUI_AA_DrawLine(310,200,298,197);
	}

	// 严重污染 2
	if(sensorstepbuf < 15)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(308,209,296,205);
		GUI_AA_DrawLine(305,218,293,213);
		GUI_AA_DrawLine(302,226,290,220);
		GUI_AA_DrawLine(298,234,287,228);
	}
	else
	{
		GUI_SetColor(0x0027237C);     
		GUI_AA_DrawLine(308,209,296,205);
		GUI_AA_DrawLine(305,218,293,213);
		GUI_AA_DrawLine(302,226,290,220);
		GUI_AA_DrawLine(298,234,287,228);
	}

	// 严重污染 3
	if(sensorstepbuf < 16)
	{
		GUI_SetColor(0x008b8889);     
		GUI_AA_DrawLine(293,242,282,235);
		GUI_AA_DrawLine(288,249,278,242);
		GUI_AA_DrawLine(282,256,272,248);
		GUI_AA_DrawLine(276,263,267,254);
	}
	else
	{
		GUI_SetColor(0x00201D64);     
		GUI_AA_DrawLine(293,242,282,235);
		GUI_AA_DrawLine(288,249,278,242);
		GUI_AA_DrawLine(282,256,272,248);
		GUI_AA_DrawLine(276,263,267,254);
	}

	GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
	GUI_SetTextMode(GUI_TM_TRANS);
	GUI_SetColor(GUI_WHITE);
	GUI_SetFont(&GUI_Fontfont_yh_61);
	GUI_GotoXY(180,180);
	GUI_DispDecMin(SysParameterCur.nAqiData);

	GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
	GUI_SetTextMode(GUI_TM_TRANS);
	GUI_SetColor(0x00373638);
	GUI_SetFont(GUI_FONT_32_ASCII);
	GUI_DispStringAt("AQI",180,268);

	//GUI_AA_DisableHiRes();
}

// AQI 按键回调函数
static void _cbButtonAqi(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
				
			}
			else
			{
				f_DrawAqiPhoto(SysParameterCur.nCkSensorStep);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 标题栏
void f_HeadStatusDis(void)
{
	unsigned short xendbuf;
	unsigned char pointdatabuf;

	GUI_SetColor(0X0057565A);
	GUI_FillRect(0,0,480,90);

	// wifi 图标
	if (nWifiData.nWifiNetSetStatus != WIFI_NET_SET_OK)
	{
		GUI_PNG_Draw(acnosigle,sizeof(acnosigle),17,26);
	}
	else
	{
		switch(SysParameterCur.WifiSigle)
		{
			case 0:
				GUI_PNG_Draw(acnosigle,sizeof(acnosigle),17,26);
				break;
			case 1:
				GUI_PNG_Draw(aconesigle,sizeof(aconesigle),17,26);
				break;
			case 2:
				GUI_PNG_Draw(actwosigle,sizeof(actwosigle),17,26);
				break;
			case 3:
				GUI_PNG_Draw(acallsigle,sizeof(acallsigle),17,26);
				break;
		}
	}

	// 定时图标
	if(SysParameterCur.nTmOnOffStatus == 1)   // 定时开关功能开启
	{
		GUI_DrawBitmap(&bmtimeonofflogo,354,30);
	}

	if(SysParameterCur.nHw1Status != 2)   // 高级设置界面
	{

		// 电池
		if(BatteryDataCur.nBatteryStatus == 1)       // 充电
		{
			GUI_DrawBitmap(&bmbatterycharging,452,30);
		}
		
		if(BatteryDataCur.nBatteryData <= 10)       // 需要充电
			GUI_SetColor(GUI_RED);
		else
			GUI_SetColor(GUI_WHITE);

		pointdatabuf = (BatteryDataCur.nBatteryData * 4) % 10;
		
		xendbuf = 402 + (BatteryDataCur.nBatteryData * 40 / 100);
		if(pointdatabuf > 5) 
			xendbuf += 1;

		GUI_AA_FillRoundedRect(402,34,xendbuf,50,0);           // 电池电量

		GUI_PNG_Draw(acbatteryframe,sizeof(acbatteryframe),398,30);  // 电池轮廓
	}

	// 时间
	GUI_SetFont(GUI_FONT_32_ASCII);
	GUI_SetColor(GUI_WHITE);
	GUI_SetTextMode(GUI_TM_TRANS);
	GUI_SetTextAlign(GUI_TA_VCENTER);
	GUI_GotoXY(76,42);
	GUI_DispDec(RTC_DateStruct.RTC_Year + 2000,4);
	GUI_DispString("-");
	GUI_DispDec(RTC_DateStruct.RTC_Month,2);
	GUI_DispString("-");
	GUI_DispDec(RTC_DateStruct.RTC_Date,2);
	GUI_DispString("   ");

	GUI_DispDec(RTC_TimeStruct.RTC_Hours,2);
	GUI_DispString(" : ");
	GUI_DispDec(RTC_TimeStruct.RTC_Minutes,2);
	 
}

/* ===================================================
 * 函数名称:  f_GetAqiStepClr
 * 功能说明:  获取颜色
 * 输入说明:
 * 输出说明:
 * 作          者:  王聪
 * 编辑时间:  
 * 备          注:
 ===================================================*/
void f_GetAqiStepClr(unsigned char stepbuf)
{
	switch(stepbuf)
	{
     		case 0:         // 优
		case 1:
			SysParameterCur.AqiStepColor = SENSOR_STEP1_COLOR;  //0x00F4CD7E;
			break;
		case 2:         // 良
		case 3:
		case 4:
			SysParameterCur.AqiStepColor = SENSOR_STEP2_COLOR;  //0x008AC5EC;
			break;
		case 5:         // 轻度污染
		case 6:
		case 7:
			SysParameterCur.AqiStepColor = SENSOR_STEP3_COLOR;  //0x00558DF2;
			break;
		case 8:         // 中度污染
		case 9:
		case 10:
			SysParameterCur.AqiStepColor = SENSOR_STEP4_COLOR;  //0x003A44D2;
			break;
		case 11:       // 重度污染
		case 12:
		case 13:
			SysParameterCur.AqiStepColor = SENSOR_STEP5_COLOR;  //0x00231E97;
			break;
		case 14:       // 严重污染
		case 15:
		case 16:
			SysParameterCur.AqiStepColor = SENSOR_STEP6_COLOR;  //0x009A5E87;
			break;
	}
}
	

// 首页窗口回调函数
static void _cbWindowPage1(WM_MESSAGE * pMsg)
{
	
	int     NCode;
       int     Id;
	float   tvocbuf;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		f_HeadStatusDis();

		f_GetAqiStepClr(SysParameterCur.nCkSensorStep);  // 获取AQI颜色
		// PM2.5
		GUI_SetColor(SysParameterCur.AqiStepColor);
		GUI_FillRect(0,100,118,218);
       
		// PM10
		GUI_SetColor(SysParameterCur.AqiStepColor);
		GUI_FillRect(120,100,238,218);

		// 甲醛
		GUI_SetColor(SysParameterCur.AqiStepColor);
		GUI_FillRect(240,100,358,218);

		// 温湿度
		GUI_SetColor(SysParameterCur.AqiStepColor);
		GUI_FillRect(360,100,480,218);
		GUI_PNG_Draw(actemp,sizeof(actemp),460,106);  // 温度logo
		GUI_PNG_Draw(achumi,sizeof(achumi),458,160);   // 湿度logo
		
		GUI_PNG_Draw(acunitwendu,sizeof(acunitwendu),438,130);
		GUI_PNG_Draw(acunitshidu,sizeof(acunitshidu),438,180);

		// 2.5um颗粒数
		GUI_SetColor(SysParameterCur.AqiStepColor);
		GUI_FillRect(0,220,118,338);
		
		// 10um颗粒数
		GUI_SetColor(SysParameterCur.AqiStepColor);
		GUI_FillRect(120,220,238,338);

		// TVOC
		GUI_SetColor(SysParameterCur.AqiStepColor);
		GUI_FillRect(240,220,358,338);

		// CO2
		GUI_SetColor(SysParameterCur.AqiStepColor);
		GUI_FillRect(360,220,480,338);

		// PM2.5
		GUI_SetFont(&GUI_Fontfont_yh_31);
		GUI_SetColor(GUI_WHITE);
		GUI_GotoXY(60,147);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispFloatMin(SensorPM2_5DataCur.Pm2_5DataCur,2);
       
		// PM10
		GUI_GotoXY(180,147);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispFloatMin(SensorPM2_5DataCur.Pm10DataCur,2);

		// 甲醛
		GUI_GotoXY(300,147);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispString("...");
//		GUI_DispDecMin(datatest);

		// 温湿度
		GUI_GotoXY(413,136);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispDecMin(nTempValueCur);
 
		GUI_GotoXY(413,185);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispDecMin(nHumiValueCur);

		// 2.5um颗粒数
		GUI_GotoXY(60,267);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispDecMin(SensorPM2_5DataCur.Pm2_5DustCur);
		
		// 10um颗粒数
		GUI_GotoXY(180,267);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispDecMin(SensorPM2_5DataCur.Pm10DustCur);

		// TVOC
		tvocbuf = ((float)(nTvocValueCur)) / 1000;
		GUI_GotoXY(300,267);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispFloatMin(tvocbuf,3);

		// CO2
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_GotoXY(420,267);
		GUI_DispString("...");
//		GUI_DispDecMin(datatest);

		break;
	  
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 定时开关设置按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
        
			break;
		  case WM_NOTIFICATION_RELEASED:
			SysParameterCur.nHw1Status = 1;
			GUI_EndDialog(pMsg->hWin, 0);
		    hItemCur = GUI_CreateDialogBox(_aDialogCreateTimeOffSetPage1, GUI_COUNTOF(_aDialogCreateTimeOffSetPage1), _cbDialogTimeOffSetPage1, WM_HBKWIN, 0, 0);
			
			break;
		  }
		  break;
		case ID_BUTTON_2: // 检测时间设置按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
        
			break;
		  case WM_NOTIFICATION_RELEASED:
		  	SysParameterCur.SysSensorCkTmMemory = SysParameterCur.SysSensorCkTm;
			SysParameterCur.nHw1Status = 1;
			GUI_EndDialog(pMsg->hWin, 0);
			hItemCur = GUI_CreateDialogBox(_aDialogCreateCkTmSet, GUI_COUNTOF(_aDialogCreateCkTmSet), _cbDialogCkTimeSet,WM_HBKWIN, 0, 0);
			break;
		  }
		  break;
		case ID_BUTTON_3: // 历史数据查看按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
        
			break;
		  case WM_NOTIFICATION_RELEASED:
			SysParameterCur.nHw1Status = 1;
			GUI_EndDialog(pMsg->hWin, 0);
			hItemCur = GUI_CreateDialogBox(_aDialogCreateRecordPage, GUI_COUNTOF(_aDialogCreateRecordPage), _cbDialogRecordPage,WM_HBKWIN, 0, 0);
			break;
		  }
		  break;
		case ID_BUTTON_4: // 高级设置按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
        
			break;
		  case WM_NOTIFICATION_RELEASED:
			SysParameterCur.nHw1Status = 2;
			GUI_EndDialog(pMsg->hWin, 0); 
		    hItemCur = GUI_CreateDialogBox(_aDialogCreateSetPage1, GUI_COUNTOF(_aDialogCreateSetPage1), _cbDialogSetPage1, WM_HBKWIN, 0, 0);
			break;
		  }
		  break;
		case ID_BUTTON_5: // 开启/停止按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
        
			break;
		  case WM_NOTIFICATION_RELEASED:
			if(SysParameterCur.nCkSensorStatus == 0)
				SysParameterCur.nCkSensorStatus = 1;
			else
				SysParameterCur.nCkSensorStatus = 0;
			break;
		  }
		  break;
		case ID_BUTTON_6: // AQI按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
        
			break;
		  case WM_NOTIFICATION_RELEASED:
			SysParameterCur.nHw1Status = 3;
			GUI_EndDialog(pMsg->hWin, 0);
			hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePm2_5Page, GUI_COUNTOF(_aDialogCreatePm2_5Page), _cbDialogPM2_5Page, WM_HBKWIN, 0, 0);
			break;
		  }
		}
		break;
	  default:
		WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _cbDialogPage1
*/
static void _cbDialogPage1(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowPage1);                  // 窗口

	// 按钮
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);     // 定时开关机按钮
	WM_SetCallback(hItem,_cbButtonTimeOffSet);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);     // 检测时间设置按钮
	WM_SetCallback(hItem,_cbButtonCkTimeSet);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);     // 查看历史记录按钮
	WM_SetCallback(hItem,_cbButtonCkRecord);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);     // 高级设置按钮
	WM_SetCallback(hItem,_cbButtonSet);

	
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);     // 开启按钮
	WM_SetCallback(hItem,_cbButtonStart);
	

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);     // AQI按钮
	WM_SetCallback(hItem,_cbButtonAqi);

	// 文本
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // PM2.5
    TEXT_SetFont(hItem, &GUI_Fontfont_yh20);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "PM2.5浓度");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);       // PM10
    TEXT_SetFont(hItem, &GUI_Fontfont_yh20);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "PM10浓度");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);       // 甲醛
    TEXT_SetFont(hItem, &GUI_Fontfont_yh20);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "甲醛 浓度");

	//hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);       // 温湿度
    //TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
	//TEXT_SetTextColor(hItem,GUI_WHITE);
    //TEXT_SetText(hItem, "TEMP");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);       // 2.5颗粒物
    TEXT_SetFont(hItem, &GUI_Fontfont_yh20);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "2.5um颗粒数");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);       // 10颗粒物
    TEXT_SetFont(hItem, &GUI_Fontfont_yh20);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "10um颗粒数");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);       // TVOC
    TEXT_SetFont(hItem, &GUI_Fontfont_yh20);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "TVOC");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_8);       // CO2
    TEXT_SetFont(hItem, &GUI_Fontfont_yh20);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "CO2浓度");
	
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}


// 返回按键回调函数
static void _cbButtonBack(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(0X0057565A);
				GUI_Clear();
				GUI_DrawBitmap(&bmback,53,13);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 返回主界面按键回调函数
static void _cbButtonBackMain(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(0X0057565A);
				GUI_Clear();
				GUI_DrawBitmap(&bmbackfirst,53,13);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 设定按键回调函数
static void _cbButtonTimeOpenSet(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				//BackgroundClor = 0X00EEB611;
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();
				
				GUI_PNG_Draw(acsheding,sizeof(acsheding),27,2);

				//GUI_SetTextMode(GUI_TM_TRANS);
//				GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
//				GUI_SetColor(GUI_WHITE);
//				GUI_SetFont(&GUI_Fontfont_yh_dingshi);
//				GUI_DispStringAt("设定",48,19);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 开机按键回调函数1
static void _cbButtonTimeOpenOn(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();
				if(SysParameterCur.TimeOnSetStatus == 1)
					GUI_PNG_Draw(actimeOffsetON,sizeof(actimeOffsetON),5,2);
				else
					GUI_PNG_Draw(actimeOffsetOff,sizeof(actimeOffsetOff),1,0);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 开机按键回调函数2
static void _cbButtonTimeOpenOff(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();
				if(SysParameterCur.TimeOffSetStatus == 1)
					GUI_PNG_Draw(actimeOffsetON,sizeof(actimeOffsetON),5,2);
				else
					GUI_PNG_Draw(actimeOffsetOff,sizeof(actimeOffsetOff),1,0);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 定时开关机窗口回调函数
static void _cbWindowTimeOffSetPage1(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

//		GUI_PNG_Draw(actmfuction,sizeof(actmfuction),63,131);    // 定时功能

//		GUI_PNG_Draw(acdingshi,sizeof(acdingshi),75,221);        // 定时开机
//		GUI_PNG_Draw(acdingshion,sizeof(acdingshion),116,221);

//		GUI_PNG_Draw(acdingshi,sizeof(acdingshi),75,355);        // 定时关机
//		GUI_PNG_Draw(acdingshioff,sizeof(acdingshioff),116,355);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(48,192,431,492,5);
		GUI_DrawRoundedRect(49,193,430,491,5);

		// 白色横线
		GUI_SetColor(GUI_WHITE);
		GUI_FillRect(63,331,403,333);

		// 定时开机时间
		GUI_SetFont(GUI_FONT_32_ASCII);
		GUI_SetColor(GUI_WHITE);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_GotoXY(80,273);
		GUI_DispDec(SysParameterCur.TimeOnSetData.hour,2);
		GUI_DispString(":");
		GUI_DispDec(SysParameterCur.TimeOnSetData.min,2);

		// 定时关机时间
		GUI_SetFont(GUI_FONT_32_ASCII);
		GUI_SetColor(GUI_WHITE);
		GUI_GotoXY(80,406);
		GUI_DispDec(SysParameterCur.TimeOffSetData.hour,2);
		GUI_DispString(":");
		GUI_DispDec(SysParameterCur.TimeOffSetData.min,2);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_3: // 开机设定按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemCur = GUI_CreateDialogBox(_aDialogCreateTmSetOnOff, GUI_COUNTOF(_aDialogCreateTmSetOnOff), _cbDialogSetTimeOnPage, WM_HBKWIN, 0, 0);
				break;
		  }
		  break;
		case ID_BUTTON_4: // 开机开关按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				if(SysParameterCur.TimeOnSetStatus == 0)
				{
					SysParameterCur.TimeOnSetStatus = 1;
					SysParameterCur.nTmOnOffStatus = 1;
				}
				else
				{
					if(SysParameterCur.TimeOffSetStatus == 0)
						SysParameterCur.nTmOnOffStatus = 0;
					SysParameterCur.TimeOnSetStatus = 0;
				}
				
				break;
		  }
		  break;
		 case ID_BUTTON_5: // 关机设定按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemCur = GUI_CreateDialogBox(_aDialogCreateTmSetOnOff, GUI_COUNTOF(_aDialogCreateTmSetOnOff), _cbDialogSetTimeOffPage, WM_HBKWIN, 0, 0);
				break;
		  }
		  break;
		case ID_BUTTON_6: // 关机开关按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				if(SysParameterCur.TimeOffSetStatus == 0)
				{
					SysParameterCur.TimeOffSetStatus = 1;
					SysParameterCur.nTmOnOffStatus = 1;
				}
				else
				{
					SysParameterCur.TimeOffSetStatus = 0;
					if(SysParameterCur.TimeOnSetStatus == 0)
						SysParameterCur.nTmOnOffStatus = 0;
				}
				break;
		  }
		  break;
		}
		break;
	  default:
		WM_DefaultProc(pMsg);
  }
}

// 标题栏窗口
static void _cbHeadWinBack(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
     	// 标题栏
		f_HeadStatusDis();
		
		break;
	 case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
	  switch(Id) {
		case ID_BUTTON_6: // 参数设置按钮（电池）
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				
				hItemNumPad = GUI_CreateDialogBox(_aDialogCreateNumPadPage, GUI_COUNTOF(_aDialogCreateNumPadPage), _cbDialogNumPadPage, WM_HBKWIN, 0, 0);
			    WM_SetStayOnTop(hItemNumPad, 1);
			    WM_HideWindow(hItemNumPad);

			    hItemCur = GUI_CreateDialogBox(_aDialogCreatePasswordPage, GUI_COUNTOF(_aDialogCreatePasswordPage), _cbDialogPasswordPage, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 1;
				break;
		  }
		  break;
		}
	}
}

// 定时开关机对话框设置界面
static void _cbDialogTimeOffSetPage1(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
 
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowTimeOffSetPage1);        // 窗口

	//hItem = WM_GetDialogItem(pMsg->hWin, ID_WINDOW_HEAD);       // 标题栏
    //WM_SetCallback(hItem,_cbHeadWinBack);
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0);


	// 按钮
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 开机设定按钮
	WM_SetCallback(hItem,_cbButtonTimeOpenSet);

	hItemTimeOnSetButton = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 开机开关按钮
	WM_SetCallback(hItemTimeOnSetButton,_cbButtonTimeOpenOn);
	
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);       // 关机设定按钮
	WM_SetCallback(hItem,_cbButtonTimeOpenSet);

	hItemTimeOnSetButtoff = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);       // 关机开关按钮
	WM_SetCallback(hItemTimeOnSetButtoff,_cbButtonTimeOpenOff);

	// 文本
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 定时功能
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "定时功能");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);       // 定时开机
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_dingshi);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "定时开机");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);       // 定时关机
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_dingshi);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "定时关机");

    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

// 定时开设置界面窗口回调函数
static void _cbWindowSetTimeOn(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		//f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(48,192,431,492,5);
		GUI_DrawRoundedRect(49,193,430,491,5);

		// 定时关机
		// hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 定时功能
//	    GUI_SetFont(&GUI_Fontfont_yh_set);
//		GUI_SetColor(GUI_WHITE);
//		GUI_SetTextAlign(TEXT_CF_HCENTER | TEXT_CF_VCENTER);
//	    GUI_DispStringAt( "定时关机",125,150);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
			    hItemCur = GUI_CreateDialogBox(_aDialogCreateTimeOffSetPage1, GUI_COUNTOF(_aDialogCreateTimeOffSetPage1), _cbDialogTimeOffSetPage1, WM_HBKWIN, 0, 0);
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_3: // 保存按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
			  	SysParameterCur.TimeOnSetData.hour = SysParameterCur.TimeOnSetDataLast.hour;
				SysParameterCur.TimeOnSetData.min = SysParameterCur.TimeOnSetDataLast.min;
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_4: // 取消按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_LISTWHEEL_0:            // 滚轮参数设置
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				SysParameterCur.TimeOnSetDataLast.hour = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0));
				break;
		  }
		  break;
		case ID_LISTWHEEL_1:            // 滚轮参数设置
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				SysParameterCur.TimeOnSetDataLast.min = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_1));
				break;
		  }
		  break;
	  default:
		WM_DefaultProc(pMsg);
	}
  }
}

// 定时关设置界面窗口回调函数
static void _cbWindowSetTimeOff(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		//f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(48,192,431,492,5);
		GUI_DrawRoundedRect(49,193,430,491,5);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
			    hItemCur = GUI_CreateDialogBox(_aDialogCreateTimeOffSetPage1, GUI_COUNTOF(_aDialogCreateTimeOffSetPage1), _cbDialogTimeOffSetPage1, WM_HBKWIN, 0, 0);
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_3: // 保存按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				SysParameterCur.TimeOffSetData.hour = SysParameterCur.TimeOffSetDataLast.hour;
				SysParameterCur.TimeOffSetData.min = SysParameterCur.TimeOffSetDataLast.min;
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_4: // 取消按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_LISTWHEEL_0:            // 滚轮参数设置
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				SysParameterCur.TimeOffSetDataLast.hour = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0));
				break;
		  }
		  break;
		case ID_LISTWHEEL_1:            // 滚轮参数设置
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				SysParameterCur.TimeOffSetDataLast.min = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_1));
				break;
		  }
		  break;
	  default:
		WM_DefaultProc(pMsg);
	}
  }
}

// 保存按钮
static void _cbButtonSave(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				// 背景色
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();				

				// 白色框
				GUI_SetColor(GUI_WHITE);
				GUI_DrawRoundedRect(0,0,96,37,5);

//				GUI_SetFont(GUI_FONT_32_ASCII);
//				GUI_SetTextMode(GUI_TM_TRANS);
//				GUI_DispStringHCenterAt("save",46,5);
				
			      GUI_SetFont(&GUI_Fontfong_yh_save);
			      GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
				  GUI_SetColor(GUI_WHITE);
			      GUI_DispStringAt("保存",48,18);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 取消按钮
static void _cbButtonFault(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				// 背景色
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();				

				// 白色框
				GUI_SetColor(GUI_WHITE);
				GUI_DrawRoundedRect(0,0,96,37,5);

				GUI_SetFont(&GUI_Fontfong_yh_save);
			      GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
			      GUI_DispStringAt("取消",48,18);
				
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 定时开自绘函数
static int _OwnerDrawSetTimeOn(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  WM_HWIN   hWin;
  WHEEL   * pWheel;
  int       xPos;
  int       yPos;
  int       xSizeWin;
  int       ySizeWin;
  int       xSizeDev;

  hWin = pDrawItemInfo->hWin;
  //
  // Process messages
  //
  switch (pDrawItemInfo->Cmd) {
  case WIDGET_ITEM_GET_XSIZE:
    //
    // Return x-size of item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_GET_YSIZE:
    //
    // Return y-size of item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_DRAW:
    //
    // Draw item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_DRAW_BACKGROUND:
    xSizeWin = WM_GetWindowSizeX(hWin);
    ySizeWin = WM_GetWindowSizeY(hWin);
    //
    // Draw background
    //
    GUI_SetColor(SysParameterCur.BackgroundClor);
    GUI_FillRect(0, 0, xSizeWin, ySizeWin);

    GUI_SetColor(GUI_GRAY);
    GUI_FillRect(0,(ySizeWin / 2) - (36 / 2),xSizeWin,(ySizeWin / 2) + (35 / 2));
    break;
  case WIDGET_ITEM_DRAW_OVERLAY:
    LISTWHEEL_GetUserData(hWin, &pWheel, sizeof(pWheel));
    xPos     = WM_GetWindowOrgX(hWin);
    yPos     = WM_GetWindowOrgY(hWin);
    xSizeWin = WM_GetWindowSizeX(hWin);
    xSizeDev = GUI_MEMDEV_GetXSize(pWheel->hMemRBorder);
    //
    // Draw border
    //
    GUI_MEMDEV_WriteAt(pWheel->hMemLBorder, xPos, yPos);
    GUI_MEMDEV_WriteAt(pWheel->hMemRBorder, xPos + xSizeWin - xSizeDev, yPos);
    //
    // Draw overlay
    //
    GUI_MEMDEV_WriteAt(pWheel->hMemOverlay, xPos, yPos);
    break;
  }
  return 0;
}

// 定时开设置对话框设置界面
static void _cbDialogSetTimeOnPage(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  unsigned char i;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowSetTimeOn);                  // 窗口

	// 标题栏
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

	// 按钮
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 保存按钮
	WM_SetCallback(hItem,_cbButtonSave);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 取消按钮
	WM_SetCallback(hItem,_cbButtonFault);

	// 文本
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 参数设置
	TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
	TEXT_SetText(hItem, "定时开机");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);         // 时
	TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
       TEXT_SetText(hItem, "时");


	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);         // 分
      TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
      TEXT_SetText(hItem, "分");

	// 车轮参数设置
	// 时
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);  // 1 - 23
    LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTimeOn);
	_aWheelpostTimeSetOnOff = &_aWheelTimeSetOnOff[0];
    LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSetOnOff, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetHourTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetHourTimeWheelData + i)));
	}
	SysParameterCur.TimeOnSetDataLast.hour = SysParameterCur.TimeOnSetData.hour;
	LISTWHEEL_MoveToPos(hItem,SysParameterCur.TimeOnSetData.hour);

	// 分
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_1);  // 0 - 59
    LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTimeOn);
	_aWheelpostTimeSetOnOff = &_aWheelTimeSetOnOff[1];
    LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSetOnOff, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetMinTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetMinTimeWheelData + i)));
	}
	SysParameterCur.TimeOnSetDataLast.min = SysParameterCur.TimeOnSetData.min;
	LISTWHEEL_MoveToPos(hItem,SysParameterCur.TimeOnSetData.min);

    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

// 定时关设置对话框设置界面
static void _cbDialogSetTimeOffPage(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  unsigned char i;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowSetTimeOff);                 // 窗口

	// 标题栏
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

	// 按钮
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 保存按钮
	WM_SetCallback(hItem,_cbButtonSave);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 取消按钮
	WM_SetCallback(hItem,_cbButtonFault);

	// 文本
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 定时关机
	TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
	TEXT_SetText(hItem, "定时关机");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);         // 时
	TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
       TEXT_SetText(hItem, "时");


	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);         // 分
      TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
      TEXT_SetText(hItem, "分");

	  
	// 车轮参数设置
	// 时
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);  // 1 - 23
    LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTimeOn);
	_aWheelpostTimeSetOnOff = &_aWheelTimeSetOnOff[0];
    LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSetOnOff, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetHourTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetHourTimeWheelData + i)));
	}
	SysParameterCur.TimeOffSetDataLast.hour = SysParameterCur.TimeOffSetData.hour;
	LISTWHEEL_MoveToPos(hItem,SysParameterCur.TimeOffSetData.hour);

	// 分
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_1);  // 0 - 59
    LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTimeOn);
	_aWheelpostTimeSetOnOff = &_aWheelTimeSetOnOff[1];
    LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSetOnOff, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetMinTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetMinTimeWheelData + i)));
	}
	SysParameterCur.TimeOffSetDataLast.min = SysParameterCur.TimeOffSetData.min;
	LISTWHEEL_MoveToPos(hItem,SysParameterCur.TimeOffSetData.min);

    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

// 高级设置界面窗口回调函数
static void _cbWindowSetPage1(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		//f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

		// 高级设置
		//GUI_SetFont(GUI_FONT_32_ASCII);
		//GUI_SetColor(GUI_WHITE);
		//GUI_SetTextMode(GUI_TM_TRANS);
		//GUI_DispStringAt("SET",148,235);
		//GUI_PNG_Draw(acgaojiset,sizeof(acgaojiset),152,234);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_3: // 时间设置按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
			  	
				GUI_EndDialog(pMsg->hWin, 0);
				hItemCur = GUI_CreateDialogBox(_aDialogCreateSetTimePage,GUI_COUNTOF(_aDialogCreateSetTimePage),_cbDialogSetTimePage,WM_HBKWIN,0,0);
				SysParameterCur.nHw1Status = 1;
				break;
		  }
		  break;
		case ID_BUTTON_4: // 网络设置按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				memset(WifiPasswordKeyBuf,0,30);
				memset(WifiNumKeyBuf,0,30);
				
//				GUI_EndDialog(pMsg->hWin, 0);
//				hItemCur = GUI_CreateDialogBox(_aDialogCreateWifiPage, GUI_COUNTOF(_aDialogCreateWifiPage), _cbDialogWifiPage, WM_HBKWIN, 0, 0);
//				SysParameterCur.nHw1Status = 1;


				SysParameterCur.nHw1Status = 1;
				GUI_EndDialog(pMsg->hWin, 0);
				WifiPadMode = WIFI_PAD_MODE_ABC;
				WifiPadAbcMode = WIFI_PAD_ABC_MDOE_1;
				GUI_CreateDialogBox(_aDialogCreateWifiPasswordPage, GUI_COUNTOF(_aDialogCreateWifiPasswordPage), _cbDialogWifiPasswordPage, WM_HBKWIN, 0, 0);			
				break;
		  }
		  break;
		 case ID_BUTTON_5: // 背景设置按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemCur = GUI_CreateDialogBox(_aDialogCreateBackRoundSetPage,GUI_COUNTOF(_aDialogCreateBackRoundSetPage),_cbDialogBackRoundSetPage,WM_HBKWIN,0,0);
				SysParameterCur.nHw1Status = 1;
				break;
		  }
		  break;
		
		}
		break;
	  default:
		WM_DefaultProc(pMsg);
  }
}

// 电池按钮
static void _cbButtonBatterySet(WM_MESSAGE * pMsg)
{
	unsigned short xendbuf;
	unsigned char pointdatabuf;
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(0X0057565A);
				GUI_Clear();
				// 电池
				if(BatteryDataCur.nBatteryStatus == 1)       // 充电
				{
					GUI_DrawBitmap(&bmbatterycharging,62,30);
				}
				
				if(BatteryDataCur.nBatteryData <= 10)       // 需要充电
					GUI_SetColor(GUI_RED);
				else
					GUI_SetColor(GUI_WHITE);

				pointdatabuf = (BatteryDataCur.nBatteryData * 4) % 10;
				
				xendbuf = 12 + (BatteryDataCur.nBatteryData * 40 / 100);
				if(pointdatabuf > 5) 
					xendbuf += 1;

				GUI_AA_FillRoundedRect(12,34,xendbuf,50,0);           // 电池电量

				GUI_PNG_Draw(acbatteryframe,sizeof(acbatteryframe),8,30);  // 电池轮廓
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 时间设置按钮
static void _cbButtonSysTimeSet(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				// 背景色
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();				

				// 白色框
				GUI_SetColor(GUI_WHITE);
				GUI_DrawRoundedRect(0,0,269,56,20);
				GUI_DrawRoundedRect(1,1,268,55,20);

				//GUI_SetFont(GUI_FONT_32_ASCII);
				//GUI_SetTextMode(GUI_TM_TRANS);
				//GUI_DispStringHCenterAt("timeset",135,15);
				GUI_PNG_Draw(actmbuttongj,sizeof(actmbuttongj),83,17);
				GUI_PNG_Draw(acshezhibuttongaoji,sizeof(acshezhibuttongaoji),140,17);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 网络设置按钮
static void _cbButtonSysNetSet(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				// 背景色
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();				

				// 白色框
				GUI_SetColor(GUI_WHITE);
				GUI_DrawRoundedRect(0,0,269,56,20);
				GUI_DrawRoundedRect(1,1,268,55,20);

				GUI_PNG_Draw(acnetbuttongj,sizeof(acnetbuttongj),83,17);
				GUI_PNG_Draw(acshezhibuttongaoji,sizeof(acshezhibuttongaoji),140,17);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 背景设置按钮
static void _cbButtonBlackRoundClSet(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				// 背景色
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();				

				// 白色框
				GUI_SetColor(GUI_WHITE);
				GUI_DrawRoundedRect(0,0,269,56,20);
				GUI_DrawRoundedRect(1,1,268,55,20);

				GUI_PNG_Draw(acbackgroundgj,sizeof(acbackgroundgj),83,17);
				GUI_PNG_Draw(acshezhibuttongaoji,sizeof(acshezhibuttongaoji),140,17);
				
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}


// 高级设置对话框设置界面
static void _cbDialogSetPage1(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
 
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowSetPage1);                  // 窗口

	// 标题栏
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 
    hItem = BUTTON_CreateAsChild(390,0,90,90,hItemHead,ID_BUTTON_6,WM_CF_SHOW);          // 创建按钮
	WM_SetCallback(hItem,_cbButtonBatterySet);

	// 按钮
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 时间设置按钮
	WM_SetCallback(hItem,_cbButtonSysTimeSet);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 网络设置按钮
	WM_SetCallback(hItem,_cbButtonSysNetSet);
	
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);       // 背景设置按钮
	WM_SetCallback(hItem,_cbButtonBlackRoundClSet);

	//hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);       // 电池设置按钮
	//WM_SetCallback(hItem,_cbButtonBatterySet);
	// 文本
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 连续检测
    TEXT_SetFont(hItem, &GUI_Fontfont_gaojiset);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "高级设置");

    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

// 数字键盘窗口回调函数
static void _cbWindowNumPadPage(WM_MESSAGE * pMsg)
{
	int      Pressed;
	int     NCode;
    int     Id;

	Pressed = 0;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_GRAY);
		GUI_Clear();

		// 画两个按键框
		GUI_SetColor(GUI_BLACK);
		GUI_AA_FillRoundedRect(1,1,395,57,3);
		GUI_AA_FillRoundedRect(1,286,118,358,5);

        GUI_SetColor(GUI_WHITE);
		GUI_AA_FillRoundedRect(2,2,394,56,3);
		GUI_AA_FillRoundedRect(2,287,117,357,5);


		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(NCode) {
			case WM_NOTIFICATION_CLICKED:
				if(Id == ID_BUTTON_7)
					break;
				Pressed = 1;
			case WM_NOTIFICATION_RELEASED:
				switch(Id) { 
				case ID_BUTTON_7:                         // 向下
					//GUI_EndDialog(pMsg->hWin, 0); 
					WM_HideWindow(hItemNumPad);
					break;
				case ID_BUTTON_8:                         // 1  
					GUI_SendKeyMsg('1', Pressed); 
					break;
				case ID_BUTTON_9:                         // 2  
					GUI_SendKeyMsg('2', Pressed); 
					break;
				case ID_BUTTON_10:                         // 3  
					GUI_SendKeyMsg('3', Pressed); 
					break;
				case ID_BUTTON_11:                         // 4  
					GUI_SendKeyMsg('4', Pressed); 
					break;
				case ID_BUTTON_12:                         // 5  
					GUI_SendKeyMsg('5', Pressed); 
					break;
				case ID_BUTTON_13:                         // 6  
					GUI_SendKeyMsg('6', Pressed); 
					break;
				case ID_BUTTON_14:                         // 7  
					GUI_SendKeyMsg('7', Pressed); 
					break;
				case ID_BUTTON_15:                         // 8  
					GUI_SendKeyMsg('8', Pressed); 
					break;
				case ID_BUTTON_16:                         // 9  
					GUI_SendKeyMsg('9', Pressed); 
					break;
				case ID_BUTTON_17:                         // 0  
					GUI_SendKeyMsg('0', Pressed); 
					break;
				case ID_BUTTON_18:                         // . 
					GUI_SendKeyMsg('.', Pressed); 
					break;
				case ID_BUTTON_19:                         // delete  
					GUI_SendKeyMsg(GUI_KEY_BACKSPACE, Pressed); 
					break;
				case ID_BUTTON_20:                         // enter
					// GUI_SendKeyMsg('1', Pressed); 
					break;
				}
				break;
		}
		
	  default:
		WM_DefaultProc(pMsg);
	}
}

// 向下按键回调函数
static void _cbButtonDown(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
				
			}
			else
			{
				GUI_SetBkColor(GUI_LIGHTGRAY);
				GUI_Clear();
				GUI_PNG_Draw(acdown,sizeof(acdown),16,5);
				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(1,0,80);
				GUI_DrawHLine(55,0,80);


				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(0,0,80);
				GUI_DrawHLine(56,0,80);
				GUI_DrawHLine(57,0,80);
				GUI_DrawVLine(0,0,58);
				GUI_DrawVLine(80,0,58);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 删除按键回调函数
static void _cbButtonDelete(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(GUI_LIGHTGRAY);
				GUI_Clear();
				GUI_PNG_Draw(acbackspace,sizeof(acbackspace),35,50);
				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(1,0,118);
				GUI_DrawHLine(145,0,118);
				GUI_DrawVLine(1,0,148);

				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(0,0,118);
				GUI_DrawHLine(146,0,118);
				GUI_DrawHLine(147,0,118);
				GUI_DrawVLine(0,0,148);
				GUI_DrawVLine(117,0,148);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 回车按键回调函数
static void _cbButtonEnter(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(GUI_LIGHTGRAY);
				GUI_Clear();
				GUI_PNG_Draw(acenter,sizeof(acenter),35,50);
				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(1,0,118);
				GUI_DrawHLine(145,0,118);
				GUI_DrawVLine(1,0,148);

				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(0,0,118);
				GUI_DrawHLine(146,0,118);
				GUI_DrawHLine(147,0,118);
				GUI_DrawVLine(0,0,148);
				GUI_DrawVLine(117,0,148);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 数字键盘对话框设置界面
static void _cbDialogNumPadPage(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  unsigned int i;
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowNumPadPage);                  // 窗口
    
	// 按键禁止输入焦点
	for(i = 0; i < ID_BUTTON_20 - ID_BUTTON_7 + 1; i++)
	{
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7 + i);
		BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,GUI_LIGHTGRAY);
		BUTTON_SetFont(hItem,GUI_FONT_32_ASCII);
		BUTTON_SetFocussable(hItem,0);
	}

	// 向下按键
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
	WM_SetCallback(hItem,_cbButtonDown);

	// 删除键
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_19);
	WM_SetCallback(hItem,_cbButtonDelete);

	// 回车键
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_20);
	WM_SetCallback(hItem,_cbButtonEnter);

    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}


// 参数密码窗口回调函数
static void _cbWindowPasswordPage(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(48,192,431,667,5);
		GUI_DrawRoundedRect(49,193,430,666,5);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemCur = GUI_CreateDialogBox(_aDialogCreateSetPage1, GUI_COUNTOF(_aDialogCreateSetPage1), _cbDialogSetPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 2;
				break;
			  case WM_NOTIFICATION_RELEASED:
			
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				GUI_EndDialog(hItemNumPad, 0); 
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_EDIT_0:
		  switch(NCode) {
			case WM_NOTIFICATION_CLICKED:               // 单击小工具 
			  
			  WM_ShowWindow(hItemNumPad);
			  EDIT_EnableBlink(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),500,1);
			  break;
			case WM_NOTIFICATION_VALUE_CHANGED:         // 编辑小工具的值已更改
		      EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(char *)SysParameterCur.password,10);
			  if(memcmp(SysParameterCur.password,passwordcmp,6) == 0)                         // 清除历史数据
			  {
			  	f_ClearListViewData();
				GUI_EndDialog(pMsg->hWin, 0);
				GUI_EndDialog(hItemNumPad, 0); 
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				f_SaveClearAllEn();
//				WM_HideWindow(hItemNumPad);
			  }
			  else if(memcmp(SysParameterCur.password,passwordSensorSetcmp,6) == 0)   // 参数设置
			  {
				  WM_HideWindow(hItemNumPad);
				  GUI_EndDialog(pMsg->hWin, 0);
				  hItemCur = GUI_CreateDialogBox(_aDialogCreateSensorSetPage, GUI_COUNTOF(_aDialogCreateSensorSetPage), _cbDialogSensorSetPage, WM_HBKWIN, 0, 0);
			  }
			  break;
			}
		  break;
	  default:
		WM_DefaultProc(pMsg);
	}
  }
}

// 参数密码界面对话框设置界面
static void _cbDialogPasswordPage(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowPasswordPage);                  // 窗口

	// 标题栏
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

	// 按钮
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);


	// 文本
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 参数设置
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "参数设置");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);          // 请输入密码
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_inpassword);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "请输入密码");

	// 编辑框
	hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);          // 编辑框
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
    EDIT_EnableBlink(hItem, 500, 1);
	EDIT_SetMaxLen(hItem,6);
	EDIT_SetTextAlign(hItem,GUI_TA_LEFT | GUI_TA_VCENTER);

    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

// 参数设置窗口回调函数
static void _cbWindowSensorSetPage(WM_MESSAGE * pMsg)
{
	int     NCode;
       int     Id;
	WM_HWIN hwinbuf;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(48,192,431,667,5);
		GUI_DrawRoundedRect(49,193,430,666,5);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemCur = GUI_CreateDialogBox(_aDialogCreatePasswordPage, GUI_COUNTOF(_aDialogCreatePasswordPage), _cbDialogPasswordPage, WM_HBKWIN, 0, 0);
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				GUI_EndDialog(hItemNumPad, 0); 
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_3: // 保存按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				hwinbuf = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
			  	if((EDIT_GetNumChars(hwinbuf) > 0) && (EDIT_GetNumChars(hwinbuf) <= 4))
			  	{
					memset(SensorSetPM2_5,0,4);
					EDIT_GetText(hwinbuf,(void *)SensorSetPM2_5,4);
			  	}
				else
				{
					SensorSetPM2_5[0] = f_AscToHex(SensorSetPM2_5Xs / 100);
					SensorSetPM2_5[1] = f_AscToHex((SensorSetPM2_5Xs % 100) / 10);
					SensorSetPM2_5[2] = f_AscToHex((SensorSetPM2_5Xs % 100) % 10);
				}

				hwinbuf = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);
				if((EDIT_GetNumChars(hwinbuf) > 0) && (EDIT_GetNumChars(hwinbuf) <= 4))
			  	{
					memset(SensorSetPM10,0,4);
					EDIT_GetText(hwinbuf,(void *)SensorSetPM10,4);
			  	}
				else
				{
					SensorSetPM10[0] = f_AscToHex(SensorSetPM10Xs / 100);
					SensorSetPM10[1] = f_AscToHex((SensorSetPM10Xs % 100) / 10);
					SensorSetPM10[2] = f_AscToHex((SensorSetPM10Xs % 100) % 10);
				}

				hwinbuf = WM_GetDialogItem(pMsg->hWin, ID_EDIT_4);
				if((EDIT_GetNumChars(hwinbuf) > 0) && (EDIT_GetNumChars(hwinbuf) <= 4))
			  	{
					memset(SensorSetTvoc,0,4);
					EDIT_GetText(hwinbuf,(void *)SensorSetTvoc,4);
			  	}
				else
				{
					SensorSetTvoc[0] = f_AscToHex(SensorSetTvocXs / 100);
					SensorSetTvoc[1] = f_AscToHex((SensorSetTvocXs % 100) / 10);
					SensorSetTvoc[2] = f_AscToHex((SensorSetTvocXs % 100) % 10);
				}

				f_PmSensorSetXsEn();

				GUI_EndDialog(pMsg->hWin, 0);
				GUI_EndDialog(hItemNumPad, 0); 
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_4: // 取消按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				GUI_EndDialog(hItemNumPad, 0); 
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_EDIT_0:  // PM2.5编辑框
		  switch(NCode) {
			case WM_NOTIFICATION_CLICKED:               // 单击小工具 
			  
			  WM_ShowWindow(hItemNumPad);
			  break;
			case WM_NOTIFICATION_VALUE_CHANGED:         // 编辑小工具的值已更改
		      
			  break;
			}
		  break;
		case ID_EDIT_1:  // PM10编辑框
		  switch(NCode) {
			case WM_NOTIFICATION_CLICKED:               // 单击小工具 
			  
			  WM_ShowWindow(hItemNumPad);
			  break;
			case WM_NOTIFICATION_VALUE_CHANGED:         // 编辑小工具的值已更改
		      
			  break;
			}
		  break;
		case ID_EDIT_2:  // 0.5um编辑框
		  switch(NCode) {
			case WM_NOTIFICATION_CLICKED:               // 单击小工具 
			  
			  WM_ShowWindow(hItemNumPad);
			  break;
			case WM_NOTIFICATION_VALUE_CHANGED:         // 编辑小工具的值已更改
		      
			  break;
			}
		  break;
		case ID_EDIT_3:  // 2.5um编辑框
		  switch(NCode) {
			case WM_NOTIFICATION_CLICKED:               // 单击小工具 
			  
			  WM_ShowWindow(hItemNumPad);
			  break;
			case WM_NOTIFICATION_VALUE_CHANGED:         // 编辑小工具的值已更改
		      
			  break;
			}
		  break;
		case ID_EDIT_4:  // TVOC编辑框
		  switch(NCode) {
			case WM_NOTIFICATION_CLICKED:               // 单击小工具 
			  
			  WM_ShowWindow(hItemNumPad);
			  break;
			case WM_NOTIFICATION_VALUE_CHANGED:         // 编辑小工具的值已更改
		      
			  break;
			}
		  break;
		case ID_EDIT_5:  // HCHO编辑框
		  switch(NCode) {
			case WM_NOTIFICATION_CLICKED:               // 单击小工具 
			  
			  WM_ShowWindow(hItemNumPad);
			  break;
			case WM_NOTIFICATION_VALUE_CHANGED:         // 编辑小工具的值已更改
		      
			  break;
			}
		  break;
		case ID_EDIT_6:  // CO2编辑框
		  switch(NCode) {
			case WM_NOTIFICATION_CLICKED:               // 单击小工具 
			  
			  WM_ShowWindow(hItemNumPad);
			  break;
			case WM_NOTIFICATION_VALUE_CHANGED:         // 编辑小工具的值已更改
		      
			  break;
			}
		  break;
	  default:
		WM_DefaultProc(pMsg);
	}
  }
}

// 参数设置界面对话框设置界面
static void _cbDialogSensorSetPage(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  unsigned char i;
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowSensorSetPage);              // 窗口

	// 标题栏
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

	// 按钮
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 保存按钮
	WM_SetCallback(hItem,_cbButtonSave);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 取消按钮
	WM_SetCallback(hItem,_cbButtonFault);

	// 文本
	for(i = 0;i < ID_TEXT_8 - ID_TEXT_1 + 1;i ++)
	{
		if(i == 0)         // 参数设置
		{
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 参数设置
			TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
			TEXT_SetTextColor(hItem,GUI_WHITE);
			TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
			TEXT_SetText(hItem, "参数设置");
		}
		else if(i == 6)   // 甲醛
		{
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);       // 参数设置
			TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
			TEXT_SetTextColor(hItem,GUI_WHITE);
			TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
			TEXT_SetText(hItem, "甲   醛");
		}
		else
		{
			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1 + i);          // 参数设置
			TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
			TEXT_SetTextColor(hItem,GUI_WHITE);
			TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
			TEXT_SetText(hItem, (char *)(*(sensorsettext + i)));
		}
	}
	
   
	// 编辑框
	for(i = 0; i < ID_EDIT_6 - ID_EDIT_0 + 1;i ++)
	{
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0 + i);          // 编辑框
		EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
		//EDIT_EnableBlink(hItem, 500, 1);
		EDIT_SetMaxLen(hItem,3);
		EDIT_SetTextAlign(hItem,GUI_TA_LEFT | GUI_TA_VCENTER);
	}

    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

// 时间设置界面窗口回调函数
static void _cbWindowSetTime(WM_MESSAGE * pMsg)
{
       int     NCode;
       int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		//f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

		// 时间设置
		//GUI_PNG_Draw(actmsetgj,sizeof(actmsetgj),65,133);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(48,192,431,492,5);
		GUI_DrawRoundedRect(49,193,430,491,5);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemCur = GUI_CreateDialogBox(_aDialogCreateSetPage1, GUI_COUNTOF(_aDialogCreateSetPage1), _cbDialogSetPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 2;
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_3: // 保存按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				f_SysRtcSetEn();
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_4: // 取消按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_LISTWHEEL_0:            // 年
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				RTC_DateStructureSet.RTC_Year = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0));
				break;
		  }
		  break;
		case ID_LISTWHEEL_1:            // 月
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				RTC_DateStructureSet.RTC_Month = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_1)) + 1;
				break;
		  }
		  break;
		case ID_LISTWHEEL_2:            // 日
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				RTC_DateStructureSet.RTC_Date = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_2)) + 1;
				break;
		  }
		  break;
		 case ID_LISTWHEEL_3:            // 时
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				RTC_TimeStructureSet.RTC_Hours = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_3));
				RTC_TimeStructureSet.RTC_Seconds = 0;
				break;
		  }
		  break;
		case ID_LISTWHEEL_4:            // 分
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				RTC_TimeStructureSet.RTC_Minutes = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_4));
				RTC_TimeStructureSet.RTC_Seconds = 0;
				break;
		  }
		  break;
	  default:
		WM_DefaultProc(pMsg);
	}
  }
}

/*********************************************************************
*
*       时间设置自汇函数
*/
static int _OwnerDrawSetTime(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  WM_HWIN   hWin;
  WHEEL   * pWheel;
  int       xPos;
  int       yPos;
  int       xSizeWin;
  int       ySizeWin;
  int       xSizeDev;

  hWin = pDrawItemInfo->hWin;
  //
  // Process messages
  //
  switch (pDrawItemInfo->Cmd) {
  case WIDGET_ITEM_GET_XSIZE:
    //
    // Return x-size of item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_GET_YSIZE:
    //
    // Return y-size of item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_DRAW:
    //
    // Draw item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_DRAW_BACKGROUND:
    xSizeWin = WM_GetWindowSizeX(hWin);
    ySizeWin = WM_GetWindowSizeY(hWin);
    //
    // Draw background
    //
    GUI_SetColor(SysParameterCur.BackgroundClor);
    GUI_FillRect(0, 0, xSizeWin, ySizeWin);

    GUI_SetColor(GUI_GRAY);
    GUI_FillRect(0,(ySizeWin / 2) - (36 / 2),xSizeWin,(ySizeWin / 2) + (35 / 2));
    break;
  case WIDGET_ITEM_DRAW_OVERLAY:
    LISTWHEEL_GetUserData(hWin, &pWheel, sizeof(pWheel));
    xPos     = WM_GetWindowOrgX(hWin);
    yPos     = WM_GetWindowOrgY(hWin);
    xSizeWin = WM_GetWindowSizeX(hWin);
    xSizeDev = GUI_MEMDEV_GetXSize(pWheel->hMemRBorder);
    //
    // Draw border
    //
    GUI_MEMDEV_WriteAt(pWheel->hMemLBorder, xPos, yPos);
    GUI_MEMDEV_WriteAt(pWheel->hMemRBorder, xPos + xSizeWin - xSizeDev, yPos);
    //
    // Draw overlay
    //
    GUI_MEMDEV_WriteAt(pWheel->hMemOverlay, xPos, yPos);
    break;
  }
  return 0;
}

// 时间设置对话框设置界面
static void _cbDialogSetTimePage(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  unsigned char i;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowSetTime);                  // 窗口

	// 标题栏
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

	// 按钮
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 保存按钮
	WM_SetCallback(hItem,_cbButtonSave);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 取消按钮
	WM_SetCallback(hItem,_cbButtonFault);

	// 文本
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 连续检测
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "时间设置");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);         // 年
	TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
    TEXT_SetText(hItem, "年");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);         // 月
	TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
    TEXT_SetText(hItem, "月");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);         // 日
	TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
    TEXT_SetText(hItem, "日");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);         // 时
	TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
    TEXT_SetText(hItem, "时");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);         // 分
	TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
    TEXT_SetText(hItem, "分");

	// 车轮参数设置
	// 年
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);  // 2000 ~ 2099
    LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTime);
	_aWheelpostTimeSet = &_aWheelTimeSet[0];
    LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSet, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetYearTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetYearTimeWheelData + i)));
	}
	LISTWHEEL_MoveToPos(hItem,RTC_DateStruct.RTC_Year);
	RTC_DateStructureSet.RTC_Year = RTC_DateStruct.RTC_Year;

	// 月
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_1);  // 1 - 12
    LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTime);
	_aWheelpostTimeSet = &_aWheelTimeSet[1];
    LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSet, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetMonTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetMonTimeWheelData + i)));
	}
	LISTWHEEL_MoveToPos(hItem,RTC_DateStruct.RTC_Month - 1);
	RTC_DateStructureSet.RTC_Month = RTC_DateStruct.RTC_Month;
	
	// 日
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_2);  // 1 - 31
       LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTime);
	_aWheelpostTimeSet = &_aWheelTimeSet[2];
       LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSet, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetDayTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetDayTimeWheelData + i)));
	}
	LISTWHEEL_MoveToPos(hItem,RTC_DateStruct.RTC_Date - 1);
	RTC_DateStructureSet.RTC_Date = RTC_DateStruct.RTC_Date;

	// 时
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_3);  // 1 - 23
    LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTime);
	_aWheelpostTimeSet = &_aWheelTimeSet[3];
    LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSet, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetHourTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetHourTimeWheelData + i)));
	}
	LISTWHEEL_MoveToPos(hItem,RTC_TimeStruct.RTC_Hours);
	RTC_TimeStructureSet.RTC_Hours = RTC_TimeStruct.RTC_Hours;

	// 分
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_4);  // 0 - 59
    LISTWHEEL_SetFont(hItem,GUI_FONT_24_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDrawSetTime);
	_aWheelpostTimeSet = &_aWheelTimeSet[4];
    LISTWHEEL_SetUserData(hItem, &_aWheelpostTimeSet, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < GUI_COUNTOF(SetMinTimeWheelData);i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(SetMinTimeWheelData + i)));
	}
	LISTWHEEL_MoveToPos(hItem,RTC_TimeStruct.RTC_Minutes);
	RTC_TimeStructureSet.RTC_Minutes = RTC_TimeStruct.RTC_Minutes;

	RTC_TimeStructureSet.RTC_Seconds = RTC_TimeStruct.RTC_Seconds;

    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

// 背景设置界面窗口回调函数
static void _cbWindowBackRoundSet(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	unsigned char GetCheckBoxValue;
	//unsigned char GetSliderValue;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		//f_HeadStatusDis();

		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(64,190,418,287,5);
		GUI_DrawRoundedRect(65,191,417,286,5);

//		GUI_PNG_Draw(acbackgroundset,sizeof(acbackgroundset),64,133);    // 背景

//		GUI_PNG_Draw(acbrightset,sizeof(acbrightset),63,313);            // 亮度

//		GUI_PNG_Draw(acsleepset,sizeof(acsleepset),63,440);              // 休眠时间

		GUI_PNG_Draw(acchangliang,sizeof(acchangliang),366,544);         // 常亮

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);

		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
		  	BrightDataCur.SysBkBrightStep = BrightDataCur.SysBkBrightStepLast;
			SysParameterCur.BackgroundClor = SysParameterCur.BackgroundClorLast;
			GUI_EndDialog(pMsg->hWin, 0);
			hItemCur = GUI_CreateDialogBox(_aDialogCreateSetPage1, GUI_COUNTOF(_aDialogCreateSetPage1), _cbDialogSetPage1, WM_HBKWIN, 0, 0);
			SysParameterCur.nHw1Status = 2;
			break;
		  case WM_NOTIFICATION_RELEASED:
			
			break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
		  	BrightDataCur.SysBkBrightStep = BrightDataCur.SysBkBrightStepLast;
			SysParameterCur.BackgroundClor = SysParameterCur.BackgroundClorLast;
			GUI_EndDialog(pMsg->hWin, 0);
			hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
			SysParameterCur.nHw1Status = 0;
			break;
		  case WM_NOTIFICATION_RELEASED:
			
			break;
		  }
		case ID_BUTTON_3: // 保存按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
        
			break;
		  case WM_NOTIFICATION_RELEASED:
			BrightDataCur.SysBkSleepMode = BrightDataCur.SysBkSleepModeLast;
			f_BrightSleepClear();
			GUI_EndDialog(pMsg->hWin, 0);
			hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
			SysParameterCur.nHw1Status = 0;
			break;
		  }
		  break;
		case ID_BUTTON_4: // 取消按钮
		  switch(NCode) {
		  case WM_NOTIFICATION_CLICKED:
        
			break;
		  case WM_NOTIFICATION_RELEASED:
		  	BrightDataCur.SysBkBrightStep = BrightDataCur.SysBkBrightStepLast;
			SysParameterCur.BackgroundClor = SysParameterCur.BackgroundClorLast;
		  	GUI_EndDialog(pMsg->hWin, 0);
			hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
			SysParameterCur.nHw1Status = 0;
			break;
		  }
		case ID_CHCKBOX_1:   // 背景1
			switch(NCode) {
			case WM_NOTIFICATION_VALUE_CHANGED:
				GetCheckBoxValue = CHECKBOX_GetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_1));
				if(GetCheckBoxValue == 1)
				{
					SysParameterCur.BackgroundClor = BACKGROUND_COLOR_1;
					WM_InvalidateWindow(pMsg->hWin);
					WM_InvalidateWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3));
					WM_InvalidateWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4));
					CHECKBOX_SetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_2),0);
					CHECKBOX_SetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_3),0);
				}
				break;
			case WM_NOTIFICATION_RELEASED:

				break;
			}
			
		  break;
		case ID_CHCKBOX_2:   // 背景2
		    switch(NCode) {
			case WM_NOTIFICATION_VALUE_CHANGED:
				GetCheckBoxValue = CHECKBOX_GetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_2));
				if(GetCheckBoxValue == 1)
				{
					SysParameterCur.BackgroundClor = BACKGROUND_COLOR_2;
					WM_InvalidateWindow(pMsg->hWin);
					WM_InvalidateWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3));
					WM_InvalidateWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4));
					CHECKBOX_SetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_1),0);
					CHECKBOX_SetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_3),0);
				}
				break;
			case WM_NOTIFICATION_RELEASED:

				break;
			}
			
		  break;
		case ID_CHCKBOX_3:   // 背景3
		    switch(NCode) {
			case WM_NOTIFICATION_VALUE_CHANGED:
				GetCheckBoxValue = CHECKBOX_GetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_3));
				if(GetCheckBoxValue == 1)
				{
					SysParameterCur.BackgroundClor = BACKGROUND_COLOR_3;
					WM_InvalidateWindow(pMsg->hWin);
					WM_InvalidateWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3));
					WM_InvalidateWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4));
					CHECKBOX_SetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_1),0);
					CHECKBOX_SetState(WM_GetDialogItem(pMsg->hWin,ID_CHCKBOX_2),0);
				}
				break;
			case WM_NOTIFICATION_RELEASED:

				break;
			}
			
		  break;
		case ID_SLIDER_1:             // 亮度
			switch(NCode){
			case WM_NOTIFICATION_RELEASED:   // 已释放
				BrightDataCur.SysBkBrightStep = SLIDER_GetValue(WM_GetDialogItem(pMsg->hWin,ID_SLIDER_1)) + 1;
				break;
			}
			break;
		case ID_SLIDER_2:            // 休眠时间
			switch(NCode){
			case WM_NOTIFICATION_RELEASED:   // 已释放
				BrightDataCur.SysBkSleepModeLast = SLIDER_GetValue(WM_GetDialogItem(pMsg->hWin,ID_SLIDER_2));
				break;
			}
			break;
	  default:
		WM_DefaultProc(pMsg);
	}
  }
}

// 背景色1选择控件自绘函数
static int _DrawSkinFlexBackground1(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  int xstart,xend;
  int ystart,yend;

  xstart = pDrawItemInfo->x0;
  ystart = pDrawItemInfo->y0;
  xend = pDrawItemInfo->x1;
  yend = pDrawItemInfo->y1;

  switch (pDrawItemInfo->Cmd) {
  //case WIDGET_ITEM_DRAW_BACKGROUND:
  case WIDGET_ITEM_DRAW_BUTTON:
	GUI_SetBkColor(SysParameterCur.BackgroundClor);
	GUI_Clear();
	GUI_SetColor(GUI_WHITE);
	GUI_AA_FillRoundedRect(xstart + 1,ystart + 1, xend - 1, yend - 1, 10);
	GUI_SetColor(BACKGROUND_COLOR_1);
	GUI_AA_FillRoundedRect(xstart + 3,ystart + 3, xend - 3, yend - 3, 10);

    return 0;
  case WIDGET_ITEM_DRAW_FOCUS:
	//GUI_SetColor(GUI_GREEN);
	//GUI_DrawRect(pDrawItemInfo->x0,pDrawItemInfo->y0, pDrawItemInfo->x1, pDrawItemInfo->y1);
	return 0;
  case WIDGET_ITEM_DRAW_BITMAP:
	GUI_SetColor(GUI_BLACK);
	GUI_DrawRect(pDrawItemInfo->x0,pDrawItemInfo->y0, pDrawItemInfo->x1, pDrawItemInfo->y1);
	GUI_DrawRect(pDrawItemInfo->x0 + 1,pDrawItemInfo->y0 + 1, pDrawItemInfo->x1 - 1, pDrawItemInfo->y1 - 1);
	return 0;
  default:
    return SLIDER_DrawSkinFlex(pDrawItemInfo);
  }
}

// 背景色2选择控件自绘函数
static int _DrawSkinFlexBackground2(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  int xstart,xend;
  int ystart,yend;

  xstart = pDrawItemInfo->x0;
  ystart = pDrawItemInfo->y0;
  xend = pDrawItemInfo->x1;
  yend = pDrawItemInfo->y1;

  switch (pDrawItemInfo->Cmd) {
  //case WIDGET_ITEM_DRAW_BACKGROUND:
  case WIDGET_ITEM_DRAW_BUTTON:
	GUI_SetBkColor(SysParameterCur.BackgroundClor);
	GUI_Clear();
	GUI_SetColor(GUI_WHITE);
	GUI_AA_FillRoundedRect(xstart + 1,ystart + 1, xend - 1, yend - 1, 10);
	GUI_SetColor(BACKGROUND_COLOR_2);
	GUI_AA_FillRoundedRect(xstart + 3,ystart + 3, xend - 3, yend - 3, 10);

    return 0;
  case WIDGET_ITEM_DRAW_FOCUS:
	//GUI_SetColor(GUI_GREEN);
	//GUI_DrawRect(pDrawItemInfo->x0,pDrawItemInfo->y0, pDrawItemInfo->x1, pDrawItemInfo->y1);
	return 0;
  case WIDGET_ITEM_DRAW_BITMAP:
	GUI_SetColor(GUI_BLACK);
	GUI_DrawRect(pDrawItemInfo->x0,pDrawItemInfo->y0, pDrawItemInfo->x1, pDrawItemInfo->y1);
	GUI_DrawRect(pDrawItemInfo->x0 + 1,pDrawItemInfo->y0 + 1, pDrawItemInfo->x1 - 1, pDrawItemInfo->y1 - 1);
	return 0;
  default:
    return SLIDER_DrawSkinFlex(pDrawItemInfo);
  }
}

// 背景色3选择控件自绘函数
static int _DrawSkinFlexBackground3(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  int xstart,xend;
  int ystart,yend;

  xstart = pDrawItemInfo->x0;
  ystart = pDrawItemInfo->y0;
  xend = pDrawItemInfo->x1;
  yend = pDrawItemInfo->y1;

  switch (pDrawItemInfo->Cmd) {
  //case WIDGET_ITEM_DRAW_BACKGROUND:
  case WIDGET_ITEM_DRAW_BUTTON:
	GUI_SetBkColor(SysParameterCur.BackgroundClor);
	GUI_Clear();
	GUI_SetColor(GUI_WHITE);
	GUI_AA_FillRoundedRect(xstart + 1,ystart + 1, xend - 1, yend - 1, 10);
	GUI_SetColor(BACKGROUND_COLOR_3);
	GUI_AA_FillRoundedRect(xstart + 3,ystart + 3, xend - 3, yend - 3, 10);

    return 0;
  case WIDGET_ITEM_DRAW_FOCUS:
	//GUI_SetColor(GUI_GREEN);
	//GUI_DrawRect(pDrawItemInfo->x0,pDrawItemInfo->y0, pDrawItemInfo->x1, pDrawItemInfo->y1);
	return 0;
  case WIDGET_ITEM_DRAW_BITMAP:
	GUI_SetColor(GUI_BLACK);
	GUI_DrawRect(pDrawItemInfo->x0,pDrawItemInfo->y0, pDrawItemInfo->x1, pDrawItemInfo->y1);
	GUI_DrawRect(pDrawItemInfo->x0 + 1,pDrawItemInfo->y0 + 1, pDrawItemInfo->x1 - 1, pDrawItemInfo->y1 - 1);
	return 0;
  default:
    return SLIDER_DrawSkinFlex(pDrawItemInfo);
  }
}

// 亮度调节控件自绘
static int _DrawSkinFlexBrightSet(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  //int x;
  int y;

  switch (pDrawItemInfo->Cmd) {
  case WIDGET_ITEM_DRAW_THUMB:
    GUI_SetColor(GUI_WHITE);
    GUI_AA_FillRoundedRect(pDrawItemInfo->x0, pDrawItemInfo->y0, pDrawItemInfo->x1, pDrawItemInfo->y1, 3);
	GUI_SetColor(GUI_BLACK);
	GUI_AA_DrawRoundedRect(pDrawItemInfo->x0, pDrawItemInfo->y0, pDrawItemInfo->x1, pDrawItemInfo->y1, 3);
    return 0;
  case WIDGET_ITEM_DRAW_TICKS:
    return 0;
  case WIDGET_ITEM_DRAW_FOCUS:
    return 0;
  case WIDGET_ITEM_DRAW_SHAFT:

	//x = (pDrawItemInfo->x1 - pDrawItemInfo->x0) / 2;
	y = (pDrawItemInfo->y1 - pDrawItemInfo->y0) / 2;

	//GUI_SetColor(GUI_LIGHTGRAY);
	GUI_SetColor(GUI_WHITE);
	GUI_AA_FillRoundedRect(16,y - 2,43,y + 2,2);
	GUI_AA_FillRoundedRect(71,y - 2,97,y + 2,2);
	GUI_AA_FillRoundedRect(125,y - 2,150,y + 2,2);
	GUI_AA_FillRoundedRect(178,y - 2,203,y + 2,2);
	GUI_AA_FillRoundedRect(231,y - 2,256,y + 2,2);
	GUI_AA_FillRoundedRect(284,y - 2,310,y + 2,2);
	

	GUI_AA_FillRoundedRect(2,pDrawItemInfo->y0 + 4,6,pDrawItemInfo->y1 - 4,2);
	GUI_AA_FillRoundedRect(55,pDrawItemInfo->y0 + 8,59,pDrawItemInfo->y1 - 8,2);
	GUI_AA_FillRoundedRect(109,pDrawItemInfo->y0 + 8,113,pDrawItemInfo->y1 - 8,2);
	GUI_AA_FillRoundedRect(162,pDrawItemInfo->y0 + 8,166,pDrawItemInfo->y1 - 8,2);
	GUI_AA_FillRoundedRect(215,pDrawItemInfo->y0 + 8,219,pDrawItemInfo->y1 - 8,2);
	GUI_AA_FillRoundedRect(268,pDrawItemInfo->y0 + 8,272,pDrawItemInfo->y1 - 8,2);
	GUI_AA_FillRoundedRect(322,pDrawItemInfo->y0 + 4,326,pDrawItemInfo->y1 - 4,2);

    return 0;
  default:
    return SLIDER_DrawSkinFlex(pDrawItemInfo);
  }
}

// 熄屏时间调节控件自绘
static int _DrawSkinFlexTimeSet(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  int x;
  int y;

  switch (pDrawItemInfo->Cmd) {
  case WIDGET_ITEM_DRAW_THUMB:
	x = (pDrawItemInfo->x1 - pDrawItemInfo->x0) / 2;
	y = (pDrawItemInfo->y1 - pDrawItemInfo->y0) / 2;

	GUI_SetColor(GUI_GRAY);
	GUI_AA_FillCircle(pDrawItemInfo->x0 + x, y, 15);

	GUI_SetColor(GUI_LIGHTGRAY);
	GUI_AA_FillCircle(pDrawItemInfo->x0 + x, y, 14);
	GUI_AA_FillCircle(pDrawItemInfo->x0 + x, y, 13);
	GUI_AA_FillCircle(pDrawItemInfo->x0 + x, y, 12);

	GUI_SetColor(GUI_WHITE);
    GUI_AA_FillCircle(pDrawItemInfo->x0 + x, y, 11);

    return 0;
  case WIDGET_ITEM_DRAW_TICKS:
    return 0;
  case WIDGET_ITEM_DRAW_FOCUS:
    return 0;
  case WIDGET_ITEM_DRAW_SHAFT:

	x = (pDrawItemInfo->x1 - pDrawItemInfo->x0) / 2;
	y = (pDrawItemInfo->y1 - pDrawItemInfo->y0) / 2;

	//GUI_SetColor(GUI_LIGHTGRAY);
	GUI_SetColor(GUI_WHITE);
	GUI_AA_FillRoundedRect(0,y - 2,pDrawItemInfo->x1,y + 2,2);
	
	GUI_AA_FillCircle(20, 18, 10);
	GUI_AA_FillCircle(92, 18, 10);
	GUI_AA_FillCircle(164, 18, 10);
	GUI_AA_FillCircle(236, 18, 10);
	GUI_AA_FillCircle(308, 18, 10);
	

    return 0;
  default:
    return SLIDER_DrawSkinFlex(pDrawItemInfo);
  }
}

// 背景设置对话框设置界面
static void _cbDialogBackRoundSetPage(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowBackRoundSet);

	// 标题栏
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 
	
    // 按钮
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 保存按钮
	WM_SetCallback(hItem,_cbButtonSave);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 取消按钮
	WM_SetCallback(hItem,_cbButtonFault);

	// CHECKBOX
	SysParameterCur.BackgroundClorLast = SysParameterCur.BackgroundClor;
	hItem = WM_GetDialogItem(pMsg->hWin, ID_CHCKBOX_1);      // 背景色1选择
	CHECKBOX_SetSkin(hItem,_DrawSkinFlexBackground1);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_CHCKBOX_2);      // 背景色2选择
	CHECKBOX_SetSkin(hItem,_DrawSkinFlexBackground2);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_CHCKBOX_3);      // 背景色3选择
	CHECKBOX_SetSkin(hItem,_DrawSkinFlexBackground3);

	// 滑块
       hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_1);       // 亮度调节
	SLIDER_SetSkin(hItem,_DrawSkinFlexBrightSet);
	SLIDER_SetRange(hItem, 0, 6);
	SLIDER_SetValue(hItem,BrightDataCur.SysBkBrightStep - 1);
	BrightDataCur.SysBkBrightStepLast = BrightDataCur.SysBkBrightStep;
//	WM_SetFocus(hItem);
		
	hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_2);       // 熄屏时间调节
	SLIDER_SetSkin(hItem,_DrawSkinFlexTimeSet);
	SLIDER_SetRange(hItem, 0, 4);
	SLIDER_SetWidth(hItem,40);
	SLIDER_SetValue(hItem,BrightDataCur.SysBkSleepMode);

	BrightDataCur.SysBkSleepModeLast = BrightDataCur.SysBkSleepMode;

	// ID_TEXT
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 背景
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "背景");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);       // 亮度
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "亮度");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);       // 休眠时间
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "休眠时间");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);         // 1m 2m 5m 10m 
	TEXT_SetFont(hItem, GUI_FONT_24_ASCII);
	TEXT_SetTextColor(hItem,GUI_WHITE);
    TEXT_SetText(hItem, "1m        2m       5m       10m");
	
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}


// 历史数据列表界面窗口回调函数
static void _cbWindowRecordPage(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		//f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(10,150,470,690,5);
		GUI_DrawRoundedRect(11,151,469,689,5);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_LISTVIEW_1:
			switch(NCode) {
				case WM_NOTIFICATION_SEL_CHANGED:
					
					break;
				case WM_NOTIFICATION_RELEASED:
					
					break;
			}
			break;
		}
		break;
	  default:
		WM_DefaultProc(pMsg);
  }
}


// 历史数据列表对话框界面
static void _cbDialogRecordPage(WM_MESSAGE * pMsg) {
  unsigned char i;
  WM_HWIN hItem;

  
  switch (pMsg->MsgId) {
    case WM_INIT_DIALOG:
	  // 窗口
      hItem = pMsg->hWin;
	  WM_SetCallback(hItem,_cbWindowRecordPage);                  // 窗口

	  // 标题栏
	  hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 
	  
	  // 按键
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	  WM_SetCallback(hItem,_cbButtonBack);
    
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
      WM_SetCallback(hItem,_cbButtonBackMain);

	  // listview
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_1);

	  WIDGET_SetEffect(hItem,&WIDGET_Effect_None);
	  WIDGET_SetEffect(LISTVIEW_GetHeader(hItem),&WIDGET_Effect_None);

	  HEADER_SetFont(LISTVIEW_GetHeader(hItem),&GUI_Fontfont_yh_record);
	  HEADER_SetTextColor(LISTVIEW_GetHeader(hItem),GUI_WHITE);
	  HEADER_SetBkColor(LISTVIEW_GetHeader(hItem),GUI_LIGHTBLUE);
	  //LISTVIEW_SetDefaultBkColor(LISTVIEW_CI_SELFOCUS,GUI_LIGHTRED);
 
	  LISTVIEW_AddColumn(hItem, 100, "序号",         GUI_TA_HCENTER | GUI_TA_VCENTER);
	  LISTVIEW_AddColumn(hItem, 100, "时间",         GUI_TA_HCENTER | GUI_TA_VCENTER);
	  LISTVIEW_AddColumn(hItem, 100, "PM2.5",            GUI_TA_HCENTER | GUI_TA_VCENTER);
	  LISTVIEW_AddColumn(hItem, 100, "PM10",             GUI_TA_HCENTER | GUI_TA_VCENTER);
	  LISTVIEW_AddColumn(hItem, 100, "TVOC",             GUI_TA_HCENTER | GUI_TA_VCENTER);
	  LISTVIEW_AddColumn(hItem, 100, "甲醛",          GUI_TA_HCENTER | GUI_TA_VCENTER);
	  LISTVIEW_AddColumn(hItem, 100, "CO2",               GUI_TA_HCENTER | GUI_TA_VCENTER);
	  
	  LISTVIEW_SetAutoScrollH(hItem,1);
	  LISTVIEW_SetAutoScrollV(hItem,1);
	  LISTVIEW_SetBkColor(hItem,LISTVIEW_CI_UNSEL,GUI_WHITE);
	  LISTVIEW_SetHeaderHeight(hItem,30);
	  LISTVIEW_SetGridVis(hItem,1);

	  
	  LISTVIEW_SetFont(hItem,GUI_FONT_24_ASCII);
	  LISTVIEW_SetTextAlign(hItem,1,GUI_TA_HCENTER | GUI_TA_VCENTER);
	  LISTVIEW_SetRowHeight(hItem,60);

         for(i = 0;i < 50;i ++)
	  {
	  	if(*listviewbuf[i][0] == '\n')
			break;
		LISTVIEW_AddRow(hItem, (void *)listviewbuf[i]);
         }
	  

	  // 文本
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 连续检测
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "历史数据");
	
      break;
    default:
      WM_DefaultProc(pMsg);
  }
}

// 检测时间设置界面窗口回调函数
static void _cbWindowCkTimeSet(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		//f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);
		GUI_FillRect(0,100,480,695);
		
		// 连续检测
		//GUI_PNG_Draw(aclianxuck,sizeof(aclianxuck),64,132);

		// 白色框
		GUI_SetColor(GUI_WHITE);
		GUI_DrawRoundedRect(48,192,431,492,5);
		GUI_DrawRoundedRect(49,193,430,491,5);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_3: // 保存按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				SysParameterCur.SysSensorCkTm = SysParameterCur.SysSensorCkTmMemory;
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_4: // 取消按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_LISTWHEEL_0:            // 滚轮参数设置
		  switch(NCode){
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				SysParameterCur.SysSensorCkTmMemory = LISTWHEEL_GetPos(WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0)) + 1;    // 获取索引项
				break;
		  }
		  break;
	  default:
		WM_DefaultProc(pMsg);
	}
  }
}


/*********************************************************************
*
*       _OwnerDraw
*/
static int _OwnerDraw(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo) {
  WM_HWIN   hWin;
  WHEEL   * pWheel;
  int       xPos;
  int       yPos;
  int       xSizeWin;
  int       ySizeWin;
  int       xSizeDev;

  hWin = pDrawItemInfo->hWin;
  //
  // Process messages
  //
  switch (pDrawItemInfo->Cmd) {
  case WIDGET_ITEM_GET_XSIZE:
    //
    // Return x-size of item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_GET_YSIZE:
    //
    // Return y-size of item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_DRAW:
    //
    // Draw item
    //
    return LISTWHEEL_OwnerDraw(pDrawItemInfo);
  case WIDGET_ITEM_DRAW_BACKGROUND:
    xSizeWin = WM_GetWindowSizeX(hWin);
    ySizeWin = WM_GetWindowSizeY(hWin);
    //
    // Draw background
    //
    GUI_SetColor(SysParameterCur.BackgroundClor);
    GUI_FillRect(0, 0, xSizeWin, ySizeWin);

    GUI_SetColor(GUI_GRAY);
    GUI_FillRect(0,(ySizeWin / 2) - (36 / 2),xSizeWin,(ySizeWin / 2) + (35 / 2));
    break;
  case WIDGET_ITEM_DRAW_OVERLAY:
    LISTWHEEL_GetUserData(hWin, &pWheel, sizeof(pWheel));
    xPos     = WM_GetWindowOrgX(hWin);
    yPos     = WM_GetWindowOrgY(hWin);
    xSizeWin = WM_GetWindowSizeX(hWin);
    xSizeDev = GUI_MEMDEV_GetXSize(pWheel->hMemRBorder);
    //
    // Draw border
    //
    GUI_MEMDEV_WriteAt(pWheel->hMemLBorder, xPos, yPos);
    GUI_MEMDEV_WriteAt(pWheel->hMemRBorder, xPos + xSizeWin - xSizeDev, yPos);
    //
    // Draw overlay
    //
    GUI_MEMDEV_WriteAt(pWheel->hMemOverlay, xPos, yPos);
    break;
  }
  return 0;
}


// 检测时间设置对话框设置界面
static void _cbDialogCkTimeSet(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  unsigned char i;
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
	
	// 窗口
    hItem = pMsg->hWin;
	WM_SetCallback(hItem,_cbWindowCkTimeSet);                  // 窗口

	// 标题栏
	hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

	// 按钮
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	WM_SetCallback(hItem,_cbButtonBack);
    
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
	WM_SetCallback(hItem,_cbButtonBackMain);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 保存按钮
	WM_SetCallback(hItem,_cbButtonSave);

	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 取消按钮
	WM_SetCallback(hItem,_cbButtonFault);

	// 文本
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // 连续检测
    TEXT_SetFont(hItem, &GUI_Fontfont_yh_set);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "连续检测");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);       // 每
    TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "每");

	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);       // 分钟检测一次
    TEXT_SetFont(hItem, &GUI_Fontfong_yh_time);
	TEXT_SetTextColor(hItem,GUI_WHITE);
	TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
    TEXT_SetText(hItem, "分钟    检测一次");

	// 车轮参数设置
	hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTWHEEL_0);  // 1 ~ 60
    LISTWHEEL_SetFont(hItem,GUI_FONT_32_ASCII);
	LISTWHEEL_SetTextAlign(hItem,GUI_TA_VCENTER | GUI_TA_HCENTER);
	LISTWHEEL_SetSnapPosition(hItem, (270 - 35) / 2);
	LISTWHEEL_SetOwnerDraw(hItem, _OwnerDraw);
	_aWheelpost = &_aWheel;
    LISTWHEEL_SetUserData(hItem, &_aWheelpost, 4);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_UNSEL,GUI_WHITE);
	LISTWHEEL_SetTextColor(hItem,LISTWHEEL_CI_SEL,GUI_WHITE);
	LISTWHEEL_SetLineHeight(hItem,35);
	
	for(i = 0; i < 60;i ++)
	{
		LISTWHEEL_AddString(hItem,(char *)(*(CkTimeWheelData + i)));
	}
	LISTWHEEL_MoveToPos(hItem,SysParameterCur.SysSensorCkTm - 1);
	
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

// PM2.5界面窗口回调函数
static void _cbWindowPM2_5Page(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(SysParameterCur.BackgroundClor);    // PM2.5颗粒物
		GUI_FillRect(0,100,480,394);

		GUI_SetColor(SysParameterCur.BackgroundClor);    // PM2.5浓度
		GUI_FillRect(0,399,480,695);


		// PM2.5颗粒物
		GUI_GotoXY(240,247);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(GUI_FONT_D48);
		GUI_DispDecMin(SensorPM2_5DataCur.Pm2_5DustCur);
		
		// PM2.5浓度
		GUI_GotoXY(240,547);
		GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispFloatMin(SensorPM2_5DataCur.Pm2_5DataCur,2);


		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(Id) {
    
		case ID_BUTTON_1: // 返回按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_2: // 返回主界面按钮
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
				SysParameterCur.nHw1Status = 0;
				break;
		  }
		  break;
		case ID_BUTTON_3: // 开始停止
		  switch(NCode) {
			  case WM_NOTIFICATION_CLICKED:
        
				break;
			  case WM_NOTIFICATION_RELEASED:
				if(SysParameterCur.nCkSensorStatus == 0)
					SysParameterCur.nCkSensorStatus = 1;
				else
					SysParameterCur.nCkSensorStatus = 0;
				break;
		  }
		  break;
	  default:
		WM_DefaultProc(pMsg);
	}
  }
}

// pm2.5开始按键回调函数
static void _cbButtonPm2_5Start(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
				
			}
			else
			{
				GUI_SetBkColor(0X0057565a);
				GUI_Clear();
				if(SysParameterCur.nCkSensorStatus == 0)
				{
					GUI_DrawBitmap(&bmstart,60,14);    // 开始
				}
				else
				{
					GUI_DrawBitmap(&bmstopkey,55,20);  // 停止
				}
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// PM2.5数据对话框界面
static void _cbDialogPM2_5Page(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  switch (pMsg->MsgId) {
    case WM_INIT_DIALOG:
	  // 窗口
      hItem = pMsg->hWin;
	  WM_SetCallback(hItem,_cbWindowPM2_5Page);                // 窗口

	  // 标题栏
      //hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 
	  
	  // 按键
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
	  WM_SetCallback(hItem,_cbButtonBack);
    
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
      WM_SetCallback(hItem,_cbButtonBackMain);

      hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // 开始停止按钮
      WM_SetCallback(hItem,_cbButtonPm2_5Start);

	  // 文本
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);         // PM2.5um 颗粒数
      TEXT_SetFont(hItem, &GUI_Fontfont_yh_pm2_5);
	  TEXT_SetTextColor(hItem,GUI_WHITE);
	  TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
      TEXT_SetText(hItem, "PM2.5um 颗粒数");

      hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);           // PM2.5 浓度
      TEXT_SetFont(hItem, &GUI_Fontfont_yh_pm2_5);
	  TEXT_SetTextColor(hItem,GUI_WHITE);
	  TEXT_SetTextAlign(hItem,TEXT_CF_HCENTER | TEXT_CF_VCENTER);
      TEXT_SetText(hItem, "PM2.5 浓度");

	  
      break;
    default:
      WM_DefaultProc(pMsg);
  }
}

// abc 按钮
static void _cbButtonWifiPadABC(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();
				GUI_SetFont(&GUI_Fontfont_yh_padsym);
				if(WifiPadMode == WIFI_PAD_MODE_ABC)
					GUI_SetColor(GUI_BLACK);
				else
					GUI_SetColor(GUI_WHITE);
				GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
				GUI_DispStringAt("abc",44,25);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}
// 123 按钮
static void _cbButtonWifiPad123(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();
				GUI_SetFont(&GUI_Fontfont_yh_padsym);
				if(WifiPadMode == WIFI_PAD_MODE_123)
					GUI_SetColor(GUI_BLACK);
				else
					GUI_SetColor(GUI_WHITE);
				GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
				GUI_DispStringAt("123",44,25);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 符号 按钮
static void _cbButtonWifiPadSym(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(SysParameterCur.BackgroundClor);
				GUI_Clear();
				GUI_SetFont(&GUI_Fontfont_yh_padsym);
				if(WifiPadMode == WIFI_PAD_MODE_SYM)
					GUI_SetColor(GUI_BLACK);
				else
					GUI_SetColor(GUI_WHITE);
				GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
				GUI_DispStringAt("符号",44,25);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 大小写 按钮
static void _cbButtonWifiPadAbcMode(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				if(WifiPadAbcMode == WIFI_PAD_ABC_MDOE_1)             // 大写
					GUI_SetBkColor(0X00BCB3AA);
				else if(WifiPadAbcMode == WIFI_PAD_ABC_MDOE_2)      //  小写
					GUI_SetBkColor(GUI_LIGHTGRAY);
				GUI_Clear();
				GUI_PNG_Draw(acwifipadabcmode,GUI_COUNTOF(acwifipadabcmode),11,12); 

				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(1,1,52);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(0,0,53);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawVLine(0,1,54);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawVLine(0,0,55);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawVLine(52,1,54);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawVLine(53,0,55);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(54,1,52);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(55,0,53);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// 删除 按钮
static void _cbButtonWifiPadBackspace(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(0X00BCB3AA);
				GUI_Clear();
				GUI_PNG_Draw(acwifibackspace,GUI_COUNTOF(acwifibackspace),11,12); 

				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(1,1,52);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(0,0,53);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawVLine(0,1,54);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawVLine(0,0,55);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawVLine(52,1,54);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawVLine(53,0,55);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(54,1,52);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(55,0,53);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}


// wifi 密码界面窗口回调函数
static void _cbWindowWifiPasswordPage(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	int      Pressed;

	Pressed = 0;
	switch (pMsg->MsgId) 
	{
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(0x00edbc38);    
		GUI_FillRect(0,100,480,400);

		// 键盘底色
		GUI_SetColor(GUI_GRAY);    
		GUI_FillRect(0,400,480,700);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(NCode)
		{
			case WM_NOTIFICATION_CLICKED:
				if((Id == ID_BUTTON_1) || (Id == ID_BUTTON_2)
				  || (Id == ID_BUTTON_3) || (Id == ID_BUTTON_4) 
				  || (Id == ID_BUTTON_5))
				{
					break;
				}
				Pressed = 1;
			case WM_NOTIFICATION_RELEASED:
				{
					switch(Id)
					{
						case ID_BUTTON_1: // 取消
//							GUI_EndDialog(pMsg->hWin, 0);
//							hItemCur = GUI_CreateDialogBox(_aDialogCreateWifiPage, GUI_COUNTOF(_aDialogCreateWifiPage), _cbDialogWifiPage, WM_HBKWIN, 0, 0);
//							SysParameterCur.nHw1Status = 1;
							GUI_EndDialog(pMsg->hWin, 0);
							hItemCur = GUI_CreateDialogBox(_aDialogCreateSetPage1, GUI_COUNTOF(_aDialogCreateSetPage1), _cbDialogSetPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 2;
							break;
						case ID_BUTTON_2:  // 连接
							GUI_EndDialog(pMsg->hWin, 0);
							hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 0;
							break;
						case ID_BUTTON_3:
							break;
						case ID_BUTTON_4:
//							WifiPasswordNum = EDIT_GetNumChars(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0));
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
													
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadMode = WIFI_PAD_MODE_123;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordNumPage,GUI_COUNTOF(_aDialogCreateWifiPasswordNumPage),_cbDialogWifiPasswordNumPage, WM_HBKWIN,0 , 0); 
							break;
						case ID_BUTTON_5:
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadMode = WIFI_PAD_MODE_SYM;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordSymPage, GUI_COUNTOF(_aDialogCreateWifiPasswordSymPage),_cbDialogWifiPasswordSymPage, WM_HBKWIN, 0, 0);
							break;
						case ID_BUTTON_6:      // Q
							GUI_SendKeyMsg('Q', Pressed); 
							break;
						case ID_BUTTON_7:      // W
							GUI_SendKeyMsg('W', Pressed); 
							break;
						case ID_BUTTON_8:      // E
							GUI_SendKeyMsg('E', Pressed); 
							break;
						case ID_BUTTON_9:      // R
							GUI_SendKeyMsg('R', Pressed); 
							break;
						case ID_BUTTON_10:      // T
							GUI_SendKeyMsg('T', Pressed); 
							break;
						case ID_BUTTON_11:      // Y
							GUI_SendKeyMsg('Y', Pressed); 
							break;
						case ID_BUTTON_12:      // U
							GUI_SendKeyMsg('U', Pressed); 
							break;
						case ID_BUTTON_13:      // I
							GUI_SendKeyMsg('I', Pressed); 
							break;
						case ID_BUTTON_14:      // O
							GUI_SendKeyMsg('O', Pressed); 
							break;
						case ID_BUTTON_15:      // P
							GUI_SendKeyMsg('P', Pressed); 
							break;
						case ID_BUTTON_16:      // A
							GUI_SendKeyMsg('A', Pressed); 
							break;
						case ID_BUTTON_17:      // S
							GUI_SendKeyMsg('S', Pressed); 
							break;
						case ID_BUTTON_18:      // D
							GUI_SendKeyMsg('D', Pressed); 
							break;
						case ID_BUTTON_19:      // F
							GUI_SendKeyMsg('F', Pressed); 
							break;
						case ID_BUTTON_20:      // G
							GUI_SendKeyMsg('G', Pressed); 
							break;
						case ID_BUTTON_21:      // H
							GUI_SendKeyMsg('H', Pressed); 
							break;
						case ID_BUTTON_22:      // J
							GUI_SendKeyMsg('J', Pressed); 
							break;
						case ID_BUTTON_23:      // K
							GUI_SendKeyMsg('K', Pressed); 
							break;
						case ID_BUTTON_24:      // L
							GUI_SendKeyMsg('L', Pressed); 
							break;
						case ID_BUTTON_25:      // 大小写转换
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadAbcMode = WIFI_PAD_ABC_MDOE_2;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordMinPage, GUI_COUNTOF(_aDialogCreateWifiPasswordMinPage),_cbDialogWifiPasswordMinPage, WM_HBKWIN, 0, 0); //GUI_SendKeyMsg('Z', Pressed); 
							break;
						case ID_BUTTON_26:      // Z
							GUI_SendKeyMsg('Z', Pressed); 
							break;
						case ID_BUTTON_27:      // X
							GUI_SendKeyMsg('X', Pressed); 
							break;
						case ID_BUTTON_28:      // C
							GUI_SendKeyMsg('C', Pressed); 
							break;
						case ID_BUTTON_29:      // V
							GUI_SendKeyMsg('V', Pressed); 
							break;
						case ID_BUTTON_30:      // B
							GUI_SendKeyMsg('B', Pressed); 
							break;
						case ID_BUTTON_31:      // M
							GUI_SendKeyMsg('N', Pressed); 
							break;
						case ID_BUTTON_32:      // N
							GUI_SendKeyMsg('M', Pressed); 
							break;
						case ID_BUTTON_33:      // 删除
							GUI_SendKeyMsg(GUI_KEY_BACKSPACE, Pressed); 
							break;
						case ID_BUTTON_34:      // 空格
							GUI_SendKeyMsg(' ', Pressed); 
							break;
						case ID_BUTTON_35:      // 确认
							// GUI_SendKeyMsg('Q', Pressed); 
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordSend,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNameSend,30);

							GUI_EndDialog(pMsg->hWin, 0);
							hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 0;

							f_WifiNetEn();							
							break;
						default:
							WM_DefaultProc(pMsg);
					}
				}
				break;
			default:
				break;
		}
	}
}

// wifi 密码对话框界面
static void _cbDialogWifiPasswordPage(WM_MESSAGE * pMsg) 
{
	unsigned char i;
	WM_HWIN    hItem;
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			// 窗口
			hItem = pMsg->hWin;
			WM_SetCallback(hItem,_cbWindowWifiPasswordPage);                  // 窗口

			// 标题栏
			hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

			// 文本
//			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // wifi名称
//			TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
//			TEXT_SetTextColor(hItem,GUI_WHITE);
//			TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
//			TEXT_SetText(hItem,(void *)GetWifiSetBuf);

			// 密码输入框
			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);       // 	
			EDIT_SetFont(hItem,GUI_FONT_24_ASCII);
			EDIT_SetTextAlign(hItem, GUI_TA_VCENTER);
			EDIT_SetMaxLen(hItem,50);
			EDIT_EnableBlink(hItem,500,1);
			WM_SetFocus(hItem);
			EDIT_SetText(hItem,(void *)WifiPasswordKeyBuf);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);       // 	
			EDIT_SetFont(hItem,GUI_FONT_24_ASCII);
			EDIT_SetTextAlign(hItem, GUI_TA_VCENTER);
			EDIT_SetMaxLen(hItem,50);
			EDIT_EnableBlink(hItem,500,1);
			WM_SetFocus(hItem);
			EDIT_SetText(hItem,(void *)WifiNumKeyBuf);

			// 按键
			for(i = 0;i < 28;i ++)
			{
				hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6 + i);       // 
				BUTTON_SetFont(hItem,GUI_FONT_32_ASCII);

			}

			for(i = 0;i < 33;i ++)
			{
				hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3 + i);       // 
				BUTTON_SetFocussable(hItem,0);
				BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,GUI_LIGHTGRAY);
			}

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
			WM_SetCallback(hItem,_cbButtonBack);
		    
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
		       WM_SetCallback(hItem,_cbButtonBackMain);
			
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // abc
			WM_SetCallback(hItem,_cbButtonWifiPadABC);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 123
			WM_SetCallback(hItem,_cbButtonWifiPad123);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);       // 符号
			WM_SetCallback(hItem,_cbButtonWifiPadSym);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_25);       // 大小写
			WM_SetCallback(hItem,_cbButtonWifiPadAbcMode);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_33);       // 删除
			WM_SetCallback(hItem,_cbButtonWifiPadBackspace);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_34);       // 空格
			BUTTON_SetFont(hItem,&GUI_Fontfont_yh_wifisure);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_35);       // 确认
			BUTTON_SetFont(hItem,&GUI_Fontfont_yh_wifisure);
			BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,0X00EDBC38);
			
//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 取消
//			WM_SetCallback(hItem,_cbButtonWifiFault);

//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 连接
//			WM_SetCallback(hItem,_cbButtonWifiConnect);

			
			//
			//WM_SetCallback(hItem,_cbButtonBack);

			break;
		default:
			WM_DefaultProc(pMsg);
	}
}

// wifi 密码界面窗口回调函数(小写)
static void _cbWindowWifiPasswordMinPage(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	int      Pressed;

	Pressed = 0;
	switch (pMsg->MsgId) 
	{
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(0x00edbc38);    
		GUI_FillRect(0,100,480,400);

		// 键盘底色
		GUI_SetColor(GUI_GRAY);    
		GUI_FillRect(0,400,480,700);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(NCode)
		{
			case WM_NOTIFICATION_CLICKED:
				if((Id == ID_BUTTON_1) || (Id == ID_BUTTON_2)
				  || (Id == ID_BUTTON_3) || (Id == ID_BUTTON_4) 
				  || (Id == ID_BUTTON_5))
				{
					break;
				}
				Pressed = 1;
			case WM_NOTIFICATION_RELEASED:
				{
					switch(Id)
					{
						case ID_BUTTON_1: // 取消
//							GUI_EndDialog(pMsg->hWin, 0);
//							hItemCur = GUI_CreateDialogBox(_aDialogCreateWifiPage, GUI_COUNTOF(_aDialogCreateWifiPage), _cbDialogWifiPage, WM_HBKWIN, 0, 0);
//							SysParameterCur.nHw1Status = 1;	
							GUI_EndDialog(pMsg->hWin, 0);
							hItemCur = GUI_CreateDialogBox(_aDialogCreateSetPage1, GUI_COUNTOF(_aDialogCreateSetPage1), _cbDialogSetPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 2;
							break;
						case ID_BUTTON_2:  // 连接
							GUI_EndDialog(pMsg->hWin, 0);
							hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 0;
							break;
						case ID_BUTTON_3:
							
							break;
						case ID_BUTTON_4:
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadMode = WIFI_PAD_MODE_123;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordNumPage,GUI_COUNTOF(_aDialogCreateWifiPasswordNumPage),_cbDialogWifiPasswordNumPage, WM_HBKWIN,0 , 0); 
							break;
						case ID_BUTTON_5:
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadMode = WIFI_PAD_MODE_SYM;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordSymPage, GUI_COUNTOF(_aDialogCreateWifiPasswordSymPage),_cbDialogWifiPasswordSymPage, WM_HBKWIN, 0, 0);
							break;
						case ID_BUTTON_6:      // q
							GUI_SendKeyMsg('q', Pressed); 
							break;
						case ID_BUTTON_7:      // w
							GUI_SendKeyMsg('w', Pressed); 
							break;
						case ID_BUTTON_8:      // e
							GUI_SendKeyMsg('e', Pressed); 
							break;
						case ID_BUTTON_9:      // r
							GUI_SendKeyMsg('r', Pressed); 
							break;
						case ID_BUTTON_10:      // t
							GUI_SendKeyMsg('t', Pressed); 
							break;
						case ID_BUTTON_11:      // y
							GUI_SendKeyMsg('y', Pressed); 
							break;
						case ID_BUTTON_12:      // u
							GUI_SendKeyMsg('u', Pressed); 
							break;
						case ID_BUTTON_13:      // i
							GUI_SendKeyMsg('i', Pressed); 
							break;
						case ID_BUTTON_14:      // o
							GUI_SendKeyMsg('o', Pressed); 
							break;
						case ID_BUTTON_15:      // p
							GUI_SendKeyMsg('p', Pressed); 
							break;
						case ID_BUTTON_16:      // a
							GUI_SendKeyMsg('a', Pressed); 
							break;
						case ID_BUTTON_17:      // s
							GUI_SendKeyMsg('s', Pressed); 
							break;
						case ID_BUTTON_18:      // d
							GUI_SendKeyMsg('d', Pressed); 
							break;
						case ID_BUTTON_19:      // f
							GUI_SendKeyMsg('f', Pressed); 
							break;
						case ID_BUTTON_20:      // g
							GUI_SendKeyMsg('g', Pressed); 
							break;
						case ID_BUTTON_21:      // h
							GUI_SendKeyMsg('h', Pressed); 
							break;
						case ID_BUTTON_22:      // j
							GUI_SendKeyMsg('j', Pressed); 
							break;
						case ID_BUTTON_23:      // k
							GUI_SendKeyMsg('k', Pressed); 
							break;
						case ID_BUTTON_24:      // l
							GUI_SendKeyMsg('l', Pressed); 
							break;
						case ID_BUTTON_25:      // 大小写转换
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadAbcMode = WIFI_PAD_ABC_MDOE_1;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordPage, GUI_COUNTOF(_aDialogCreateWifiPasswordPage),_cbDialogWifiPasswordPage, WM_HBKWIN, 0, 0);
							//GUI_SendKeyMsg('Z', Pressed); 
							break;
						case ID_BUTTON_26:      // z
							GUI_SendKeyMsg('z', Pressed); 
							break;
						case ID_BUTTON_27:      // x
							GUI_SendKeyMsg('x', Pressed); 
							break;
						case ID_BUTTON_28:      // c
							GUI_SendKeyMsg('c', Pressed); 
							break;
						case ID_BUTTON_29:      // v
							GUI_SendKeyMsg('v', Pressed); 
							break;
						case ID_BUTTON_30:      // b
							GUI_SendKeyMsg('b', Pressed); 
							break;
						case ID_BUTTON_31:      // n
							GUI_SendKeyMsg('n', Pressed); 
							break;
						case ID_BUTTON_32:      // m
							GUI_SendKeyMsg('m', Pressed); 
							break;
						case ID_BUTTON_33:      // 删除
							GUI_SendKeyMsg(GUI_KEY_BACKSPACE, Pressed); 
							break;
						case ID_BUTTON_34:      // 空格
							GUI_SendKeyMsg(' ', Pressed); 
							break;
						case ID_BUTTON_35:      // 确认
							// GUI_SendKeyMsg('Q', Pressed); 
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordSend,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNameSend,30);

							GUI_EndDialog(pMsg->hWin, 0);
							hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 0;

							f_WifiNetEn();
							break;
						default:
							WM_DefaultProc(pMsg);
					}
				}
				break;
			default:
				break;
		}
	}
}

// wifi 密码对话框界面
static void _cbDialogWifiPasswordMinPage(WM_MESSAGE * pMsg) 
{
	unsigned char i;
	WM_HWIN    hItem;
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			// 窗口
			hItem = pMsg->hWin;
			WM_SetCallback(hItem,_cbWindowWifiPasswordMinPage);                  // 窗口

			// 标题栏
			hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

			// 文本
//			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // wifi名称
//			TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
//			TEXT_SetTextColor(hItem,GUI_WHITE);
//			TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
//			TEXT_SetText(hItem, (void *)GetWifiSetBuf);

			// 密码输入框
			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);       // 	
			EDIT_SetFont(hItem,GUI_FONT_24_ASCII);
			EDIT_SetTextAlign(hItem, GUI_TA_VCENTER);
			EDIT_SetMaxLen(hItem,50);
			EDIT_EnableBlink(hItem,500,1);
			WM_SetFocus(hItem);
			EDIT_SetText(hItem,(void *)WifiPasswordKeyBuf);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);       // 	
			EDIT_SetFont(hItem,GUI_FONT_24_ASCII);
			EDIT_SetTextAlign(hItem, GUI_TA_VCENTER);
			EDIT_SetMaxLen(hItem,50);
			EDIT_EnableBlink(hItem,500,1);
			WM_SetFocus(hItem);
			EDIT_SetText(hItem,(void *)WifiNumKeyBuf);

			// 按键
			for(i = 0;i < 28;i ++)
			{
				hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6 + i);       // 
				BUTTON_SetFont(hItem,GUI_FONT_32_ASCII);

			}

			for(i = 0;i < 33;i ++)
			{
				hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3 + i);       // 
				BUTTON_SetFocussable(hItem,0);
				BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,GUI_LIGHTGRAY);
			}
			
//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 取消
//			WM_SetCallback(hItem,_cbButtonWifiFault);

//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 连接
//			WM_SetCallback(hItem,_cbButtonWifiConnect);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
			WM_SetCallback(hItem,_cbButtonBack);
		    
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
		       WM_SetCallback(hItem,_cbButtonBackMain);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // abc
			WM_SetCallback(hItem,_cbButtonWifiPadABC);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 123
			WM_SetCallback(hItem,_cbButtonWifiPad123);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);       // 符号
			WM_SetCallback(hItem,_cbButtonWifiPadSym);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_25);       // 大小写
			WM_SetCallback(hItem,_cbButtonWifiPadAbcMode);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_33);       // 删除
			WM_SetCallback(hItem,_cbButtonWifiPadBackspace);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_34);       // 空格
			BUTTON_SetFont(hItem,&GUI_Fontfont_yh_wifisure);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_35);       // 确认
			BUTTON_SetFont(hItem,&GUI_Fontfont_yh_wifisure);
			BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,0X00EDBC38);
			
			//
			//WM_SetCallback(hItem,_cbButtonBack);

			break;
		default:
			WM_DefaultProc(pMsg);
	}
}

// wifi 密码数字界面窗口回调函数
static void _cbWindowWifiPasswordNumPage(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	int      Pressed;

	Pressed = 0;
	switch (pMsg->MsgId) 
	{
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(0x00edbc38);    
		GUI_FillRect(0,100,480,400);

		// 键盘底色
		GUI_SetColor(GUI_GRAY);    
		GUI_FillRect(0,400,480,700);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(NCode)
		{
			case WM_NOTIFICATION_CLICKED:
				if((Id == ID_BUTTON_1) || (Id == ID_BUTTON_2)
				  || (Id == ID_BUTTON_3) || (Id == ID_BUTTON_4) 
				  || (Id == ID_BUTTON_5))
				{
					break;
				}
				Pressed = 1;
			case WM_NOTIFICATION_RELEASED:
				{
					switch(Id)
					{
						case ID_BUTTON_1: // 取消
//							GUI_EndDialog(pMsg->hWin, 0);
//							hItemCur = GUI_CreateDialogBox(_aDialogCreateWifiPage, GUI_COUNTOF(_aDialogCreateWifiPage), _cbDialogWifiPage, WM_HBKWIN, 0, 0);
//							SysParameterCur.nHw1Status = 1;	

							GUI_EndDialog(pMsg->hWin, 0);
							hItemCur = GUI_CreateDialogBox(_aDialogCreateSetPage1, GUI_COUNTOF(_aDialogCreateSetPage1), _cbDialogSetPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 2;
							break;
						case ID_BUTTON_2:  // 连接
							GUI_EndDialog(pMsg->hWin, 0);
							hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 0;
							break;
						case ID_BUTTON_3:
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadMode = WIFI_PAD_MODE_ABC;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordPage, GUI_COUNTOF(_aDialogCreateWifiPasswordPage), _cbDialogWifiPasswordPage, WM_HBKWIN, 0, 0);
							break;
						case ID_BUTTON_4:
							break;
						case ID_BUTTON_5:
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadMode = WIFI_PAD_MODE_SYM;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordSymPage, GUI_COUNTOF(_aDialogCreateWifiPasswordSymPage),_cbDialogWifiPasswordSymPage, WM_HBKWIN, 0, 0);
							break;
						case ID_BUTTON_6:      // 1
							GUI_SendKeyMsg('1', Pressed); 
							break;
						case ID_BUTTON_7:      // 2
							GUI_SendKeyMsg('2', Pressed); 
							break;
						case ID_BUTTON_8:      // 3
							GUI_SendKeyMsg('3', Pressed); 
							break;
						case ID_BUTTON_9:      // 删除
							GUI_SendKeyMsg(GUI_KEY_BACKSPACE, Pressed); 
							break;
						case ID_BUTTON_10:      // 4
							GUI_SendKeyMsg('4', Pressed); 
							break;
						case ID_BUTTON_11:      // 5
							GUI_SendKeyMsg('5', Pressed); 
							break;
						case ID_BUTTON_12:      // 6
							GUI_SendKeyMsg('6', Pressed); 
							break;
						case ID_BUTTON_13:      // 0
							GUI_SendKeyMsg('0', Pressed); 
							break;
						case ID_BUTTON_14:      // 7
							GUI_SendKeyMsg('7', Pressed); 
							break;
						case ID_BUTTON_15:      // 8
							GUI_SendKeyMsg('8', Pressed); 
							break;
						case ID_BUTTON_16:      // 9
							GUI_SendKeyMsg('9', Pressed); 
							break;
						case ID_BUTTON_17:      // 确认
							//GUI_SendKeyMsg('s', Pressed); 
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordSend,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNameSend,30);

							GUI_EndDialog(pMsg->hWin, 0);
							hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 0;

							f_WifiNetEn();
							break;
						default:
							WM_DefaultProc(pMsg);
					}
				}
				break;
			default:
				break;
		}
	}
}

// 数字键盘删除 按钮
static void _cbButtonWifiPadNumBackspace(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(0X00BCB3AA);
				GUI_Clear();
				GUI_PNG_Draw(acwifibackspace,GUI_COUNTOF(acwifibackspace),41,24); 

				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(1,1,113);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(0,0,114);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawVLine(1,1,78);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawVLine(0,0,79);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawVLine(113,1,78);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawVLine(114,0,79);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(78,1,113);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(79,0,114);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}

// wifi 密码数字对话框界面
static void _cbDialogWifiPasswordNumPage(WM_MESSAGE * pMsg) 
{
	unsigned char i;
	WM_HWIN    hItem;
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			// 窗口
			hItem = pMsg->hWin;
			WM_SetCallback(hItem,_cbWindowWifiPasswordNumPage);                  // 窗口

			// 标题栏
			hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

			// 文本
//			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // wifi名称
//			TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
//			TEXT_SetTextColor(hItem,GUI_WHITE);
//			TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
//			TEXT_SetText(hItem, (void *)GetWifiSetBuf);

			// 密码输入框
			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);       // 	
			EDIT_SetFont(hItem,GUI_FONT_24_ASCII);
			EDIT_SetTextAlign(hItem, GUI_TA_VCENTER);
			EDIT_SetMaxLen(hItem,50);
			EDIT_EnableBlink(hItem,500,1);
			WM_SetFocus(hItem);
			EDIT_SetText(hItem,(void *)WifiPasswordKeyBuf);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);       // 	
			EDIT_SetFont(hItem,GUI_FONT_24_ASCII);
			EDIT_SetTextAlign(hItem, GUI_TA_VCENTER);
			EDIT_SetMaxLen(hItem,50);
			EDIT_EnableBlink(hItem,500,1);
			WM_SetFocus(hItem);
			EDIT_SetText(hItem,(void *)WifiNumKeyBuf);

			// 按键
			for(i = 0;i < 28;i ++)
			{
				hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6 + i);       // 
				BUTTON_SetFont(hItem,GUI_FONT_32_ASCII);

			}

			for(i = 0;i < 33;i ++)
			{
				hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3 + i);       // 
				BUTTON_SetFocussable(hItem,0);
				BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,GUI_LIGHTGRAY);
			}

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
			WM_SetCallback(hItem,_cbButtonBack);
		    
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
		       WM_SetCallback(hItem,_cbButtonBackMain);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // abc
			WM_SetCallback(hItem,_cbButtonWifiPadABC);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 123
			WM_SetCallback(hItem,_cbButtonWifiPad123);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);       // 符号
			WM_SetCallback(hItem,_cbButtonWifiPadSym);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);       // 删除
			WM_SetCallback(hItem,_cbButtonWifiPadNumBackspace);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_17);       // 确认
			BUTTON_SetFont(hItem,&GUI_Fontfont_yh_wifisure);
			BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,0X00EDBC38);
			 
//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 取消
//			WM_SetCallback(hItem,_cbButtonWifiFault);

//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 连接
//			WM_SetCallback(hItem,_cbButtonWifiConnect);
			
			//
			//WM_SetCallback(hItem,_cbButtonBack);

			break;
		default:
			WM_DefaultProc(pMsg);
	}
}

// wifi 密码符号界面窗口回调函数
static void _cbWindowWifiPasswordSymPage(WM_MESSAGE * pMsg)
{
	int     NCode;
    int     Id;
	int      Pressed;

	Pressed = 0;
	switch (pMsg->MsgId) 
	{
	  case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		// 标题栏
		f_HeadStatusDis();
		
		// 背景色
		GUI_SetColor(0x00edbc38);    
		GUI_FillRect(0,100,480,400);

		// 键盘底色
		GUI_SetColor(GUI_GRAY);    
		GUI_FillRect(0,400,480,700);

		// 底部
		GUI_SetColor(0X0057565A);
		GUI_FillRect(0,700,480,800);
		
		break;
	  case WM_NOTIFY_PARENT:
		Id    = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch(NCode)
		{
			case WM_NOTIFICATION_CLICKED:
				if((Id == ID_BUTTON_1) || (Id == ID_BUTTON_2)
				  || (Id == ID_BUTTON_3) || (Id == ID_BUTTON_4) 
				  || (Id == ID_BUTTON_5) || (Id == ID_BUTTON_30)
				  || (Id == ID_BUTTON_36) || (Id == ID_BUTTON_37))
				{
					break;
				}
				Pressed = 1;
			case WM_NOTIFICATION_RELEASED:
				{
					switch(Id)
					{
						case ID_BUTTON_1: // 取消
//							GUI_EndDialog(pMsg->hWin, 0);
//							hItemCur = GUI_CreateDialogBox(_aDialogCreateWifiPage, GUI_COUNTOF(_aDialogCreateWifiPage), _cbDialogWifiPage, WM_HBKWIN, 0, 0);
//							SysParameterCur.nHw1Status = 1;	

							GUI_EndDialog(pMsg->hWin, 0);
							hItemCur = GUI_CreateDialogBox(_aDialogCreateSetPage1, GUI_COUNTOF(_aDialogCreateSetPage1), _cbDialogSetPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 2;
							break;
						case ID_BUTTON_2:  // 连接
							GUI_EndDialog(pMsg->hWin, 0);
							hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 0;
							break;
						case ID_BUTTON_3:
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadMode = WIFI_PAD_MODE_ABC;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordPage, GUI_COUNTOF(_aDialogCreateWifiPasswordPage), _cbDialogWifiPasswordPage, WM_HBKWIN, 0, 0);
							break;
						case ID_BUTTON_4:
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
							
							GUI_EndDialog(pMsg->hWin, 0);
							WifiPadMode = WIFI_PAD_MODE_123;
							GUI_CreateDialogBox(_aDialogCreateWifiPasswordNumPage,GUI_COUNTOF(_aDialogCreateWifiPasswordNumPage),_cbDialogWifiPasswordNumPage, WM_HBKWIN,0 , 0); 
							break;
						case ID_BUTTON_5:
							break;
						case ID_BUTTON_6:      // [
							GUI_SendKeyMsg('[', Pressed); 
							break;
						case ID_BUTTON_7:      // ]
							GUI_SendKeyMsg(']', Pressed); 
							break;
						case ID_BUTTON_8:      // {
							GUI_SendKeyMsg('{', Pressed);
							break;
						case ID_BUTTON_9:      // }
							GUI_SendKeyMsg('}', Pressed); 
							break;
						case ID_BUTTON_10:      // #
							GUI_SendKeyMsg('#', Pressed); 
							break;
						case ID_BUTTON_11:      // %
							GUI_SendKeyMsg('%', Pressed); 
							break;
						case ID_BUTTON_12:      // ^
							GUI_SendKeyMsg('^', Pressed); 
							break;
						case ID_BUTTON_13:      // *
							GUI_SendKeyMsg('*', Pressed); 
							break;
						case ID_BUTTON_14:      // +
							GUI_SendKeyMsg('+', Pressed); 
							break;
						case ID_BUTTON_15:      // =
							GUI_SendKeyMsg('=', Pressed); 
							break;
						case ID_BUTTON_16:      // _
							GUI_SendKeyMsg('_', Pressed); 
							break;
						case ID_BUTTON_17:      // -
							GUI_SendKeyMsg('-', Pressed); 
							break;
						case ID_BUTTON_18:      // /
							GUI_SendKeyMsg('/', Pressed); 
							break;
						case ID_BUTTON_19:      // \ 
							GUI_SendKeyMsg('\\', Pressed); 
							break;
						case ID_BUTTON_20:      // |
							GUI_SendKeyMsg('|', Pressed); 
							break;
						case ID_BUTTON_21:      // :
							GUI_SendKeyMsg(':', Pressed); 
							break;
						case ID_BUTTON_22:      // ;
							GUI_SendKeyMsg(';', Pressed); 
							break;
						case ID_BUTTON_23:      // (
							GUI_SendKeyMsg('(', Pressed); 
							break;
						case ID_BUTTON_24:      // )
							GUI_SendKeyMsg(')', Pressed); 
							break;
						case ID_BUTTON_25:      // ~
							GUI_SendKeyMsg('~', Pressed); 
							break;
						case ID_BUTTON_26:      // .
							GUI_SendKeyMsg('.', Pressed); 
							break;
						case ID_BUTTON_27:      // ,
							GUI_SendKeyMsg(',', Pressed); 
							break;
						case ID_BUTTON_28:      // `
							GUI_SendKeyMsg('`', Pressed); 
							break;
						case ID_BUTTON_29:      // ?
							GUI_SendKeyMsg('?', Pressed); 
							break;
						case ID_BUTTON_30:      // !
							if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0)))
							{
								WifiPasswordNum = EDIT_GetNumChars(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0));
								EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
								WifiPasswordKeyBuf[WifiPasswordNum] = '!';
								EDIT_SetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf);
							}

							if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1)))
							{
								WifiNameNum = EDIT_GetNumChars(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1));
								EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
								WifiNumKeyBuf[WifiNameNum] = '!';
								EDIT_SetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf);
							}
						
							break;
						case ID_BUTTON_31:      // &
							GUI_SendKeyMsg('&', Pressed); 
							break;
						case ID_BUTTON_32:      // @
							GUI_SendKeyMsg('@', Pressed); 
							break;
						case ID_BUTTON_33:      // 删除
							GUI_SendKeyMsg(GUI_KEY_BACKSPACE, Pressed); 
							break;
						case ID_BUTTON_34:      // <
							GUI_SendKeyMsg('<', Pressed); 
							break;
						case ID_BUTTON_35:      // >
							GUI_SendKeyMsg('>', Pressed); 
							break;
						case ID_BUTTON_36:      // "
							if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0)))
							{
								WifiPasswordNum = EDIT_GetNumChars(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0));
								EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
								WifiPasswordKeyBuf[WifiPasswordNum] = '\"';
								EDIT_SetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf);
							}

							if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1)))
							{
								WifiNameNum = EDIT_GetNumChars(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1));
								EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
								WifiNumKeyBuf[WifiNameNum] = '!';
								EDIT_SetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf);
							}
							
							break;
						case ID_BUTTON_37:      // "
							if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0)))
							{
								WifiPasswordNum = EDIT_GetNumChars(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0));
								EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf,30);
								WifiPasswordKeyBuf[WifiPasswordNum] = '\"';
								EDIT_SetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordKeyBuf);
							}

							if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1)))
							{
								WifiNameNum = EDIT_GetNumChars(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1));
								EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf,30);
								WifiNumKeyBuf[WifiNameNum] = '!';
								EDIT_SetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNumKeyBuf);
							}
							
							break;
						case ID_BUTTON_38:      // $
							GUI_SendKeyMsg('$', Pressed); 
							break;
						case ID_BUTTON_39:      // 空格
							GUI_SendKeyMsg(' ', Pressed); 
							break;
						case ID_BUTTON_40:      // 确认
							//GUI_SendKeyMsg('Q', Pressed); 
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_0),(void *)WifiPasswordSend,30);
							EDIT_GetText(WM_GetDialogItem(pMsg->hWin, ID_EDIT_1),(void *)WifiNameSend,30);

							GUI_EndDialog(pMsg->hWin, 0);
							hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
							SysParameterCur.nHw1Status = 0;

							f_WifiNetEn();
							break;

						default:
							WM_DefaultProc(pMsg);
					}
				}
				break;
			default:
				break;
		}
	}
}
// 符号键盘删除 按钮
static void _cbButtonWifiPadSymBackspace(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			if(BUTTON_IsPressed(hWin))
			{
				GUI_SetBkColor(GUI_WHITE);
				GUI_Clear();
			}
			else
			{
				GUI_SetBkColor(0X00BCB3AA);
				GUI_Clear();
				GUI_PNG_Draw(acwifibackspace,GUI_COUNTOF(acwifibackspace),50,12); 

				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(1,1,130);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(0,0,131);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawVLine(1,1,54);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawVLine(0,0,55);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawVLine(130,1,54);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawVLine(131,0,55);

				GUI_SetColor(GUI_WHITE);
				GUI_DrawHLine(54,1,130);
				GUI_SetColor(GUI_BLACK);
				GUI_DrawHLine(55,0,131);
			}
			break;
		default:
			BUTTON_Callback(pMsg);
			break;
	}
}
// wifi 密码符号对话框界面
static void _cbDialogWifiPasswordSymPage(WM_MESSAGE * pMsg) 
{
	unsigned char i;
	WM_HWIN    hItem;
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			// 窗口
			hItem = pMsg->hWin;
			WM_SetCallback(hItem,_cbWindowWifiPasswordSymPage);                  // 窗口

			// 标题栏
			hItemHead = WM_CreateWindowAsChild(0,0,480,90,hItem,WM_CF_SHOW,_cbHeadWinBack,0); 

			// 文本
//			hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);       // wifi名称
//			TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
//			TEXT_SetTextColor(hItem,GUI_WHITE);
//			TEXT_SetTextAlign(hItem,TEXT_CF_LEFT | TEXT_CF_VCENTER);
//			TEXT_SetText(hItem, (void *)GetWifiSetBuf);

			// 密码输入框
			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);       // 	
			EDIT_SetFont(hItem,GUI_FONT_24_ASCII);
			EDIT_SetTextAlign(hItem, GUI_TA_VCENTER);
			EDIT_SetMaxLen(hItem,50);
			EDIT_EnableBlink(hItem,500,1);
			WM_SetFocus(hItem);
			EDIT_SetText(hItem,(void *)WifiPasswordKeyBuf);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);       // 	
			EDIT_SetFont(hItem,GUI_FONT_24_ASCII);
			EDIT_SetTextAlign(hItem, GUI_TA_VCENTER);
			EDIT_SetMaxLen(hItem,50);
			EDIT_EnableBlink(hItem,500,1);
			WM_SetFocus(hItem);
			EDIT_SetText(hItem,(void *)WifiNumKeyBuf);

			// 按键
			for(i = 0;i < 37;i ++)
			{
				hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6 + i);       // 
				BUTTON_SetFont(hItem,GUI_FONT_32_ASCII);

			}

			for(i = 0;i < 40;i ++)
			{
				hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3 + i);       // 
				BUTTON_SetFocussable(hItem,0);
				BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,GUI_LIGHTGRAY);
			}

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 返回按钮
			WM_SetCallback(hItem,_cbButtonBack);
		    
			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 返回主界面按钮
		       WM_SetCallback(hItem,_cbButtonBackMain);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);       // abc
			WM_SetCallback(hItem,_cbButtonWifiPadABC);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);       // 123
			WM_SetCallback(hItem,_cbButtonWifiPad123);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);       // 符号
			WM_SetCallback(hItem,_cbButtonWifiPadSym);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_33);       // 删除
			WM_SetCallback(hItem,_cbButtonWifiPadSymBackspace);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_39);       // 空格
			BUTTON_SetFont(hItem,&GUI_Fontfont_yh_wifisure);

			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_40);       // 确认
			BUTTON_SetFont(hItem,&GUI_Fontfont_yh_wifisure);
			BUTTON_SetBkColor(hItem,BUTTON_CI_UNPRESSED,0X00EDBC38);

//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);       // 取消
//			WM_SetCallback(hItem,_cbButtonWifiFault);

//			hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);       // 连接
//			WM_SetCallback(hItem,_cbButtonWifiConnect);

			//
			//WM_SetCallback(hItem,_cbButtonBack);

			break;
		default:
			WM_DefaultProc(pMsg);
	}
}

// 桌面回调函数
static void _cbHbkWin(WM_MESSAGE * pMsg)
{
//	static unsigned char buttoncountbuf;
	switch (pMsg->MsgId) {
	  case WM_PAINT:
		
		break;
	  case WM_TIMER:

		if(SysParameterCur.nHw1Status == 0)       // 首界面
		{
			WM_InvalidateWindow(hItemPage1);
			WM_InvalidateWindow(WM_GetDialogItem(hItemPage1,ID_BUTTON_6));
			
		}
		else if(SysParameterCur.nHw1Status == 3)
		{
			WM_InvalidateWindow(hItemPage1);
		}
		else
		{
			WM_InvalidateWindow(hItemHead);
			if(SysParameterCur.nHw1Status == 2)   // 高级设置界面
			{
				WM_InvalidateWindow(WM_GetDialogItem(hItemHead,ID_BUTTON_6));
			}
//			GUI_Exec();
		}
			//WM_InvalidateWindow(WM_GetDialogItem(hItemCur,ID_WINDOW_HEAD));
			//WM_InvalidateWindow(hItemCur);
		//if(nHw1Status == 2)       // PM2.5界面
		//{
		//	WM_InvalidateWindow(hItemPm2_5Page);
		//}

		
		WM_RestartTimer(pMsg->Data.v, 1000);		
		break;
  }
}

/*********************************************************************
*
*       MainTask
*/
void f_MainTask(void) {
  #if GUI_SUPPORT_MEMDEV
    WM_SetCreateFlags(WM_CF_MEMDEV);
  #endif
  //
  // Check if recommended memory for the sample is available
  //
//  if (GUI_ALLOC_GetNumFreeBytes() < RECOMMENDED_MEMORY) {
//    GUI_ErrorOut("Not enough memory available."); 
//    return;
//  }
  WM_SetCreateFlags(WM_CF_MEMDEV);
  GUI_Init();
  GUI_UC_SetEncodeUTF8();
  
  SysParameterCur.BackgroundClor = BACKGROUND_COLOR_1;
  
  WM_SetCallback(WM_HBKWIN,_cbHbkWin);

  SysParameterCur.nHw1Status = 0;
  hItemPage1 = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbDialogPage1, WM_HBKWIN, 0, 0);
  WM_CreateTimer(WM_HBKWIN,0,1000,0);

// 	 GUI_Delay(1000);
}

/*************************** End of file ****************************/

