#ifndef  __MYTEST_H
#define  __MYTEST_H

#ifdef   MYTEST_TYPE_CLYLE
	#define  MYTEST_TYPE
#else
	#define  MYTEST_TYPE     extern
#endif

#include "Dialog.h"

#define ID_WINDOW_MY   (GUI_ID_USER + 0X00)
#define ID_BUTTON_1    (GUI_ID_USER + 0X01)
#define ID_BUTTON_2    (GUI_ID_USER + 0X02)
#define ID_BUTTON_3    (GUI_ID_USER + 0X03)
#define ID_BUTTON_4    (GUI_ID_USER + 0X04)
#define ID_BUTTON_5    (GUI_ID_USER + 0X05)
#define ID_BUTTON_6    (GUI_ID_USER + 0X06)

#define ID_BUTTON_7    (GUI_ID_USER + 0X07)
#define ID_BUTTON_8    (GUI_ID_USER + 0X08)
#define ID_BUTTON_9    (GUI_ID_USER + 0X09)
#define ID_BUTTON_10    (GUI_ID_USER + 0X0a)
#define ID_BUTTON_11    (GUI_ID_USER + 0X0b)
#define ID_BUTTON_12    (GUI_ID_USER + 0X0c)
#define ID_BUTTON_13    (GUI_ID_USER + 0X0d)
#define ID_BUTTON_14    (GUI_ID_USER + 0X0e)
#define ID_BUTTON_15    (GUI_ID_USER + 0X0f)
#define ID_BUTTON_16    (GUI_ID_USER + 0X10)
#define ID_BUTTON_17    (GUI_ID_USER + 0X11)
#define ID_BUTTON_18    (GUI_ID_USER + 0X12)
#define ID_BUTTON_19    (GUI_ID_USER + 0X13)
#define ID_BUTTON_20    (GUI_ID_USER + 0X14)

#define ID_BUTTON_21    (GUI_ID_USER + 0X15)
#define ID_BUTTON_22    (GUI_ID_USER + 0X16)
#define ID_BUTTON_23    (GUI_ID_USER + 0X17)
#define ID_BUTTON_24    (GUI_ID_USER + 0X18)
#define ID_BUTTON_25    (GUI_ID_USER + 0X19)
#define ID_BUTTON_26    (GUI_ID_USER + 0X1a)
#define ID_BUTTON_27    (GUI_ID_USER + 0X1b)
#define ID_BUTTON_28    (GUI_ID_USER + 0X1c)
#define ID_BUTTON_29    (GUI_ID_USER + 0X1d)
#define ID_BUTTON_30    (GUI_ID_USER + 0X1e)
#define ID_BUTTON_31    (GUI_ID_USER + 0X1f)
#define ID_BUTTON_32    (GUI_ID_USER + 0X20)
#define ID_BUTTON_33    (GUI_ID_USER + 0X21)
#define ID_BUTTON_34    (GUI_ID_USER + 0X22)
#define ID_BUTTON_35    (GUI_ID_USER + 0X23)
#define ID_BUTTON_36    (GUI_ID_USER + 0X24)
#define ID_BUTTON_37    (GUI_ID_USER + 0X25)
#define ID_BUTTON_38    (GUI_ID_USER + 0X26)
#define ID_BUTTON_39    (GUI_ID_USER + 0X27)
#define ID_BUTTON_40    (GUI_ID_USER + 0X28)
#define ID_BUTTON_41    (GUI_ID_USER + 0X29)
#define ID_BUTTON_42    (GUI_ID_USER + 0X2a)


#define ID_WINDOW_HEAD  (GUI_ID_USER + 0X41)


#define ID_TEXT_1      (GUI_ID_USER + 0X51)
#define ID_TEXT_2      (GUI_ID_USER + 0X52)
#define ID_TEXT_3      (GUI_ID_USER + 0X53)
#define ID_TEXT_4      (GUI_ID_USER + 0X54)
#define ID_TEXT_5      (GUI_ID_USER + 0X55)
#define ID_TEXT_6      (GUI_ID_USER + 0X56)
#define ID_TEXT_7      (GUI_ID_USER + 0X57)
#define ID_TEXT_8      (GUI_ID_USER + 0X58)
#define ID_TEXT_9      (GUI_ID_USER + 0X59)

#define ID_LISTWHEEL_0  (GUI_ID_USER + 0X71)
#define ID_LISTWHEEL_1  (GUI_ID_USER + 0X72)
#define ID_LISTWHEEL_2  (GUI_ID_USER + 0X73)
#define ID_LISTWHEEL_3  (GUI_ID_USER + 0X74)
#define ID_LISTWHEEL_4  (GUI_ID_USER + 0X75)

