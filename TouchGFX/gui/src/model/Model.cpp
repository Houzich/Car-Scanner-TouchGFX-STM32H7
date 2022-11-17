#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/model/WiFi.hpp>

#include <gui/common/enums.hpp>
#include <gui/common/structs.hpp>

#include <stdio.h>
#include <string.h>

#ifdef SIMULATOR
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_shape.h>
#include <SDL2/SDL_syswm.h>
#else
#include "BSP.h"
#include "cmsis_os.h"
#endif //SIMULATOR


#include "../App/App.hpp"
#include <touchgfx/Utils.hpp>

#include "../../../Data/CarModels.hpp"
using namespace Data;

uint32_t prev_request = 0;
WiFiClass w;

uint32_t GetTicks() {
#if defined(SIMULATOR)
    return SDL_GetTicks();
#else
    return osKernelSysTick();
#endif
}


#ifdef SIMULATOR
QueueMessageClass< osEvent, 20 > GUIEvent;
#else
QueueMessageClass GUIEvent;
#endif //SIMULATOR



Model::Model() : modelListener(0), inWiFiMenu(false)
{
    wifi = &w;
#ifndef SIMULATOR
    /* GUI Queue */
    osMessageQDef(GUI_QueueIn, 20, uint16_t);
    GUIEvent.queue_in = osMessageCreate (osMessageQ(GUI_QueueIn), NULL);
    osMessageQDef(GUI_QueueOut, 20, uint16_t);
    GUIEvent.queue_out = osMessageCreate (osMessageQ(GUI_QueueOut), NULL);
#endif //!(SIMULATOR)
    lastBrightnessValue = DisplaySettings.getBrightnessPercentage();
}


//SDL_Delay
void Model::tick()
{
    osEvent event;
    osStatus status;

    event = GUIEvent.popMessageIn(0);

    if (event.status == osEventMessage)
    {
        /*Update WIFI Done*/
        switch (event.value.v)
        {
        case UPDATE_WIFI_AP_DONE:
            prev_request = GetTicks();
            wifi->updateWifi();
            wifi->updateWifiSignalStrength();
            break;

            /*Connection to WIFI Error*/
        case CONNECTING_TO_WIFI_ERROR:
            modelListener->wifiConnection(false);
            break;

            /*Connection to WIFI OK*/
        case CONNECTING_TO_WIFI_OK:
            wifi->setIsWifiConected(true);
            modelListener->wifiConnection(true);
            break;

        }
    }

    if (wifi->getGetWifiData())
    {
        //    if(!wifiIsBusy)
        {
            status = AppMessages.pushMessageIn(UPDATE_WIFI_AP, 0);
        }
        wifi->setGetWifiData(false);
    }

    if (inWiFiMenu)
    {
        //uint32_t curr_ticks = GetTicks();
        //touchgfx_printf("curr_ticks: %ul\n", curr_ticks);
        if ((prev_request != 0) && (GetTicks() - prev_request >= 10000) && !wifi->getIsWifiConected())
        {
            status = AppMessages.pushMessageIn(UPDATE_WIFI_AP, 0);
            prev_request = GetTicks();
        }
    }

    if (wifi->getConnectingToWifi())
    {
    	status = AppMessages.pushMessageIn(CONNECTING_TO_WIFI , 0);
    	wifi->setConnectingToWifi(false);
    }
}

void Model::setInWiFiMenu(bool inWiFiMenu)
{
    this->inWiFiMenu = inWiFiMenu;
}


int Model::getBrightnessValue()
{
	return DisplaySettings.getBrightnessPercentage();
}

void Model::setBrightnessValue(int value)
{
  if (value != lastBrightnessValue)
  {
    lastBrightnessValue = value;
    if(lastBrightnessValue < 1)
    {
      lastBrightnessValue = 1;
    }
    DisplaySettings.setBrightnessPercentage(value);
#ifndef SIMULATOR
    BSP_SetBrightness(lastBrightnessValue);
#endif
    //touchgfx_printf("New brightness: %d\r\n", lastBrightnessValue);
  }
}

void Model::setAndSaveBrightnessValue(int value)
{
  if (value != lastBrightnessValue)
  {
	setBrightnessValue(value);
    AppMessages.pushMessageIn(SET_AND_SAVE_BRIGHTNESS_VALUE, 0);
    //touchgfx_printf("Set And Save New brightness: %d\r\n", lastBrightnessValue);
  }
}



