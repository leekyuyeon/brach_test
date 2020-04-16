/*
 * HardwareControl.h
 *
 *  Created on: 2016. 8. 1.
 *      Author: BGKim
 */

#ifndef HEADER_HARDWARECONTROL_H_
#define HEADER_HARDWARECONTROL_H_
#ifdef __cplusplus
extern "C" {
#endif

#define DAQ_NUMBER 1

//#define DEBUG_MODE_RX485
//#define DEBUG_MODE_CALIBRATION

//#define RS_232_ENABLE
#define RS_485_ENABLE

#define HIGH_VOLTAGE_GAIN 				((float)(1.0))
#define LOW_VOLTAGE_GAIN 				((float)(1.0))
#define THERMISTOR_GAIN					((float)(10.0))//((float)(1000.0))
#define THERMOCOUPLE_GAIN_T				((float)(1.378415633E-3))
#define THERMOCOUPLE_GAIN_K				((float)(1.378415633))
#define COLD_TEMP_GAIN					((float)(1000.0))

#define HIGH_VOLTAGE_GAIN_SCALE 		((float)(AD7609_5V_SCALE / 10000.0))
#define LOW_VOLTAGE_GAIN_SCALE 			((float)(AD7609_5V_SCALE / 10000.0))
#define THERMISTOR_GAIN_SCALE			((float)(AD7609_10V_SCALE / 10000.0))
#define THERMOCOUPLE_GAIN_SCALE			((float)(AD7609_5V_SCALE / 10000.0))
#define COLD_TEMP_GAIN_SCALE			((float)(AD7609_5V_SCALE / 10000.0))

#define HIGH_VOLTAGE_OFFSET_SCALE 		((float)(AD7609_5V_SCALE))
#define LOW_VOLTAGE_OFFSET_SCALE 		((float)(AD7609_5V_SCALE))
#define THERMISTOR_OFFSET_SCALE			((float)(AD7609_10V_SCALE))
#define THERMOCOUPLE_OFFSET_SCALE		((float)(AD7609_5V_SCALE))
#define COLD_TEMP_OFFSET_SCALE			((float)(AD7609_5V_SCALE))

#define THERMOCOUPLE_POLYNOMIAL(x) 		(float)((double)0.0\
										+ ((double)25727.94369  * Square(x, 1))\
										+ ((double)-767345.8295 * Square(x, 2))\
										+ ((double)78025595.81  * Square(x, 3))\
										+ ((double)-9247486589  * Square(x, 4))\
										+ ((double)6.97688E+11  * Square(x, 5))\
										+ ((double)-2.66192E+13 * Square(x, 6))\
										+ ((double)3.94078E+14  * Square(x, 7)))

#define K_TYPE_TO						(double)(-8.7935962E+00)
#define K_TYPE_VO						(double)(-3.4489914E-01)
#define K_TYPE_P1						(double)( 2.5678719E+01)
#define K_TYPE_P2                       (double)(-4.9887904E-01)
#define K_TYPE_P3                       (double)(-4.4705222E-01)
#define K_TYPE_P4                       (double)(-4.4869203E-02)
#define K_TYPE_Q1                       (double)( 2.3893439E-04)
#define K_TYPE_Q2                       (double)(-2.0397750E-02)
#define K_TYPE_Q3                       (double)(-1.8424107E-03)

#define V_VO(x)							((double)(x) - K_TYPE_VO)
#define K_TYPE_NUMERATOR(x)				(V_VO(x) * (K_TYPE_P1 + V_VO(x) * (K_TYPE_P2 + V_VO(x) * (K_TYPE_P3 + (K_TYPE_P4 * V_VO(x))))))
#define K_TYPE_DENOMINATOR(x)			(1 + V_VO(x) * (K_TYPE_Q1 + V_VO(x) * (K_TYPE_Q2 + (K_TYPE_Q3 * V_VO(x)))))
#define THERMOCOUPLE_POLYNOMIAL_K_TYPE(x) (float)(K_TYPE_TO + (K_TYPE_NUMERATOR(x) / K_TYPE_DENOMINATOR(x)))

