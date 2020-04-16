#include "..\Header\DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "..\Header\DSP2833x_Examples.h"   // DSP2833x Examples Include File

void BoardInitial(void)
{
	unsigned int ui_i = 0;
	unsigned int ui_j = 0;

	DSP_CNVT_ADC_CLEAR();

	DELAY_US(1000);
	DSP_RESET_ADC_SET();

	DELAY_US(1000);
	DSP_RESET_ADC_CLEAR();

	DELAY_US(1000);
	DSP_RESET_ADC_SET();

	DELAY_US(1000);
	DSP_RESET_ADC_CLEAR();

	DELAY_US(1000);
	s_System.BufferCounter = 0;

	for(ui_i = 0; ui_i < COLD_TEMP_MAX_CHANNEL; ui_i++)
	{
		s_System.f_GainColdTemp[ui_i]   = AD7606_SCALE;
		s_System.f_OffsetColdTemp[ui_i] = 0;
		s_System.f_ResultColdTemp[ui_i] = 0;
		for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)
		{
			s_System.s_ColdTemp[ui_i].f_Buffer[ui_j] = 0;
		}
	}

	for(ui_i = 0; ui_i < AD7609_MAX_CHANNEL; ui_i++)
	{
		s_System.f_OffsetAD7609K100[ui_i] = 0.0;
		s_System.f_GainAD7609K100[ui_i] = 1.0;

		s_System.f_OffsetAD7609K[ui_i] = 0.0;
		s_System.f_GainAD7609K[ui_i] = 1.0;

		s_System.f_GainAD7609[ui_i]   = AD7609_SCALE;
		s_System.f_OffsetAD7609[ui_i] = 0;
		s_System.f_ResultAD7609[ui_i] = 0;
		s_System.ChannelInfo[ui_i]    = 0;
		for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)
		{
			s_System.s_AD7609[ui_i].f_Buffer[ui_j] = 0;
		}
	}
    // 2019/09/10
    // DAQ Mother DC/DC + Thermocouple 40CH

    // Thermocouple 40CH
    s_System.f_OffsetAD7609[0]   = 0.0003865   ;
    s_System.f_OffsetAD7609[1]   = -0.0004434  ;
    s_System.f_OffsetAD7609[2]   = 0.0199908   ;
    s_System.f_OffsetAD7609[3]   = 0.0267125   ;
    s_System.f_OffsetAD7609[4]   = 0.01763140  ;
    s_System.f_OffsetAD7609[5]   = 0.0058819   ;
    s_System.f_OffsetAD7609[6]   = 0.0003553   ;
    s_System.f_OffsetAD7609[7]   = 0.017321    ;
    s_System.f_OffsetAD7609[8]   = 0.0003865   ;
    s_System.f_OffsetAD7609[9]   = -0.0004434  ;
    s_System.f_OffsetAD7609[10]  = 0.0199908   ;
    s_System.f_OffsetAD7609[11]  = 0.0267125   ;
    s_System.f_OffsetAD7609[12]  = 0.01763140  ;
    s_System.f_OffsetAD7609[13]  = 0.0058819   ;
    s_System.f_OffsetAD7609[14]  = 0.0003553   ;
    s_System.f_OffsetAD7609[15]  = 0.017321    ;
    s_System.f_OffsetAD7609[16]  = 0.0 ;
    s_System.f_OffsetAD7609[17]  = 0.0 ;
    s_System.f_OffsetAD7609[18]  = 0.0 ;
    s_System.f_OffsetAD7609[19]  = 0.0 ;
    s_System.f_OffsetAD7609[20]  = 0.0 ;
    s_System.f_OffsetAD7609[21]  = 0.0 ;
    s_System.f_OffsetAD7609[22]  = 0.0 ;
    s_System.f_OffsetAD7609[23]  = 0.0 ;
    s_System.f_OffsetAD7609[24]  = 0.0 ;
    s_System.f_OffsetAD7609[25]  = 0.0 ;
    s_System.f_OffsetAD7609[26]  = 0.0 ;
    s_System.f_OffsetAD7609[27]  = 0.0 ;
    s_System.f_OffsetAD7609[28]  = 0.0 ;
    s_System.f_OffsetAD7609[29]  = 0.0 ;
    s_System.f_OffsetAD7609[30]  = 0.0 ;
    s_System.f_OffsetAD7609[31]  = 0.0 ;
    s_System.f_OffsetAD7609[32]  = 0.0 ;
    s_System.f_OffsetAD7609[33]  = 0.0 ;
    s_System.f_OffsetAD7609[34]  = 0.0 ;
    s_System.f_OffsetAD7609[35]  = 0.0 ;
    s_System.f_OffsetAD7609[36]  = 0.0 ;
    s_System.f_OffsetAD7609[37]  = 0.0 ;
    s_System.f_OffsetAD7609[38]  = 0.0 ;
    s_System.f_OffsetAD7609[39]  = 0.0 ;


    // Thermocouple 40CH
    s_System.f_GainAD7609[0]   = AD7609_SCALE * 0.999222236 ;
    s_System.f_GainAD7609[1]   = AD7609_SCALE * 0.999821865 ;
    s_System.f_GainAD7609[2]   = AD7609_SCALE * 0.997872155 ;
    s_System.f_GainAD7609[3]   = AD7609_SCALE * 0.99829353  ;
    s_System.f_GainAD7609[4]   = AD7609_SCALE * 0.999481106 ;
    s_System.f_GainAD7609[5]   = AD7609_SCALE * 0.998705561 ;
    s_System.f_GainAD7609[6]   = AD7609_SCALE * 1.002632668 ;
    s_System.f_GainAD7609[7]   = AD7609_SCALE * 0.999227925 ;
    s_System.f_GainAD7609[8]   = AD7609_SCALE * 0.999222236 ;
    s_System.f_GainAD7609[9]   = AD7609_SCALE * 0.999821865 ;
    s_System.f_GainAD7609[10]  = AD7609_SCALE * 0.997872155 ;
    s_System.f_GainAD7609[11]  = AD7609_SCALE * 0.99829353  ;
    s_System.f_GainAD7609[12]  = AD7609_SCALE * 0.999481106 ;
    s_System.f_GainAD7609[13]  = AD7609_SCALE * 0.998705561 ;
    s_System.f_GainAD7609[14]  = AD7609_SCALE * 1.002632668 ;
    s_System.f_GainAD7609[15]  = AD7609_SCALE * 0.999227925 ;
    s_System.f_GainAD7609[16]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[17]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[18]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[19]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[20]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[21]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[22]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[23]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[24]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[25]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[26]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[27]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[28]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[29]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[30]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[31]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[32]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[33]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[34]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[35]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[36]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[37]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[38]  = AD7609_SCALE * 1.0 ;
    s_System.f_GainAD7609[39]  = AD7609_SCALE * 1.0 ;


	for(ui_i = 0; ui_i < RS485_RX_MAX_BUFF; ui_i++)
	s_System.s_RS485.uc_RxData[ui_i] = 0;

	for(ui_i = 0; ui_i < RS485_TX_MAX_BUFF; ui_i++)
	s_System.s_RS485.uc_TxData[ui_i] = 0;

	s_System.s_RS485.ui_RxCount					= 0;
	s_System.s_RS485.ui_RxVolt					= 0;
	s_System.s_RS485.ui_RxTemp					= 0;
	s_System.s_RS485.ui_RxTreg					= 0;
	s_System.s_RS485.ui_TxStatFlag				= 0;
	s_System.s_RS485.ui_TxEndFlag				= 0;
	s_System.s_RS485.ul_RxTimeOut				= 0;

	s_System.s_Timer.ul_Timer1_RUN_LED  = 0;
	s_System.s_Timer.ul_Timer2          = 0;
	s_System.s_Timer.ul_Timer3          = 0;
	s_System.s_Timer.ul_Timer4          = 0;
	s_System.s_Timer.ul_Timer5          = 0;
	s_System.s_Timer.ul_Timer6          = 0;
	s_System.s_Timer.ul_Timer7          = 0;
	s_System.s_Timer.ul_Timer8          = 0;
	s_System.s_Timer.ul_Timer9 			= 0;
	s_System.s_Timer.ul_Timer10			= 0;
	s_System.f_CalibrationData			= 0;
	s_System.i_Calibrationflag			= 0;
