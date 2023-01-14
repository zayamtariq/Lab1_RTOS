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
// channelNum (0 to 11) specifies which pin is sampled with sequencer 3
// software start
// return with error 1, if channelNum>11, 
// otherwise initialize ADC and return 0 (success)

//uses timer 4, at a frequency of 100 hertz, uses ADC 0
int ADC_Init(uint32_t channelNum){
	 volatile uint32_t delay;
	 DisableInterrupts();
	 // **** general initialization ****
	SYSCTL_RCGCTIMER_R |= 0x10;      // activate timer4
  delay = SYSCTL_RCGCTIMER_R;      // allow time to finish activating
  TIMER4_CTL_R &= ~TIMER_CTL_TAEN; // disable timer4A during setup
  TIMER4_CFG_R = 0;                // configure for 32-bit timer mode
  // **** timer0A initialization ****
	                                  // configure for periodic mode
  TIMER4_TAMR_R = TIMER_TAMR_TAMR_PERIOD;
  TIMER4_TAILR_R = 799999;         // start value for 100 Hz interrupts
  TIMER4_IMR_R |= TIMER_IMR_TATOIM;// enable timeout (rollover) interrupt
  TIMER4_ICR_R = TIMER_ICR_TATOCINT;// clear timer4A timeout flag
  TIMER4_CTL_R |= TIMER_CTL_TAEN;  // enable timer4A 32-b, periodic, interrupts
  // **** interrupt initialization ****
// put your Lab 1 code here
	                                 // Timer0A=priority 2
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x40000000; // top 3 bits
  NVIC_EN0_R = 1<<19;              // enable interrupt 19 in NVIC
  return 0;
}
// software start sequencer 3 and return 12 bit ADC result
uint32_t ADC_In(void){
// put your Lab 1 code here
  TIMER4_ICR_R = TIMER_ICR_TATOCINT;    // acknowledge timer0A timeout
  PF2 ^= 0x04;                   // profile
  return ADC0_InSeq3();
}
