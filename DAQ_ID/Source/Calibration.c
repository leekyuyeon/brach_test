#include "..\Header\DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "..\Header\DSP2833x_Examples.h"   // DSP2833x Examples Include File
/*
 * CalibrationData.c
 *
 *  Created on: 2016. 9. 8.
 *      Author: BGKim
 */
FLASH_ST FlashStatus;

extern Uint32 Flash_CPUScaleFactor;

SECTOR Sector[8] = {
         (Uint16 *)0x338000,(Uint16 *)0x33FFFF,
         (Uint16 *)0x330000,(Uint16 *)0x337FFF,
         (Uint16 *)0x328000,(Uint16 *)0x32FFFF,
         (Uint16 *)0x320000,(Uint16 *)0x327FFF,
         (Uint16 *)0x318000,(Uint16 *)0x31FFFF,
         (Uint16 *)0x310000,(Uint16 *)0x317FFF,
         (Uint16 *)0x308000,(Uint16 *)0x30FFFF,
         (Uint16 *)0x300000,(Uint16 *)0x307FFF
};

void InitFlashAPI(void)
{
	float32 Version;        // Version of the API in floating point
	Uint16  VersionHex;     // Version of the API in decimal encoded hex

	MemCopy(&Flash28_API_LoadStart, &Flash28_API_LoadEnd, &Flash28_API_RunStart);
	Flash_CPUScaleFactor = SCALE_FACTOR;
	VersionHex = Flash_APIVersionHex();

	if(VersionHex != 0x0210)
	{
	    // Unexpected API version
	    // Make a decision based on this info.
	    asm("    ESTOP0");
	}

	Version = Flash_APIVersion();
	if(Version != (float32)2.10)
	{
	    // Unexpected API version
	    // Make a decision based on this info.
	    asm("    ESTOP0");
	}
}

