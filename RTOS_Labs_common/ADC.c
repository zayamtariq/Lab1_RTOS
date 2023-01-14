// *************ADC.c**************
// EE445M/EE380L.6 Labs 1, 2, Lab 3, and Lab 4 
// mid-level ADC functions
// you are allowed to call functions in the low level ADCSWTrigger driver
// 
// Runs on LM4F120/TM4C123
// Jonathan W. Valvano Jan 5, 2020, valvano@mail.utexas.edu
#include <stdint.h>
#include "../inc/ADCSWTrigger.h"
#include "../inc/CortexM.h"
#include "../inc/LaunchPad.h"
#include "../inc/PLL.h"
#include "../inc/Timer4A.h"
#include "../inc/tm4c123gh6pm.h"
#include "../inc/ADCSWTrigger.h"
// channelNum (0 to 11) specifies which pin is sampled with sequencer 3
// software start
// return with error 1, if channelNum>11, 
// otherwise initialize ADC and return 0 (success)

//uses timer 4, at a frequency of 100 hertz, uses ADC 0


int ADC_Init(uint32_t channelNum){ //specifies which ADC pin, from 0-11

	DisableInterrupts();

	//init one of 11 ADCs
	ADC0_InitSWTriggerSeq3(channelNum);
	EnableInterrupts();
	return 0;
}


// software start sequencer 3 and return 12 bit ADC result
uint32_t ADC_In(void){
return ADC0_InSeq3();
}