//	CalibrationConstData();
	SRAM_CS_Select(0);
	ADC_RESET();

	for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)
	{
		SenSingOfDAQ(&s_System);
	}
	for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)
	{
		SenSingOfDAQ(&s_System);
	}
	for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)
	{
		SenSingOfDAQ(&s_System);
	}
}


//float RootMeanSquare(float* f_Source, unsigned ui_Length)
//{
//	double d_SumValue = 0.0;
//	double d_Result = 0.0;
//	double d_Sing = 0.0;
//
//	unsigned int ui_i = 0;
//
//	for(ui_i = 0; ui_i < ui_Length; ui_i++)
//	{
//		d_SumValue += (f_Source[ui_i] * f_Source[ui_i]);
//		d_Sing += f_Source[ui_i];
//	}
//
//	d_Result = sqrt(d_SumValue / ui_Length) ;
//	d_Result *= ((d_Sing >= 0) ? 1 : -1);
//	return ((float)(d_Result));
//}
float RootMeanSquare(float* f_Source, unsigned ui_Length)
{
	double d_SumValue = 0.0;
	double d_Result = 0.0;
	double d_Sing = 0.0;

	unsigned int ui_i = 0;

	for(ui_i = 0; ui_i < ui_Length; ui_i++)
	{
		d_SumValue += (f_Source[ui_i] * f_Source[ui_i]);
		d_Sing += f_Source[ui_i];
	}

	d_Result = sqrt(d_SumValue / ui_Length) ;
	d_Result *= ((d_Sing >= 0) ? 1 : -1);
	return ((float)(d_Result));
}

