/*
 * Calibration.h
 *
 *  Created on: 2016. 9. 10.
 *      Author: BGKim
 */

#ifndef HEADER_CALIBRATION_H_
#define HEADER_CALIBRATION_H_

#define PLLCR_VALUE  0x000A     // SYSCLKOUT = (OSCLK*10)/2

#define OTP_START_ADDR  0x380400
#define OTP_END_ADDR    0x3807FF

#define FLASH_START_ADDR  0x300000
#define FLASH_END_ADDR    0x33FFFF

typedef struct {
     Uint16 *StartAddr;
     Uint16 *EndAddr;
} SECTOR;

typedef union {
	float f_32bit;
	unsigned int uai_16bit[2];
}CON_F32TOUI16;

void InitFlashAPI(void);
void CalibrationConstData(void);
void CalibrationProgram(void);
void CalibrationRead(void);
void CalibrationProgram_Error(Uint16 Status);
void CalibrationProgram_Done(void);
void CalibrationHighVoltage(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
void CalibrationLowVoltage(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
void CalibrationHighThermocouple(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);
void CalibrationHighThermistor(SYSTEM_FILE *sp_System, unsigned int ui_StartAddress, unsigned int ui_EndAddress);

#endif /* HEADER_CALIBRATION_H_ */
