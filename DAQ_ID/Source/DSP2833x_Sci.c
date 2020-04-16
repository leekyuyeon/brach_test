//###########################################################################
//
// FILE:	DSP2833x_Sci.c
//
// TITLE:	DSP2833x SCI Initialization & Support Functions.
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
// InitSci: 
//---------------------------------------------------------------------------
// This function initializes the SCI(s) to a known state.
//
void InitSci(void)
{
//bgkim add
	unsigned int BRR = 0;

	// Initialize SCI-A:
//		BRR = (LSPCLK / (SCI_A_BAUD * 8)) - 1;
//
//	InitSciaGpio();
//
//	SciaRegs.SCICTL1.bit.SWRESET = 0;		// SCI 소프트웨어 리셋
//	SciaRegs.SCICCR.bit.SCICHAR = 7;		// SCI 송수신 Charcter-length 설정 : 8bit
//	SciaRegs.SCICCR.bit.LOOPBKENA = 0;		// SCI 루프백 테스트 모드 Enable
//	SciaRegs.SCICTL1.bit.RXENA = 1;			// SCI 송신기능 Enable
//	SciaRegs.SCICTL1.bit.TXENA = 1;			// SCI 수신기능 Enable
//	SciaRegs.SCICTL2.bit.TXINTENA = 0;		// SCI 송신 인터럽트 Enable
//	SciaRegs.SCICTL2.bit.RXBKINTENA = 1;	// SCI 수신 인터럽트 Enable
//
//	SciaRegs.SCIHBAUD = (BRR >> 8) & 0x00ff;// SCI Baudrate 설정
//	SciaRegs.SCILBAUD = BRR & 0x00ff;		//  - [SCIHBAUD,SCILBAUD] => 0x0050 => 38580bps(약38400bps)
//
//	SciaRegs.SCIPRI.bit.FREE = 1;			// SCI 에뮬레이션 프리 모드
//
//	SciaRegs.SCICTL1.bit.SWRESET = 1;		// SCI 소프트웨어 리셋 해제


	// Initialize SCI-B:

	BRR = (unsigned int)((LSPCLK / (SCI_B_BAUD * 8.0)) - 1);

	InitScibGpio();

	ScibRegs.SCICTL1.bit.SWRESET = 0;		// SCI 소프트웨어 리셋
	ScibRegs.SCICCR.bit.SCICHAR = 7;		// SCI 송수신 Charcter-length 설정 : 8bit
	ScibRegs.SCICCR.bit.LOOPBKENA = 0;		// SCI 루프백 테스트 모드 Enable
	ScibRegs.SCICTL1.bit.RXENA = 1;			// SCI 송신기능 Enable
	ScibRegs.SCICTL1.bit.TXENA = 1;			// SCI 수신기능 Enable
	ScibRegs.SCICTL2.bit.TXINTENA = 0;		// SCI 송신 인터럽트 Enable
	ScibRegs.SCICTL2.bit.RXBKINTENA = 1;	// SCI 수신 인터럽트 Enable

	ScibRegs.SCIHBAUD = (BRR >> 8) & 0x00ff;// SCI Baudrate 설정
	ScibRegs.SCILBAUD = BRR & 0x00ff;		//  - [SCIHBAUD,SCILBAUD] => 0x0050 => 38580bps(약38400bps)

	ScibRegs.SCIPRI.bit.FREE = 1;			// SCI 에뮬레이션 프리 모드

	ScibRegs.SCICTL1.bit.SWRESET = 1;		// SCI 소프트웨어 리셋 해제


    // Initialize SCI-C:
	BRR = (unsigned int)((LSPCLK / (SCI_C_BAUD * 8.0)) - 1);
	InitScicGpio();

	ScicRegs.SCICTL1.bit.SWRESET = 0;		// SCI 소프트웨어 리셋
	ScicRegs.SCICCR.bit.SCICHAR = 7;		// SCI 송수신 Charcter-length 설정 : 8bit
	ScicRegs.SCICCR.bit.LOOPBKENA = 0;		// SCI 루프백 테스트 모드 Enable
	ScicRegs.SCICTL1.bit.RXENA = 1;			// SCI 송신기능 Enable
	ScicRegs.SCICTL1.bit.TXENA = 1;			// SCI 수신기능 Enable
	ScicRegs.SCICTL2.bit.TXINTENA = 0;		// SCI 송신 인터럽트 Enable
	ScicRegs.SCICTL2.bit.RXBKINTENA = 1;	// SCI 수신 인터럽트 Enable

	ScicRegs.SCIHBAUD = (BRR >> 8) & 0x00ff;// SCI Baudrate 설정
	ScicRegs.SCILBAUD = BRR & 0x00ff;		//  - [SCIHBAUD,SCILBAUD] => 0x0050 => 38580bps(약38400bps)

	ScicRegs.SCIPRI.bit.FREE = 1;			// SCI 에뮬레이션 프리 모드
	ScicRegs.SCICTL1.bit.RXERRINTENA = 1;   // RxError 인터럽트 인에이블
	ScicRegs.SCICTL1.bit.SWRESET = 1;		// SCI 소프트웨어 리셋 해제


	asm(" RPT #7 || NOP");
}	