void SandDataToPc(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
	unsigned char uc_TxTemp[4] = {0,};

//	float f_Temp = 0.0;
	unsigned long ul_Temp = 0;
	unsigned int ui_i = 0;

#ifdef RS_232_ENABLE
	Rs232_Puts(RS_STX);
#endif

#ifdef RS_485_ENABLE
	Rs485_Puts(RS_STX);
#endif


	for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
	{
		uc_TxTemp[0] = (((*sp_System).f_ResultAD7609[ui_i] >= 0) ? 0x00 : 0x10) & 0x00FF;

		ul_Temp = (unsigned long)__ABS((*sp_System).f_ResultAD7609[ui_i]);
		uc_TxTemp[1] = (unsigned char)(ul_Temp) & 0x000000FF;

		ul_Temp = (unsigned long)(__ABS((*sp_System).f_ResultAD7609[ui_i]) * 10000);
		ul_Temp %= 10000;

		uc_TxTemp[2] = (unsigned char)((ul_Temp >> 8) & 0x000000FF);
		uc_TxTemp[3] = (unsigned char)(ul_Temp & 0x000000FF);


#ifdef RS_232_ENABLE
		Rs232_Wirte(&uc_TxTemp[0], 4);
#endif

#ifdef RS_485_ENABLE
		Rs485_Wirte(&uc_TxTemp[0], 4);
#endif
	}


#ifdef RS_232_ENABLE
	Rs232_Puts(RS_ETX);
#endif

#ifdef RS_485_ENABLE
	Rs485_Puts(RS_ETX);
#endif

#ifdef DEBUG_MODE_RX485

	Rs485_Puts(0x0D);//Carriage Return
	Rs485_Puts(0x0A);//Line Feed

#endif
}

