/**
  ******************************************************************************
  * @file    ST1633i.c
  * @author
  * @brief
  ******************************************************************************
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ST1633i.h"


/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/** @defgroup ST1633I_Exported_Variables ST1633I Exported Variables
  * @{
  */

/* Touch screen driver structure initialization */
ST1633I_TS_Drv_t ST1633I_TS_Driver =
{
  ST1633I_Init,
  ST1633I_DeInit,
//  ST1633I_GestureConfig,
  ST1633I_ReadID,
  ST1633I_GetState,
//  ST1633I_GetMultiTouchState,
  ST1633I_GetCapabilities,
//  ST1633I_EnableIT,
//  ST1633I_DisableIT,
//  ST1633I_ClearIT,
//  ST1633I_ITStatus
};
/**
  * @}
  */

/** @defgroup ST1633I_Private_Function_Prototypes ST1633I Private Function Prototypes
  * @{
  */
#if (ST1633I_AUTO_CALIBRATION_ENABLED == 1)
static int32_t ST1633I_TS_Calibration(ST1633I_Object_t *pObj);
static int32_t ST1633I_Delay(ST1633I_Object_t *pObj, uint32_t Delay);
#endif /* ST1633I_AUTO_CALIBRATION_ENABLED == 1 */
static int32_t ST1633I_DetectTouch(ST1633I_Object_t *pObj, uint8_t *value, uint16_t *x, uint16_t *y);
static int32_t ReadRegWrap(void *handle, uint8_t Reg, uint8_t* Data, uint16_t Length);
static int32_t WriteRegWrap(void *handle, uint8_t Reg, uint8_t* Data, uint16_t Length);

/**
  * @}
  */

/** @defgroup ST1633I_Exported_Functions ST1633I Exported Functions
  * @{
  */

/**
  * @brief  Register IO bus to component object
  * @param  Component object pointer
  * @retval error status
  */
int32_t ST1633I_RegisterBusIO (ST1633I_Object_t *pObj, ST1633I_IO_t *pIO)
{
  int32_t ret;

  if (pObj == NULL)
  {
    ret = ST1633I_ERROR;
  }
  else
  {
    pObj->IO.Init      = pIO->Init;
    pObj->IO.DeInit    = pIO->DeInit;
    pObj->IO.Address   = pIO->Address;
    pObj->IO.WriteReg  = pIO->WriteReg;
    pObj->IO.ReadReg   = pIO->ReadReg;
    pObj->IO.GetTick   = pIO->GetTick;

    pObj->Ctx.ReadReg  = ReadRegWrap;
    pObj->Ctx.WriteReg = WriteRegWrap;
    pObj->Ctx.handle   = pObj;

    if(pObj->IO.Init != NULL)
    {
      ret = pObj->IO.Init();
    }
    else
    {
      ret = ST1633I_ERROR;
    }
  }

  return ret;
}

/**
  * @brief  Get ST1633I sensor capabilities
  * @param  pObj Component object pointer
  * @param  Capabilities pointer to ST1633I sensor capabilities
  * @retval Component status
  */
int32_t ST1633I_GetCapabilities(ST1633I_Object_t *pObj, ST1633I_Capabilities_t *Capabilities)
{
  /* Prevent unused argument(s) compilation warning */
  (void)(pObj);

  /* Store component's capabilities */
  Capabilities->MultiTouch = 1;
  Capabilities->Gesture    = 1;
  Capabilities->MaxTouch   = ST1633I_MAX_NB_TOUCH;
  Capabilities->MaxXl      = ST1633I_MAX_X_LENGTH;
  Capabilities->MaxYl      = ST1633I_MAX_Y_LENGTH;

  return ST1633I_OK;
}

/**
  * @brief  Initialize the ST1633I communication bus
  *         from MCU to ST1633I : ie I2C channel initialization (if required).
  * @param  pObj Component object pointer
  * @param  GestureInit: Gesture init structure
  * @retval ST1633I_OK
  */
int32_t ST1633I_Init(ST1633I_Object_t *pObj)
{
  int32_t ret = ST1633I_OK;
  st1633i_device_control_t control_reg = {0};

  if(pObj->IsInitialized == 0U)
  {
	control_reg.proximity_enable = 1;
	ret = ST1633I_dev_control_w(&pObj->Ctx, control_reg);
    pObj->IsInitialized = 1;
  }

  if(ret != ST1633I_OK)
  {
    ret = ST1633I_ERROR;
  }

  return ret;
}

/**
  * @brief  De-Initialize the ST1633I communication bus
  *         from MCU to ST1633I : ie I2C channel initialization (if required).
  * @param  pObj Component object pointer
  * @retval ST1633I_OK
  */
int32_t ST1633I_DeInit(ST1633I_Object_t *pObj)
{
  int32_t ret = ST1633I_OK;

  if(pObj->IsInitialized == 1U)
  {
    pObj->IsInitialized = 0;
  }

  return ret;
}


/**
  * @brief  Read the ST1633I device ID, pre initialize I2C in case of need to be
  *         able to read the ST1633I device ID, and verify this is a ST1633I.
  * @param  pObj Component object pointer
  * @retval The Device ID (two bytes).
  */
