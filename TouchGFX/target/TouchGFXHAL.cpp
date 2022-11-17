/**
  ******************************************************************************
  * File Name          : TouchGFXHAL.cpp
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
#include <TouchGFXHAL.hpp>

/* USER CODE BEGIN TouchGFXHAL.cpp */
#include "../../../Data/CarModels.hpp"
#include "../../../eMMC/mmc_diskio.h"
#include <fonts/ApplicationFontProvider.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>
#include <string.h>
using namespace touchgfx;
using namespace Data;


// Define an array for the bitmap cache
__attribute__((section(".BmpCacheSection"))) __attribute__ ((aligned (32)))
uint16_t cache[8*1024*1024]; //14 MB cache

////read the file into this array in SDRAM
//__attribute__((section(".FntCacheSection"))) __attribute__ ((aligned (32)))
//uint8_t fontCache[2*1024*1024]; //2 MB cache
//
////binary font object using the data
////__attribute__((section(".FntCacheSection"))) __attribute__ ((aligned (32)))
//touchgfx::BinaryFont bf_default;
////__attribute__((section(".FntCacheSection"))) __attribute__ ((aligned (32)))
//touchgfx::BinaryFont bf_large;
////__attribute__((section(".FntCacheSection"))) __attribute__ ((aligned (32)))
//touchgfx::BinaryFont bf_small;
////__attribute__((section(".FntCacheSection"))) __attribute__ ((aligned (32)))
//touchgfx::BinaryFont bf_keyboard;
////__attribute__((section(".FntCacheSection"))) __attribute__ ((aligned (32)))
//touchgfx::BinaryFont bf_display;

void TouchGFXHAL::initialize()
{
    // Calling parent implementation of initialize().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::initialize() must be called to initialize the framework.

    TouchGFXGeneratedHAL::initialize();
    //pFrameError = new CC_FrameError[DIAGNOSTICS_NUM_MAX];
    touchgfx::Bitmap::removeCache(); //Clear any previous cache
    touchgfx::Bitmap::setCache(cache, sizeof(cache));
    touchgfx::Bitmap::cacheAll();


//    uint32_t bytesread = 0;
//    uint32_t numBytes = sizeof(fontCache);
//    uint32_t offset = 0;
//    bytesread = MMC_Read_From_File(&fontCache[offset], "Font_calibri_20_4bpp.bin", numBytes);
//    if(bytesread == 0) return;
//    //initialize BinaryFont object in bf using placement new
//    new (&bf_default) BinaryFont((const struct touchgfx::BinaryFontData*)&fontCache[offset]);
//	//replace application font 'DEFAULT' with the binary font
//	TypedTextDatabase::setFont(Typography::DEFAULT, &bf_default); //
//
//	numBytes -= bytesread;
//	offset += bytesread;
//    bytesread = MMC_Read_From_File(&fontCache[offset], "Font_calibri_40_4bpp.bin", numBytes);
//    if(bytesread == 0) return;
//    new (&bf_large) BinaryFont((const struct touchgfx::BinaryFontData*)&fontCache[offset]);
//	TypedTextDatabase::setFont(Typography::LARGE, &bf_large); //
//
//	numBytes -= bytesread;
//	offset += bytesread;
//    bytesread = MMC_Read_From_File(&fontCache[offset], "Font_calibri_10_4bpp.bin", numBytes);
//    if(bytesread == 0) return;
//    new (&bf_small) BinaryFont((const struct touchgfx::BinaryFontData*)&fontCache[offset]);
//	TypedTextDatabase::setFont(Typography::SMALL, &bf_small); //
//
//	numBytes -= bytesread;
//	offset += bytesread;
//    bytesread = MMC_Read_From_File(&fontCache[offset], "Font_calibri_34_4bpp.bin", numBytes);
//    if(bytesread == 0) return;
//    new (&bf_keyboard) BinaryFont((const struct touchgfx::BinaryFontData*)&fontCache[offset]);
//	TypedTextDatabase::setFont(Typography::KEYBOARD, &bf_keyboard); //
//
//	numBytes -= bytesread;
//	offset += bytesread;
//    bytesread = MMC_Read_From_File(&fontCache[offset], "Font_calibri_56_4bpp.bin", numBytes);
//    if(bytesread == 0) return;
//    new (&bf_display) BinaryFont((const struct touchgfx::BinaryFontData*)&fontCache[offset]);
//	TypedTextDatabase::setFont(Typography::DISPLAY, &bf_display); //
}


