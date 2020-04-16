//###########################################################################
//
// FILE:	DSP2833x_Gpio.c
//
// TITLE:	DSP2833x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: F2833x/F2823x Header Files and Peripheral Examples V141 $
// $Release Date: November  6, 2015 $
// $Copyright: Copyright (C) 2007-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "..\Header\DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "..\Header\DSP2833x_Examples.h"   // DSP2833x Examples Include File

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
   EALLOW;
   
   // Each GPIO pin can be: 
   // a) a GPIO input/output
   // b) peripheral function 1
   // c) peripheral function 2
   // d) peripheral function 3
   // By default, all are GPIO Inputs 
   GpioCtrlRegs.GPAMUX1.all = 0x0000;     // GPIO functionality GPIO0-GPIO15
   GpioCtrlRegs.GPAMUX2.all = 0x0000;     // GPIO functionality GPIO16-GPIO31
   GpioCtrlRegs.GPBMUX1.all = 0x0000;     // GPIO functionality GPIO32-GPIO39
   GpioCtrlRegs.GPBMUX2.all = 0x0000;     // GPIO functionality GPIO48-GPIO63
   GpioCtrlRegs.GPCMUX1.all = 0x0000;     // GPIO functionality GPIO64-GPIO79
   GpioCtrlRegs.GPCMUX2.all = 0x0000;     // GPIO functionality GPIO80-GPIO95

   GpioCtrlRegs.GPADIR.all = 0x0000;      // GPIO0-GPIO31 are inputs
   GpioCtrlRegs.GPBDIR.all = 0x0000;      // GPIO32-GPIO63 are inputs   
   GpioCtrlRegs.GPCDIR.all = 0x0000;      // GPI064-GPIO95 are inputs

   // Each input can have different qualification
   // a) input synchronized to SYSCLKOUT
   // b) input qualified by a sampling window
   // c) input sent asynchronously (valid for peripheral inputs only)
   GpioCtrlRegs.GPAQSEL1.all = 0x0000;    // GPIO0-GPIO15 Synch to SYSCLKOUT 
   GpioCtrlRegs.GPAQSEL2.all = 0x0000;    // GPIO16-GPIO31 Synch to SYSCLKOUT
   GpioCtrlRegs.GPBQSEL1.all = 0x0000;    // GPIO32-GPIO39 Synch to SYSCLKOUT 
   GpioCtrlRegs.GPBQSEL2.all = 0x0000;    // GPIO48-GPIO63 Synch to SYSCLKOUT 

   // Pull-ups can be enabled or disabled. 
   //GpioCtrlRegs.GPAPUD.all = 0x0000;      // Pullup's enabled GPIO0-GPIO31
   //GpioCtrlRegs.GPBPUD.all = 0x0000;      // Pullup's enabled GPIO32-GPIO63
   //GpioCtrlRegs.GPCPUD.all = 0x0000;      // Pullup's enabled GPIO64-GPIO79

   GpioCtrlRegs.GPAPUD.all = 0xFFFF;    // Pullup's disabled GPIO0-GPIO31
   GpioCtrlRegs.GPBPUD.all = 0xFFFF;    // Pullup's disabled GPIO32-GPIO34
   GpioCtrlRegs.GPCPUD.all = 0xFFFF;     // Pullup's disabled GPIO64-GPIO79

