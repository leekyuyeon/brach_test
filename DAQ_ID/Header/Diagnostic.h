/*
 * Diagnostic.h
 *
 *  Created on: 2016. 8. 1.
 *      Author: BGKim
 */

#ifndef DIAGNOSTIC_H_
#define DIAGNOSTIC_H_

#ifdef __cplusplus
extern "C" {
#endif

int ExternalMemory_Diagnostic(void);
int DAC_Diagnostic(void);
int ADC_Diagnostic(void);
int ADCInternel_Diagnostic(void);
int Board_Diagnostic(void);

//void ProcessCommand(int iMode);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DIAGNOSTIC_H_ */
//===========================================================================
// No more.
//===========================================================================