void CalibrationProgram(void)
{
	CON_F32TOUI16 Temp;

    unsigned int ui_i = 0;
    unsigned int ui_j = 0;
    unsigned int  ui_Status;
    unsigned int  *Flash_ptr;     // Pointer to a location in flash
    unsigned long  ul_Length;         // Number of 16-bit values to be programmed
    unsigned int ui_Buffer[(AD7609_MAX_CHANNEL * 2)] = {0, };
    DINT;
    DisableDog();
    //CalibrationProgram_Done();
    ui_Status = Flash_Erase((SECTORB|SECTORC),&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }

//GainColdTemp
    for(ui_i = 0, ui_j = 0; ui_i < COLD_TEMP_MAX_CHANNEL; ui_i++)
	{
    	Temp.f_32bit = s_System.f_GainColdTemp[ui_i];
    	ui_Buffer[ui_j++] = Temp.uai_16bit[0];
    	ui_Buffer[ui_j++] = Temp.uai_16bit[1];
	}
    Flash_ptr = Sector[1].StartAddr;
    ul_Length = (COLD_TEMP_MAX_CHANNEL * 2);
    ui_Status = Flash_Program(Flash_ptr,ui_Buffer,ul_Length,&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }
    ui_Status = Flash_Verify(Flash_ptr,ui_Buffer,ul_Length,&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }
//OffsetColdTemp
    for(ui_i = 0, ui_j = 0; ui_i < COLD_TEMP_MAX_CHANNEL; ui_i++)
	{
    	Temp.f_32bit = s_System.f_OffsetColdTemp[ui_i];
    	ui_Buffer[ui_j++] = Temp.uai_16bit[0];
    	ui_Buffer[ui_j++] = Temp.uai_16bit[1];
	}
    Flash_ptr = Sector[1].StartAddr + 0x100;
    ul_Length = (COLD_TEMP_MAX_CHANNEL * 2);
    ui_Status = Flash_Program(Flash_ptr,ui_Buffer,ul_Length,&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }
    ui_Status = Flash_Verify(Flash_ptr,ui_Buffer,ul_Length,&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }
 //GainAD7609
    for(ui_i = 0, ui_j = 0; ui_i < AD7609_MAX_CHANNEL; ui_i++)
	{
    	Temp.f_32bit = s_System.f_GainAD7609[ui_i];
    	ui_Buffer[ui_j++] = Temp.uai_16bit[0];
    	ui_Buffer[ui_j++] = Temp.uai_16bit[1];
	}
    Flash_ptr = Sector[1].StartAddr + 0x200;
    ul_Length = (AD7609_MAX_CHANNEL * 2);
    ui_Status = Flash_Program(Flash_ptr,ui_Buffer,ul_Length,&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }
    ui_Status = Flash_Verify(Flash_ptr,ui_Buffer,ul_Length,&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }
//OffsetAD7609
    for(ui_i = 0, ui_j = 0; ui_i < AD7609_MAX_CHANNEL; ui_i++)
	{
    	Temp.f_32bit = s_System.f_OffsetAD7609[ui_i];
    	ui_Buffer[ui_j++] = Temp.uai_16bit[0];
    	ui_Buffer[ui_j++] = Temp.uai_16bit[1];
	}
    Flash_ptr = Sector[1].StartAddr + 0x300;
    ul_Length = (AD7609_MAX_CHANNEL * 2);
    ui_Status = Flash_Program(Flash_ptr,ui_Buffer,ul_Length,&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }
    ui_Status = Flash_Verify(Flash_ptr,ui_Buffer,ul_Length,&FlashStatus);
    if(ui_Status != STATUS_SUCCESS)
    {
    	CalibrationProgram_Error(ui_Status);
    }

	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM

	EALLOW;
	SysCtrlRegs.WDCR = 0x002F;
	EDIS;

}
void CalibrationRead(void)
{
	CON_F32TOUI16 Temp;

	unsigned int ui_i = 0;
	unsigned int *Flash_ptr = Sector[1].StartAddr;

	for(ui_i = 0; ui_i < COLD_TEMP_MAX_CHANNEL; ui_i++)
    {

		Temp.uai_16bit[0] =(*(unsigned int *)(Flash_ptr++));
        Temp.uai_16bit[1] =(*(unsigned int *)(Flash_ptr++));
        s_System.f_GainColdTemp[ui_i] = (float)Temp.f_32bit;
    }
    Flash_ptr = Sector[1].StartAddr + 0x100;
	for(ui_i = 0; ui_i < COLD_TEMP_MAX_CHANNEL; ui_i++)
    {

		Temp.uai_16bit[0] =(*(unsigned int *)(Flash_ptr++));
        Temp.uai_16bit[1] =(*(unsigned int *)(Flash_ptr++));
        s_System.f_OffsetColdTemp[ui_i] = (float)Temp.f_32bit;
    }
    Flash_ptr = Sector[1].StartAddr + 0x200;
	for(ui_i = 0; ui_i < AD7609_MAX_CHANNEL; ui_i++)
    {

		Temp.uai_16bit[0] =(*(unsigned int *)(Flash_ptr++));
        Temp.uai_16bit[1] =(*(unsigned int *)(Flash_ptr++));
        s_System.f_GainAD7609[ui_i] = (float)Temp.f_32bit;
    }
    Flash_ptr = Sector[1].StartAddr + 0x300;
	for(ui_i = 0; ui_i < AD7609_MAX_CHANNEL; ui_i++)
    {

		Temp.uai_16bit[0] =(*(unsigned int *)(Flash_ptr++));
        Temp.uai_16bit[1] =(*(unsigned int *)(Flash_ptr++));
        s_System.f_OffsetAD7609[ui_i] = (float)Temp.f_32bit;
    }

    //CalibrationProgram_Done();
}
void CalibrationProgram_Error(Uint16 Status)
{
    asm("    ESTOP0");
    asm("    SB 0, UNC");
}

void CalibrationProgram_Done(void)
{
    asm("    ESTOP0");
//    asm("    SB 0, UNC");
}

