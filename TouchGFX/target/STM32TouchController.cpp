/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>

extern "C"
{
#include "BSP_TS.h"

    uint32_t LCD_GetXSize();
    uint32_t LCD_GetYSize();
}

void STM32TouchController::init()
{
    TS_Init_t hTS;
    hTS.Orientation = TS_SWAP_XY;
    hTS.Accuracy = 1;
    hTS.Width = LCD_GetXSize();
    hTS.Height = LCD_GetYSize();
    BSP_TS_Init(&hTS);
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    TS_State_t  TS_State = { 0 };
    BSP_TS_GetState(&TS_State);
    if (TS_State.TouchDetected)
    {
        x = TS_State.TouchX;
        y = TS_State.TouchY;
        return true;
    }

    return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
