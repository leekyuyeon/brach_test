#include "..\Header\DSP28x_Project.h"

//#pragma DATA_SECTION(sa_SensingFile_00,"ZONE6DATA");
//#pragma DATA_SECTION(sa_SensingFile_01,"ZONE7DATA");


//SENSING_FILE
//sa_SensingFile_00[((unsigned long)(MAX_EXTERNAL_RAM_SIZE / sizeof(SENSING_FILE)) - 1)],
//sa_SensingFile_01[((unsigned long)(MAX_EXTERNAL_RAM_SIZE / sizeof(SENSING_FILE)) - 1)];
//




SYSTEM_FILE
s_System;

#ifdef DEBUG_MODE
#endif

#ifdef DEBUG_MODE_CALIBRATION

unsigned int CalFlag = 0;

#endif



void main(void)
{
    DINT;

	InitSysCtrl();
	InitFlashAPI();


	//	InitAdc();
	InitGpio();
	InitXintf();


	InitCpuTimers();
    ConfigCpuTimer(&CpuTimer0, 150, CPU_TIMER_1MS);// 	1ms
    ConfigCpuTimer(&CpuTimer1, 150, CPU_TIMER_1S); //	1s
    InitSci();

//	InitECanaGpio();
//	InitECana();

    InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;//TIMER 0
	//PieCtrlRegs.PIEIER9.bit.INTx1 = 1;//SCIRXINTA
	//PieCtrlRegs.PIEIER9.bit.INTx5 = 1;//ECAN0INTA
	//PieCtrlRegs.PIEIER1.bit.INTx6 = 1;	//ADC_INT

#ifdef RS_232_ENABLE

	PieCtrlRegs.PIEIER9.bit.INTx3 = 1;//SCIRXINTB RS232
	IER |= M_INT1 | M_INT13 | M_INT9;

#endif

#ifdef RS_485_ENABLE

	PieCtrlRegs.PIEIER8.bit.INTx5 = 1;//SCIRXINTC RS485
	IER |= M_INT1 | M_INT8 | M_INT13;

#endif


	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM
	StartCpuTimer0();
	StartCpuTimer1();

	// Enable the watchdog
	EALLOW;
	SysCtrlRegs.WDCR = 0x002F;
	EDIS;

    Rs485_Wirte("Data Acquisition ver.1.0.0\n\r",30);
    Rs485_Wirte("Company:Phoenixon Controls\n\r",30);
    Rs485_Wirte("Initialization...\n\r",20);

	BoardInitial();

    Rs485_Wirte("Complete\n\r\n\n",16);
    Rs485_Wirte("mode selection:1(sensing mode, calibration mode)\r\n",52);

    int ALL_NUM, VOL_NUM, TEM_NUM, TRE_NUM, channel_select, cal_count;
    int volt_cal_channel = 0;
    double voltage_sum = 0;
    double voltage_avg = 0;

#ifndef DEBUG_MODE_CALIBRATION

	//CalibrationRead();

#endif

	while(1)
	{
		SenSingOfDAQ(&s_System);
		ColdTemperatureCONV(&s_System);

#ifdef DEBUG_MODE_CALIBRATION

		if(CalFlag)
		{
			CalFlag = 0;
			//CalibrationHighVoltage(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
			//CalibrationLowVoltage(&s_System, AD7609_01, AD7609_01 + 20 - 1);
			//CalibrationHighThermocouple(&s_System, AD7609_05, AD7609_05 + 5 - 1);
			//CalibrationHighThermistor(&s_System, AD7609_04, AD7609_04 + 5 - 1);
		}

#endif


//      You can select EOL mode or Cell Cycler mode.
//		If you select one, please other configuration remark
//		And SendDataToPC remark too.

//		EOL Configuration
		LowVoltageCONV(&s_System, AD7609_01, AD7609_01 + VOL_NUM - 1);
		ThermistorCONV(&s_System, AD7609_01 + VOL_NUM, (AD7609_01 + VOL_NUM) + TRE_NUM - 1);

//		Cell Cycler Configuration
//		ThermocoupleCONV(&s_System, AD7609_01, AD7609_01 + TEM_NUM - 1);


//		EOL SendDataToPC
		if(s_System.s_RS485.ui_RxVolt)
		{
			s_System.s_RS485.ui_TxStatFlag = CLEAR;
			s_System.s_RS485.ui_RxVolt = CLEAR;

			SandDataToPc(&s_System, AD7609_01, AD7609_01 + VOL_NUM - 1);
		}
        else if(s_System.s_RS485.ui_RxTreg)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxTreg = CLEAR;

            SandDataToPc(&s_System, AD7609_01 + VOL_NUM, (AD7609_01 + VOL_NUM) + TRE_NUM - 1);
        }

//		Cell Cycler SendDataToPC
		else if(s_System.s_RS485.ui_RxTemp)
		{
			s_System.s_RS485.ui_TxStatFlag = CLEAR;
			s_System.s_RS485.ui_RxTemp = CLEAR;

//			SandDataToPc(&s_System, AD7609_01, AD7609_01 + TEM_NUM - 1);
		}

//		All Sensing Data SendDataToPC
		else if(s_System.s_RS485.ui_RxAllx)
		{
			s_System.s_RS485.ui_TxStatFlag = CLEAR;
			s_System.s_RS485.ui_RxAllx = CLEAR;

			SandDataToPc(&s_System, AD7609_01, AD7609_01 + ALL_NUM - 1);
		}

//		Check infomation
        else if(s_System.s_RS485.ui_RxINFO)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxINFO = CLEAR;

            IDNUMBER();
        }

