//###########################################################################
//
// FILE:	DSP2833x_DefaultIsr.c
//
// TITLE:	DSP2833x Device Default Interrupt Service Routines.
//
// This file contains shell ISR routines for the 2833x PIE vector table.
// Typically these shell ISR routines can be used to populate the entire PIE
// vector table during device debug.  In this manner if an interrupt is taken
// during firmware development, there will always be an ISR to catch it.
//
// As development progresses, these ISR routines can be eliminated and replaced
// with the user's own ISR routines for each interrupt.  Since these shell ISRs
// include infinite loops they will typically not be included as-is in the final
// production firmware.
//
//###########################################################################
// $TI Release: F2833x/F2823x Header Files and Peripheral Examples V141 $
// $Release Date: November  6, 2015 $
// $Copyright: Copyright (C) 2007-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "..\Header\DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "..\Header\DSP2833x_Examples.h"   // DSP2833x Examples Include File

// Connected to INT13 of CPU (use MINT13 mask):
// Note CPU-Timer1 is reserved for TI use, however XINT13
// ISR can be used by the user.
interrupt void INT13_ISR(void)     // INT13 or CPU-Timer1
{
  // Insert ISR Code here
//	if(s_System.NewState.ui_Falut)
//	{
//		RUN_LED_CLEAR();
//	}
//	else
//	{
//		RUN_LED_TOGGLE();
//	}
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
//	DECREASE_32BIT(s_System.NewState.ul_RxError_Timer);
//	DECREASE_32BIT(s_System.NewState.ul_Timer);
//	DECREASE_32BIT(s_System.Rs485.ul_RxTimer);
//	DECREASE_32BIT(s_System.NewState.ul_TxPeriod);
//	DECREASE_32BIT(s_System.NewState.ul_CCMode_Timer);
//	DECREASE_32BIT(s_System.NewState.ul_PowerTimer);
//	DECREASE_32BIT(s_System.NewState.ul_ParallelSyncTimer);
//	DECREASE_32BIT(s_System.NewState.ul_StartSamplingTimer);
//
//	if(s_System.NewState.ul_TxPeriod == CLEAR)
//	{
//		s_System.NewState.ul_TxPeriod  = RS485_TX_PERIOD;
//		s_System.Rs485.ui_TxEnable = SET;
//	}
//
//	if(s_System.NewState.ul_PowerTimer == CLEAR)
//	{
//		s_System.NewState.ul_PowerTimer = POWER_UPDATA_TIME;
//		s_System.NewState.ui_PowerReferenceUpdate = SET;
//	}

//	if(__ABS(s_System.NewState.f_NowCurrent - s_System.NewState.f_IReferenceSet) < 0.05
//			&& (s_System.NewState.f_IReferenceSet > 0))
//	{
//		s_System.NewState.ui_CCMode = SET;
//	}

	//AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;

//  asm ("      ESTOP0");
//  for(;;);
}

// Note CPU-Timer2 is reserved for TI use.
interrupt void INT14_ISR(void)     // CPU-Timer2
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void DATALOG_ISR(void)   // Datalogging interrupt
{
   // Insert ISR Code here

   // Next two lines for debug only to halt the processor here
   // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void RTOSINT_ISR(void)   // RTOS interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void EMUINT_ISR(void)    // Emulation interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void NMI_ISR(void)       // Non-maskable interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void ILLEGAL_ISR(void)   // Illegal operation TRAP
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("          ESTOP0");
  for(;;);

}


interrupt void USER1_ISR(void)     // User Defined trap 1
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

interrupt void USER2_ISR(void)     // User Defined trap 2
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);


}

interrupt void USER3_ISR(void)     // User Defined trap 3
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER4_ISR(void)     // User Defined trap 4
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER5_ISR(void)     // User Defined trap 5
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER6_ISR(void)     // User Defined trap 6
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER7_ISR(void)     // User Defined trap 7
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER8_ISR(void)     // User Defined trap 8
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER9_ISR(void)     // User Defined trap 9
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER10_ISR(void)    // User Defined trap 10
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER11_ISR(void)    // User Defined trap 11
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

interrupt void USER12_ISR(void)     // User Defined trap 12
{
 // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// -----------------------------------------------------------
// PIE Group 1 - MUXed into CPU INT1
// -----------------------------------------------------------

// INT1.1
interrupt void SEQ1INT_ISR(void)   //SEQ1 ADC
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code

  asm ("      ESTOP0");
  for(;;);

}

