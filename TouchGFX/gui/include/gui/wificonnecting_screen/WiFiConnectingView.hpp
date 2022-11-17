#ifndef WIFICONNECTINGVIEW_HPP
#define WIFICONNECTINGVIEW_HPP

#include <gui_generated/wificonnecting_screen/WiFiConnectingViewBase.hpp>
#include <gui/wificonnecting_screen/WiFiConnectingPresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>

class WiFiConnectingView : public WiFiConnectingViewBase
{
public:
    WiFiConnectingView();
    virtual ~WiFiConnectingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateWiFiInformaion(struct  wifiData data[], uint16_t numberOfPoints);
    void updateWifiIcon(int8_t strength);
    void wifiConnection(bool succesful);

    virtual void handleClickEvent(const ClickEvent& evt);
    virtual void handleTickEvent();

protected:
    void closeWiFiConnectingMenu();
#ifndef SIMULATOR
    CustomKeyboard wifiKeyboard;
#endif //SIMULATOR
    void wifiAccessPointSelected(int id);
    Callback<WiFiConnectingView, int> wifiAccessPointSelectedCallback;

    void keyboardDonePressed(Unicode::UnicodeChar buffer[]);
    Callback<WiFiConnectingView, Unicode::UnicodeChar[]> keyboardDonePressedCallback;

    int centerId;
    int selectedWiFiID;

};

#endif // WIFICONNECTINGVIEW_HPP
