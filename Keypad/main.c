
#include<stdint.h>
#include<stdio.h>

void delay(void)
{
	for(uint32_t i =0 ; i < 300000 ; i++);

}

int main(void)
{
	//peripheral register addresses
	uint32_t volatile *const pGPIOGModeReg  =  (uint32_t*)(0x40021800);
	uint32_t volatile *const pInPutDataReg  =  (uint32_t*)(0x40021800+0x10);
	uint32_t volatile *const pOutPutDataReg =  (uint32_t*)(0x40021800+0x14);
	uint32_t volatile *const pClockCtrlReg  =  (uint32_t*)(0x40023800+0x30);
	uint32_t volatile *const pPullupDownReg =  (uint32_t*)(0x40021800+0x0C);

  //1.Enable the peripheral clock of GPIOG peripheral
	*pClockCtrlReg |= ( 1 << 6);


  // 2.configure PG0,PG1,PG2,PG3 as output (rows)
	*pGPIOGModeReg &= ~(0xFF); //clear with 11111111
	*pGPIOGModeReg |= (0x55);   //set with 01010101


	// 3. configure PG4 , PG5, PG6, PG7 as input (columns)
    *pGPIOGModeReg &= ~(0xFF << 8); // with 11111111

	// 4.Enable internal pull-up resistors for PG4 , PG5, PG6, PG7
    *pPullupDownReg &= ~(0xFF << 8);// clear with 11111111
    *pPullupDownReg |=  (0x55 << 8);// set with 01010101

while(1)
    {
        //make all rows HIGH
        *pOutPutDataReg |= (0x0F); // set with 1111

        //make R1 LOW(PG0)
        *pOutPutDataReg &= ~( 1 << 0);

        //scan the columns
        //check C1(PG4) low or high
        if(!(*pInPutDataReg & ( 1 << 4))){
          //key is pressed
          delay();
          printf("1\n");
        }

        //check C2(PG5) low or high
        if(!(*pInPutDataReg & ( 1 << 5))){
          //key is pressed
          delay();
          printf("2\n");
        }

        //check C3(PG6) low or high
        if(!(*pInPutDataReg & ( 1 << 6))){
          //key is pressed
          delay();
          printf("3\n");
        }

        //check C4(PG7) low or high
        if(!(*pInPutDataReg & ( 1 << 7))){
          //key is pressed
          delay();
          printf("A\n");
        }


        //make all rows HIGH
         *pOutPutDataReg |= (0x0F);
        //make R2 LOW(PG1)
        *pOutPutDataReg &= ~( 1 << 1);

        //scan the columns
        //check C1(PG4) low or high
        if(!(*pInPutDataReg & ( 1 << 4))){
          //key is pressed
          delay();
          printf("4\n");
        }

        //check C2(PG5) low or high
        if(!(*pInPutDataReg & ( 1 << 5))){
          //key is pressed
          delay();
          printf("5\n");
        }

        //check C3(PG6) low or high
        if(!(*pInPutDataReg & ( 1 << 6))){
          //key is pressed
          delay();
          printf("6\n");
        }

        //check C4(PG7) low or high
        if(!(*pInPutDataReg & ( 1 << 7))){
          //key is pressed
          delay();
          printf("B\n");
        }

        //make all rows HIGH
         *pOutPutDataReg |= (0x0F);
        //make R3 LOW(PG2)
        *pOutPutDataReg &= ~( 1 << 2);

        //scan the columns
        //check C1(PG4) low or high
        if(!(*pInPutDataReg & ( 1 << 4))){
          //key is pressed
          delay();
          printf("7\n");
        }

        //check C2(PG5) low or high
        if(!(*pInPutDataReg & ( 1 << 5))){
          //key is pressed
          delay();
          printf("8\n");
        }

        //check C3(PG6) low or high
        if(!(*pInPutDataReg & ( 1 << 6))){
          //key is pressed
          delay();
          printf("9\n");
        }

        //check C4(PG7) low or high
        if(!(*pInPutDataReg & ( 1 << 7))){
          //key is pressed
          delay();
          printf("C\n");
        }

        //make all rows HIGH
         *pOutPutDataReg |= (0x0F);
        //make R4 LOW(PG3)
        *pOutPutDataReg &= ~( 1 << 3);

        //scan the columns
        //check C1(PG4) low or high
        if(!(*pInPutDataReg & ( 1 << 4))){
          //key is pressed
          delay();
          printf("*\n");
        }

        //check C2(PG5) low or high
        if(!(*pInPutDataReg & ( 1 << 5))){
          //key is pressed
          delay();
          printf("0\n");
        }

        //check C3(PG6) low or high
        if(!(*pInPutDataReg & ( 1 << 6))){
          //key is pressed
          delay();
          printf("#\n");
        }

        //check C4(PG7) low or high
        if(!(*pInPutDataReg & ( 1 << 7))){
          //key is pressed
          delay();
          printf("D\n");
        }

    }

}