// INT1.2
interrupt void SEQ2INT_ISR(void)  //SEQ2 ADC
{

  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code

  asm("	  ESTOP0");
  for(;;);

}
// INT1.3 - Reserved

// INT1.4
interrupt void  XINT1_ISR(void)
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT1.5
interrupt void  XINT2_ISR(void)
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT1.6
interrupt void  ADCINT_ISR(void)     // ADC
{
//	unsigned int ui_Temp[4] = {0,};
	// Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
//	 ui_Temp[0] = AdcRegs.ADCRESULT0>>4;
//	 ui_Temp[1] = AdcRegs.ADCRESULT1>>4;
//	 ui_Temp[2] = AdcRegs.ADCRESULT2>>4;
//	 ui_Temp[3] = AdcRegs.ADCRESULT3>>4;
//
//	 s_System.Measure.f_Temperature_00 = (float)(ui_Temp[2] * ADC_INTERNEL_SCALE);
//	 s_System.Measure.f_Temperature_00 /= (TEMPERATURE_GAIN * TEMPERATUER_SLOPE);
//
//	 s_System.Measure.f_Temperature_01 = (float)(ui_Temp[3] * ADC_INTERNEL_SCALE);
//	 s_System.Measure.f_Temperature_01 /= (TEMPERATURE_GAIN * TEMPERATUER_SLOPE);
//
//	/* Reinitialize for next ADC sequence */
//	AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;	/* Reset SEQ1 */
//	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;	/* Clear INT SEQ1 bit */
//	PieCtrlRegs.PIEACK.bit.ACK1 = 1;	/* Acknowledge interrupt to PIE */
  asm ("      ESTOP0");
  for(;;);
}

// INT1.7
interrupt void  TINT0_ISR(void)      // CPU-Timer 0
{

	DECREASE_32BIT(s_System.s_RS485.ul_RxTimeOut);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer1_RUN_LED);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer2);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer3);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer4);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer5);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer6);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer7);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer8);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer9);
	DECREASE_32BIT(s_System.s_Timer.ul_Timer10);

	if(!s_System.s_Timer.ul_Timer1_RUN_LED)
	{
		s_System.s_Timer.ul_Timer1_RUN_LED = LED_TOGGLE_TIME;
		RUN_LED_TOGGLE();
	}

	ServiceDog();
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}


// INT1.8
interrupt void  WAKEINT_ISR(void)    // WD, LOW Power
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}


// -----------------------------------------------------------
// PIE Group 2 - MUXed into CPU INT2
// -----------------------------------------------------------

// INT2.1
interrupt void EPWM1_TZINT_ISR(void)    // EPWM-1
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT2.2
interrupt void EPWM2_TZINT_ISR(void)    // EPWM-2
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT2.3
interrupt void EPWM3_TZINT_ISR(void)    // EPWM-3
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}


// INT2.4
interrupt void EPWM4_TZINT_ISR(void)    // EPWM-4
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}


// INT2.5
interrupt void EPWM5_TZINT_ISR(void)    // EPWM-5
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT2.6
interrupt void EPWM6_TZINT_ISR(void)   // EPWM-6
{
  // Insert ISR Code here


  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT2.7 - Reserved
// INT2.8 - Reserved

// -----------------------------------------------------------
// PIE Group 3 - MUXed into CPU INT3
// -----------------------------------------------------------

// INT 3.1
interrupt void EPWM1_INT_ISR(void)     // EPWM-1
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT3.2
interrupt void EPWM2_INT_ISR(void)     // EPWM-2
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT3.3
interrupt void EPWM3_INT_ISR(void)    // EPWM-3
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT3.4
interrupt void EPWM4_INT_ISR(void)    // EPWM-4
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT3.5
interrupt void EPWM5_INT_ISR(void)    // EPWM-5
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT3.6
interrupt void EPWM6_INT_ISR(void)    // EPWM-6
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT3.7 - Reserved
// INT3.8 - Reserved


// -----------------------------------------------------------
// PIE Group 4 - MUXed into CPU INT4
// -----------------------------------------------------------

// INT 4.1
interrupt void ECAP1_INT_ISR(void)    // ECAP-1
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT4.2
interrupt void ECAP2_INT_ISR(void)    // ECAP-2
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT4.3
interrupt void ECAP3_INT_ISR(void)    // ECAP-3
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT4.4
interrupt void ECAP4_INT_ISR(void)     // ECAP-4
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT4.5
interrupt void ECAP5_INT_ISR(void)     // ECAP-5
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}
// INT4.6
interrupt void ECAP6_INT_ISR(void)     // ECAP-6
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}
// INT4.7 - Reserved
// INT4.8 - Reserved