//      VOLtage Channel Number Setting
        else if(s_System.s_RS485.ui_RxVOL0)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL0 = CLEAR;
            VOL_NUM = 0;
        }
        else if(s_System.s_RS485.ui_RxVOL1)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL1 = CLEAR;
            VOL_NUM = 8;
        }
        else if(s_System.s_RS485.ui_RxVOL2)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL2 = CLEAR;
            VOL_NUM = 16;
        }
        else if(s_System.s_RS485.ui_RxVOL3)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL3 = CLEAR;
            VOL_NUM = 24;
        }
        else if(s_System.s_RS485.ui_RxVOL4)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL4 = CLEAR;
            VOL_NUM = 32;
        }
        else if(s_System.s_RS485.ui_RxVOL5)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL5 = CLEAR;
            VOL_NUM = 40;
        }
        else if(s_System.s_RS485.ui_RxVOL6)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL6 = CLEAR;
            VOL_NUM = 48;
        }
        else if(s_System.s_RS485.ui_RxVOL7)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL7 = CLEAR;
            VOL_NUM = 56;
        }
        else if(s_System.s_RS485.ui_RxVOL8)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL8 = CLEAR;
            VOL_NUM = 64;
        }
        else if(s_System.s_RS485.ui_RxVOL9)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOL9 = CLEAR;
            VOL_NUM = 72;
        }
        else if(s_System.s_RS485.ui_RxVOLA)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOLA = CLEAR;
            VOL_NUM = 80;
        }
        else if(s_System.s_RS485.ui_RxVOLB)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOLB = CLEAR;
            VOL_NUM = 88;
        }
        else if(s_System.s_RS485.ui_RxVOLC)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOLC = CLEAR;
            VOL_NUM = 96;
        }
        else if(s_System.s_RS485.ui_RxVOLD)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOLD = CLEAR;
            VOL_NUM = 104;
        }

        else if(s_System.s_RS485.ui_RxVOLE)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOLE = CLEAR;
            VOL_NUM = 112;
        }
        else if(s_System.s_RS485.ui_RxVOLF)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxVOLF = CLEAR;
            VOL_NUM = 120;
        }


//		Thermocouple Channel Number Setting
		else if(s_System.s_RS485.ui_RxTEM0)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM0 = CLEAR;
		    TEM_NUM = 0;
		}
		else if(s_System.s_RS485.ui_RxTEM1)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM1 = CLEAR;
		    TEM_NUM = 8;
		}
		else if(s_System.s_RS485.ui_RxTEM2)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM2 = CLEAR;
		    TEM_NUM = 16;
		}
		else if(s_System.s_RS485.ui_RxTEM3)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM3 = CLEAR;
		    TEM_NUM = 24;
		}
		else if(s_System.s_RS485.ui_RxTEM4)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM4 = CLEAR;
		    TEM_NUM = 32;
		}
		else if(s_System.s_RS485.ui_RxTEM5)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM5 = CLEAR;
		    TEM_NUM = 40;
		}
		else if(s_System.s_RS485.ui_RxTEM6)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM6 = CLEAR;
		    TEM_NUM = 48;
		}
		else if(s_System.s_RS485.ui_RxTEM7)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM7 = CLEAR;
		    TEM_NUM = 56;
		}
		else if(s_System.s_RS485.ui_RxTEM8)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM8 = CLEAR;
		    TEM_NUM = 64;
		}
		else if(s_System.s_RS485.ui_RxTEM9)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEM9 = CLEAR;
		    TEM_NUM = 72;
		}
		else if(s_System.s_RS485.ui_RxTEMA)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEMA = CLEAR;
		    TEM_NUM = 80;
		}
		else if(s_System.s_RS485.ui_RxTEMB)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEMB = CLEAR;
		    TEM_NUM = 88;
		}
		else if(s_System.s_RS485.ui_RxTEMC)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEMC = CLEAR;
		    TEM_NUM = 96;
		}
		else if(s_System.s_RS485.ui_RxTEMD)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEMD = CLEAR;
		    TEM_NUM = 104;
		}

		else if(s_System.s_RS485.ui_RxTEME)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEME = CLEAR;
		    TEM_NUM = 112;
		}
		else if(s_System.s_RS485.ui_RxTEMF)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTEMF = CLEAR;
		    TEM_NUM = 120;
		}

