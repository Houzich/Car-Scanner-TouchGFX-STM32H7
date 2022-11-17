/**
 ******************************************************************************
 * @file    ST1633i_reg.h
 * @author  MCD Application Team
 * @brief   Header of ST1633i_reg.c
 *          
 ******************************************************************************
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ST1633I_REG_H
#define ST1633I_REG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
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

/* Exported types ------------------------------------------------------------*/

/** @defgroup ST1633I_Exported_Types ST1633I Exported Types
 * @{
 */
/************** Generic Function  *******************/

typedef int32_t (*ST1633I_Write_Func)(void *, uint8_t, uint8_t*, uint16_t);
typedef int32_t (*ST1633I_Read_Func) (void *, uint8_t, uint8_t*, uint16_t);

/**
 * @}
 */

/** @defgroup ST1633I_Imported_Globals ST1633I Imported Globals
 * @{
 */
typedef struct
{
  ST1633I_Write_Func   WriteReg;
  ST1633I_Read_Func    ReadReg;
  void                *handle;
} ST1633I_ctx_t;
/**
 * @}
 */

/** @defgroup ST1633I_Exported_Constants ST1633I Exported Constants
 * @{
 */

//#############################################################################################################
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################


/* Device Control register of the ST1633I (R/W) */
#define ST1633I_DEV_CONTROL_REG         0x02

/* Advanced Touch Information Register */
#define ST1633I_ADVANCED_TOUCH_INFO_REG          0x10

#define ST1633I_SENSING_COUNTER_H_REG          0x07
#define ST1633I_SENSING_COUNTER_L_REG          0x08

#define XY0_Coordinate_H_REG         0x12
#define X0_Coordinate_L_REG          0x13
#define Y0_Coordinate_L_REG          0x14

#define XY1_Coordinate_H_REG         0x16
#define X1_Coordinate_L_REG          0x17
#define Y1_Coordinate_L_REG          0x18

#define XY2_Coordinate_H_REG         0x1A
#define X2_Coordinate_L_REG          0x1B
#define Y2_Coordinate_L_REG          0x1C

#define XY3_Coordinate_H_REG         0x1E
#define X3_Coordinate_L_REG          0x1F
#define Y3_Coordinate_L_REG          0x20

#define XY4_Coordinate_H_REG         0x22
#define X4_Coordinate_L_REG          0x23
#define Y4_Coordinate_L_REG          0x24

#define XY5_Coordinate_H_REG         0x26
#define X5_Coordinate_L_REG          0x27
#define Y5_Coordinate_L_REG          0x28

#define XY6_Coordinate_H_REG         0x2A
#define X6_Coordinate_L_REG          0x2B
#define Y6_Coordinate_L_REG          0x2C

#define XY7_Coordinate_H_REG         0x2E
#define X7_Coordinate_L_REG          0x2F
#define Y7_Coordinate_L_REG          0x30

#define XY8_Coordinate_H_REG         0x32
#define X8_Coordinate_L_REG          0x33
#define Y8_Coordinate_L_REG          0x34

#define XY9_Coordinate_H_REG         0x36
#define X9_Coordinate_L_REG          0x37
#define Y9_Coordinate_L_REG          0x38


/*******************************************************************************
* Register      : Device Control Register
* Address       : 0X02
* Bit Group Name:
* Permission    : R/W
*******************************************************************************/
typedef struct {
  uint8_t reset              	: 1;
  uint8_t power_down            : 1;
  uint8_t deep_power_down       : 1;
  uint8_t not_used_1            : 1;
  uint8_t not_used_2            : 1;
  uint8_t proximity_enable      : 1;
  uint8_t multi_touch_disable   : 1;
  uint8_t not_used_3            : 1;
} st1633i_device_control_t;

