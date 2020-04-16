#ifndef HEADER_TESTPROGRAM_H_
#define HEADER_TESTPROGRAM_H_

#ifdef __cplusplus
extern "C" {
#endif

//void TestLowVoltage(void);
//void TestHIGHVoltage(void);
//void TestTemp(void);
//void TestTemp2(void);
//int TestEXRam(DAQ_FILE *Data, CIRCULAR_BUFF_FILE *BuFF);
//
//void Test_RS485(void);
//void TestRS232(void);
void TestCAN_A(void);
//void TestSort(void);
//int TestRS485RxBuff(void);

//void Test_PulsePatten_00(SYSTEM_FILE *sp_System);
//void Test_PulsePatten_01(SYSTEM_FILE *sp_System);
//void Test_PulsePatten_02(SYSTEM_FILE *sp_System);

int AutoCalibration(SYSTEM_FILE *sp_System);
void Calibration(SYSTEM_FILE *sp_System, unsigned int *Control);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* HEADER_TESTPROGRAM_H_ */

//===========================================================================
// No more.
//===========================================================================