#define ID_EDIT_0       (GUI_ID_USER + 0XA0)
#define ID_EDIT_1       (GUI_ID_USER + 0XA1)
#define ID_EDIT_2       (GUI_ID_USER + 0XA2)
#define ID_EDIT_3       (GUI_ID_USER + 0XA3)
#define ID_EDIT_4       (GUI_ID_USER + 0XA4)
#define ID_EDIT_5       (GUI_ID_USER + 0XA5)
#define ID_EDIT_6       (GUI_ID_USER + 0XA6)

#define ID_SLIDER_1            (GUI_ID_USER + 0XB1)
#define ID_SLIDER_2            (GUI_ID_USER + 0XB2)

#define ID_CHCKBOX_1           (GUI_ID_USER + 0XC1)
#define ID_CHCKBOX_2           (GUI_ID_USER + 0XC2)
#define ID_CHCKBOX_3           (GUI_ID_USER + 0XC3)

#define ID_LISTBOX_1           (GUI_ID_USER + 0XD0)

#define ID_LISTVIEW_1          (GUI_ID_USER + 0XE1)

MYTEST_TYPE WM_HWIN hItemNumPad;              // 数字键盘对话框句柄
MYTEST_TYPE WM_HWIN hItemPage1;               // 首页对话框句柄
MYTEST_TYPE WM_HWIN hItemPm2_5Page;           // PM2.5对话框句柄

MYTEST_TYPE WM_HWIN hItemCur;                 // 当前窗口
MYTEST_TYPE WM_HWIN hItemHead;                // 标题栏
MYTEST_TYPE WM_HWIN ListWheeltest;

MYTEST_TYPE unsigned char *listviewbuf[50][7];
MYTEST_TYPE unsigned char *listviewWifibuf[20][1];

MYTEST_TYPE unsigned char GetWifiSetBuf[25];

MYTEST_TYPE int WifiPasswordNum;
MYTEST_TYPE int WifiNameNum;
MYTEST_TYPE unsigned char WifiPasswordKeyBuf[30];

MYTEST_TYPE unsigned char WifiNumKeyBuf[30];

MYTEST_TYPE unsigned char WifiNameSend[30];
MYTEST_TYPE unsigned char WifiPasswordSend[30];

MYTEST_TYPE unsigned char WifiPadMode;               // 键盘模式
MYTEST_TYPE unsigned char WifiPadAbcMode;          // 键盘字母大小写模式

MYTEST_TYPE unsigned char SensorSetPM2_5[4];
MYTEST_TYPE unsigned char SensorSetPM10[4];
MYTEST_TYPE unsigned char SensorSetTvoc[4];

MYTEST_TYPE unsigned short SensorSetPM2_5Xs;
MYTEST_TYPE unsigned short SensorSetPM10Xs;
MYTEST_TYPE unsigned short SensorSetTvocXs;

enum  eunmWifiPadMode
{
	WIFI_PAD_MODE_ABC = 0,             // 字母模式
	WIFI_PAD_MODE_123,                   // 数字模式
	WIFI_PAD_MODE_SYM                   // 符号模式
};

enum  eunmWifiPadAbcMode
{
	WIFI_PAD_ABC_MDOE_1 = 0,             // 大写
	WIFI_PAD_ABC_MDOE_2                   // 小写
};

typedef  struct
{
	unsigned char hour;
	unsigned char min;
}TimeSet;

typedef  struct
{
	unsigned char SysSensorCkTm;                       // 传感器检测时间
	unsigned char SysSensorCkTmMemory;           // 记忆值

	unsigned char TimeOnSetStatus;                     // 定时开机功能状态
	unsigned char TimeOffSetStatus;                    // 定时关机功能状态
      
	TimeSet TimeOnSetData;
	TimeSet TimeOffSetData;

	TimeSet TimeOnSetDataLast;
	TimeSet TimeOffSetDataLast;

	unsigned char WifiSigle;                                  // 信号强度
	unsigned char nCkSensorStatus;                     // 检测开关状态
	unsigned char nCkSensorStep;                        // 环境检测空气质量等级
	unsigned int   nAqiData;                                 // AQI
	unsigned char nTmOnOffStatus;                      // 定制开关状态

	
	unsigned char nHw1Status;                            // 窗口是否在首页状态
	GUI_COLOR BackgroundClor;                         // 背景颜色
	GUI_COLOR BackgroundClorLast;
       GUI_COLOR AqiStepColor;                             // AQI阶级颜色

      unsigned char password[10];                          // 密码输入串
      
}SysParameter;

MYTEST_TYPE SysParameter  SysParameterCur;  

#endif
