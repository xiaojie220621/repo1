#ifndef    MYTESTCONST_H
#define    MYTESTCONST_H




//extern GUI_CONST_STORAGE GUI_BITMAP bmstart;
//extern GUI_CONST_STORAGE GUI_BITMAP bmstopkey;
//extern GUI_CONST_STORAGE GUI_BITMAP bmtimeoffsetkey;
//extern GUI_CONST_STORAGE GUI_BITMAP bmtimeset;
//extern GUI_CONST_STORAGE GUI_BITMAP bmrecord;
//extern GUI_CONST_STORAGE GUI_BITMAP bmset;
//extern GUI_CONST_STORAGE GUI_BITMAP bmback;
//extern GUI_CONST_STORAGE GUI_BITMAP bmbackfirst;


#define BACKGROUND_COLOR_1       0x00edbc38
#define BACKGROUND_COLOR_2       0x0078daa7//0x00d5daa7
#define BACKGROUND_COLOR_3       0x0057565a

#define  SENSOR_STEP1_COLOR        0X00EF9E1E
#define  SENSOR_STEP2_COLOR        0x0044ace2//0X0056ACE2
#define  SENSOR_STEP3_COLOR        0X001355EA
#define  SENSOR_STEP4_COLOR        0X00241FC0
#define  SENSOR_STEP5_COLOR        0X001C177A
#define  SENSOR_STEP6_COLOR        0X007D1F58

static const unsigned char passwordcmp[6] = "666666";              // 清零历史数据密码
static const unsigned char passwordSensorSetcmp[6] = "234567";     // 设置传感器参数密码


// 参数设置项
static const unsigned char * sensorsettext[] = {
	"","PM2.5","PM10","0.5um","2.5um","TVOC","","CO2"
};

// 检测时间设置
const unsigned char * CkTimeWheelData[] = {
	"1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10",
	"11","12","13","14","15","16","17","18","19","20",
	"21","22","23","24","25","26","27","28","29","30",
	"31","32","33","34","35","36","37","38","39","40",
	"41","42","43","44","45","46","47","48","49","50",
	"51","52","53","54","55","56","57","58","59","60"
};

// 年
const unsigned char * SetYearTimeWheelData[] = {
	"2000" ,"2001" ,"2002" ,"2003" ,"2004" ,"2005" ,"2006" ,"2007" ,"2008" ,"2009",
	"2010" ,"2011" ,"2012" ,"2013" ,"2014" ,"2015" ,"2016" ,"2017" ,"2018" ,"2019",
	"2020" ,"2021" ,"2022" ,"2023" ,"2024" ,"2025" ,"2026" ,"2027" ,"2028" ,"2029",
	"2030" ,"2031" ,"2032" ,"2033" ,"2034" ,"2035" ,"2036" ,"2037" ,"2038" ,"2039",
	"2040" ,"2041" ,"2042" ,"2043" ,"2044" ,"2045" ,"2046" ,"2047" ,"2048" ,"2049",
	"2050" ,"2051" ,"2052" ,"2053" ,"2054" ,"2055" ,"2056" ,"2057" ,"2058" ,"2059",
	"2060" ,"2061" ,"2062" ,"2063" ,"2064" ,"2065" ,"2066" ,"2067" ,"2068" ,"2069",
	"2070" ,"2071" ,"2072" ,"2073" ,"2074" ,"2075" ,"2076" ,"2077" ,"2078" ,"2079",
	"2080" ,"2081" ,"2082" ,"2083" ,"2084" ,"2085" ,"2086" ,"2087" ,"2088" ,"2089",
	"2090" ,"2091" ,"2092" ,"2093" ,"2094" ,"2095" ,"2096" ,"2097" ,"2098" ,"2099"
};

// 月
const unsigned char * SetMonTimeWheelData[] = {
	"1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10","11","12"
};

// 日
const unsigned char * SetDayTimeWheelData[] = {
	"1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10",
	"11","12","13","14","15","16","17","18","19","20",
	"21","22","23","24","25","26","27","28","29","30",
	"31"
};

// 时
const unsigned char * SetHourTimeWheelData[] = {
	"0" ,"1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10",
	"11","12","13","14","15","16","17","18","19","20",
	"21","22","23"
};

// 分
const unsigned char * SetMinTimeWheelData[] = {
	"0" ,"1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,
	"10","11","12","13","14","15","16","17","18","19",
	"20","21","22","23","24","25","26","27","28","29",
	"30","31","32","33","34","35","36","37","38","39",
	"40","41","42","43","44","45","46","47","48","49",
	"50","51","52","53","54","55","56","57","58","59"
};


typedef struct {
  WM_HWIN           hWin;
  GUI_MEMDEV_Handle hMemOverlay;
  GUI_MEMDEV_Handle hMemRBorder;
  GUI_MEMDEV_Handle hMemLBorder;
  const GUI_FONT GUI_UNI_PTR * pFont;
} WHEEL;



BUTTON_Handle hItemTimeOnSetButton,hItemTimeOnSetButtoff;

static WHEEL _aWheel;
WHEEL * _aWheelpost;

static WHEEL _aWheelTimeSet[5];
WHEEL * _aWheelpostTimeSet;

static WHEEL _aWheelTimeSetOnOff[2];
WHEEL * _aWheelpostTimeSetOnOff;


#endif
