#include <stdint.h>
#include "main.h"
#include <stdio.h>


int main(void)
{

	RCC_AHB1ENR_t volatile *const pClkCtrlreg = (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MODE_t volatile *const pPortGModeReg = (GPIOx_MODE_t*)0x40021800;
	GPIOx_ODR_t volatile *const pPortGOutReg = (GPIOx_ODR_t*)0x40021814;


	//1.Enable the clock for GPIOG  peripheral in the AHB1ENR (set the 3rd bit position)
	pClkCtrlreg->gpiog_en = 1;

	//2.Configure the mode of the IO pin as output
	//a. clear the 26th and 27th bit position (CLEAR)
	pPortGModeReg->pin_13 = 1;



   while(1){

   //3. SET 12th bit of the output data register to make I/O pin12 as HIGH
   pPortGOutReg->pin_13 = 1;

   //Introduce small human observable delay
   //THis loop executes for 300k times
   for(uint32_t i = 0; i < 300000; i++);

   //Turn OFF the LED
   pPortGOutReg->pin_13 = 0;


   for(uint32_t i = 0; i < 300000; i++);

   }
}