// -----------------------------------------------------------
// PIE Group 5 - MUXed into CPU INT5
// -----------------------------------------------------------

// INT 5.1
interrupt void EQEP1_INT_ISR(void)    // EQEP-1
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT5.2
interrupt void EQEP2_INT_ISR(void)    // EQEP-2
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT5.3 - Reserved
// INT5.4 - Reserved
// INT5.5 - Reserved
// INT5.6 - Reserved
// INT5.7 - Reserved
// INT5.8 - Reserved

// -----------------------------------------------------------
// PIE Group 6 - MUXed into CPU INT6
// -----------------------------------------------------------

// INT6.1
interrupt void SPIRXINTA_ISR(void)    // SPI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT6.2
interrupt void SPITXINTA_ISR(void)     // SPI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT6.3
interrupt void MRINTB_ISR(void)     // McBSP-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT6.4
interrupt void MXINTB_ISR(void)     // McBSP-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT6.5
interrupt void MRINTA_ISR(void)     // McBSP-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT6.6
interrupt void MXINTA_ISR(void)     // McBSP-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT6.7 - Reserved
// INT6.8 - Reserved




// -----------------------------------------------------------
// PIE Group 7 - MUXed into CPU INT7
// -----------------------------------------------------------

// INT7.1
interrupt void DINTCH1_ISR(void)     // DMA
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT7.2
interrupt void DINTCH2_ISR(void)     // DMA
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT7.3
interrupt void DINTCH3_ISR(void)     // DMA
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT7.4
interrupt void DINTCH4_ISR(void)     // DMA
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT7.5
interrupt void DINTCH5_ISR(void)     // DMA
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT7.6
interrupt void DINTCH6_ISR(void)     // DMA
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT7.7 - Reserved
// INT7.8 - Reserved

// -----------------------------------------------------------
// PIE Group 8 - MUXed into CPU INT8
// -----------------------------------------------------------

// INT8.1
interrupt void I2CINT1A_ISR(void)     // I2C-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT8.2
interrupt void I2CINT2A_ISR(void)     // I2C-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);
}

// INT8.3 - Reserved
// INT8.4 - Reserved

