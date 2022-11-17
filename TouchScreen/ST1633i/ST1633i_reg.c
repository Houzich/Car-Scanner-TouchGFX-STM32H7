/**
 ******************************************************************************
 * @file    ST1633I_reg.c
 * @author  MCD Application Team
 * @brief   This file provides unitary register function to control the ST1633I Touch
 *
 ******************************************************************************
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "BSP.h"

#include "ST1633i_reg.h"

//#define DEBUG_ST1633I_REG

#ifdef DEBUG_ST1633I_REG
#undef DEBUG /* DEBUG */
#undef DEBUG_PRINT /* DEBUG_PRINT */
#define DEBUG_MESSAGE(...)		do {debug_header("ST1633I_REG --> ", __VA_ARGS__);} while (0)
#define DEBUG_PRINT(x)		debug_print x;
#else
#define DEBUG_MESSAGE(...)
#define DEBUG_PRINT(...)
#endif // DEBUG_TERMINAL_BUTTONS

/** @addtogroup BSP
 * @{
 */

/** @addtogroup Component
 * @{
 */

/** @defgroup ST1633I ST1633I
 * @{
 */
/**
 * @brief  Read ST1633I registers.
 * @param  ctx Component context
 * @param  reg Component reg to read from
 * @param  pdata pointer to data to be read
 * @param  length Length of data to read
 * @retval Component status
 */
int32_t ST1633I_read_reg(ST1633I_ctx_t *ctx, uint8_t reg, uint8_t *pdata,
		uint16_t length) {
	return ctx->ReadReg(ctx->handle, reg, pdata, length);
}

/**
 * @brief  Write ST1633I registers.
 * @param  ctx Component context
 * @param  reg Component reg to write to
 * @param  pdata pointer to data to be written
 * @param  length Length of data to write
 * @retval Component status
 */
int32_t ST1633I_write_reg(ST1633I_ctx_t *ctx, uint8_t reg, uint8_t *pdata,
		uint16_t length) {
	return ctx->WriteReg(ctx->handle, reg, pdata, length);
}

/**
 * @brief  Set ST1633I working mode
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_DEV_MODE_REG register
 * @retval Component status
 */
int32_t ST1633I_dev_control_w(ST1633I_ctx_t *ctx,
		st1633i_device_control_t value) {
	int32_t ret;
	ret = ST1633I_write_reg(ctx, ST1633I_DEV_CONTROL_REG, (uint8_t*) &value, 1);

	return ret;
}

/**
 * @brief  Get ST1633I working mode
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_DEV_MODE_REG register
 * @retval Component status
 */
int32_t ST1633I_dev_control_r(ST1633I_ctx_t *ctx,
		st1633i_device_control_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_DEV_CONTROL_REG, (uint8_t*) value, 1);

	return ret;
}

/**
 * @brief  Get ST1633I Touch Data Status
 * @param  ctx Component context
 * @param  value pointer to the value of Touch Data Status register
 * @retval Component status
 */
int32_t ST1633I_touch_status(ST1633I_ctx_t *ctx,
		uint8_t *value, uint16_t *x, uint16_t *y) {
	int32_t ret;
//	st1633i_advanced_touch_info_t reg;
//	ret = ST1633I_read_reg(ctx, ST1633I_ADVANCED_TOUCH_INFO_REG,
//			(uint8_t*) &reg, 1);
//  uint16_t counter;
//  ret = ST1633I_sensing_counter(ctx, &counter);

	uint8_t valid;
	uint16_t x_coord;
	uint16_t y_coord;
	ret = ST1633I_xy0(ctx, &valid, &x_coord, &y_coord);
	if (ret == 0) {
		*value = valid;
		*x = x_coord;
		*y = y_coord;
		if (valid) {
			DEBUG_MESSAGE("valid xy0 is set\n");
		}
	}






	return ret;
}