void CalibrationHighVoltage(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
	unsigned int ui_i = 0;
	unsigned int ui_j = 0;

	float f_Temp = 0.0;

	for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
	{
		while(1)
		{
			if((*sp_System).f_ResultAD7609[ui_i] > (*sp_System).f_CalibrationData)
			{
				if((*sp_System).i_Calibrationflag)//SET=Gain, CLEAR=Offset
				{
					(*sp_System).f_GainAD7609[ui_i] -= HIGH_VOLTAGE_GAIN_SCALE;
				}
				else
				{
					(*sp_System).f_OffsetAD7609[ui_i] -= HIGH_VOLTAGE_GAIN_SCALE;
				}
			}
			else if((*sp_System).f_ResultAD7609[ui_i] < (*sp_System).f_CalibrationData)
			{
				if((*sp_System).i_Calibrationflag)
				{
					(*sp_System).f_GainAD7609[ui_i] += HIGH_VOLTAGE_GAIN_SCALE;
				}
				else
				{
					(*sp_System).f_OffsetAD7609[ui_i] += HIGH_VOLTAGE_GAIN_SCALE;
				}
			}
			else if((*sp_System).f_ResultAD7609[ui_i] == (*sp_System).f_CalibrationData)break;


			for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)SenSingOfDAQ(sp_System);

			(*sp_System).f_ResultAD7609[ui_i] = RootMeanSquare(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA);
			(*sp_System).f_ResultAD7609[ui_i] *= HIGH_VOLTAGE_GAIN;


			f_Temp = (*sp_System).f_ResultAD7609[ui_i] - (*sp_System).f_CalibrationData;

			if(f_Temp <= 0.001 && f_Temp >= -0.001)break;
		}
	}
	CalibrationProgram();
}
void CalibrationLowVoltage(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
	unsigned int ui_i = 0;
	unsigned int ui_j = 0;

	float f_Temp = 0.0;

	for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
	{
		while(1)
		{
			if((*sp_System).f_ResultAD7609[ui_i] > (*sp_System).f_CalibrationData)
			{
				if((*sp_System).i_Calibrationflag)//SET=Gain, CLEAR=Offset
				{
					(*sp_System).f_GainAD7609[ui_i] -= LOW_VOLTAGE_GAIN_SCALE;
				}
				else
				{
					(*sp_System).f_OffsetAD7609[ui_i] -= LOW_VOLTAGE_GAIN_SCALE;
				}
			}
			else if((*sp_System).f_ResultAD7609[ui_i] < (*sp_System).f_CalibrationData)
			{
				if((*sp_System).i_Calibrationflag)
				{
					(*sp_System).f_GainAD7609[ui_i] += LOW_VOLTAGE_GAIN_SCALE;
				}
				else
				{
					(*sp_System).f_OffsetAD7609[ui_i] += LOW_VOLTAGE_GAIN_SCALE;
				}
			}
			else if((*sp_System).f_ResultAD7609[ui_i] == (*sp_System).f_CalibrationData)break;


			for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)SenSingOfDAQ(sp_System);


			(*sp_System).f_ResultAD7609[ui_i] = RootMeanSquare(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA);
			(*sp_System).f_ResultAD7609[ui_i] *= LOW_VOLTAGE_GAIN;


			f_Temp = (*sp_System).f_ResultAD7609[ui_i] - (*sp_System).f_CalibrationData;

			if(f_Temp <= 0.001 && f_Temp >= -0.001)break;
		}
	}
	CalibrationProgram();
}