// INT8.5
interrupt void SCIRXINTC_ISR(void)     // SCI-C
{
#ifdef RS_485_ENABLE
	unsigned char uc_Buffer = 0;
	static unsigned char ui_RxCount = 0;
	static unsigned char cal_flag = 0;
	static unsigned char reset_flag = 0;
    static unsigned char board_number = 0;
    static unsigned char volt1_cal_flag = 0;
    static unsigned char volt5_cal_flag = 0;


	uc_Buffer = (unsigned char)(ScicRegs.SCIRXBUF.all & 0x00FF);

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

#ifdef DEBUG_MODE_RX485
	if(ui_RxCount >= 10)ui_RxCount = 0;
	s_System.s_RS485.uc_RxData[ui_RxCount++] = uc_Buffer;
#endif

	if(ScicRegs.SCIRXST.bit.RXERROR)
	{
		ScicRegs.SCICTL1.bit.SWRESET = 0;
		asm(" RPT #7 || NOP");
		ScicRegs.SCICTL1.bit.SWRESET = 1;
		asm(" RPT #7 || NOP");

		InitSci();
		DELAY_US(1000);
	}
	else
	{
		switch(s_System.s_RS485.ui_RxCount)
		{
		case 0 :
			if(uc_Buffer == '$')
			{
				s_System.s_RS485.ui_RxCount = 1;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 1 :
			if(uc_Buffer == 'V')
			{
				s_System.s_RS485.ui_RxCount = 2;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'T')
			{
				s_System.s_RS485.ui_RxCount = 2;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'A')
			{
				s_System.s_RS485.ui_RxCount = 2;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'I') // $INFO? - JS
			{
				s_System.s_RS485.ui_RxCount = 2;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
            else if(uc_Buffer == 'F')
            {
                s_System.s_RS485.ui_RxCount = 2;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                reset_flag = 1;
            }
            else if(uc_Buffer == '1')
            {
                s_System.s_RS485.ui_RxCount = 2;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                volt1_cal_flag = 1;
            }
            else if(uc_Buffer == '5')
            {
                s_System.s_RS485.ui_RxCount = 2;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                volt5_cal_flag = 1;
            }
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 2 :
			if(uc_Buffer == 'O')
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				cal_flag = 1;
			}
			else if(uc_Buffer == 'E')
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				cal_flag = 2;
			}
			else if(uc_Buffer == 'R')
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				cal_flag = 3;
			}
			else if(uc_Buffer == 'L')
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				cal_flag = 4;
			}
			else if(uc_Buffer == 'N') // $INFO? - JS
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
            else if(uc_Buffer == 'V')
            {
                s_System.s_RS485.ui_RxCount = 3;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
            }
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 3 :

			if(uc_Buffer == 'L')
			{
				s_System.s_RS485.ui_RxCount = 4;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'M')
			{
				s_System.s_RS485.ui_RxCount = 4;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'E')
			{
				s_System.s_RS485.ui_RxCount = 4;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'F')
			{
				s_System.s_RS485.ui_RxCount = 4;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
            else if(uc_Buffer == 'S')
            {
                s_System.s_RS485.ui_RxCount = 4;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                board_number = 0;
            }
            else if(uc_Buffer == 'O')
            {
                s_System.s_RS485.ui_RxCount = 4;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                board_number = 0;

            }
            else if(uc_Buffer == '0')
            {
                s_System.s_RS485.ui_RxCount = 4;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                board_number = 0;
            }
            else if(uc_Buffer == '1')
            {
                s_System.s_RS485.ui_RxCount = 4;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                board_number = 8;
            }
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 4 :
			if(uc_Buffer == 'T')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				s_System.s_RS485.ui_RxVolt = SET;
				if(reset_flag == 1)
				    s_System.s_RS485.ui_RxFRST = SET;
			}
            if(uc_Buffer == 'L')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(volt1_cal_flag == 1){
                    s_System.s_RS485.ui_Rx1VOL = SET;
                    volt1_cal_flag = 0;
                }
                if(volt5_cal_flag == 1){
                    s_System.s_RS485.ui_Rx5VOL = SET;
                    volt5_cal_flag = 0;
                }
            }
			else if(uc_Buffer == 'P')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				s_System.s_RS485.ui_RxTemp = SET;
			}
			else if(uc_Buffer == 'G')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				s_System.s_RS485.ui_RxTreg = SET;
			}
			else if(uc_Buffer == 'X')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;

				s_System.s_RS485.ui_RxAllx = SET;
			}
            else if(uc_Buffer == 'O')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                s_System.s_RS485.ui_RxINFO = SET;
            }
			else if(uc_Buffer == '0')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL0 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM0 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE0 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL0 = SET;
				s_System.s_RS485.ui_RxINF1 = SET;
			}
            else if(uc_Buffer == '1')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL1 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM1 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE1 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL1 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '2')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL2 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM2 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE2 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL2 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '3')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL3 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM3 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE3 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL3 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '4')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL4 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM4 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE4 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL4 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '5')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL5 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM5 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE5 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL5 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '6')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL6 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM6 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE6 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL6 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '7')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL7 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM7 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE7 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL7 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '8')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL8 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM8 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE8 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL8 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '9')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL9 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM9 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE9 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL9 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'A')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLA = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMA = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREA = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLA = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'B')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLB = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMB = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREB = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLB = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'C')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLC = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMC = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREC = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLC = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'D')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLD = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMD = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRED = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLD = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'E')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLE = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEME = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREE = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLE = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'F')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLF = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMF = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREF = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLF = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 5 :
			if(uc_Buffer == '?')
			{
				s_System.s_RS485.ui_TxStatFlag = SET;
				s_System.s_RS485.ui_RxCount = 0;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
				s_System.s_RS485.ui_RxTemp = CLEAR;
				s_System.s_RS485.ui_RxVolt = CLEAR;
				s_System.s_RS485.ui_RxTreg = CLEAR;
				s_System.s_RS485.ui_RxAllx = CLEAR;
				s_System.s_RS485.ui_RxINFO = CLEAR;
				s_System.s_RS485.ui_RxINF1 = CLEAR;
				s_System.s_RS485.ui_RxINF2 = CLEAR;
			}
			break;
		default : s_System.s_RS485.ui_RxCount = 0;break;
		}
	}