// Font_calibri_20_4bpp
// Font_calibri_40_4bpp
// Font_calibri_10_4bpp
// Font_calibri_34_4bpp
// Font_calibri_56_4bpp


/**
 * Gets the frame buffer address used by the TFT controller.
 *
 * @return The address of the frame buffer currently being displayed on the TFT.
 */
uint16_t* TouchGFXHAL::getTFTFrameBuffer() const
{
    // Calling parent implementation of getTFTFrameBuffer().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    return TouchGFXGeneratedHAL::getTFTFrameBuffer();
}

/**
 * Sets the frame buffer address used by the TFT controller.
 *
 * @param [in] address New frame buffer address.
 */
void TouchGFXHAL::setTFTFrameBuffer(uint16_t* address)
{
    // Calling parent implementation of setTFTFrameBuffer(uint16_t* address).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::setTFTFrameBuffer(address);
}

/**
 * This function is called whenever the framework has performed a partial draw.
 *
 * @param rect The area of the screen that has been drawn, expressed in absolute coordinates.
 *
 * @see flushFrameBuffer().
 */
void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    // Calling parent implementation of flushFrameBuffer(const touchgfx::Rect& rect).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::flushFrameBuffer(const touchgfx::Rect& rect) must
    // be called to notify the touchgfx framework that flush has been performed.
    // To calculate he start adress of rect,
    // use advanceFrameBufferToRect(uint8_t* fbPtr, const touchgfx::Rect& rect)
    // defined in TouchGFXGeneratedHAL.cpp

    TouchGFXGeneratedHAL::flushFrameBuffer(rect);
}

bool TouchGFXHAL::blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes)
{
    //return TouchGFXGeneratedHAL::blockCopy(dest, src, numBytes);

	  // If requested data is located within the memory block we have assigned for ExtFlashSection,
	  // provide an implementation for data copying.
	  if (src >= (const void*)0x40000000 && src < (const void*)(0x40000000 + 0x80000000))
	  {
		  FSIZE_t dataOffset = (FSIZE_t )src  - 0x40000000;
	    // In this example we assume graphics is placed in SD card, and that we have an appropriate function
	    // for copying data from there.
		//memset((void *)dest, 255, numBytes);
	    //printf("blockCopy -> dest: 0x%08X, dataOffset: 0x%08X, numBytes: %lu\n",(unsigned int)dest,(unsigned int)dataOffset,numBytes);
	    MMC_Read_From_Image((void *)dest, dataOffset, numBytes);
	    return true;
	  }
	  else
	  {
	    // For all other addresses, just use the default implementation.
	    // This is important, as blockCopy is also used for other things in the core framework.
	    return HAL::blockCopy(dest, src, numBytes);
	  }

}

/**
 * Configures the interrupts relevant for TouchGFX. This primarily entails setting
 * the interrupt priorities for the DMA and LCD interrupts.
 */
void TouchGFXHAL::configureInterrupts()
{
    // Calling parent implementation of configureInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::configureInterrupts();
}

/**
 * Used for enabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::enableInterrupts()
{
    // Calling parent implementation of enableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::enableInterrupts();
}

/**
 * Used for disabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::disableInterrupts()
{
    // Calling parent implementation of disableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::disableInterrupts();
}

/**
 * Configure the LCD controller to fire interrupts at VSYNC. Called automatically
 * once TouchGFX initialization has completed.
 */
void TouchGFXHAL::enableLCDControllerInterrupt()
{
    // Calling parent implementation of enableLCDControllerInterrupt().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    TouchGFXGeneratedHAL::enableLCDControllerInterrupt();
}

/* USER CODE END TouchGFXHAL.cpp */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