void SenSingOfDAQ(SYSTEM_FILE *sp_System)
{
	unsigned int ui_i = 0;

	SRAM_CS_Select(0); //  0 = Non Select SRAM
	ADC_RESET();
	AD7609_Convert();

	for(ui_i = 0;  ui_i < AD7609_MAX_CHANNEL; ui_i+=8)
	{
		AD7609_Read(&(*sp_System).al_SensAD7609[ui_i], OVER_SAMPLING_64, (unsigned int)(ui_i / 8));
 	}

	for(ui_i = 0;  ui_i < AD7609_MAX_CHANNEL; ui_i++)
	{
		(*sp_System).s_AD7609[ui_i].f_Buffer[(*sp_System).BufferCounter] =
				(float)(((float)(*sp_System).al_SensAD7609[ui_i] * (*sp_System).f_GainAD7609[ui_i]) + (*sp_System).f_OffsetAD7609[ui_i]);
	}

	AD7606_Read(&(*sp_System).ai_SensColdTemp[0], OVER_SAMPLING_64);

	for(ui_i = 0;  ui_i < COLD_TEMP_MAX_CHANNEL; ui_i++)
	{
		(*sp_System).s_ColdTemp[ui_i].f_Buffer[(*sp_System).BufferCounter] =
				(float)(((*sp_System).ai_SensColdTemp[ui_i] * (*sp_System).f_GainColdTemp[ui_i]) + (*sp_System).f_OffsetColdTemp[ui_i]);
	}

	if(++(*sp_System).BufferCounter >= SAMPLING_MAX_DATA)
	{
		(*sp_System).BufferCounter = 0;
		(*sp_System).HighVoltageSamplingFlag = 1;
		(*sp_System).LowVoltageSamplingFlag = 1;
		(*sp_System).ThermistorSamplingFlag = 1;
		(*sp_System).ThermocoupleSamplingFlag = 1;
		(*sp_System).ColdTempSamplingFlag = 1;
	}
	ADC_RESET();

}
//void SenSingOfDAQ(SYSTEM_FILE *sp_System)
//{
//	unsigned int ui_i = 0;
//
//	SRAM_CS_Select(0); //  0 = Non Select SRAM
//	ADC_RESET();
//	AD7609_Convert();
//
//	for(ui_i = 0;  ui_i < AD7609_MAX_CHANNEL; ui_i+=8)
//	{
//		AD7609_Read(&(*sp_System).al_SensAD7609[ui_i], OVER_SAMPLING_32, (unsigned int)(ui_i / 8));
// 	}
//
//	for(ui_i = 0;  ui_i < AD7609_MAX_CHANNEL; ui_i++)
//	{
//		(*sp_System).s_AD7609[ui_i].f_Buffer[(*sp_System).BufferCounter] =
//				(float)(((float)(*sp_System).al_SensAD7609[ui_i] * (*sp_System).f_GainAD7609[ui_i]) + (*sp_System).f_OffsetAD7609[ui_i]);
//	}
//
//	AD7606_Read(&(*sp_System).ai_SensColdTemp[0], OVER_SAMPLING_32);
//
//	for(ui_i = 0;  ui_i < COLD_TEMP_MAX_CHANNEL; ui_i++)
//	{
//		(*sp_System).s_ColdTemp[ui_i].f_Buffer[(*sp_System).BufferCounter] =
//				(float)(((*sp_System).ai_SensColdTemp[ui_i] * (*sp_System).f_GainColdTemp[ui_i]) + (*sp_System).f_OffsetColdTemp[ui_i]);
//	}
//
//	if(++(*sp_System).BufferCounter >= SAMPLING_MAX_DATA)
//	{
//		(*sp_System).BufferCounter = 0;
//	}
//	ADC_RESET();
//
//}

//(*sp_System).HighVoltageSamplingFlag++;
//(*sp_System).LowVoltageSamplingFlag++;
//(*sp_System).ThermistorSamplingFlag++;
//(*sp_System).ThermocoupleSamplingFlag++;

void HighVoltageCONV(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
	unsigned int ui_i = 0;
	unsigned int ui_j = 0;
	float f_Sum = 0;

	if((*sp_System).HighVoltageSamplingFlag >= 1)
	{
		(*sp_System).HighVoltageSamplingFlag = 0;

		for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
		{
			InsertionSort(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA - 1);

			f_Sum = 0.0;
			for(ui_j = 10; ui_j < (SAMPLING_MAX_DATA - 10); ui_j++)
			{
				f_Sum += (*sp_System).s_AD7609[ui_i].f_Buffer[ui_j];
			}
			f_Sum /= (float)(ui_j);

			(*sp_System).f_ResultAD7609[ui_i]  = f_Sum;
			(*sp_System).f_ResultAD7609[ui_i] *= HIGH_VOLTAGE_GAIN;
		}
	}
}

