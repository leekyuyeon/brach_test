//###########################################################################
//
// FILE:   DSP2833x_Xintf.h
//
// TITLE:  DSP2833x Device External Interface Register Definitions.
//
//###########################################################################
// $TI Release: F2833x/F2823x Header Files and Peripheral Examples V141 $
// $Release Date: November  6, 2015 $
// $Copyright: Copyright (C) 2007-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef EXTERNALDEVICE_H
#define EXTERNALDEVICE_H


#ifdef __cplusplus
extern "C" {
#endif

#define SET   		(1)
#define CLEAR 		(0)
#define ENABLE 		(1)
#define DISENABLE 	(0)
#define ON 			(1)
#define OFF 		(0)
#define TRUE		(1)
#define FALSE 		(0)
#define INPUT		(0)
#define OUTPUT		(1)

#define	ADC7609_CS_BASE  0x004080
#define ADC7609_CS_STEP  0x10
#define ADC7609_CS_CLEAR 0x004000

#define ADC7609_CS00_SET 0x004080
#define	ADC7609_CS01_SET 0x004090
#define	ADC7609_CS02_SET 0x0040A0
#define	ADC7609_CS03_SET 0x0040B0
#define	ADC7609_CS04_SET 0x0040C0
#define	ADC7609_CS05_SET 0x0040D0
#define	ADC7609_CS06_SET 0x0040E0
#define	ADC7609_CS07_SET 0x0040F0

#define	ADC7609_CS08_SET 0x004180
#define	ADC7609_CS09_SET 0x004190
#define	ADC7609_CS10_SET 0x0041A0
#define	ADC7609_CS11_SET 0x0041B0
#define	ADC7609_CS12_SET 0x0041C0
#define	ADC7609_CS13_SET 0x0041D0
#define	ADC7609_CS14_SET 0x0041E0
#define	ADC7609_CS15_SET 0x0041F0

#define SYSTEM_CLOCK_SPPED 		(150E6)

#define CPU_TIMER_1S    		(1.0E6)
#define CPU_TIMER_1MS			(1.0E3)
#define CPU_TIMER_1US			(1.0)

#define RAM_ZONE_6_BASE   		(0x0100000)
#define RAM_ZONE_7_BASE  		(0x0200000)
#define RAM_SIZE	  			102400	// 2048K / 20 Word = 102400
#define RAM_OFFSET	 			 51200		// 2048K / 20 Word / 2 = 51,200

#define AD7606_SCALE 	  		(0.000152587890625)//(152.6E-6)

#define AD7609_DEFAULT_GAIN 	(4.0)
#define AD7609_5V_SCALE   		(0.000076293945312)
#define AD7609_10V_SCALE  		(0.000152587890625)
#define AD7609_SCALE 	  		(0.000076293945312)

#define AD7609_REST()			{(*(volatile int*)ADC7609_CS_CLEAR) = 0;}
#define AD7606_RD_DATA()		(int)(*(volatile int*)0x4000)

#define ADC_RESET()		    	{DSP_RESET_ADC_SET(); asm(" RPT #100 || NOP"); DSP_RESET_ADC_CLEAR();}

#define AD7606_CONVST()			{COLD_CNVT_ADC_SET(); asm(" RPT #100 || NOP"); COLD_CNVT_ADC_CLEAR();}
#define AD7609_CONVST()			{DSP_CNVT_ADC_SET();  asm(" RPT #100 || NOP"); DSP_CNVT_ADC_CLEAR(); }

#define OVER_SAMPLING_02()		{ADC_OS2_CLEAR(); ADC_OS1_CLEAR();}
#define OVER_SAMPLING_08()		{ADC_OS2_CLEAR(); ADC_OS1_SET();  }
#define OVER_SAMPLING_32()		{ADC_OS2_SET();   ADC_OS1_CLEAR();}
#define OVER_SAMPLING_64()		{ADC_OS2_SET();   ADC_OS1_SET();  }

typedef union {
	float f_32bit;
	unsigned int uai_16bit[2];
}CON_L32TOI16;

enum
{
	OVER_SAMPLING_02			=2,
	OVER_SAMPLING_08			=8,
	OVER_SAMPLING_32			=32,
	OVER_SAMPLING_64			=64
};

void AD7606_Convert(void);
void ADC_OverSampleSet(unsigned int ui_OverSampleValue);
int  AD7606_Read(volatile int* ia_ConversionData, unsigned int ui_OverSampleValue);

void AD7609_Reset(void);
void AD7609_Convert(void);
int  AD7609_Read(volatile long* al_ConversionData, unsigned int ui_OverSampleValue, unsigned int ui_Channel);

void SRAM_CS_Select(unsigned int ui_SRM_Number);

void Rs485_Puts(unsigned char ui_Char);
void Rs485_Wirte(unsigned char *ui_String, unsigned int ui_Length);

void Rs232_Puts(unsigned char ui_Char);
void Rs232_Wirte(unsigned char *ui_String, unsigned int ui_Length);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_XINTF_H definition

//===========================================================================
// No more.
//===========================================================================
