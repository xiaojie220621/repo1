/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef   MAIN_TYPE_CLYLE
	#define MAIN_TYPE
#else
	#define MAIN_TYPE  extern
#endif



MAIN_TYPE byte_def SysTmRunFlagAll1;
#define nSysTmRunFlagAll1                 SysTmRunFlagAll1.m_byte
#define bSys5msFlag                           SysTmRunFlagAll1.m_bit.b0
#define bSys10msFlag                         SysTmRunFlagAll1.m_bit.b1
#define bSys50msFlag                         SysTmRunFlagAll1.m_bit.b2   
#define bSys100msFlag                       SysTmRunFlagAll1.m_bit.b3
#define bSys125msFlag                       SysTmRunFlagAll1.m_bit.b4
#define bSys250msFlag                       SysTmRunFlagAll1.m_bit.b5
#define bSys500msFlag                       SysTmRunFlagAll1.m_bit.b6
#define bSys1sFlag                             SysTmRunFlagAll1.m_bit.b7

MAIN_TYPE uint16_t SysTmRun;                // 系统时间片计时驱动
MAIN_TYPE uint16_t co2;
MAIN_TYPE uint8_t co2Step;

MAIN_TYPE uint16_t Hcho;
MAIN_TYPE uint8_t HchoStep;

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