void LowVoltageCONV(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
//	unsigned int ui_i = 0;
//
//	for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
//	{
//		(*sp_System).f_ResultAD7609[ui_i] = RootMeanSquare(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA);
//		(*sp_System).f_ResultAD7609[ui_i] *= LOW_VOLTAGE_GAIN;
//	}

	unsigned int ui_i = 0;
	unsigned int ui_j = 0;
	float f_Sum = 0;

	if((*sp_System).LowVoltageSamplingFlag >= 1)
	{
		(*sp_System).LowVoltageSamplingFlag = 0;

		for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
		{
			InsertionSort(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA - 1);

			f_Sum = 0.0;
			for(ui_j = 10; ui_j < (SAMPLING_MAX_DATA - 10); ui_j++)
			{
				f_Sum += (*sp_System).s_AD7609[ui_i].f_Buffer[ui_j];
			}
			f_Sum /= (float)(10);

			(*sp_System).f_ResultAD7609[ui_i]  = f_Sum;
			(*sp_System).f_ResultAD7609[ui_i] *= LOW_VOLTAGE_GAIN;
		}
	}
}

void ThermistorCONV(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
	unsigned int ui_i = 0;

	for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
	{
		(*sp_System).f_ResultAD7609[ui_i] = RootMeanSquare(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA);
		(*sp_System).f_ResultAD7609[ui_i] = 4.7 - (*sp_System).f_ResultAD7609[ui_i];
		(*sp_System).f_ResultAD7609[ui_i] *= THERMISTOR_GAIN;
	}
}

void ThermocoupleCONV(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
//	unsigned int ui_i = 0;
//
//	float f_Temp = 0.0;
//	float f_ColdTemp = 0.0;
//
//	for(ui_i = 0; ui_i < 4; ui_i++)f_ColdTemp += (*sp_System).f_ResultColdTemp[ui_i];
//	f_ColdTemp /=(float)(4.0);
//
//	for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
//	{
//		f_Temp  = RootMeanSquare(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA);
//		f_Temp *= THERMOCOUPLE_GAIN_K;
//
//
//		(*sp_System).f_ResultAD7609[ui_i] = THERMOCOUPLE_POLYNOMIAL_K_TYPE(f_Temp); //K_Type
//		(*sp_System).f_ResultAD7609[ui_i] += f_ColdTemp;
//
//		//(*sp_System).f_ResultAD7609[ui_i] = THERMOCOUPLE_POLYNOMIAL(f_Temp); //T_Type
//		//(*sp_System).f_ResultAD7609[ui_i] += (*sp_System).f_ResultColdTemp[((unsigned int)(ui_i/ 8) % 4)];
//
//		//(*sp_System).f_ResultAD7609[ui_i] = f_Temp; //CAL
//	}

	unsigned int ui_i = 0;
	unsigned int ui_j = 0;
	float f_Sum = 0;

//	float f_Temp = 0.0;
	float f_ColdTemp = 0.0;

	for(ui_i = 0; ui_i < 4; ui_i++)f_ColdTemp += (*sp_System).f_ResultColdTemp[ui_i];
	f_ColdTemp /=(float)(4.0);
	f_ColdTemp +=(float)(-0.551999999999996); //smyeo offset ess 장비 있는 곳 offset


	if((*sp_System).ThermocoupleSamplingFlag >= 1)
	{
		(*sp_System).ThermocoupleSamplingFlag = 0;

		for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
		{
			InsertionSort(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA - 1);

			f_Sum = 0.0;
			for(ui_j = 10; ui_j < (SAMPLING_MAX_DATA - 10); ui_j++)
			{
				f_Sum += (*sp_System).s_AD7609[ui_i].f_Buffer[ui_j];
			}
			f_Sum /= (float)(10.0);

			f_Sum *= THERMOCOUPLE_GAIN_K;

			if(f_Sum > 4.096)
			{
				(*sp_System).f_ResultAD7609[ui_i] = THERMOCOUPLE_POLYNOMIAL_K100_TYPE(f_Sum); //K_Type
				(*sp_System).f_ResultAD7609[ui_i] += f_ColdTemp;

				(*sp_System).f_ResultAD7609[ui_i] += (*sp_System).f_OffsetAD7609K100[ui_i];
				(*sp_System).f_ResultAD7609[ui_i] *= (*sp_System).f_GainAD7609K100[ui_i];
			}
			else
			{
				(*sp_System).f_ResultAD7609[ui_i] = THERMOCOUPLE_POLYNOMIAL_K_TYPE(f_Sum); //K_Type
				(*sp_System).f_ResultAD7609[ui_i] += f_ColdTemp;

				(*sp_System).f_ResultAD7609[ui_i] += (*sp_System).f_OffsetAD7609K[ui_i];
				(*sp_System).f_ResultAD7609[ui_i] *= (*sp_System).f_GainAD7609K[ui_i];
			}

			//(*sp_System).f_ResultAD7609[ui_i] = THERMOCOUPLE_POLYNOMIAL(f_Sum); //T_Type
			//(*sp_System).f_ResultAD7609[ui_i] += (*sp_System).f_ResultColdTemp[((unsigned int)(ui_i/ 8) % 4)];

//			(*sp_System).f_ResultAD7609[ui_i] = f_Sum; //CAL
		}
	}

}

