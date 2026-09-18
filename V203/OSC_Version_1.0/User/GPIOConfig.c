#include <ch32v20X.h>

void GPIOConfigInit(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIOInitStruct = {0};
    GPIOInitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIOInitStruct.GPIO_Pin = 0x00FF;//PA0-7
    GPIOInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIOInitStruct);

    GPIOA -> OUTDR = 0x0000;

    GPIOInitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIOInitStruct.GPIO_Pin = GPIO_Pin_15;//LED
    GPIOInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIOInitStruct);
}