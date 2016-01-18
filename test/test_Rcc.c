#include "unity.h"
#include "Rcc.h"
#include "Registers.h"
#include "Host.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_rcc(void){
  TEST_ASSERT_EQUAL(RCC_BASE_ADDRESS,&HostRcc);
  
}

void test_gpicA_address(void){
  TEST_ASSERT_EQUAL(GPIOA_BASE_ADDRESS,&HostGpioA);
}

void test_gpioUnresetEnableClock_(void){
  
  
  
  
  
}