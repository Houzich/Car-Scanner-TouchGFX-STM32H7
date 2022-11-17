/**
 ******************************************************************************
 * @file    ST1633I.h
 * @author  MCD Application Team
 * @brief   This file contains all the functions prototypes for the
 *          ST1633I.c IO expander driver.
 ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ST1633I_H
#define ST1633I_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "ST1633i_reg.h"
#include <stddef.h>
#include "ST1633i_conf.h"
  
/* Macros --------------------------------------------------------------------*/

/** @addtogroup BSP
 * @{
 */

/** @addtogroup Component
 * @{
 */

/** @addtogroup ST1633I
 * @{
 */

/** @defgroup ST1633I_Exported_Constants ST1633I Exported Constants
 * @{
 */
#define ST1633I_OK                      (0)
#define ST1633I_ERROR                   (-1)

/* Max detectable simultaneous touches */
#define ST1633I_MAX_NB_TOUCH             5U
  
/* Touch ST1633I IDs */
#define ST1633I_ID                        0x51U

/* Possible values of ST1633I_DEV_MODE_REG */
#define ST1633I_DEV_MODE_WORKING          0x00U
#define ST1633I_DEV_MODE_FACTORY          0x04U
     
/* Possible values of ST1633I_GEST_ID_REG */
#define ST1633I_GEST_ID_NO_GESTURE        0x00U
#define ST1633I_GEST_ID_MOVE_UP           0x10U
#define ST1633I_GEST_ID_MOVE_RIGHT        0x14U
#define ST1633I_GEST_ID_MOVE_DOWN         0x18U
#define ST1633I_GEST_ID_MOVE_LEFT         0x1CU
#define ST1633I_GEST_ID_ZOOM_IN           0x48U
#define ST1633I_GEST_ID_ZOOM_OUT          0x49U
     
/* Values Pn_XH and Pn_YH related */
#define ST1633I_TOUCH_EVT_FLAG_PRESS_DOWN 0x00U
#define ST1633I_TOUCH_EVT_FLAG_LIFT_UP    0x01U
#define ST1633I_TOUCH_EVT_FLAG_CONTACT    0x02U
#define ST1633I_TOUCH_EVT_FLAG_NO_EVENT   0x03U

/* Possible values of ST1633I_GMODE_REG */
#define ST1633I_G_MODE_INTERRUPT_POLLING  0x00U
#define ST1633I_G_MODE_INTERRUPT_TRIGGER  0x01U

/**
 * @}
 */

/* Exported types ------------------------------------------------------------*/

/** @defgroup ST1633I_Exported_Types ST1633I Exported Types
 * @{
 */
typedef struct
{ 
  uint32_t  Radian;
  uint32_t  OffsetLeftRight;
  uint32_t  OffsetUpDown;
  uint32_t  DistanceLeftRight;
  uint32_t  DistanceUpDown;
  uint32_t  DistanceZoom;  
}ST1633I_Gesture_Init_t;

typedef int32_t (*ST1633I_Init_Func)    (void);
typedef int32_t (*ST1633I_DeInit_Func)  (void);
typedef int32_t (*ST1633I_GetTick_Func) (void);
typedef int32_t (*ST1633I_Delay_Func)   (uint32_t);
typedef int32_t (*ST1633I_WriteReg_Func)(uint16_t, uint16_t, uint8_t*, uint16_t);
typedef int32_t (*ST1633I_ReadReg_Func) (uint16_t, uint16_t, uint8_t*, uint16_t);

typedef struct
{
  ST1633I_Init_Func          Init;
  ST1633I_DeInit_Func        DeInit;
  uint16_t                  Address;  
  ST1633I_WriteReg_Func      WriteReg;
  ST1633I_ReadReg_Func       ReadReg;
  ST1633I_GetTick_Func       GetTick;
} ST1633I_IO_t;

typedef struct
{
  uint32_t  TouchDetected;
  uint32_t  TouchX;
  uint32_t  TouchY;
} ST1633I_State_t;

typedef struct
{
  uint32_t  TouchDetected;
  uint32_t  TouchX[ST1633I_MAX_NB_TOUCH];
  uint32_t  TouchY[ST1633I_MAX_NB_TOUCH];
  uint32_t  TouchWeight[ST1633I_MAX_NB_TOUCH];
  uint32_t  TouchEvent[ST1633I_MAX_NB_TOUCH];
  uint32_t  TouchArea[ST1633I_MAX_NB_TOUCH];
} ST1633I_MultiTouch_State_t;

typedef struct
{
  ST1633I_IO_t         IO;
  ST1633I_ctx_t        Ctx;
  uint8_t             IsInitialized;
} ST1633I_Object_t;

typedef struct 
{       
  uint8_t   MultiTouch;      
  uint8_t   Gesture;
  uint8_t   MaxTouch;
  uint32_t  MaxXl;
  uint32_t  MaxYl;
} ST1633I_Capabilities_t;

 typedef struct
{
  int32_t ( *Init                 ) ( ST1633I_Object_t *);
  int32_t ( *DeInit               ) ( ST1633I_Object_t * );
//  int32_t ( *GestureConfig        ) ( ST1633I_Object_t *, ST1633I_Gesture_Init_t* );
  int32_t ( *ReadID               ) ( ST1633I_Object_t *, uint32_t * );
  int32_t ( *GetState             ) ( ST1633I_Object_t *, ST1633I_State_t* );
//  int32_t ( *GetMultiTouchState   ) ( ST1633I_Object_t *, ST1633I_MultiTouch_State_t* );
  int32_t ( *GetCapabilities      ) ( ST1633I_Object_t *, ST1633I_Capabilities_t * );
//  int32_t ( *EnableIT             ) ( ST1633I_Object_t * );
//  int32_t ( *DisableIT            ) ( ST1633I_Object_t * );
//  int32_t ( *ClearIT              ) ( ST1633I_Object_t * );
//  int32_t ( *ITStatus             ) ( ST1633I_Object_t * );
} ST1633I_TS_Drv_t;
/**
 * @}
 */

/** @addtogroup ST1633I_Exported_Variables
  * @{
  */
extern ST1633I_TS_Drv_t ST1633I_TS_Driver;
/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup ST1633I_Exported_Functions
 * @{
 */

int32_t ST1633I_RegisterBusIO (ST1633I_Object_t *pObj, ST1633I_IO_t *pIO);
int32_t ST1633I_Init(ST1633I_Object_t *pObj);
int32_t ST1633I_DeInit(ST1633I_Object_t *pObj);
//int32_t ST1633I_GestureConfig(ST1633I_Object_t *pObj, ST1633I_Gesture_Init_t *GestureInit);
int32_t ST1633I_ReadID(ST1633I_Object_t *pObj, uint32_t *Id);
//int32_t ST1633I_GetDeviceStatus(ST1633I_Object_t *pObj, uint8_t *Status);
int32_t ST1633I_GetState(ST1633I_Object_t *pObj, ST1633I_State_t *State);
//int32_t ST1633I_GetMultiTouchState(ST1633I_Object_t *pObj, ST1633I_MultiTouch_State_t *State);
//int32_t ST1633I_EnableIT(ST1633I_Object_t *pObj);
//int32_t ST1633I_DisableIT(ST1633I_Object_t *pObj);
//int32_t ST1633I_ITStatus(ST1633I_Object_t *pObj);
//int32_t ST1633I_ClearIT(ST1633I_Object_t *pObj);
int32_t ST1633I_GetCapabilities(ST1633I_Object_t *pObj, ST1633I_Capabilities_t *Capabilities);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* ST1633I_H */

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
