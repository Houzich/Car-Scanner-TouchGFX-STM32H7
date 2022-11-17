
#include <gui/model/ModelListener.hpp>
#include "gui/model/WiFi.hpp"
#include <gui/common/structs.hpp>

#include <stdio.h>
#include <string.h>




#if (!(defined SIMULATOR))&&(defined WIN32)

#elif (!(defined SIMULATOR))
#include "esp32_wifi.h"
//#include "../../../WIFI/Network_Library/Includes/net_connect.h"
//#include "../../../WIFI/Network_Library/Includes/net_internals.h"
#endif //SIMULATOR



const char* encryption_status[] = { "Open", "WEP", "WPA", "WPA2", "WPA-WPA2", "WPA2-TKIP", "Unknown" };

#ifndef SIMULATOR
extern ESP32_WIFI_APs_t ESP32APs;
#endif //SIMULATOR

uint8_t password_ascii[64];
uint8_t ssid_ascii[32];
uint8_t encryption_ascii[30];


WiFiClass::WiFiClass() : modelListener(0), numberOfWifiAccesPoints(0), getWifiData(false), connectingToWifi(false), isWifiConected(false)
{
    /* GUI Queue */
    //osMessageQDef(GUI_Queue, 10, uint16_t);
    //GUIEvent = osMessageCreate(osMessageQ(GUI_Queue), NULL);

}

static inline int rssi_to_strength(int16_t RSSI)
{
    if (RSSI >= -70)
    {
        return 4;
    }
    if (RSSI >= -80)
    {
        return 3;
    }
    if (RSSI >= -90)
    {
        return 2;
    }
    if (RSSI >= -100)
    {
        return 1;
    }
    return 0;
}

/**
  * @brief  Convert wifi security enum value to string
  * @param  sec is an unsigned integer
  * @retval a constant string , for instance "Open" or "WPA2-AES"
  */
static const char *esp32_wifi_security_to_string(uint32_t sec)
{
    const char* s;
#ifndef SIMULATOR
  if (sec == ESP32_WIFI_SEC_OPEN)
  {
    s =  "Open";
  }
  else if (sec == ESP32_WIFI_SEC_WEP)
  {
    s = "WEP-shared";
  }
  else if (sec == ESP32_WIFI_SEC_WPA_PSK)
  {
    s = "WPA-PSK";
  }
  else if (sec == ESP32_WIFI_SEC_WPA2_PSK)
  {
    s = "WPA2-PSK";
  }
  else if (sec == ESP32_WIFI_SEC_WPA_WPA2_PSK)
  {
    s = "WPA-WPA2-PSK";
  }
  else if (sec == ESP32_WIFI_SEC_WPA2_ENTERPRISE)
  {
    s = "WPA2-Enterprise";
  }
  else if (sec == ESP32_WIFI_SEC_WPA3_PSK)
  {
    s = "WPA3-PSK";
  }
  else if (sec == ESP32_WIFI_SEC_WPA2_WPA3_PSK)
  {
    s = "WPA2-WPA3-PSK";
  }
  else if (sec == ESP32_WIFI_SEC_WAPI_PSK)
  {
    s = "WAPI-PSK";
  }
  else if (sec == ESP32_WIFI_SEC_UNKNOWN)
  {
    s = "unknown";
  }
  else
  {
    s = "unknown";
  }
#else
    s = "unknown";
#endif //SIMULATOR
  return s;
}

void WiFiClass::updateWifi()
{
#ifndef SIMULATOR
    for (int cnt = 0; (cnt < ESP32APs.nbr)&&(cnt < ESP32_WIFI_MAX_DETECTED_AP); cnt++)
    {
        wifiAccessPoints[cnt].id = cnt;
        touchgfx::Unicode::snprintf(wifiAccessPoints[cnt].ssid, 32, (const char*)ESP32APs.AP[cnt].SSID);
        touchgfx::Unicode::snprintf(wifiAccessPoints[cnt].encryption, 30, esp32_wifi_security_to_string(ESP32APs.AP[cnt].Security));
        wifiAccessPoints[cnt].signalStrength = rssi_to_strength(ESP32APs.AP[cnt].RSSI);
        //if ((ESP32APs.AP[cnt].Security != NET_WIFI_SM_OPEN) && (ESP32APs.AP[cnt].Security != NET_WIFI_SM_UNKNOWN))
        //{
            wifiAccessPoints[cnt].encrypted = true;
        //}

        numberOfWifiAccesPoints = cnt + 1;
    }

    modelListener->updateWiFiInformaion(wifiAccessPoints, numberOfWifiAccesPoints);
#endif //SIMULATOR
}

void WiFiClass::getWifiAccessPoints(wifiData& ap, int id)
{
    memcpy(&ap, &wifiAccessPoints[id], sizeof(ap));
}

void WiFiClass::setWifiPassword(touchgfx::Unicode::UnicodeChar* password, int id)
{

    touchgfx::Unicode::snprintf(currentConnectedWifi.password, 64, "%s", password);
    touchgfx::Unicode::snprintf(currentConnectedWifi.wifi.ssid, 32, "%s", wifiAccessPoints[id].ssid);
    touchgfx::Unicode::snprintf(currentConnectedWifi.wifi.encryption, 30, "%s", wifiAccessPoints[id].encryption);
    currentConnectedWifi.wifi.signalStrength = wifiAccessPoints[id].signalStrength;

    touchgfx::Unicode::toUTF8(password, password_ascii, 64);
    touchgfx::Unicode::toUTF8(wifiAccessPoints[id].ssid, ssid_ascii, 32);
    touchgfx::Unicode::toUTF8(wifiAccessPoints[id].encryption, encryption_ascii, 30);

    connectingToWifi = true;

}

wifiData WiFiClass::getCurrentConnectedWiFiData()
{
    return this->currentConnectedWifi.wifi;
}

void WiFiClass::setIsWifiConected(bool isWifiConected)
{
    this->isWifiConected = isWifiConected;
}

bool WiFiClass::getIsWifiConected()
{
    return this->isWifiConected;
}

void WiFiClass::setConnectingToWifi(bool connectingToWifi)
{
    this->connectingToWifi = connectingToWifi;
}
bool WiFiClass::getConnectingToWifi()
{
    return this->connectingToWifi;
}

void WiFiClass::setGetWifiData(bool getWifiData)
{
    this->getWifiData = getWifiData;
}

bool WiFiClass::getGetWifiData()
{
    return getWifiData;
}

void WiFiClass::updateWifiSignalStrength(void)
{
    if (getIsWifiConected())
    {
        for (int i = 0; i < numberOfWifiAccesPoints; i++)
        {
            if (touchgfx::Unicode::strncmp(currentConnectedWifi.wifi.ssid, wifiAccessPoints[i].ssid, 32) == 0)
            {
                currentConnectedWifi.wifi.signalStrength = wifiAccessPoints[i].signalStrength;
                modelListener->updateWifiIcon(currentConnectedWifi.wifi.signalStrength);
                break;
            }
        }
    }
}