//		Thermistor Channel Number Setting
		else if(s_System.s_RS485.ui_RxTRE0)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE0 = CLEAR;
		    TRE_NUM = 0;
		}
		else if(s_System.s_RS485.ui_RxTRE1)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE1 = CLEAR;
		    TRE_NUM = 8;
		}
		else if(s_System.s_RS485.ui_RxTRE2)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE2 = CLEAR;
		    TRE_NUM = 16;
		}
		else if(s_System.s_RS485.ui_RxTRE3)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE3 = CLEAR;
		    TRE_NUM = 24;
		}
		else if(s_System.s_RS485.ui_RxTRE4)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE4 = CLEAR;
		    TRE_NUM = 32;
		}
		else if(s_System.s_RS485.ui_RxTRE5)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE5 = CLEAR;
		    TRE_NUM = 40;
		}
		else if(s_System.s_RS485.ui_RxTRE6)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE6 = CLEAR;
		    TRE_NUM = 48;
		}
		else if(s_System.s_RS485.ui_RxTRE7)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE7 = CLEAR;
		    TRE_NUM = 56;
		}
		else if(s_System.s_RS485.ui_RxTRE8)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE8 = CLEAR;
		    TRE_NUM = 64;
		}
		else if(s_System.s_RS485.ui_RxTRE9)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRE9 = CLEAR;
		    TRE_NUM = 72;
		}
		else if(s_System.s_RS485.ui_RxTREA)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTREA = CLEAR;
		    TRE_NUM = 80;
		}
		else if(s_System.s_RS485.ui_RxTREB)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTREB = CLEAR;
		    TRE_NUM = 88;
		}
		else if(s_System.s_RS485.ui_RxTREC)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTREC = CLEAR;
		    TRE_NUM = 96;
		}
		else if(s_System.s_RS485.ui_RxTRED)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTRED = CLEAR;
		    TRE_NUM = 104;
		}

		else if(s_System.s_RS485.ui_RxTREE)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTREE = CLEAR;
		    TRE_NUM = 112;
		}
		else if(s_System.s_RS485.ui_RxTREF)
		{
		    s_System.s_RS485.ui_TxStatFlag = CLEAR;
		    s_System.s_RS485.ui_RxTREF = CLEAR;
		    TRE_NUM = 120;
		}