//---------------------------------------------------------------------------
// Example: InitSciGpio: 
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as SCI pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.  
// 
// Caution: 
// Only one GPIO pin should be enabled for SCITXDA/B operation.
// Only one GPIO pin shoudl be enabled for SCIRXDA/B operation. 
// Comment out other unwanted lines.

void InitSciGpio()
{
   InitSciaGpio();
#if DSP28_SCIB   
   InitScibGpio();
#endif // if DSP28_SCIB  
#if DSP28_SCIC
   InitScicGpio();
#endif // if DSP28_SCIC
}

void InitSciaGpio()
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.  
// This will enable the pullups for the specified pins.

	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up for GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;	   // Enable pull-up for GPIO29 (SCITXDA)

/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.  
// This will select asynch (no qualification) for the selected pins.

	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SCIRXDA)

/* Configure SCI-A pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be SCI functional pins.

	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // Configure GPIO28 for SCIRXDA operation
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // Configure GPIO29 for SCITXDA operation
	
    EDIS;
}

#if DSP28_SCIB 
void InitScibGpio()
{
   EALLOW;
	
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.  
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

//  GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;     // Enable pull-up for GPIO9  (SCITXDB)
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;    // Enable pull-up for GPIO14 (SCITXDB)
//	GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;	   // Enable pull-up for GPIO18 (SCITXDB)
//  GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;    // Enable pull-up for GPIO22 (SCITXDB)

	
//  GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;    // Enable pull-up for GPIO11 (SCIRXDB)
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // Enable pull-up for GPIO15 (SCIRXDB)
//    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;	   // Enable pull-up for GPIO19 (SCIRXDB)
//  GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;    // Enable pull-up for GPIO23 (SCIRXDB)

/* Set qualification for selected pins to asynch only */
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.

//  GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 3;  // Asynch input GPIO11 (SCIRXDB)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;  // Asynch input GPIO15 (SCIRXDB)
//	GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3;  // Asynch input GPIO19 (SCIRXDB)
//  GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 3;  // Asynch input GPIO23 (SCIRXDB)

/* Configure SCI-B pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be SCI functional pins.
// Comment out other unwanted lines.

//  GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 2;    // Configure GPIO9 for SCITXDB operation
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 2;   // Configure GPIO14 for SCITXDB operation
//	GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 2;   // Configure GPIO18 for SCITXDB operation
//  GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 3;   // Configure GPIO22 for SCITXDB operation
	
//  GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 2;   // Configure GPIO11 for SCIRXDB operation
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 2;   // Configure GPIO15 for SCIRXDB operation
//  GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 2;   // Configure GPIO19 for SCIRXDB operation
//  GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 3;   // Configure GPIO23 for SCIRXDB operation
	
    EDIS;
}
#endif // if DSP28_SCIB 

#if DSP28_SCIC
void InitScicGpio()
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.  
// This will enable the pullups for the specified pins.

	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0;    // Enable pull-up for GPIO62 (SCIRXDC)
	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 0;	   // Enable pull-up for GPIO63 (SCITXDC)

/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.  
// This will select asynch (no qualification) for the selected pins.

	GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 3;  // Asynch input GPIO62 (SCIRXDC)

/* Configure SCI-C pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be SCI functional pins.

	GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 1;   // Configure GPIO62 for SCIRXDC operation
	GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 1;   // Configure GPIO63 for SCITXDC operation
	
    EDIS;
}
#endif // if DSP28_SCIC 

	
//===========================================================================
// End of file.
//===========================================================================