#define K100_TYPE_TO				    (double)(3.1018976E+02)
#define K100_TYPE_VO				    (double)(1.2631386E+01)
#define K100_TYPE_P1				    (double)(2.4061949E+01)
#define K100_TYPE_P2                    (double)(4.0158622E+00)
#define K100_TYPE_P3                    (double)(2.6853917E-01)
#define K100_TYPE_P4                    (double)(-9.7188544E-03)
#define K100_TYPE_Q1                    (double)( 1.6995872E-01)
#define K100_TYPE_Q2                    (double)(1.1413069E-02)
#define K100_TYPE_Q3                    (double)(-3.9275155E-04)


#define V100_VO(x)							 ((double)(x) - K100_TYPE_VO)
#define K100_TYPE_NUMERATOR(x)				 (V100_VO(x) * (K100_TYPE_P1 + V100_VO(x) * (K100_TYPE_P2 + V100_VO(x) * (K100_TYPE_P3 + (K100_TYPE_P4 * V100_VO(x))))))
#define K100_TYPE_DENOMINATOR(x)			 (1 + V100_VO(x) * (K100_TYPE_Q1 + V100_VO(x) * (K100_TYPE_Q2 + (K100_TYPE_Q3 * V100_VO(x)))))
#define THERMOCOUPLE_POLYNOMIAL_K100_TYPE(x) (float)(K100_TYPE_TO + (K100_TYPE_NUMERATOR(x) / K100_TYPE_DENOMINATOR(x)))

#define COLD_TEMP_POLYNOMIAL(x) 		(float)(((x * x) * -8.451576E-06) + (x * -1.769281E-01) + 2.043937E+02)

#define HIGH_VOLTAGE_MAX_CHANNEL 		(1)
#define LOW_VOLTAGE_MAX_CHANNEL 		(1)
#define THERMISTOR_MAX_CHANNEL			(1)
#define THERMOCOUPLE_MAX_CHANNEL 		(1)

#define SAMPLING_MAX_DATA 				(30)

//---------------------------------------------------------
#define AD7609_MAX_CHANNEL 				(40)
//---------------------------------------------------------

#define COLD_TEMP_MAX_CHANNEL 			(4)

#define RS_STX 							'$'
#define RS_ETX 							'@'

#define RS485_RX_MAX_BUFF 				(10)
#define RS485_TX_MAX_BUFF 				(10)
#define RS485_RX_TIMEOUT  				(10)

#define LED_TOGGLE_TIME 				(400)//400ms



#define __ABS(x) ((x) > 0 ? (x) : ((x) * -1.0))

#define MAX_16BIT_COUNT 	(65535)
#define MAX_32BIT_COUNT	(4294967295)

#define INCREASE_16BIT(x) {if(x < MAX_16BIT_COUNT) x += 1;}
#define INCREASE_32BIT(x) {if(x < MAX_32BIT_COUNT) x += 1;}

#define DECREASE_16BIT(x) {if(x) x -= 1;}
#define DECREASE_32BIT(x) {if(x) x -= 1;}

typedef struct {
	float f_Buffer[SAMPLING_MAX_DATA];
}BUFFER_FILE;

typedef struct {
	unsigned long ul_Timer1_RUN_LED;
	unsigned long ul_Timer2;
	unsigned long ul_Timer3;
	unsigned long ul_Timer4;
	unsigned long ul_Timer5;
	unsigned long ul_Timer6;
	unsigned long ul_Timer7;
	unsigned long ul_Timer8;
	unsigned long ul_Timer9;
	unsigned long ul_Timer10;
}TIMER_FILE;