//      All Channel Number Setting
        else if(s_System.s_RS485.ui_RxALL0)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL0 = CLEAR;
            ALL_NUM = 0;
        }
        else if(s_System.s_RS485.ui_RxALL1)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL1 = CLEAR;
            ALL_NUM = 8;
        }
        else if(s_System.s_RS485.ui_RxALL2)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL2 = CLEAR;
            ALL_NUM = 16;
        }
        else if(s_System.s_RS485.ui_RxALL3)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL3 = CLEAR;
            ALL_NUM = 24;
        }
        else if(s_System.s_RS485.ui_RxALL4)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL4 = CLEAR;
            ALL_NUM = 32;
        }
        else if(s_System.s_RS485.ui_RxALL5)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL5 = CLEAR;
            ALL_NUM = 40;
        }
        else if(s_System.s_RS485.ui_RxALL6)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL6 = CLEAR;
            ALL_NUM = 48;
        }
        else if(s_System.s_RS485.ui_RxALL7)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL7 = CLEAR;
            ALL_NUM = 56;
        }
        else if(s_System.s_RS485.ui_RxALL8)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL8 = CLEAR;
            ALL_NUM = 64;
        }
        else if(s_System.s_RS485.ui_RxALL9)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALL9 = CLEAR;
            ALL_NUM = 72;
        }
        else if(s_System.s_RS485.ui_RxALLA)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALLA = CLEAR;
            ALL_NUM = 80;
        }
        else if(s_System.s_RS485.ui_RxALLB)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALLB = CLEAR;
            ALL_NUM = 88;
        }
        else if(s_System.s_RS485.ui_RxALLC)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALLC = CLEAR;
            ALL_NUM = 96;
        }
        else if(s_System.s_RS485.ui_RxALLD)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALLD = CLEAR;
            ALL_NUM = 104;
        }

        else if(s_System.s_RS485.ui_RxALLE)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALLE = CLEAR;
            ALL_NUM = 112;
        }
        else if(s_System.s_RS485.ui_RxALLF)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxALLF = CLEAR;
            ALL_NUM = 120;
        }
        else if(s_System.s_RS485.ui_RxFRST)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_RxFRST = CLEAR;
            for(channel_select=0 ; channel_select<ALL_NUM ; channel_select++){
                s_System.f_OffsetAD7609[channel_select] = 0.0;
                s_System.f_GainAD7609[channel_select] = AD7609_SCALE * 1.0;
            }
        }
        else if(s_System.s_RS485.ui_Rx1VOL)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_Rx1VOL = CLEAR;
            //input 1V data
            for(volt_cal_channel = 0; volt_cal_channel < VOL_NUM; volt_cal_channel++){
                for(cal_count = 0; cal_count < 100; cal_count++){
                        voltage_sum += s_System.f_ResultAD7609[volt_cal_channel];
                }
                voltage_avg = voltage_sum / 100;
                s_System.f_1VoltageBuffer[volt_cal_channel] = voltage_avg;
                voltage_sum = 0;
                voltage_avg = 0;
            }
        }
        else if(s_System.s_RS485.ui_Rx5VOL)
        {
            s_System.s_RS485.ui_TxStatFlag = CLEAR;
            s_System.s_RS485.ui_Rx5VOL = CLEAR;
            //input 5V data
            for(volt_cal_channel = 0; volt_cal_channel < VOL_NUM; volt_cal_channel++){
                for(cal_count = 0; cal_count < 100; cal_count++){
                        voltage_sum += s_System.f_ResultAD7609[volt_cal_channel];
                }
                voltage_avg = voltage_sum / 100;
                s_System.f_5VoltageBuffer[volt_cal_channel] = voltage_avg;
                voltage_sum = 0;
                voltage_avg = 0;
            }
//            for(volt_cal_channel = 0; volt_cal_channel < VOL_NUM; volt_cal_channel++){
//                s_System.f_CalculateVoltageGain[volt_cal_channel]=4/(s_System.f_5VoltageBuffer[volt_cal_channel] - s_System.f_1VoltageBuffer[volt_cal_channel]);
//                s_System.f_CalculateVoltageOffset[volt_cal_channel]=(s_System.f_5VoltageBuffer[volt_cal_channel] - s_System.f_1VoltageBuffer[volt_cal_channel])/4-s_System.f_1VoltageBuffer[volt_cal_channel];
//            }
        }



//        else if(s_System.s_RS485.ui_RxCAL1)
//        {
//            s_System.s_RS485.ui_TxStatFlag = CLEAR;
//            s_System.s_RS485.ui_RxALLF = CLEAR;
//            //input 1V data
//            for(volt_cal_channel = 0; volt_cal_channel < VOL_NUM; volt_cal_channel++){
//                for(cal_count = 0; cal_count < 100; cal_count++){
//                        voltage_sum += s_System.f_ResultAD7609[volt_cal_channel];
//                }
//                voltage_avg = voltage_sum/100;
//                s_System.f_1VoltageBuffer[volt_cal_channel] = voltage_avg;
//            }
//        }
//        else if(s_System.s_RS485.ui_Rx5VOL)
//        {
//            s_System.s_RS485.ui_TxStatFlag = CLEAR;
//            s_System.s_RS485.ui_RxCAL2 = CLEAR;
//            //input 5V data
//            for(volt_cal_channel = 0; volt_cal_channel < VOL_NUM; volt_cal_channel++){
//                for(cal_count = 0; cal_count < 100; cal_count++){
//                        voltage_sum += s_System.f_ResultAD7609[volt_cal_channel];
//                }
//                voltage_avg = voltage_sum/100;
//                s_System.f_5VoltageBuffer[volt_cal_channel] = voltage_avg;
//            }



#ifdef RS_232_ENABLE

		if(ScicRegs.SCIRXST.bit.RXERROR)
		{
			ScibRegs.SCICTL1.bit.SWRESET = 0;
			asm(" RPT #7 || NOP");
			ScibRegs.SCICTL1.bit.SWRESET = 1;
			asm(" RPT #7 || NOP");

			InitSci();
			DELAY_US(1000);
		}

#endif

#ifdef RS_485_ENABLE

		if(ScicRegs.SCIRXST.bit.RXERROR)
		{
			ScicRegs.SCICTL1.bit.SWRESET = 0;
			asm(" RPT #7 || NOP");
			ScicRegs.SCICTL1.bit.SWRESET = 1;
			asm(" RPT #7 || NOP");

			InitSci();
			DELAY_US(1000);
		}

#endif
	}
}

//===========================================================================
// End of file.
//===========================================================================
