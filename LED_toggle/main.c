#include <stdint.h>



int main(void)
{

    uint32_t *pClkCtrlreg = (uint32_t*)0x40023830;
    uint32_t *pPortGModeReg = (uint32_t*)0x40021800;
    uint32_t *pPortGOutReg = (uint32_t*)0x40021814;

    *pClkCtrlreg |= (1 << 6);
    *pPortGModeReg &= ~(3 << 26);
    *pPortGModeReg |= (1 << 26);

    while(1){

      *pPortGOutReg |=  (1 << 13);

      //delay 
      for(uint32_t i = 0; i < 300000; i++ );

      //turn off the LED
      *pPortGOutReg &= ~(1<< 13);

      for(uint32_t i = 0; i < 300000; i++ );
    }


   while(1);
}
