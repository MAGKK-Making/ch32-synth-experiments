#include <ch32v20X.h>

#define DeltaTimeUs 50

void LogicTimeBaseInit(void){
    //TIM2µÍËÙÊ±»ù
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitTypeDef TIMTimeBaseInitStruct = {0};
    TIMTimeBaseInitStruct.TIM_ClockDivision = 0;
    TIMTimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIMTimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIMTimeBaseInitStruct.TIM_Period = DeltaTimeUs - 1;
    TIMTimeBaseInitStruct.TIM_Prescaler = 30 - 1;
    TIM_TimeBaseInit(TIM2, &TIMTimeBaseInitStruct);

    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef NVICInitStruct = {0};
    NVICInitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVICInitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVICInitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVICInitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVICInitStruct);

    TIM_Cmd(TIM2, ENABLE);

    //³¬Âý
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    TIMTimeBaseInitStruct.TIM_ClockDivision = 0;
    TIMTimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIMTimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIMTimeBaseInitStruct.TIM_Period = 10000 - 1;
    TIMTimeBaseInitStruct.TIM_Prescaler = 14400 - 1;
    TIM_TimeBaseInit(TIM3, &TIMTimeBaseInitStruct);

    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

    NVICInitStruct.NVIC_IRQChannel = TIM3_IRQn;
    NVICInitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVICInitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVICInitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVICInitStruct);

    TIM_Cmd(TIM3, ENABLE);
}