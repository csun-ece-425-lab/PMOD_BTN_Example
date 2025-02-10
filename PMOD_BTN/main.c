/**
 * @file main.c
 *
 * @brief Main source code for the PMOD_BTN program.
 *
 * This file contains the main entry point and function definitions for the PMOD_BTN program.
 * It interfaces with the following:
 *	- EduBase Board LEDs (LED0 - LED3)
 *  - PMOD BTN (4 User Push Buttons)
 *
 * @author
 */

#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include "PMOD_BTN.h"

// Declare the user-defined function prototype for PMOD_BTN
void PMOD_BTN_Int_Handler(uint8_t pmod_btn_status);

// Initialize a global variable for an 8-bit counter
static uint8_t counter = 0;

int main(void)
{
	EduBase_LEDs_Init();
	
	PMOD_BTN_Interrupt_Init(&PMOD_BTN_Int_Handler);
	
	while(1)
	{

	}
}

/**
 * @brief
 *
 * @param
 *
 * @return
 */
void PMOD_BTN_Int_Handler(uint8_t pmod_btn_status)
{
	switch(pmod_btn_status)
	{
		// BTN0 (PA2) is pressed
		case 0x04:
		{
			if (counter >= 15) 
			{
				counter = 0;
			}
			
			else
			{
				counter = counter + 1;
			}
			
			break;
		}
		
		// BTN1 (PA3) is pressed
		case 0x08:
		{

			break;
		}
		
		// BTN2 (PA4) is pressed
		case 0x10:
		{

			break;
		}
		
		// BTN3 (PA5) is pressed
		case 0x20:
		{

			break;
		}
		
		default:
		{
			
			break;
		}
	}
	
	EduBase_LEDs_Output(counter);
}
