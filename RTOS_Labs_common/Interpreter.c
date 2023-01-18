// *************Interpreter.c**************
// Students implement this as part of EE445M/EE380L.12 Lab 1,2,3,4 
// High-level OS user interface
// 
// Runs on LM4F120/TM4C123
// Jonathan W. Valvano 1/18/20, valvano@mail.utexas.edu
#include <stdint.h>
#include <string.h> 
#include <stdio.h>
#include "../RTOS_Labs_common/OS.h"
#include "../RTOS_Labs_common/ST7735.h"
#include "../inc/ADCT0ATrigger.h"
#include "../inc/ADCSWTrigger.h"
#include "../RTOS_Labs_common/UART0int.h"
#include "../RTOS_Labs_common/eDisk.h"
#include "../RTOS_Labs_common/eFile.h"

enum command{help,echo,ADCTest,showTime,error};

enum command parseCommand(char *command_){
	enum command returnCommand = error;
	
	if(strncmp(command_,"help",10)){
	returnCommand = help;
	}
	
	if(strncmp(command_,"echo",10)){
	returnCommand = echo;
	}
	
	if(strncmp(command_,"ADCTest",10)){
	returnCommand = ADCTest;		
	}
	
	if(strncmp(command_,"showTime",10)){
	returnCommand = showTime;
	}
	return returnCommand;
}

void helpCommand(void){
return;
}

void showTimeCommand(void){
return;
}

void echoCommand(void){
return;
}

void ADCTestCommand(void){
return;
}




// Print jitter histogram
void Jitter(int32_t MaxJitter, uint32_t const JitterSize, uint32_t JitterHistogram[]){
  // write this for Lab 3 (the latest)
	
}

// *********** Command line interpreter (shell) ************
void Interpreter(void){ 
  // write this  
	
	while(TRUE){
	//get line from UART
	//strtok to get and remove first word of string
	//get the command enum
	//call appropriate function based on command enum
	
		
		
	}
}


