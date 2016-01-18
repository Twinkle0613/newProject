#include "Host.h"
#include "Registers.h"
#include "Rcc.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_rcc(void){

  UnityAssertEqualNumber((_U_SINT)(((&HostRcc))), (_U_SINT)((&HostRcc)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT);



}



void test_gpicA_address(void){

  UnityAssertEqualNumber((_U_SINT)(((&HostGpioA))), (_U_SINT)((&HostGpioA)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

}



void test_gpioUnresetEnableClock_(void){











}