int32_t ST1633I_ReadID(ST1633I_Object_t *pObj, uint32_t *Id)
{
  return ST1633I_chip_id(&pObj->Ctx, (uint8_t *)Id);
}

//int32_t ST1633I_GetDeviceStatus(ST1633I_Object_t *pObj, uint8_t *Status)
//{
//  return ST1633I_device_status(&pObj->Ctx, Status);
//}


/**
  * @brief  Get the touch screen X and Y positions values
  * @param  pObj Component object pointer
  * @param  State: Single Touch stucture pointer
  * @retval ST1633I_OK.
  */
int32_t ST1633I_GetState(ST1633I_Object_t *pObj, ST1633I_State_t *State)
{
  int32_t ret = ST1633I_OK;

  ret = ST1633I_DetectTouch(pObj, (uint8_t *)&State->TouchDetected, (uint16_t *)&State->TouchX, (uint16_t *)&State->TouchY);
  if(ret != ST1633I_OK)
  {
    ret = ST1633I_ERROR;
  }

  return ret;
}

/**
  * @brief  Get the touch screen Xn and Yn positions values in multi-touch mode
  * @param  pObj Component object pointer
  * @param  State Multi Touch structure pointer
  * @retval ST1633I_OK.
  */
int32_t ST1633I_GetMultiTouchState(ST1633I_Object_t *pObj, ST1633I_MultiTouch_State_t *State)
{
  int32_t ret = ST1633I_OK;
  uint8_t  data[30];
  uint32_t i;

  ret = (uint32_t)ST1633I_DetectTouch(pObj, (uint8_t *)&State->TouchDetected, (uint16_t *)&State->TouchX, (uint16_t *)&State->TouchY);

  if(ST1633I_read_reg(&pObj->Ctx, ST1633I_P1_XH_REG, data, (uint16_t)sizeof(data)) != ST1633I_OK)
  {
    ret = ST1633I_ERROR;
  }
  else
  {
    for(i = 0; i < ST1633I_MAX_NB_TOUCH; i++)
    {
    /* Send back first ready X position to caller */
    State->TouchX[i] = (((uint32_t)data[i*6U] & ST1633I_P1_XH_TP_BIT_MASK) << 8U) | ((uint32_t)data[(i*6U) + 1U] & ST1633I_P1_XL_TP_BIT_MASK);
    /* Send back first ready Y position to caller */
    State->TouchY[i] = (((uint32_t)data[(i*6U) + 2U] & ST1633I_P1_YH_TP_BIT_MASK) << 8U) | ((uint32_t)data[(i*6U) + 3U] & ST1633I_P1_YL_TP_BIT_MASK);
    /* Send back first ready Event to caller */
    State->TouchEvent[i] = (((uint32_t)data[i*6U] & ST1633I_P1_XH_EF_BIT_MASK) >> ST1633I_P1_XH_EF_BIT_POSITION);
    /* Send back first ready Weight to caller */
    State->TouchWeight[i] = ((uint32_t)data[(i*6U) + 4U] & ST1633I_P1_WEIGHT_BIT_MASK);
    /* Send back first ready Area to caller */
    State->TouchArea[i] = ((uint32_t)data[(i*6U) + 5U] & ST1633I_P1_MISC_BIT_MASK) >> ST1633I_P1_MISC_BIT_POSITION;
    }
  }

  return ret;
}

/**
  * @brief  Return if there is touches detected or not.
  *         Try to detect new touches and forget the old ones (reset internal global
  *         variables).
  * @param  pObj Component object pointer
  * @retval Number of active touches detected (can be 0, 1 or 2) or ST1633I_ERROR
  *         in case of error
  */
static int32_t ST1633I_DetectTouch(ST1633I_Object_t *pObj, uint8_t *value, uint16_t *x, uint16_t *y)
{
  int32_t ret;
  uint8_t value_tmp;
  uint16_t x_tmp;
  uint16_t y_tmp;

  /* Read register ST1633I_TD_STAT_REG to check number of touches detection */
  ret = ST1633I_touch_status(&pObj->Ctx, &value_tmp, &x_tmp, &y_tmp);
  if( ret != ST1633I_OK)
  {
    ret = ST1633I_ERROR;
  }
  else
  {
	  *value = value_tmp;
	  *x = x_tmp;
	  *y = y_tmp;
  }
  return ret;
}

/**
  * @brief  Function
  * @param  handle: Component object handle
  * @param  Reg: The target register address to write
  * @param  pData: The target register value to be written
  * @param  Length: buffer size to be written
  * @retval error status
  */
static int32_t ReadRegWrap(void *handle, uint8_t Reg, uint8_t* pData, uint16_t Length)
{
  ST1633I_Object_t *pObj = (ST1633I_Object_t *)handle;

  return pObj->IO.ReadReg(pObj->IO.Address, Reg, pData, Length);
}

/**
  * @brief  Function
  * @param  handle: Component object handle
  * @param  Reg: The target register address to write
  * @param  pData: The target register value to be written
  * @param  Length: buffer size to be written
  * @retval error status
  */
static int32_t WriteRegWrap(void *handle, uint8_t Reg, uint8_t* pData, uint16_t Length)
{
  ST1633I_Object_t *pObj = (ST1633I_Object_t *)handle;

  return pObj->IO.WriteReg(pObj->IO.Address, Reg, pData, Length);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