#endif

#ifndef RS_485_ENABLE
	  // Insert ISR Code here

	  // To receive more interrupts from this PIE group, acknowledge this interrupt
	  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

	  // Next two lines for debug only to halt the processor here
	  // Remove after inserting ISR Code
	  asm ("      ESTOP0");
	  for(;;);
#endif
}

// INT8.6
interrupt void SCITXINTC_ISR(void)     // SCI-C
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT8.7 - Reserved
// INT8.8 - Reserved


// -----------------------------------------------------------
// PIE Group 9 - MUXed into CPU INT9
// -----------------------------------------------------------

// INT9.1
interrupt void SCIRXINTA_ISR(void)     // SCI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT9.2
interrupt void SCITXINTA_ISR(void)     // SCI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}


// INT9.3
interrupt void SCIRXINTB_ISR(void)     // SCI-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
#ifdef RS_232_ENABLE

	unsigned char uc_Buffer = 0;
	static unsigned char ui_RxCount = 0;
    static unsigned char cal_flag = 0;

	uc_Buffer = (unsigned char)(ScibRegs.SCIRXBUF.all & 0x00FF);
//	Rs232_Puts(uc_Buffer);
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

#ifdef DEBUG_MODE_RX485
	if(ui_RxCount >= 10)ui_RxCount = 0;
	s_System.s_RS485.uc_RxData[ui_RxCount++] = uc_Buffer;
#endif

	if(ScibRegs.SCIRXST.bit.RXERROR)
	{
		ScibRegs.SCICTL1.bit.SWRESET = 0;
		asm(" RPT #7 || NOP");
		ScibRegs.SCICTL1.bit.SWRESET = 1;
		asm(" RPT #7 || NOP");

		InitSci();
		DELAY_US(1000);
	}
	else
	{
		switch(s_System.s_RS485.ui_RxCount)
		{
		case 0 :
			if(uc_Buffer == '$')
			{
				s_System.s_RS485.ui_RxCount = 1;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 1 :
			if(uc_Buffer == 'V')
			{
				s_System.s_RS485.ui_RxCount = 2;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'T')
			{
				s_System.s_RS485.ui_RxCount = 2;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'A')
			{
				s_System.s_RS485.ui_RxCount = 2;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'I') // $INFO? : ID NUMBER - JS
			{
				s_System.s_RS485.ui_RxCount = 2;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 2 :
			if(uc_Buffer == 'O')
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				cal_flag = 1;
			}
			else if(uc_Buffer == 'E')
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				cal_flag = 2;
			}
			else if(uc_Buffer == 'R')
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				cal_flag = 3;
			}
			else if(uc_Buffer == 'L')
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				cal_flag = 4;
			}
			else if(uc_Buffer == 'N') // $INFO? : ID NUMBER - JS
			{
				s_System.s_RS485.ui_RxCount = 3;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 3 :

			if(uc_Buffer == 'L')
			{
				s_System.s_RS485.ui_RxCount = 4;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'M')
			{
				s_System.s_RS485.ui_RxCount = 4;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'E')
			{
				s_System.s_RS485.ui_RxCount = 4;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else if(uc_Buffer == 'F') // $INFO? - JS
			{
				s_System.s_RS485.ui_RxCount = 4;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 4 :
			if(uc_Buffer == 'T')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				s_System.s_RS485.ui_RxVolt = SET;
			}
			else if(uc_Buffer == 'P')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				s_System.s_RS485.ui_RxTemp = SET;
			}
			else if(uc_Buffer == 'G')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				s_System.s_RS485.ui_RxTreg = SET;
			}
			else if(uc_Buffer == 'X')
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				s_System.s_RS485.ui_RxAllx = SET;
			}
			else if(uc_Buffer == 'O') // $INFO? - JS
			{
				s_System.s_RS485.ui_RxCount = 5;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
				s_System.s_RS485.ui_RxINFO = SET;
			}
            else if(uc_Buffer == '0')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL0 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM0 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE0 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL0 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '1')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL1 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM1 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE1 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL1 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '2')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL2 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM2 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE2 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL2 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '3')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL3 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM3 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE3 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL3 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '4')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL4 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM4 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE4 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL4 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '5')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL5 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM5 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE5 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL5 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '6')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL6 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM6 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE6 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL6 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '7')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL7 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM7 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE7 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL7 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '8')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL8 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM8 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE8 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL8 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == '9')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOL9 = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEM9 = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRE9 = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALL9 = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'A')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLA = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMA = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREA = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLA = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'B')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLB = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMB = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREB = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLB = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'C')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLC = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMC = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREC = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLC = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'D')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLD = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMD = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTRED = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLD = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'E')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLE = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEME = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREE = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLE = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
            else if(uc_Buffer == 'F')
            {
                s_System.s_RS485.ui_RxCount = 5;
                s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
                if(cal_flag == 1)
                    s_System.s_RS485.ui_RxVOLF = SET;
                if(cal_flag == 2)
                    s_System.s_RS485.ui_RxTEMF = SET;
                if(cal_flag == 3)
                    s_System.s_RS485.ui_RxTREF = SET;
                if(cal_flag == 4)
                    s_System.s_RS485.ui_RxALLF = SET;
                s_System.s_RS485.ui_RxINF1 = SET;
            }
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
			}
			break;

		case 5 :
			if(uc_Buffer == '?')
			{
				s_System.s_RS485.ui_TxStatFlag = SET;
				s_System.s_RS485.ui_RxCount = 0;
				s_System.s_RS485.ul_RxTimeOut = RS485_RX_TIMEOUT;
			}
			else
			{
				s_System.s_RS485.ui_RxCount = 0;
				s_System.s_RS485.ui_RxTemp = CLEAR;
				s_System.s_RS485.ui_RxVolt = CLEAR;
				s_System.s_RS485.ui_RxTreg = CLEAR;
				s_System.s_RS485.ui_RxAllx = CLEAR;
				s_System.s_RS485.ui_RxINFO = CLEAR;
			}
			break;
		default : s_System.s_RS485.ui_RxCount = 0;break;
		}
	}