typedef struct {
	unsigned char uc_RxData[RS485_RX_MAX_BUFF];
	unsigned char uc_TxData[RS485_TX_MAX_BUFF];
	unsigned int  ui_RxCount;
	unsigned int  ui_RxVolt;
	unsigned int  ui_RxTemp;
	unsigned int  ui_RxTreg;
	unsigned int  ui_RxAllx;
	unsigned int  ui_TxStatFlag;
	unsigned int  ui_TxEndFlag;
	unsigned long ul_RxTimeOut;

	//$INFO? set flag
	unsigned int  ui_RxINFO;
    unsigned int  ui_RxINF1;
    unsigned int  ui_RxINF2;

    //Voltage Channel Number Setting
    unsigned int  ui_RxVOL0;
    unsigned int  ui_RxVOL1;
    unsigned int  ui_RxVOL2;
    unsigned int  ui_RxVOL3;
    unsigned int  ui_RxVOL4;
    unsigned int  ui_RxVOL5;
    unsigned int  ui_RxVOL6;
    unsigned int  ui_RxVOL7;
    unsigned int  ui_RxVOL8;
    unsigned int  ui_RxVOL9;
    unsigned int  ui_RxVOLA;
    unsigned int  ui_RxVOLB;
    unsigned int  ui_RxVOLC;
    unsigned int  ui_RxVOLD;
    unsigned int  ui_RxVOLE;
    unsigned int  ui_RxVOLF;

    //Thermistor Channel Number Setting
    unsigned int  ui_RxTRE0;
    unsigned int  ui_RxTRE1;
    unsigned int  ui_RxTRE2;
    unsigned int  ui_RxTRE3;
    unsigned int  ui_RxTRE4;
    unsigned int  ui_RxTRE5;
    unsigned int  ui_RxTRE6;
    unsigned int  ui_RxTRE7;
    unsigned int  ui_RxTRE8;
    unsigned int  ui_RxTRE9;
    unsigned int  ui_RxTREA;
    unsigned int  ui_RxTREB;
    unsigned int  ui_RxTREC;
    unsigned int  ui_RxTRED;
    unsigned int  ui_RxTREE;
    unsigned int  ui_RxTREF;

    //Thermocouple Channel Number Setting
    unsigned int  ui_RxTEM0;
    unsigned int  ui_RxTEM1;
    unsigned int  ui_RxTEM2;
    unsigned int  ui_RxTEM3;
    unsigned int  ui_RxTEM4;
    unsigned int  ui_RxTEM5;
    unsigned int  ui_RxTEM6;
    unsigned int  ui_RxTEM7;
    unsigned int  ui_RxTEM8;
    unsigned int  ui_RxTEM9;
    unsigned int  ui_RxTEMA;
    unsigned int  ui_RxTEMB;
    unsigned int  ui_RxTEMC;
    unsigned int  ui_RxTEMD;
    unsigned int  ui_RxTEME;
    unsigned int  ui_RxTEMF;

    //All Channel Number Setting
    unsigned int  ui_RxALL0;
    unsigned int  ui_RxALL1;
    unsigned int  ui_RxALL2;
    unsigned int  ui_RxALL3;
    unsigned int  ui_RxALL4;
    unsigned int  ui_RxALL5;
    unsigned int  ui_RxALL6;
    unsigned int  ui_RxALL7;
    unsigned int  ui_RxALL8;
    unsigned int  ui_RxALL9;
    unsigned int  ui_RxALLA;
    unsigned int  ui_RxALLB;
    unsigned int  ui_RxALLC;
    unsigned int  ui_RxALLD;
    unsigned int  ui_RxALLE;
    unsigned int  ui_RxALLF;

    //Factory Reset
    unsigned int  ui_RxFRST ;

    //Calibration input sensing data

    unsigned int  ui_Rx1VOL ;
    unsigned int  ui_Rx5VOL ;

}RS485_FILE;