void ColdTemperatureCONV(SYSTEM_FILE *sp_System)
{
//	unsigned int ui_i = 0;
//	float f_Temp = 0.0;
//	ColdTempSamplingFlag
//	for(ui_i = 0; ui_i < 4; ui_i++)
//	{
//		f_Temp  = RootMeanSquare(&(*sp_System).s_ColdTemp[ui_i].f_Buffer[0], SAMPLING_MAX_DATA);
//		f_Temp *= COLD_TEMP_GAIN;
//		(*sp_System).f_ResultColdTemp[ui_i] = COLD_TEMP_POLYNOMIAL(f_Temp);
//	}

	unsigned int ui_i = 0;
	unsigned int ui_j = 0;

	float f_Sum = 0;

	if((*sp_System).ColdTempSamplingFlag >= 1)
	{
		(*sp_System).ColdTempSamplingFlag = 0;

		for(ui_i = 0; ui_i < 4; ui_i++)
		{
			InsertionSort(&(*sp_System).s_ColdTemp[ui_i].f_Buffer[0], SAMPLING_MAX_DATA - 1);

			f_Sum = 0.0;
			for(ui_j = 10; ui_j < (SAMPLING_MAX_DATA - 10); ui_j++)
			{
				f_Sum += (*sp_System).s_ColdTemp[ui_i].f_Buffer[ui_j];
			}
			f_Sum /= (float)(10.0);
			f_Sum *= COLD_TEMP_GAIN;
			(*sp_System).f_ResultColdTemp[ui_i] = COLD_TEMP_POLYNOMIAL(f_Sum);
		}
	}
}

double Square(float f_Data, unsigned int ui_Number)
{
	unsigned int ui_i = 0;
	double d_Temp = (double)(f_Data);

	for(ui_i = 0; ui_i < (ui_Number - 1); ui_i++)
	{
		d_Temp *= ((double)(f_Data));
	}
	return (d_Temp);
}


//=====================================================================
// ID NUMBER : to match project code with DAQ        - JS
void IDNUMBER(){
    unsigned char *uc_TxState = {0,};

#ifdef RS_232_ENABLE
    Rs232_Puts(RS_STX);
#endif

#ifdef RS_485_ENABLE
    Rs485_Puts(RS_STX);
#endif

    uc_TxState = "5V300A8CH_01"; // sk 개조건 코드 매칭 : 뒷 번호 1~20 바꾸기

#ifdef RS_232_ENABLE
    Rs232_Wirte(&uc_TxState[0], 12);
#endif

#ifdef RS_485_ENABLE
    Rs485_Wirte(&uc_TxState[0], 12);
#endif



#ifdef RS_232_ENABLE
Rs232_Puts(RS_ETX);
#endif

#ifdef RS_485_ENABLE
Rs485_Puts(RS_ETX);
#endif

#ifdef DEBUG_MODE_RX485

Rs485_Puts(0x0D);//Carriage Return
Rs485_Puts(0x0A);//Line Feed

#endif
}
//=====================================================================




//===========================================================================
// End of file.
//===========================================================================
