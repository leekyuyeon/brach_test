#include "..\Header\DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "..\Header\DSP2833x_Examples.h"   // DSP2833x Examples Include File

void AD7606_Convert(void)
{
	ADC_RESET();
	ADC_RESET();
	AD7606_CONVST();
}

void ADC_OverSampleSet(unsigned int ui_OverSampleValue)
{
	switch(ui_OverSampleValue)
	{
		case OVER_SAMPLING_02 : OVER_SAMPLING_02(); break;
		case OVER_SAMPLING_08 : OVER_SAMPLING_08(); break;
		case OVER_SAMPLING_32 : OVER_SAMPLING_32(); break;
		default				  : OVER_SAMPLING_02(); break;
	}
	DELAY_US(1);
}

int AD7606_Read(volatile int* ia_ConversionData, unsigned int ui_OverSampleValue)
{
	unsigned int ui_i = 0;
	nWE0_CLEAR();
	//AD7609_REST();
	ADC_OverSampleSet(ui_OverSampleValue);

	AD7606_Convert();
	SRAM_CS_Select(0); //  0 = Non Select SRAM
	DELAY_US(6 * ui_OverSampleValue);

	COLD_ADC_CS_SET();
	DELAY_US(2);
	for(ui_i = COLD_TEMP_MAX_CHANNEL; ui_i > 0 ; ui_i--)//Read Data
	{
		ia_ConversionData[ui_i - 1] = AD7606_RD_DATA();
	}

	COLD_ADC_CS_CLEAR();
//	nWE0_SET();
	return (TRUE);
}

void AD7609_Convert(void)
{
	SRAM_CS_Select(0); //  0 = Non Select SRAM
	COLD_ADC_CS_CLEAR();
	AD7609_CONVST();
}

int AD7609_Read(volatile long* al_ConversionData, unsigned int ui_OverSampleValue, unsigned int ui_Channel)
{
	int ai_Temp = 0;
	unsigned int aui_Temp = 0;
	const unsigned int cui_400us = 400;
	const unsigned int cu_Address[16] = {3,2,1,0, 7,6,5,4, 11,10,9,8, 15,14,13,12};

	unsigned int ui_i = 0;

	unsigned long ul_ChannelAddress = ADC7609_CS_BASE;

	unsigned int ui_Timer = 0;
	//int i_Temp = 0;

	nWE0_SET();
	ul_ChannelAddress += (unsigned long)(ADC7609_CS_STEP * cu_Address[ui_Channel]);

//	AD7609_Convert();

	while(1)//Busy Chack
	{
		DELAY_US(1);

		if(CLEAR == BUSY_ADC())break;

		if(ui_Timer++ >= cui_400us)
		{
			ADC_RESET();
			return (FALSE);
		}
	}

	for(ui_i = 0; ui_i < 8; ui_i++)
	{
		ai_Temp = (int)(*(volatile int*) ul_ChannelAddress);
		aui_Temp = (unsigned int)(*(volatile int*) ul_ChannelAddress);

		al_ConversionData[ui_i] = (long)(ai_Temp);
		al_ConversionData[ui_i] *= 4;
		al_ConversionData[ui_i] +=(long)(aui_Temp >> 14);
	}

	AD7609_REST();
//	nWE0_CLEAR();
	return (TRUE);
}

void SRAM_CS_Select(unsigned int ui_SRM_Number)
{
	SRAM_CARD00_CLEAR();
	SRAM_CARD01_CLEAR();
	SRAM_CARD02_CLEAR();
	SRAM_CARD03_CLEAR();
	SRAM_CARD04_CLEAR();
	SRAM_CARD05_CLEAR();
	SRAM_CARD06_CLEAR();
	SRAM_CARD07_CLEAR();
	SRAM_CARD08_CLEAR();
	SRAM_CARD09_CLEAR();
	SRAM_CARD10_CLEAR();
	SRAM_CARD11_CLEAR();
	SRAM_CARD12_CLEAR();
	SRAM_CARD13_CLEAR();

	switch (ui_SRM_Number)
	{
		case 1:  SRAM_CARD00_SET();break;
		case 2:  SRAM_CARD01_SET();break;
		case 3:  SRAM_CARD02_SET();break;
		case 4:  SRAM_CARD03_SET();break;
		case 5:  SRAM_CARD04_SET();break;
		case 6:  SRAM_CARD05_SET();break;
		case 7:  SRAM_CARD06_SET();break;
		case 8:  SRAM_CARD07_SET();break;
		case 9:  SRAM_CARD08_SET();break;
		case 10: SRAM_CARD09_SET();break;
		case 11: SRAM_CARD10_SET();break;
		case 12: SRAM_CARD11_SET();break;
		case 13: SRAM_CARD12_SET();break;
		case 14: SRAM_CARD13_SET();break;
		case 15: SRAM_CARD14_SET();break;
		case 16: SRAM_CARD15_SET();break;
		default : break;
	}
	DELAY_US(1);
}

void Rs485_Puts(unsigned char ui_Char)
{

    GpioDataRegs.GPASET.bit.GPIO20 = 1;
    GpioDataRegs.GPASET.bit.GPIO21 = 1;
    GpioDataRegs.GPASET.bit.GPIO22 = 1;

    while (!ScicRegs.SCICTL2.bit.TXRDY);
    ScicRegs.SCITXBUF = (ui_Char & 0x00FF);
    asm(" RPT #20 || NOP");
    //133.4ns

    while (!ScicRegs.SCICTL2.bit.TXEMPTY);
    asm(" RPT #20 || NOP");
    //133.4ns

    GpioDataRegs.GPACLEAR.bit.GPIO20 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO21 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO22 = 1;

}

void Rs485_Wirte(unsigned char *ui_String, unsigned int ui_Length)
{
	unsigned int ui_Count = 0;

	for(ui_Count = 0; ui_Count < ui_Length; ui_Count++)Rs485_Puts(ui_String[ui_Count]);

}

void Rs232_Puts(unsigned char ui_Char)
{
	while(!ScibRegs.SCICTL2.bit.TXRDY);
	ScibRegs.SCITXBUF = (ui_Char & 0x00FF);
	asm(" RPT #20 || NOP"); //133.4ns

	while(!ScibRegs.SCICTL2.bit.TXEMPTY);
	asm(" RPT #20 || NOP"); //133.4ns
}

void Rs232_Wirte(unsigned char *ui_String, unsigned int ui_Length)
{
	unsigned int ui_Count = 0;

	for(ui_Count = 0; ui_Count < ui_Length; ui_Count++)Rs232_Puts(ui_String[ui_Count]);

}

//===========================================================================
// End of file.
//===========================================================================
