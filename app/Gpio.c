#include "Gpio.h"
#include "Rcc.h"


void configureIntPin(int direction,int pinNum, GPIO* port){

	gpioUnresetEnableClock(port);

	 port->MODER &= ~( 3 << (pinNum *2));         //build mask first
	 port->MODER |= direction << (pinNum *2);

	 port->PUPDR &= ~( 3 << (pinNum *2));
	 port->PUPDR |= NO_PULL_UD << (pinNum *2);

}


void configureOutPin(int direction, int pinNum, GPIO *port){


	 gpioUnresetEnableClock(port);
	 port->MODER &= ~( 3 << (pinNum *2));         //build mask first
	 port->MODER |= direction << (pinNum *2);

	 port->OTYPER &= ~( 3 << (pinNum));
	 port->OTYPER |= OUTPUT_PUSH_PULL << (pinNum);

	 port->OSPEED &= ~( 3 << (pinNum *2));
	 port->OSPEED |= HIGH_SPEED << (pinNum *2);

}

void configureAlterFuncPin(int pinNum, GPIO *port, int valueAFR){
	gpioUnresetEnableClock(port);
	 port->MODER &= ~( 3 << (pinNum *2));
	 port->MODER |= GPIO_MODE_ALFUNCTION << (pinNum *2);
	 if(pinNum > 7){
 	  port->AFRH &= ~( 15 << ( (pinNum%8) * 4 ));
	  port->AFRH |= valueAFR << ( (pinNum%8) * 4 );
	 }else{
      port->AFRL &= ~( 15 << ( pinNum * 4 ));
      port->AFRL |= valueAFR << ( pinNum * 4 );
	 }
}


int filterSignal(uint64_t Data){
   int inputSignal = Data & (0b0000000000000001);
   return inputSignal;
}


//GPIO
// __HAL_RCC_GPIOG_CLK_ENABLE();
// __HAL_RCC_GPIOC_CLK_ENABLE();
// __HAL_RCC_GPIOB_CLK_ENABLE();

 /*
 int *ptr = (int*)0x40021800;
 ptr[0] =0X14000000;  //output = 14 and 13
 ptr[1] =0x00000000;
 ptr[2] =0X28000000;
 int *ptr2 = (int*)0x40020800; //PC
 ptr2[0] =0X00000400;  //output = 5
 ptr2[1] =0x00000000;
 ptr2[2] =0X00000800;
 int *ptr3 = (int*)0x40020400; //PB
 ptr3[0] =0X04000000;  //output = 13
 ptr3[1] =0x00000000;
 ptr3[2] =0X08000000;
*/

//RCC
//	int *ptr =(int*)0x40023800;
//	ptr[((int*)0x40023810)/4] = 0x000007BF;  //offset = 0x10
//	ptr[((int*)0x40023830)/4] = 0x00000040;  //offset = 0x30
/*
	int *ptr2 =(int*)0x40023810;
	ptr2[0] = 0x000007B9;

	int *ptr3 =(int*)0x40023830;
	ptr3[0] = 0x00000046;
*/


/*
gpio.Pin = pinNum;
gpio.Mode =direction;
gpio.Pull = GPIO_NOPULL;
gpio.Speed = GPIO_SPEED_MEDIUM;
HAL_GPIO_Init(port,&gpio);
*/
