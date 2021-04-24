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

MYTEST_TYPE WM_HWIN hItemNumPad;              // ���ּ��̶Ի�����
MYTEST_TYPE WM_HWIN hItemPage1;               // ��ҳ�Ի�����
MYTEST_TYPE WM_HWIN hItemPm2_5Page;           // PM2.5�Ի�����

MYTEST_TYPE WM_HWIN hItemCur;                 // ��ǰ����
MYTEST_TYPE WM_HWIN hItemHead;                // ������
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

MYTEST_TYPE unsigned char WifiPadMode;               // ����ģʽ
MYTEST_TYPE unsigned char WifiPadAbcMode;          // ������ĸ��Сдģʽ

MYTEST_TYPE unsigned char SensorSetPM2_5[4];
MYTEST_TYPE unsigned char SensorSetPM10[4];
MYTEST_TYPE unsigned char SensorSetTvoc[4];

MYTEST_TYPE unsigned short SensorSetPM2_5Xs;
MYTEST_TYPE unsigned short SensorSetPM10Xs;
MYTEST_TYPE unsigned short SensorSetTvocXs;

enum  eunmWifiPadMode
{
	WIFI_PAD_MODE_ABC = 0,             // ��ĸģʽ
	WIFI_PAD_MODE_123,                   // ����ģʽ
	WIFI_PAD_MODE_SYM                   // ����ģʽ
};

enum  eunmWifiPadAbcMode
{
	WIFI_PAD_ABC_MDOE_1 = 0,             // ��д
	WIFI_PAD_ABC_MDOE_2                   // Сд
};

typedef  struct
{
	unsigned char hour;
	unsigned char min;
}TimeSet;

typedef  struct
{
	unsigned char SysSensorCkTm;                       // ���������ʱ��
	unsigned char SysSensorCkTmMemory;           // ����ֵ

	unsigned char TimeOnSetStatus;                     // ��ʱ��������״̬
	unsigned char TimeOffSetStatus;                    // ��ʱ�ػ�����״̬
      
	TimeSet TimeOnSetData;
	TimeSet TimeOffSetData;

	TimeSet TimeOnSetDataLast;
	TimeSet TimeOffSetDataLast;

	unsigned char WifiSigle;                                  // �ź�ǿ��
	unsigned char nCkSensorStatus;                     // ��⿪��״̬
	unsigned char nCkSensorStep;                        // ���������������ȼ�
	unsigned int   nAqiData;                                 // AQI
	unsigned char nTmOnOffStatus;                      // ���ƿ���״̬

	
	unsigned char nHw1Status;                            // �����Ƿ�����ҳ״̬
	GUI_COLOR BackgroundClor;                         // ������ɫ
	GUI_COLOR BackgroundClorLast;
       GUI_COLOR AqiStepColor;                             // AQI�׼���ɫ

      unsigned char password[10];                          // �������봮
      
}SysParameter;

MYTEST_TYPE SysParameter  SysParameterCur;  

#endif
