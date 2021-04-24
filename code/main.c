#define  MAIN_TYPE_CLYLE

#include "Public.h"

extern void f_MainTask(void);
/* ===================================================
 * 函数名称:  f_ClamTm
 * 功能说明:  时间片处理时间函数
 * 输入说明:
 * 输出说明:
 * 作          者:  王聪
 * 编辑时间:  2017-1-6
 * 备          注:
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
 * 函数名称:  f_ParameterInit
 * 功能说明:  参数初始化
 * 输入说明:
 * 输出说明:
 * 作          者:  王聪
 * 编辑时间:  
 * 备          注:
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
 * 函数名称:  main
 * 功能说明:  主函数
 * 输入说明:
 * 输出说明:
 * 作          者:   王聪
 * 编辑时间:  
 * 备          注:
 ===================================================*/
int main(void)  
{
	unsigned char i;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);        //设置系统中断优先级分组2
	
	f_ParameterInit();
//	GUI_Init();
	f_MainTask();

	//W25QXX_Erase_Chip();
	
  	while(1)
	{
		GUI_Exec();                           // GUI 
		f_ClamTm();                           // 时基
		f_GetHumiTempValue();          // 温湿度处理
		f_TvocDeal();                         // TVOC 处理
		f_SensorPM2_5Deal();            // PM2.5处理
		f_BatteryDeal();                     // 电池处理
		f_SysRtcDeal();                      // RTC 处理
		f_BrightDeal();                       // 亮度处理
		f_SaveDeal();                         // 存储处理
		f_WifiDeal();
	} 
}
