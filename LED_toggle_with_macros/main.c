#include <stdint.h>
#include "main.h"
#include <stdio.h>


int main(void)
{

	RCC_AHB1ENR_t volatile *const pClkCtrlreg = ADDR_REG_AHB1ENR;
	GPIOx_MODE_t volatile *const pPortGModeReg = ADDR_REG_GPIOG_MODE;
	GPIOx_ODR_t volatile *const pPortGOutReg = ADDR_REG_GPIOG_OD;


	//1.Enable the clock for GPIOG  peripheral in the AHB1ENR (set the 3rd bit position)
	pClkCtrlreg->gpiog_en = CLOCK_ENABLE;

	//2.Configure the mode of the IO pin as output
	//a. clear the 26th and 27th bit position (CLEAR)
	pPortDModeReg->pin_13 = MODE_CONF_OUTPUT;



   while(1){

     //3. SET 12th bit of the output data register to make I/O pin12 as HIGH
     pPortGOutReg->pin_13 = PIN_STATE_HIGH;

     //Introduce small human observable delay
     //THis loop executes for 300k times
     for(uint32_t i = 0; i < DELAY_COUNT; i++);

     //Turn OFF the LED
     pPortGOutReg->pin_13 = PIN_STATE_LOW;


     for(uint32_t i = 0; i < DELAY_COUNT; i++);

   }
}