int32_t ST1633I_sensing_counter(ST1633I_ctx_t *ctx, uint16_t *value) {
	int32_t ret;
	uint16_t counter;
	ret = ST1633I_read_reg(ctx, ST1633I_SENSING_COUNTER_H_REG,
			(uint8_t*) &counter, 2);

	if (ret == 0) {
		*value = counter;
		if (counter) {
			DEBUG_MESSAGE("counter: %u\n", counter);
		}
	}

	return ret;
}

int32_t ST1633I_xy(ST1633I_ctx_t *ctx, uint8_t reg, uint8_t *valid, uint16_t *x, uint16_t *y) {
	int32_t ret;
	uint8_t regs[3];
	st1633i_xy_coordinates_t *xy_h;
	ret = ST1633I_read_reg(ctx, reg, (uint8_t*) &regs, 3);

	if (ret == 0) {
		xy_h = (st1633i_xy_coordinates_t *)regs;
		*valid = xy_h->valid;
		*x = (xy_h->x<<8)|regs[1];
		*y = (xy_h->y<<8)|regs[2];
	}
	return ret;
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy0(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY0_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy1(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY1_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy2(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY2_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy3(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY3_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy4(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY4_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy5(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY5_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy6(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY6_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy7(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY7_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy8(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY8_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy9(ST1633I_ctx_t *ctx, uint8_t *valid, uint16_t *x, uint16_t *y){
	return ST1633I_xy(ctx, XY9_Coordinate_H_REG, valid, x, y);
}
/**
 * @brief  Get ST1633I XY Touch Position
 * @param  ctx Component context
 * @param
 * @retval Component status
 */
int32_t ST1633I_xy_all(ST1633I_ctx_t *ctx, uint8_t *valid_arr, uint16_t *x_arr, uint16_t *y_arr){
	int32_t ret;
	ret = ST1633I_xy0(ctx, &valid_arr[0], &x_arr[0], &y_arr[0]);
	if (ret != 0) return ret;
	ret = ST1633I_xy1(ctx, &valid_arr[1], &x_arr[1], &y_arr[1]);
	if (ret != 0) return ret;
	ret = ST1633I_xy2(ctx, &valid_arr[2], &x_arr[2], &y_arr[2]);
	if (ret != 0) return ret;
	ret = ST1633I_xy3(ctx, &valid_arr[3], &x_arr[3], &y_arr[3]);
	if (ret != 0) return ret;
	ret = ST1633I_xy4(ctx, &valid_arr[4], &x_arr[4], &y_arr[4]);
	if (ret != 0) return ret;
	ret = ST1633I_xy5(ctx, &valid_arr[5], &x_arr[5], &y_arr[5]);
	if (ret != 0) return ret;
	ret = ST1633I_xy6(ctx, &valid_arr[6], &x_arr[6], &y_arr[6]);
	if (ret != 0) return ret;
	ret = ST1633I_xy7(ctx, &valid_arr[7], &x_arr[7], &y_arr[7]);
	if (ret != 0) return ret;
	ret = ST1633I_xy8(ctx, &valid_arr[8], &x_arr[8], &y_arr[8]);
	if (ret != 0) return ret;
	ret = ST1633I_xy9(ctx, &valid_arr[9], &x_arr[9], &y_arr[9]);
	return ret;
}







/**
 * @brief  Get ST1633I First X Event Flag
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P1_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p1_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P1_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P1_XH_EF_BIT_MASK;
		*value = *value >> ST1633I_P1_XH_EF_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I First X High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P1_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p1_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P1_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P1_XH_TP_BIT_MASK;
		*value = *value >> ST1633I_P1_XH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I First X Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P1_XL_REG register
 * @retval Component status
 */
int32_t ST1633I_p1_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P1_XL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I First Touch ID
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P1_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p1_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P1_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P1_YH_TID_BIT_MASK;
		*value = *value >> ST1633I_P1_YH_TID_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I First Y High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P1_YH_REG register
 * @retval Component status
 */
int32_t ST1633I_p1_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P1_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P1_YH_TP_BIT_MASK;
		*value = *value >> ST1633I_P1_YH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I First Y Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P1_YL_REG register
 * @retval Component status
 */
int32_t ST1633I_p1_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P1_YL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I First Touch pressure
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P1_WEIGHT_REG register
 * @retval Component status
 */
int32_t ST1633I_p1_weight(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P1_WEIGHT_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I First Touch area
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P1_MISC_REG register
 * @retval Component status
 */
int32_t ST1633I_p1_misc(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P1_MISC_REG, (uint8_t*) value, 1);
	if (ret == 0) {
		*value &= ST1633I_P1_MISC_BIT_MASK;
		*value = *value >> ST1633I_P1_MISC_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Second X Event Flag
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P2_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p2_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P2_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P2_XH_EF_BIT_MASK;
		*value = *value >> ST1633I_P2_XH_EF_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Second X High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P2_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p2_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P2_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P2_XH_TP_BIT_MASK;
		*value = *value >> ST1633I_P2_XH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Second X Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P2_XL_REG register
 * @retval Component status
 */
int32_t ST1633I_p2_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P2_XL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Second Touch ID
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P2_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p2_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P2_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P2_YH_TID_BIT_MASK;
		*value = *value >> ST1633I_P2_YH_TID_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Second Y High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P2_YH_REG register
 * @retval Component status
 */
int32_t ST1633I_p2_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P2_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P2_YH_TP_BIT_MASK;
		*value = *value >> ST1633I_P2_YH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Second Y Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P2_YL_REG register
 * @retval Component status
 */
int32_t ST1633I_p2_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P2_YL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Second Touch pressure
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P2_WEIGHT_REG register
 * @retval Component status
 */
int32_t ST1633I_p2_weight(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P2_WEIGHT_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Second Touch area
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P2_MISC_REG register
 * @retval Component status
 */
int32_t ST1633I_p2_misc(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P2_MISC_REG, (uint8_t*) value, 1);
	if (ret == 0) {
		*value &= ST1633I_P2_MISC_BIT_MASK;
		*value = *value >> ST1633I_P2_MISC_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Third X Event Flag
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P3_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p3_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P3_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P3_XH_EF_BIT_MASK;
		*value = *value >> ST1633I_P3_XH_EF_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Third X High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P3_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p3_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P3_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P3_XH_TP_BIT_MASK;
		*value = *value >> ST1633I_P3_XH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Third X Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P3_XL_REG register
 * @retval Component status
 */
int32_t ST1633I_p3_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P3_XL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Third Touch ID
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P3_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p3_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P3_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P3_YH_TID_BIT_MASK;
		*value = *value >> ST1633I_P3_YH_TID_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Third Y High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P3_YH_REG register
 * @retval Component status
 */
int32_t ST1633I_p3_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P3_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P3_YH_TP_BIT_MASK;
		*value = *value >> ST1633I_P3_YH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Third Y Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P3_YL_REG register
 * @retval Component status
 */
int32_t ST1633I_p3_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P3_YL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Third Touch pressure
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P3_WEIGHT_REG register
 * @retval Component status
 */
int32_t ST1633I_p3_weight(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P3_WEIGHT_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Third Touch area
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P3_MISC_REG register
 * @retval Component status
 */
int32_t ST1633I_p3_misc(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P3_MISC_REG, (uint8_t*) value, 1);
	if (ret == 0) {
		*value &= ST1633I_P3_MISC_BIT_MASK;
		*value = *value >> ST1633I_P3_MISC_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fourth X Event Flag
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P4_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p4_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P4_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P4_XH_EF_BIT_MASK;
		*value = *value >> ST1633I_P4_XH_EF_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fourth X High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P4_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p4_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P4_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P4_XH_TP_BIT_MASK;
		*value = *value >> ST1633I_P4_XH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fourth X Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P4_XL_REG register
 * @retval Component status
 */
int32_t ST1633I_p4_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P4_XL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Fourth Touch ID
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P4_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p4_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P4_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P4_YH_TID_BIT_MASK;
		*value = *value >> ST1633I_P4_YH_TID_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fourth Y High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P4_YH_REG register
 * @retval Component status
 */
int32_t ST1633I_p4_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P4_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P4_YH_TP_BIT_MASK;
		*value = *value >> ST1633I_P4_YH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fourth Y Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P4_YL_REG register
 * @retval Component status
 */
int32_t ST1633I_p4_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P4_YL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Fourth Touch pressure
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P4_WEIGHT_REG register
 * @retval Component status
 */
int32_t ST1633I_p4_weight(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P4_WEIGHT_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Fourth Touch area
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P4_MISC_REG register
 * @retval Component status
 */
int32_t ST1633I_p4_misc(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P4_MISC_REG, (uint8_t*) value, 1);
	if (ret == 0) {
		*value &= ST1633I_P4_MISC_BIT_MASK;
		*value = *value >> ST1633I_P4_MISC_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fifth X Event Flag
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P5_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p5_xh_ef(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P5_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P5_XH_EF_BIT_MASK;
		*value = *value >> ST1633I_P5_XH_EF_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fifth X High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P5_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p5_xh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P5_XH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P5_XH_TP_BIT_MASK;
		*value = *value >> ST1633I_P5_XH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fifth X Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P5_XL_REG register
 * @retval Component status
 */
int32_t ST1633I_p5_xl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P5_XL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Fifth Touch ID
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P5_XH_REG register
 * @retval Component status
 */
int32_t ST1633I_p5_yh_tid(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P5_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P5_YH_TID_BIT_MASK;
		*value = *value >> ST1633I_P5_YH_TID_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fifth Y High Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P5_YH_REG register
 * @retval Component status
 */
int32_t ST1633I_p5_yh_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P5_YH_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_P5_YH_TP_BIT_MASK;
		*value = *value >> ST1633I_P5_YH_TP_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Get ST1633I Fifth Y Low Touch Position
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P5_YL_REG register
 * @retval Component status
 */
int32_t ST1633I_p5_yl_tp(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P5_YL_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Fifth Touch pressure
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P5_WEIGHT_REG register
 * @retval Component status
 */
int32_t ST1633I_p5_weight(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_P5_WEIGHT_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Get ST1633I Fifth Touch area
 * @param  ctx Component context
 * @param  value pointer to the value of ST1633I_P5_MISC_REG register
 * @retval Component status
 */
int32_t ST1633I_p5_misc(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_P5_MISC_REG, (uint8_t*) value, 1);
	if (ret == 0) {
		*value &= ST1633I_P5_MISC_BIT_MASK;
		*value = *value >> ST1633I_P5_MISC_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Set ST1633I Threshold for touch detection
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_TH_GROUP_REG register
 * @retval Component status
 */
int32_t ST1633I_th_group(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_TH_GROUP_REG, &value, 1);
}

/**
 * @brief  Set ST1633I Filter function coefficient
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_TH_DIFF_REG register
 * @retval Component status
 */
int32_t ST1633I_th_diff(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_TH_DIFF_REG, &value, 1);
}

/**
 * @brief  Control the Switch between Active and Monitoring Mode
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_CTRL_REG register
 * @retval Component status
 */
int32_t ST1633I_ctrl(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_CTRL_REG, &value, 1);
}

/**
 * @brief  Set the time period of switching from Active mode to Monitor
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_TIMEENTERMONITOR_REG register
 * @retval Component status
 */
int32_t ST1633I_time_enter_monitor(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_TIMEENTERMONITOR_REG, &value, 1);
}

/**
 * @brief  Set rate in Active mode
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_PERIODACTIVE_REG register
 * @retval Component status
 */
int32_t ST1633I_period_active(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_PERIODACTIVE_REG, &value, 1);
}

/**
 * @brief  Set rate in Monitor mode
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_PERIODMONITOR_REG register
 * @retval Component status
 */
int32_t ST1633I_period_monitor(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_PERIODMONITOR_REG, &value, 1);
}

/**
 * @brief  Set the value of the minimum allowed angle while Rotating
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_RADIAN_VALUE_REG register
 * @retval Component status
 */
int32_t ST1633I_radian_value(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_RADIAN_VALUE_REG, &value, 1);
}

/**
 * @brief  Set Maximum offset while Moving Left and Moving Right gesture
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_OFFSET_LR_REG register
 * @retval Component status
 */
int32_t ST1633I_offset_left_right(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_OFFSET_LR_REG, &value, 1);
}

/**
 * @brief  Set Maximum offset while Moving Up and Moving Down gesture
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_OFFSET_UD_REG register
 * @retval Component status
 */
int32_t ST1633I_offset_up_down(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_OFFSET_UD_REG, &value, 1);
}

/**
 * @brief  Set Minimum distance while Moving Left and Moving Right gesture
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_DISTANCE_LR_REG register
 * @retval Component status
 */
int32_t ST1633I_disatnce_left_right(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_DISTANCE_LR_REG, &value, 1);
}

/**
 * @brief  Set Minimum distance while Moving Up and Moving Down gesture
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_DISTANCE_UD_REG register
 * @retval Component status
 */
int32_t ST1633I_distance_up_down(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_DISTANCE_UD_REG, &value, 1);
}

/**
 * @brief  Set Maximum distance while Zoom In and Zoom Out gesture
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_DISTANCE_ZOOM_REG register
 * @retval Component status
 */
int32_t ST1633I_distance_zoom(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_DISTANCE_ZOOM_REG, &value, 1);
}

/**
 * @brief  Read High 8-bit of LIB Version info
 * @param  ctx Component context
 * @param  value Pointer to ST1633I_LIB_VER_H_REG register value
 * @retval Component status
 */
int32_t ST1633I_lib_ver_high(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_LIB_VER_H_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Read Low 8-bit of LIB Version info
 * @param  ctx Component context
 * @param  value Pointer to ST1633I_LIB_VER_L_REG register value
 * @retval Component status
 */
int32_t ST1633I_lib_ver_low(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_LIB_VER_L_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Read status of cipher register
 * @param  ctx Component context
 * @param  value Pointer to ST1633I_CIPHER_REG register value
 * @retval Component status
 */
int32_t ST1633I_cipher(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_CIPHER_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Select Interrupt (polling or trigger) mode
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_GMODE_REG register
 * @retval Component status
 */
int32_t ST1633I_g_mode(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_GMODE_REG, &value, 1);
}

/**
 * @brief  Select Current power mode
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_PWR_MODE_REG register
 * @retval Component status
 */
int32_t ST1633I_pwr_mode(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_PWR_MODE_REG, &value, 1);
}

/**
 * @brief  Read the Firmware Version
 * @param  ctx Component context
 * @param  value Pointer to ST1633I_FIRMID_REG register value
 * @retval Component status
 */
int32_t ST1633I_firm_id(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_FIRMID_REG, (uint8_t*) value, 1);
}

/**
 * @brief  Read the FocalTech's Panel ID
 * @param  ctx Component context
 * @param  value Pointer to ST1633I_CHIP_ID_REG register value
 * @retval Component status
 */
int32_t ST1633I_chip_id(ST1633I_ctx_t *ctx, uint8_t *value) {
	int32_t ret;

	ret = ST1633I_read_reg(ctx, ST1633I_CHIP_ID_REG, (uint8_t*) value, 1);

	if (ret == 0) {
		*value &= ST1633I_CHIP_ID_BIT_MASK;
		*value = *value >> ST1633I_CHIP_ID_BIT_POSITION;
	}

	return ret;
}

/**
 * @brief  Read the Release code version
 * @param  ctx Component context
 * @param  value Pointer to ST1633I_RELEASE_CODE_ID_REG register value
 * @retval Component status
 */
int32_t ST1633I_release_code_id(ST1633I_ctx_t *ctx, uint8_t *value) {
	return ST1633I_read_reg(ctx, ST1633I_RELEASE_CODE_ID_REG, (uint8_t*) value,
			1);
}

/**
 * @brief  Select Current Operating mode
 * @param  ctx Component context
 * @param  value Value to write to ST1633I_STATE_REG register
 * @retval Component status
 */
int32_t ST1633I_state(ST1633I_ctx_t *ctx, uint8_t value) {
	return ST1633I_write_reg(ctx, ST1633I_STATE_REG, &value, 1);
}

/*****************************END OF FILE****/