typedef struct {
	unsigned int 	ui_AD7609_01;
	unsigned int 	ui_AD7609_02;
	unsigned int 	ui_AD7609_03;
	unsigned int 	ui_AD7609_04;
	unsigned int 	ui_AD7609_05;
	unsigned int 	ui_AD7609_06;
	unsigned int 	ui_AD7609_07;
	unsigned int 	ui_AD7609_08;
	unsigned int 	ui_AD7609_09;
	unsigned int 	ui_AD7609_10;
	unsigned int 	ui_AD7609_11;
	unsigned int 	ui_AD7609_12;
	unsigned int 	ui_AD7609_13;
	unsigned int 	ui_AD7609_14;
	unsigned int 	ui_AD7609_15;
	unsigned int 	ui_AD7609_16;
}AD7609_CHANNEL_FILE;

typedef struct {
	unsigned int BufferCounter;
	unsigned int HighVoltageSamplingFlag;
	unsigned int LowVoltageSamplingFlag;
	unsigned int ThermocoupleSamplingFlag;
	unsigned int ThermistorSamplingFlag;
	unsigned int ColdTempSamplingFlag;

	unsigned int ChannelInfo[(unsigned int)(AD7609_MAX_CHANNEL / 8)];
	int ai_SensColdTemp[COLD_TEMP_MAX_CHANNEL];
	long al_SensAD7609[AD7609_MAX_CHANNEL];

	BUFFER_FILE s_ColdTemp[COLD_TEMP_MAX_CHANNEL];
	BUFFER_FILE s_AD7609[AD7609_MAX_CHANNEL];

	float f_ResultColdTemp[COLD_TEMP_MAX_CHANNEL];
	float f_ResultAD7609[AD7609_MAX_CHANNEL];

	float f_1VoltageBuffer[AD7609_MAX_CHANNEL];
	float f_5VoltageBuffer[AD7609_MAX_CHANNEL];

	float f_CalculateVoltageGain[AD7609_MAX_CHANNEL];
	float f_CalculateVoltageOffset[AD7609_MAX_CHANNEL];

	float f_GainColdTemp[COLD_TEMP_MAX_CHANNEL];
	float f_OffsetColdTemp[COLD_TEMP_MAX_CHANNEL];
	float f_GainAD7609[AD7609_MAX_CHANNEL];
	float f_OffsetAD7609[AD7609_MAX_CHANNEL];

	float f_GainAD7609K[AD7609_MAX_CHANNEL];
	float f_OffsetAD7609K[AD7609_MAX_CHANNEL];

	float f_GainAD7609K100[AD7609_MAX_CHANNEL];
	float f_OffsetAD7609K100[AD7609_MAX_CHANNEL];

	float f_CalibrationData;
	unsigned int i_Calibrationflag;

	RS485_FILE s_RS485;
	TIMER_FILE s_Timer;
}SYSTEM_FILE;

enum
{
	AD7609_01			=1,
	AD7609_02			=9,
	AD7609_03			=17,
	AD7609_04			=25,

	AD7609_05			=33,
	AD7609_06			=41,
	AD7609_07			=49,
	AD7609_08			=57,

	AD7609_09			=65,
	AD7609_10			=73,
	AD7609_11			=81,
	AD7609_12			=89,

	AD7609_13			=97,
	AD7609_14			=105,
	AD7609_15			=113,
	AD7609_16			=121
};

enum
{
	HIGH_VOLTAGE		=1,
	LOW_VOLTAGE			=2,
	THERMISTOR			=3,
	THERMOCOUPLE		=4,
};
void BoardInitial(void);
float RootMeanSquare(float* f_Source, unsigned ui_Length);
void SandDataToPc(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
void SenSingOfDAQ(SYSTEM_FILE *sp_System);
void HighVoltageCONV(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
void LowVoltageCONV(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
void ThermistorCONV(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
void ThermocoupleCONV(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
void ColdTemperatureCONV(SYSTEM_FILE *sp_System);
double Square(float f_Data, unsigned int Number);

void IDNUMBER(void);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* HEADER_HARDWARECONTROL_H_ */

//===========================================================================
// No more.
//===========================================================================