//bgkim add
   GpioCtrlRegs.GPAMUX1.bit.GPIO0  = 0;/*SRAM_CARD0*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO1  = 0;/*SRAM_CARD1*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO2  = 0;/*SRAM_CARD2*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO3  = 0;/*SRAM_CARD3*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO4  = 0;/*SRAM_CARD4*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO5  = 0;/*SRAM_CARD5*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO6  = 0;/*SRAM_CARD6*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO7  = 0;/*SRAM_CARD7*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO8  = 0;/*SRAM_CARD8*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO9  = 0;/*SRAM_CARD9*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;/*SRAM_CARD10*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;/*SRAM_CARD11*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;/*SRAM_CARD12*/
   GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;/*SRAM_CARD13*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 0;/*SRAM_CARD14*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 0;/*SRAM_CARD15*/
   GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;/*DSP_ADC_CS*/
   GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;/*RUN_LED*/
   GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 0;/*COLD_CNVT_ADC*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 0;/*ADC_OS2*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 0;/*ADC_OS1*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;/*TRIGGER_OUT7*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 0;/*TRIGGER_OUT6*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0;/*TRIGGER_OUT5*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 0;/*TRIGGER_OUT4*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;/*TRIGGER_OUT3*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;/*TRIGGER_OUT2*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0;/*TRIGGER_OUT1*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 0;/*TRIGGER_OUT0*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;/*DSP_RESET_ADC*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 0;/*DSP_CNVT_ADC*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0;/*TRIGGER_IN0*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0;/*TRIGGER_IN1*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;/*TRIGGER_IN2*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 0;/*TRIGGER_IN3*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;/*TRIGGER_IN4*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 0;/*TRIGGER_IN5*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;/*TRIGGER_IN6*/
   GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;/*TRIGGER_IN7*/
   GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 0;/*BUSY_ADC*/

   GpioCtrlRegs.GPBMUX1.bit.GPIO38 = 0;/*nWE*/

   GpioCtrlRegs.GPADIR.bit.GPIO0  = OUTPUT;/*SRAM_CARD0*/
   GpioCtrlRegs.GPADIR.bit.GPIO1  = OUTPUT;/*SRAM_CARD1*/
   GpioCtrlRegs.GPADIR.bit.GPIO2  = OUTPUT;/*SRAM_CARD2*/
   GpioCtrlRegs.GPADIR.bit.GPIO3  = OUTPUT;/*SRAM_CARD3*/
   GpioCtrlRegs.GPADIR.bit.GPIO4  = OUTPUT;/*SRAM_CARD4*/
   GpioCtrlRegs.GPADIR.bit.GPIO5  = OUTPUT;/*SRAM_CARD5*/
   GpioCtrlRegs.GPADIR.bit.GPIO6  = OUTPUT;/*SRAM_CARD6*/
   GpioCtrlRegs.GPADIR.bit.GPIO7  = OUTPUT;/*SRAM_CARD7*/
   GpioCtrlRegs.GPADIR.bit.GPIO8  = OUTPUT;/*SRAM_CARD8*/
   GpioCtrlRegs.GPADIR.bit.GPIO9  = OUTPUT;/*SRAM_CARD9*/
   GpioCtrlRegs.GPADIR.bit.GPIO10 = OUTPUT;/*SRAM_CARD10*/
   GpioCtrlRegs.GPADIR.bit.GPIO11 = OUTPUT;/*SRAM_CARD11*/
   GpioCtrlRegs.GPADIR.bit.GPIO12 = OUTPUT;/*SRAM_CARD12*/
   GpioCtrlRegs.GPADIR.bit.GPIO13 = OUTPUT;/*SRAM_CARD13*/
   GpioCtrlRegs.GPADIR.bit.GPIO16 = OUTPUT;/*SRAM_CARD14*/
   GpioCtrlRegs.GPADIR.bit.GPIO17 = OUTPUT;/*SRAM_CARD15*/
   GpioCtrlRegs.GPBDIR.bit.GPIO32 = OUTPUT;/*DSP_ADC_CS*/
   GpioCtrlRegs.GPBDIR.bit.GPIO34 = OUTPUT;/*RUN_LED*/
   GpioCtrlRegs.GPBDIR.bit.GPIO35 = OUTPUT;/*COLD_CNVT_ADC*/
   GpioCtrlRegs.GPBDIR.bit.GPIO48 = OUTPUT;/*ADC_OS2*/
   GpioCtrlRegs.GPBDIR.bit.GPIO49 = OUTPUT;/*ADC_OS1*/
   GpioCtrlRegs.GPBDIR.bit.GPIO52 = OUTPUT;/*TRIGGER_OUT7*/
   GpioCtrlRegs.GPBDIR.bit.GPIO53 = OUTPUT;/*TRIGGER_OUT6*/
   GpioCtrlRegs.GPBDIR.bit.GPIO54 = OUTPUT;/*TRIGGER_OUT5*/
   GpioCtrlRegs.GPBDIR.bit.GPIO55 = OUTPUT;/*TRIGGER_OUT4*/
   GpioCtrlRegs.GPBDIR.bit.GPIO56 = OUTPUT;/*TRIGGER_OUT3*/
   GpioCtrlRegs.GPBDIR.bit.GPIO57 = OUTPUT;/*TRIGGER_OUT2*/
   GpioCtrlRegs.GPBDIR.bit.GPIO58 = OUTPUT;/*TRIGGER_OUT1*/
   GpioCtrlRegs.GPBDIR.bit.GPIO59 = OUTPUT;/*TRIGGER_OUT0*/
   GpioCtrlRegs.GPBDIR.bit.GPIO60 = OUTPUT;/*DSP_RESET_ADC*/
   GpioCtrlRegs.GPBDIR.bit.GPIO61 = OUTPUT;/*DSP_CNVT_ADC*/
   GpioCtrlRegs.GPADIR.bit.GPIO20 = OUTPUT;/*TRIGGER_IN0*/
   GpioCtrlRegs.GPADIR.bit.GPIO21 = OUTPUT;/*TRIGGER_IN1*/
   GpioCtrlRegs.GPADIR.bit.GPIO22 = OUTPUT;/*TRIGGER_IN2*/
   GpioCtrlRegs.GPADIR.bit.GPIO23 = INPUT;/*TRIGGER_IN3*/
   GpioCtrlRegs.GPADIR.bit.GPIO24 = INPUT;/*TRIGGER_IN4*/
   GpioCtrlRegs.GPADIR.bit.GPIO25 = INPUT;/*TRIGGER_IN5*/
   GpioCtrlRegs.GPADIR.bit.GPIO26 = INPUT;/*TRIGGER_IN6*/
   GpioCtrlRegs.GPADIR.bit.GPIO27 = INPUT;/*TRIGGER_IN7*/
   GpioCtrlRegs.GPBDIR.bit.GPIO51 = INPUT;/*BUSY_ADC*/

   GpioCtrlRegs.GPBDIR.bit.GPIO38 = OUTPUT;/*nWE*/
   EDIS;

}	
	
//===========================================================================
// End of file.
//===========================================================================
