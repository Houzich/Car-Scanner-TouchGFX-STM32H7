#ifndef WIFICLASS_HPP
#define WIFICLASS_HPP

//#include <gui/model/Model.hpp>
//#include <gui/common/FrontendApplication.hpp>

#include <gui/common/structs.hpp>
#ifndef SIMULATOR
//#include "net_connect.h"
//#include "net_internals.h"
#endif //SIMULATOR

#define STATE_TRANSITION_TIMEOUT                10000
#define SSID1                                   "TUN_MCD_MW_01"
#define PASSWORD                                "DA531GKL+43RV"
#define PORT_NUMBER                             80

#define RETRY_REQUEST_NUMBER                    10
#define MAX_LISTED_AP                           10

class ModelListener;

class WiFiClass
{
public:
    WiFiClass();
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }


    void updateWifi();
    void getWifiAccessPoints(wifiData& ap, int id);
    void setWifiPassword(touchgfx::Unicode::UnicodeChar* password, int id);
    void wifiConnection(bool succesful) {}
    void setIsWifiConected(bool isWifiConected);
    bool getIsWifiConected();
    void setGetWifiData(bool getWifiData);
    bool getGetWifiData();
    void setConnectingToWifi(bool connectingToWifi);
    bool getConnectingToWifi();
    void updateWifiSignalStrength(void);
    wifiData getCurrentConnectedWiFiData();
protected:
    ModelListener* modelListener;

    struct wifiData wifiAccessPoints[20];
    int numberOfWifiAccesPoints;
    bool getWifiData;
    selectedWifi currentConnectedWifi;

    bool connectingToWifi;
    bool isWifiConected;

};


#ifndef SIMULATOR
//extern net_if_handle_t netif;
//extern net_event_handler_t net_handler;
//extern net_if_driver_init_func es_wifi_driver_ptr;
//extern net_wifi_scan_results_t APs[MAX_LISTED_AP];
#endif //SIMULATOR

extern uint8_t password_ascii[64];
extern uint8_t ssid_ascii[32];
extern uint8_t encryption_ascii[30];

#endif // WIFICLASS_HPP
