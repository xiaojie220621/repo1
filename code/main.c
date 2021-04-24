#define  MAIN_TYPE_CLYLE

#include "Public.h"

extern void f_MainTask(void);
/* ===================================================
 * ��������:  f_ClamTm
 * ����˵��:  ʱ��Ƭ����ʱ�亯��
 * ����˵��:
 * ���˵��:
 * ��          ��:  ����
 * �༭ʱ��:  2017-1-6
 * ��          ע:
 ===================================================*/
void f_ClamTm(void)
{
	if(bSys5msFlag)
	{
		bSys5msFlag = FALSE;
		
	}
	if(bSys10msFlag)
	{
		bSys10msFlag = FALSE;
		f_EspTmRun();
		f_BatteryTmRun();
	}
	if(bSys50msFlag)
	{
		bSys50msFlag = FALSE;
		
	}
	if(bSys125msFlag)
	{
		bSys125msFlag = FALSE;
		
	}
	if(bSys250msFlag)
	{
		bSys250msFlag = FALSE;
		nHumiTempGetFlag = TRUE;
		
	}
	if(bSys500msFlag)
	{
		bSys500msFlag = FALSE;
		bSysRtcFreshFlag = TRUE;
	}
	if(bSys1sFlag)
	{
		bSys1sFlag = FALSE;
		nTvocGetFlag = TRUE;
		SensorPM2_5DataCur.bPM2_5DriveFlag = TRUE;

		BatteryDataCur.bBatteryGetAdEnFlag = TRUE;
		
		f_BrightRunTmDrive();
		f_WifiAirjoyAqDataComRun();

//		if(BatteryDataCur.nBatteryData < 100)
//			BatteryDataCur.nBatteryData ++;
//		else
//			BatteryDataCur.nBatteryData = 0;
	}
}

/* ===================================================
 * ��������:  f_ParameterInit
 * ����˵��:  ������ʼ��
 * ����˵��:
 * ���˵��:
 * ��          ��:  ����
 * �༭ʱ��:  
 * ��          ע:
 ===================================================*/
void f_ParameterInit(void)
{
	f_McuInitDrive();
	f_HumiTempInit();
	f_TvocInit();
	f_SensorPM2_5Init();
	f_SysRtcInit();
	f_BrightInit();
	W25QXX_Init();
	f_MySaveDataInit();
	f_SaveSensorXsInit();
	f_WifiInit();
	f_BatteryInit();
}
/* ===================================================
 * ��������:  main
 * ����˵��:  ������
 * ����˵��:
 * ���˵��:
 * ��          ��:   ����
 * �༭ʱ��:  
 * ��          ע:
 ===================================================*/
int main(void)  
{
	unsigned char i;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);        //����ϵͳ�ж����ȼ�����2
	
	f_ParameterInit();
//	GUI_Init();
	f_MainTask();

	//W25QXX_Erase_Chip();
	
  	while(1)
	{
		GUI_Exec();                           // GUI 
		f_ClamTm();                           // ʱ��
		f_GetHumiTempValue();          // ��ʪ�ȴ���
		f_TvocDeal();                         // TVOC ����
		f_SensorPM2_5Deal();            // PM2.5����
		f_BatteryDeal();                     // ��ش���
		f_SysRtcDeal();                      // RTC ����
		f_BrightDeal();                       // ���ȴ���
		f_SaveDeal();                         // �洢����
		f_WifiDeal();
	} 
}