void CalibrationHighThermocouple(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
	unsigned int ui_i = 0;
	unsigned int ui_j = 0;
	unsigned int ui_Flag = 0;

	float f_Temp = 0.0;

	for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
	{
		while(1)
		{
			if((*sp_System).f_ResultAD7609[ui_i] > (*sp_System).f_CalibrationData)
			{
				if((*sp_System).i_Calibrationflag)//SET=Gain, CLEAR=Offset
				{
					if(ui_Flag)(*sp_System).f_GainAD7609[ui_i] -= THERMOCOUPLE_GAIN_SCALE;
					else (*sp_System).f_GainAD7609[ui_i] += THERMOCOUPLE_GAIN_SCALE;
				}
				else
				{
					(*sp_System).f_OffsetAD7609[ui_i] -= THERMOCOUPLE_OFFSET_SCALE;
				}
			}
			else if((*sp_System).f_ResultAD7609[ui_i] < (*sp_System).f_CalibrationData)
			{
				if((*sp_System).i_Calibrationflag)
				{
					if(ui_Flag)(*sp_System).f_GainAD7609[ui_i] += THERMOCOUPLE_GAIN_SCALE;
					else (*sp_System).f_GainAD7609[ui_i] -= THERMOCOUPLE_GAIN_SCALE;
				}
				else
				{
					(*sp_System).f_OffsetAD7609[ui_i] += THERMOCOUPLE_OFFSET_SCALE;
				}
			}
			else if((*sp_System).f_ResultAD7609[ui_i] == (*sp_System).f_CalibrationData)break;


			for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)SenSingOfDAQ(sp_System);


			f_Temp  = RootMeanSquare(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA);
			f_Temp *= THERMOCOUPLE_GAIN_K;

			(*sp_System).f_ResultAD7609[ui_i] = THERMOCOUPLE_POLYNOMIAL(f_Temp);

			if((*sp_System).f_ResultAD7609[ui_i] >= 0.0)ui_Flag = 1;
			else ui_Flag = 0;

			(*sp_System).f_ResultAD7609[ui_i] += (*sp_System).f_ResultColdTemp[((unsigned int)(ui_i/ 8) % 4)];


			f_Temp = (*sp_System).f_ResultAD7609[ui_i] - (*sp_System).f_CalibrationData;

			if(f_Temp <= 0.001 && f_Temp >= -0.001)break;
		}
	}
	CalibrationProgram();
}

void CalibrationHighThermistor(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress)
{
	unsigned int ui_i = 0;
	unsigned int ui_j = 0;

	float f_Temp = 0.0;

	for(ui_i = (ui_StartAddress - 1); ui_i < ui_EndAddress; ui_i++)
	{
		while(1)//47kOhm Reference Register * 100uV CC = 4.7V (1kOhm is Output of 0.1V)
		{		//Range 1KOhm ~ 100KOhm (100kOhm is Output of -5.3V)
			if((*sp_System).f_ResultAD7609[ui_i] > (*sp_System).f_CalibrationData)
			{
				if((*sp_System).i_Calibrationflag)//SET=Gain, CLEAR=Offset
				{
					(*sp_System).f_GainAD7609[ui_i] += THERMISTOR_GAIN_SCALE;
				}
				else
				{
					(*sp_System).f_OffsetAD7609[ui_i] += THERMISTOR_OFFSET_SCALE;
				}
			}
			else if((*sp_System).f_ResultAD7609[ui_i] < (*sp_System).f_CalibrationData)
			{
				if((*sp_System).i_Calibrationflag)
				{
					(*sp_System).f_GainAD7609[ui_i] -= THERMISTOR_GAIN_SCALE;
				}
				else
				{
					(*sp_System).f_OffsetAD7609[ui_i] -= THERMISTOR_OFFSET_SCALE;
				}
			}
			else if((*sp_System).f_ResultAD7609[ui_i] == (*sp_System).f_CalibrationData)break;


			for(ui_j = 0; ui_j < SAMPLING_MAX_DATA; ui_j++)SenSingOfDAQ(sp_System);

			(*sp_System).f_ResultAD7609[ui_i] = RootMeanSquare(&(*sp_System).s_AD7609[ui_i].f_Buffer[0], SAMPLING_MAX_DATA);
			(*sp_System).f_ResultAD7609[ui_i] = 4.7 - (*sp_System).f_ResultAD7609[ui_i];
			(*sp_System).f_ResultAD7609[ui_i] *= THERMISTOR_GAIN;

			f_Temp = (*sp_System).f_ResultAD7609[ui_i] - (*sp_System).f_CalibrationData;

			if(f_Temp <= 0.1 && f_Temp >= -0.1)break;
		}
	}
	CalibrationProgram();
}
//===========================================================================
// End of file.
//===========================================================================