#endif

#ifndef RS_232_ENABLE
	  // Insert ISR Code here

	  // To receive more interrupts from this PIE group, acknowledge this interrupt
	  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

	  // Next two lines for debug only to halt the processor here
	  // Remove after inserting ISR Code
	  asm ("      ESTOP0");
	  for(;;);
#endif

}

// INT9.4
interrupt void SCITXINTB_ISR(void)     // SCI-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT9.5
interrupt void ECAN0INTA_ISR(void)  // eCAN-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT9.6
interrupt void ECAN1INTA_ISR(void)  // eCAN-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT9.7
interrupt void ECAN0INTB_ISR(void)  // eCAN-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT9.8
interrupt void ECAN1INTB_ISR(void)  // eCAN-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// -----------------------------------------------------------
// PIE Group 10 - MUXed into CPU INT10
// -----------------------------------------------------------

// INT10.1 - Reserved
// INT10.2 - Reserved
// INT10.3 - Reserved
// INT10.4 - Reserved
// INT10.5 - Reserved
// INT10.6 - Reserved
// INT10.7 - Reserved
// INT10.8 - Reserved


// -----------------------------------------------------------
// PIE Group 11 - MUXed into CPU INT11
// -----------------------------------------------------------

// INT11.1 - Reserved
// INT11.2 - Reserved
// INT11.3 - Reserved
// INT11.4 - Reserved
// INT11.5 - Reserved
// INT11.6 - Reserved
// INT11.7 - Reserved
// INT11.8 - Reserved

// -----------------------------------------------------------
// PIE Group 12 - MUXed into CPU INT12
// -----------------------------------------------------------

// INT12.1
interrupt void XINT3_ISR(void)  // External Interrupt
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT12.2
interrupt void XINT4_ISR(void)  // External Interrupt
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT12.3
interrupt void XINT5_ISR(void)  // External Interrupt
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}
// INT12.4
interrupt void XINT6_ISR(void)  // External Interrupt
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT12.5
interrupt void XINT7_ISR(void)  // External Interrupt
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

// INT12.6 - Reserved
// INT12.7
interrupt void LVF_ISR(void)  // Latched overflow
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}
// INT12.8
interrupt void LUF_ISR(void)  // Latched underflow
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm ("      ESTOP0");
  for(;;);

}

//---------------------------------------------------------------------------
// Catch All Default ISRs:
//

interrupt void PIE_RESERVED(void)  // Reserved space.  For test.
{
  asm ("      ESTOP0");
  for(;;);
}

interrupt void rsvd_ISR(void)      // For test
{
  asm ("      ESTOP0");
  for(;;);
}

//===========================================================================
// End of file.
//===========================================================================