/*******************************************************************************
* Register      : Advanced Touch Info
* Address       : 0X10
* Bit Group Name:
* Permission    : R
*******************************************************************************/
typedef struct {
  uint8_t gesture_type              : 4;
  uint8_t not_used_1                : 1;
  uint8_t water_flag                : 1;
  uint8_t proximity_flag            : 1;
  uint8_t not_used_2                : 1;
} st1633i_advanced_touch_info_t;

/*******************************************************************************
* Register      : XY Coordinates
* Address       :
* Bit Group Name:
* Permission    : R
*******************************************************************************/
typedef struct {
  uint8_t y              	: 3;
  uint8_t not_used_1        : 1;
  uint8_t x                	: 3;
  uint8_t valid            	: 1;
} st1633i_xy_coordinates_t;


int32_t  ST1633I_dev_control_w(ST1633I_ctx_t *ctx, st1633i_device_control_t value);
int32_t  ST1633I_dev_control_r(ST1633I_ctx_t *ctx, st1633i_device_control_t *value);
int32_t	 ST1633I_touch_status(ST1633I_ctx_t *ctx, uint8_t *value, uint16_t *x, uint16_t *y);
int32_t  ST1633I_sensing_counter(ST1633I_ctx_t *ctx, uint16_t *value);
int32_t  ST1633I_xy(ST1633I_ctx_t *ctx, uint8_t reg_addr, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy0(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy1(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy2(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy3(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy4(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy5(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy6(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy7(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy8(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t  ST1633I_xy9(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y);
int32_t	 ST1633I_xy_all(ST1633I_ctx_t *ctx, uint8_t *valid_arr, uint16_t *x_arr, uint16_t *y_arr);
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################
//#############################################################################################################




/* P1 X, Y coordinates, weight and misc registers */
#define ST1633I_P1_XH_REG            0x03U
#define ST1633I_P1_XL_REG            0x04U
#define ST1633I_P1_YH_REG            0x05U
#define ST1633I_P1_YL_REG            0x06U
#define ST1633I_P1_WEIGHT_REG        0x07U
#define ST1633I_P1_MISC_REG          0x08U

/* P2 X, Y coordinates, weight and misc registers */
#define ST1633I_P2_XH_REG            0x09U
#define ST1633I_P2_XL_REG            0x0AU
#define ST1633I_P2_YH_REG            0x0BU
#define ST1633I_P2_YL_REG            0x0CU
#define ST1633I_P2_WEIGHT_REG        0x0DU
#define ST1633I_P2_MISC_REG          0x0EU

/* P3 X, Y coordinates, weight and misc registers */
#define ST1633I_P3_XH_REG            0x0FU
#define ST1633I_P3_XL_REG            0x10U
#define ST1633I_P3_YH_REG            0x11U
#define ST1633I_P3_YL_REG            0x12U
#define ST1633I_P3_WEIGHT_REG        0x13U
#define ST1633I_P3_MISC_REG          0x14U

/* P4 X, Y coordinates, weight and misc registers */
#define ST1633I_P4_XH_REG            0x15U
#define ST1633I_P4_XL_REG            0x16U
#define ST1633I_P4_YH_REG            0x17U
#define ST1633I_P4_YL_REG            0x18U
#define ST1633I_P4_WEIGHT_REG        0x19U
#define ST1633I_P4_MISC_REG          0x1AU

/* P5 X, Y coordinates, weight and misc registers */
#define ST1633I_P5_XH_REG            0x1BU
#define ST1633I_P5_XL_REG            0x1CU
#define ST1633I_P5_YH_REG            0x1DU
#define ST1633I_P5_YL_REG            0x1EU
#define ST1633I_P5_WEIGHT_REG        0x1FU
#define ST1633I_P5_MISC_REG          0x20U

/* P6 X, Y coordinates, weight and misc registers */
#define ST1633I_P6_XH_REG            0x21U
#define ST1633I_P6_XL_REG            0x22U
#define ST1633I_P6_YH_REG            0x23U
#define ST1633I_P6_YL_REG            0x24U
#define ST1633I_P6_WEIGHT_REG        0x25U
#define ST1633I_P6_MISC_REG          0x26U

/* P7 X, Y coordinates, weight and misc registers */
#define ST1633I_P7_XH_REG            0x27U
#define ST1633I_P7_XL_REG            0x28U
#define ST1633I_P7_YH_REG            0x29U
#define ST1633I_P7_YL_REG            0x2AU
#define ST1633I_P7_WEIGHT_REG        0x2BU
#define ST1633I_P7_MISC_REG          0x2CU

/* P8 X, Y coordinates, weight and misc registers */
#define ST1633I_P8_XH_REG            0x2DU
#define ST1633I_P8_XL_REG            0x2EU
#define ST1633I_P8_YH_REG            0x2FU
#define ST1633I_P8_YL_REG            0x30U
#define ST1633I_P8_WEIGHT_REG        0x31U
#define ST1633I_P8_MISC_REG          0x32U

/* P9 X, Y coordinates, weight and misc registers */
#define ST1633I_P9_XH_REG            0x33U
#define ST1633I_P9_XL_REG            0x34U
#define ST1633I_P9_YH_REG            0x35U
#define ST1633I_P9_YL_REG            0x36U
#define ST1633I_P9_WEIGHT_REG        0x37U
#define ST1633I_P9_MISC_REG          0x38U

/* P10 X, Y coordinates, weight and misc registers */
#define ST1633I_P10_XH_REG           0x39U
#define ST1633I_P10_XL_REG           0x3AU
#define ST1633I_P10_YH_REG           0x3BU
#define ST1633I_P10_YL_REG           0x3CU
#define ST1633I_P10_WEIGHT_REG       0x3DU
#define ST1633I_P10_MISC_REG         0x3EU

/* Threshold for touch detection */
#define ST1633I_TH_GROUP_REG         0x80

/* Filter function coefficients */
#define ST1633I_TH_DIFF_REG          0x85

/* Control register */
#define ST1633I_CTRL_REG             0x86

/* The time period of switching from Active mode to Monitor mode when there is no touching */
#define ST1633I_TIMEENTERMONITOR_REG 0x87

/* Report rate in Active mode */
#define ST1633I_PERIODACTIVE_REG     0x88

/* Report rate in Monitor mode */
#define ST1633I_PERIODMONITOR_REG    0x89

/* The value of the minimum allowed angle while Rotating gesture mode */
#define ST1633I_RADIAN_VALUE_REG     0x91

/* Maximum offset while Moving Left and Moving Right gesture */
#define ST1633I_OFFSET_LR_REG        0x92

/* Maximum offset while Moving Up and Moving Down gesture */
#define ST1633I_OFFSET_UD_REG        0x93

/* Minimum distance while Moving Left and Moving Right gesture */
#define ST1633I_DISTANCE_LR_REG      0x94

/* Minimum distance while Moving Up and Moving Down gesture */
#define ST1633I_DISTANCE_UD_REG      0x95

/* Maximum distance while Zoom In and Zoom Out gesture */
#define ST1633I_DISTANCE_ZOOM_REG    0x96

/* High 8-bit of LIB Version info */
#define ST1633I_LIB_VER_H_REG        0xA1

/* Low 8-bit of LIB Version info */
#define ST1633I_LIB_VER_L_REG        0xA2

/* Chip Selecting */
#define ST1633I_CIPHER_REG           0xA3

/* Interrupt mode register (used when in interrupt mode) */
#define ST1633I_GMODE_REG            0xA4

/* Current power mode the ST1633I system is in (R) */
#define ST1633I_PWR_MODE_REG         0xA5

/* ST1633I firmware version */
#define ST1633I_FIRMID_REG           0xA6

/* ST1633I Chip identification register */
#define ST1633I_CHIP_ID_REG          0xA8

/* Release code version */
#define ST1633I_RELEASE_CODE_ID_REG  0xAF

/* Current operating mode the ST1633I system is in (R) */
#define ST1633I_STATE_REG            0xBC

/**
 * @}
 */

/*******************************************************************************
* Register      : Generic - All
* Address       : Generic - All
* Bit Group Name: None
* Permission    : W
*******************************************************************************/
int32_t ST1633I_write_reg(ST1633I_ctx_t *ctx, uint8_t reg, uint8_t *pbuf, uint16_t length);
int32_t ST1633I_read_reg(ST1633I_ctx_t *ctx, uint8_t reg, uint8_t *pbuf, uint16_t length);

/**************** Base Function  *******************/



/*******************************************************************************
* Register      : GEST_DEVICE_STATUS
* Address       : 0X01
* Bit Group Name: Status Error
* Permission    : R
*******************************************************************************/
#define   ST1633I_DEVICE_STATUS_BIT_MASK        0xFFU
#define   ST1633I_DEVICE_STATUS_BIT_POSITION    0
int32_t ST1633I_device_status(ST1633I_ctx_t *ctx, uint8_t *value);
/*******************************************************************************
* Register      : P1_XH
* Address       : 0X03
* Bit Group Name: First Event Flag
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P1_XH_EF_BIT_MASK        0xC0U
#define   ST1633I_P1_XH_EF_BIT_POSITION    6
int32_t ST1633I_p1_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P1_XH
* Address       : 0X03
* Bit Group Name: First Touch X Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P1_XH_TP_BIT_MASK        0x0FU
#define   ST1633I_P1_XH_TP_BIT_POSITION    0
int32_t ST1633I_p1_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P1_XL
* Address       : 0X04
* Bit Group Name: First Touch X Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P1_XL_TP_BIT_MASK        0xFFU
#define   ST1633I_P1_XL_TP_BIT_POSITION    0
int32_t ST1633I_p1_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P1_YH
* Address       : 0X05
* Bit Group Name: First Touch ID
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P1_YH_TID_BIT_MASK        0xF0U
#define   ST1633I_P1_YH_TID_BIT_POSITION    4
int32_t ST1633I_p1_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P1_YH
* Address       : 0x06
* Bit Group Name: First Touch Y Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P1_YH_TP_BIT_MASK        0x0FU
#define   ST1633I_P1_YH_TP_BIT_POSITION    0
int32_t ST1633I_p1_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P1_YL
* Address       : 0X06
* Bit Group Name: First Touch Y Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P1_YL_TP_BIT_MASK        0xFFU
#define   ST1633I_P1_YL_TP_BIT_POSITION    0
int32_t ST1633I_p1_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P1_WEIGHT
* Address       : 0X07
* Bit Group Name: First Touch Weight(pressure)
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P1_WEIGHT_BIT_MASK        0xFFU
#define   ST1633I_P1_WEIGHT_BIT_POSITION    0
int32_t ST1633I_p1_weight(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P1_MISC
* Address       : 0X08
* Bit Group Name: First Touch Area
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P1_MISC_BIT_MASK        0xF0U
#define   ST1633I_P1_MISC_BIT_POSITION    4
int32_t ST1633I_p1_misc(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P2_XH
* Address       : 0X09
* Bit Group Name: Second Event Flag
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P2_XH_EF_BIT_MASK        0xC0U
#define   ST1633I_P2_XH_EF_BIT_POSITION    6
int32_t ST1633I_p2_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P2_XH
* Address       : 0X09
* Bit Group Name: Second Touch X Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P2_XH_TP_BIT_MASK        0x0FU
#define   ST1633I_P2_XH_TP_BIT_POSITION    0
int32_t ST1633I_p2_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P2_XL
* Address       : 0X0A
* Bit Group Name: Second Touch X Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P2_XL_TP_BIT_MASK        0xFFU
#define   ST1633I_P2_XL_TP_BIT_POSITION    0
int32_t ST1633I_p2_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P2_YH
* Address       : 0X0B
* Bit Group Name: Second Touch ID
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P2_YH_TID_BIT_MASK        0xF0U
#define   ST1633I_P2_YH_TID_BIT_POSITION    4
int32_t ST1633I_p2_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P2_YH
* Address       : 0x0B
* Bit Group Name: Second Touch Y Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P2_YH_TP_BIT_MASK        0x0FU
#define   ST1633I_P2_YH_TP_BIT_POSITION    0
int32_t ST1633I_p2_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P2_YL
* Address       : 0X0C
* Bit Group Name: Second Touch Y Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P2_YL_TP_BIT_MASK        0xFFU
#define   ST1633I_P2_YL_TP_BIT_POSITION    0
int32_t ST1633I_p2_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P2_WEIGHT
* Address       : 0X0D
* Bit Group Name: Second Touch Weight(pressure)
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P2_WEIGHT_BIT_MASK        0xFFU
#define   ST1633I_P2_WEIGHT_BIT_POSITION    0
int32_t ST1633I_p2_weight(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P2_MISC
* Address       : 0X0E
* Bit Group Name: Second Touch Area
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P2_MISC_BIT_MASK        0xF0U
#define   ST1633I_P2_MISC_BIT_POSITION    4
int32_t ST1633I_p2_misc(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P3_XH
* Address       : 0X0F
* Bit Group Name: Third Event Flag
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P3_XH_EF_BIT_MASK        0xC0U
#define   ST1633I_P3_XH_EF_BIT_POSITION    6
int32_t ST1633I_p3_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P3_XH
* Address       : 0X0F
* Bit Group Name: Third Touch X High Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P3_XH_TP_BIT_MASK        0x0FU
#define   ST1633I_P3_XH_TP_BIT_POSITION    0
int32_t ST1633I_p3_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P3_XL
* Address       : 0X10
* Bit Group Name: Third Touch X Low Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P3_XL_TP_BIT_MASK        0xFFU
#define   ST1633I_P3_XL_TP_BIT_POSITION    0
int32_t ST1633I_p3_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P3_YH
* Address       : 0X11
* Bit Group Name: Third Touch ID
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P3_YH_TID_BIT_MASK        0xF0U
#define   ST1633I_P3_YH_TID_BIT_POSITION    4
int32_t ST1633I_p3_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P3_YH
* Address       : 0x11
* Bit Group Name: Third Touch Y High Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P3_YH_TP_BIT_MASK        0x0FU
#define   ST1633I_P3_YH_TP_BIT_POSITION    0
int32_t ST1633I_p3_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P3_YL
* Address       : 0X12
* Bit Group Name: Third Touch Y Low Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P3_YL_TP_BIT_MASK        0xFFU
#define   ST1633I_P3_YL_TP_BIT_POSITION    0
int32_t ST1633I_p3_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P3_WEIGHT
* Address       : 0X13
* Bit Group Name: Third Touch Weight(pressure)
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P3_WEIGHT_BIT_MASK        0xFFU
#define   ST1633I_P3_WEIGHT_BIT_POSITION    0
int32_t ST1633I_p3_weight(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P3_MISC
* Address       : 0X14
* Bit Group Name: Third Touch Area
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P3_MISC_BIT_MASK        0xF0U
#define   ST1633I_P3_MISC_BIT_POSITION    4
int32_t ST1633I_p3_misc(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P4_XH
* Address       : 0X15
* Bit Group Name: Fourth Event Flag
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P4_XH_EF_BIT_MASK        0xC0U
#define   ST1633I_P4_XH_EF_BIT_POSITION    6
int32_t ST1633I_p4_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P4_XH
* Address       : 0X15
* Bit Group Name: Fourth Touch X High Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P4_XH_TP_BIT_MASK        0x0FU
#define   ST1633I_P4_XH_TP_BIT_POSITION    0
int32_t ST1633I_p4_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P4_XL
* Address       : 0X16
* Bit Group Name: Fourth Touch X Low Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P4_XL_TP_BIT_MASK        0xFFU
#define   ST1633I_P4_XL_TP_BIT_POSITION    0
int32_t ST1633I_p4_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P4_YH
* Address       : 0X17
* Bit Group Name: Fourth Touch ID
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P4_YH_TID_BIT_MASK        0xF0U
#define   ST1633I_P4_YH_TID_BIT_POSITION    4
int32_t ST1633I_p4_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P4_YH
* Address       : 0x17
* Bit Group Name: Fourth Touch Y High Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P4_YH_TP_BIT_MASK        0x0FU
#define   ST1633I_P4_YH_TP_BIT_POSITION    0
int32_t ST1633I_p4_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P4_YL
* Address       : 0X18
* Bit Group Name: Fourth Touch Y Low Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P4_YL_TP_BIT_MASK        0xFFU
#define   ST1633I_P4_YL_TP_BIT_POSITION    0
int32_t ST1633I_p4_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P4_WEIGHT
* Address       : 0X19
* Bit Group Name: Fourth Touch Weight(pressure)
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P4_WEIGHT_BIT_MASK        0xFFU
#define   ST1633I_P4_WEIGHT_BIT_POSITION    0
int32_t ST1633I_p4_weight(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P4_MISC
* Address       : 0X1A
* Bit Group Name: Fourth Touch Area
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P4_MISC_BIT_MASK        0xF0U
#define   ST1633I_P4_MISC_BIT_POSITION    4
int32_t ST1633I_p4_misc(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P5_XH
* Address       : 0X1B
* Bit Group Name: Fifth Event Flag
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P5_XH_EF_BIT_MASK        0xC0U
#define   ST1633I_P5_XH_EF_BIT_POSITION    6
int32_t ST1633I_p5_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P5_XH
* Address       : 0X1B
* Bit Group Name: Fifth Touch X High Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P5_XH_TP_BIT_MASK        0x0FU
#define   ST1633I_P5_XH_TP_BIT_POSITION    0
int32_t ST1633I_p5_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P5_XL
* Address       : 0X1C
* Bit Group Name: Fifth Touch X Low Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P5_XL_TP_BIT_MASK        0xFFU
#define   ST1633I_P5_XL_TP_BIT_POSITION    0
int32_t ST1633I_p5_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P5_YH
* Address       : 0X1D
* Bit Group Name: Fifth Touch ID
* Permission    : R
* Default value : 0xF0U
*******************************************************************************/
#define   ST1633I_P5_YH_TID_BIT_MASK        0xF0U
#define   ST1633I_P5_YH_TID_BIT_POSITION    4
int32_t ST1633I_p5_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P5_YH
* Address       : 0x1D
* Bit Group Name: Fifth Touch Y High Position
* Permission    : R
* Default value : 0x0FU
*******************************************************************************/
#define   ST1633I_P5_YH_TP_BIT_MASK        0x0FU
#define   ST1633I_P5_YH_TP_BIT_POSITION    0
int32_t ST1633I_p5_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P5_YL
* Address       : 0X1E
* Bit Group Name: Fifth Touch Y Low Position
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P5_YL_TP_BIT_MASK        0xFFU
#define   ST1633I_P5_YL_TP_BIT_POSITION    0
int32_t ST1633I_p5_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P5_WEIGHT
* Address       : 0X1F
* Bit Group Name: Fifth Touch Weight(pressure)
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P5_WEIGHT_BIT_MASK        0xFFU
#define   ST1633I_P5_WEIGHT_BIT_POSITION    0
int32_t ST1633I_p5_weight(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : P5_MISC
* Address       : 0X20
* Bit Group Name: Fifth Touch Area
* Permission    : R
* Default value : 0xFFU
*******************************************************************************/
#define   ST1633I_P5_MISC_BIT_MASK        0xF0U
#define   ST1633I_P5_MISC_BIT_POSITION    4
int32_t ST1633I_p5_misc(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : TH_GROUP
* Address       : 0X80
* Bit Group Name: Threshold for touch detection
* Permission    : RW
* Default value : None
*******************************************************************************/
#define   ST1633I_TH_GROUP_BIT_MASK        0xFFU
#define   ST1633I_TH_GROUP_BIT_POSITION    0
int32_t ST1633I_th_group(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : TH_DIFF
* Address       : 0X85
* Bit Group Name: Filter function coefficient
* Permission    : RW
* Default value : None
*******************************************************************************/
#define   ST1633I_TH_DIFF_BIT_MASK        0xFFU
#define   ST1633I_TH_DIFF_BIT_POSITION    0
int32_t ST1633I_th_diff(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : CTRL
* Address       : 0X86
* Bit Group Name: 
* Permission    : RW
* Default value : 0x01
*******************************************************************************/
#define   ST1633I_CTRL_BIT_MASK           0xFFU
#define   ST1633I_CTRL_BIT_POSITION       0
int32_t ST1633I_ctrl(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : TIMEENTERMONITOR
* Address       : 0X87
* Bit Group Name: 
* Permission    : RW
* Default value : 0x0A
*******************************************************************************/
#define   ST1633I_TIMEENTERMONITOR_BIT_MASK           0xFFU
#define   ST1633I_TIMEENTERMONITOR_BIT_POSITION       0
int32_t ST1633I_time_enter_monitor(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : PERIODACTIVE
* Address       : 0X88
* Bit Group Name: 
* Permission    : RW
* Default value : None
*******************************************************************************/
#define   ST1633I_PERIODACTIVE_BIT_MASK           0xFFU
#define   ST1633I_PERIODACTIVE_BIT_POSITION       0
int32_t ST1633I_period_active(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : PERIODMONITOR
* Address       : 0X89
* Bit Group Name: 
* Permission    : RW
* Default value : 0x28
*******************************************************************************/
#define   ST1633I_PERIODMONITOR_BIT_MASK           0xFFU
#define   ST1633I_PERIODMONITOR_BIT_POSITION       0
int32_t ST1633I_period_monitor(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : RADIAN_VALUE
* Address       : 0X91
* Bit Group Name: 
* Permission    : RW
* Default value : 0x0A
*******************************************************************************/
#define   ST1633I_RADIAN_VALUE_BIT_MASK           0xFFU
#define   ST1633I_RADIAN_VALUE_BIT_POSITION       0
int32_t ST1633I_radian_value(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : OFFSET_LEFT_RIGHT
* Address       : 0X92
* Bit Group Name: 
* Permission    : RW
* Default value : 0x19
*******************************************************************************/
#define   ST1633I_OFFSET_LR_BIT_MASK           0xFFU
#define   ST1633I_OFFSET_LR_BIT_POSITION       0
int32_t ST1633I_offset_left_right(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : OFFSET_UP_DOWN
* Address       : 0X93
* Bit Group Name: 
* Permission    : RW
* Default value : 0x19
*******************************************************************************/
#define   ST1633I_OFFSET_UD_BIT_MASK           0xFFU
#define   ST1633I_OFFSET_UD_BIT_POSITION       0
int32_t ST1633I_offset_up_down(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : DISTANCE_LEFT_RIGHT
* Address       : 0X94
* Bit Group Name: 
* Permission    : RW
* Default value : 0x19
*******************************************************************************/
#define   ST1633I_DISTANCE_LR_BIT_MASK           0xFFU
#define   ST1633I_DISTANCE_LR_BIT_POSITION       0
int32_t  ST1633I_disatnce_left_right(ST1633I_ctx_t *ctx, uint8_t value);
        
/*******************************************************************************
* Register      : DISTANCE_UP_DOWN
* Address       : 0X95
* Bit Group Name: 
* Permission    : RW
* Default value : 0x19
*******************************************************************************/
#define   ST1633I_DISTANCE_UD_BIT_MASK           0xFFU
#define   ST1633I_DISTANCE_UD_BIT_POSITION       0
int32_t ST1633I_distance_up_down(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : DISTANCE_ZOOM
* Address       : 0X96
* Bit Group Name: 
* Permission    : RW
* Default value : 0x32
*******************************************************************************/
#define   ST1633I_DISTANCE_ZOOM_BIT_MASK           0xFFU
#define   ST1633I_DISTANCE_ZOOM_BIT_POSITION       0
int32_t ST1633I_distance_zoom(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : LIB_VER_H
* Address       : 0XA1
* Bit Group Name: 
* Permission    : R
* Default value : None
*******************************************************************************/
#define   ST1633I_LIB_VER_H_BIT_MASK           0xFFU
#define   ST1633I_LIB_VER_H_BIT_POSITION       0
int32_t ST1633I_lib_ver_high(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : LIB_VER_L
* Address       : 0XA2
* Bit Group Name: 
* Permission    : R
* Default value : None
*******************************************************************************/
#define   ST1633I_LIB_VER_L_BIT_MASK           0xFFU
#define   ST1633I_LIB_VER_L_BIT_POSITION       0
int32_t ST1633I_lib_ver_low(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : CIPHER
* Address       : 0XA3
* Bit Group Name: 
* Permission    : R
* Default value : 0x06
*******************************************************************************/
#define   ST1633I_CIPHER_BIT_MASK           0xFFU
#define   ST1633I_CIPHER_BIT_POSITION       0
int32_t ST1633I_cipher(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : G_MODE
* Address       : 0XA4
* Bit Group Name: 
* Permission    : RW
* Default value : 0x01
*******************************************************************************/
#define   ST1633I_G_MODE_BIT_MASK           0xFFU
#define   ST1633I_G_MODE_BIT_POSITION       0
int32_t ST1633I_g_mode(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : PWR_MODE
* Address       : 0XA5
* Bit Group Name: 
* Permission    : RW
* Default value : 0x00
*******************************************************************************/
#define   ST1633I_PWR_MODE_BIT_MASK           0xFFU
#define   ST1633I_PWR_MODE_BIT_POSITION       0
int32_t ST1633I_pwr_mode(ST1633I_ctx_t *ctx, uint8_t value);

/*******************************************************************************
* Register      : FIRMID
* Address       : 0XA6
* Bit Group Name: 
* Permission    : R
* Default value : None
*******************************************************************************/
#define   ST1633I_FIRMID_BIT_MASK           0xFFU
#define   ST1633I_FIRMID_BIT_POSITION       0
int32_t ST1633I_firm_id(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : FOCALTECH_ID
* Address       : 0XA8
* Bit Group Name: 
* Permission    : R
* Default value : 0x11
*******************************************************************************/
#define   ST1633I_CHIP_ID_BIT_MASK           0xFFU
#define   ST1633I_CHIP_ID_BIT_POSITION       0
int32_t ST1633I_chip_id(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : RELEASE_CODE_ID
* Address       : 0XAF
* Bit Group Name: 
* Permission    : R
* Default value : 0x001
*******************************************************************************/
#define   ST1633I_RC_ID_BIT_MASK           0xFFU
#define   ST1633I_RC_ID_BIT_POSITION       0
int32_t ST1633I_release_code_id(ST1633I_ctx_t *ctx, uint8_t *value);

/*******************************************************************************
* Register      : STATE
* Address       : 0XBC
* Bit Group Name: 
* Permission    : RW
* Default value : 0x01
*******************************************************************************/
#define   ST1633I_STATE_BIT_MASK           0xFFU
#define   ST1633I_STATE_BIT_POSITION       0
int32_t ST1633I_state(ST1633I_ctx_t *ctx, uint8_t value);

  /**
   * @}
   */

#ifdef __cplusplus
}
#endif
#endif /* ST1633I_REG_H */


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
