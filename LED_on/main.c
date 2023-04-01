#include <stdint.h>



int main(void)
{

    uint32_t *pClkCtrlreg = (uint32_t*)0x40023830;
    uint32_t *pPortGModeReg = (uint32_t*)0x40021800;
    uint32_t *pPortGOutReg = (uint32_t*)0x40021814;

    //*pClkCtrlreg |= 0x00000040;
    *pClkCtrlreg |= (1 << 6);

    //2. Configure the mode of the IO pin as output
    //a. Clear 26th and 27th bit positions(CLEAR)
    *pPortGModeReg &= ~(3 << 26);

    //b make 26th bit position as 1 (SET)
    *pPortGModeReg |= (1 << 26);
  
    //3. SET 13th bit of output data register to make I/0 pin-13 as HIGH
    *pPortGOutReg |=  (1 << 13);


    while(1);
}
