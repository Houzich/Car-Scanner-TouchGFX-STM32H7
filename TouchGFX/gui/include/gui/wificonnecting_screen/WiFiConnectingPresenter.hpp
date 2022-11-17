#ifndef WIFICONNECTINGPRESENTER_HPP
#define WIFICONNECTINGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class WiFiConnectingView;

class WiFiConnectingPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    WiFiConnectingPresenter(WiFiConnectingView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~WiFiConnectingPresenter() {};

    void setInWiFiMenu(bool inWiFiMenu);
    void setGetWifiData(bool getWifiData);
    void updateWiFiInformaion(struct wifiData data[], int numberOfPoints);
    void setSelectedWifi(Unicode::UnicodeChar* password, int id);
    void updateWifiIcon(int strength);
    void getWifiAccessPoints(wifiData& ap, int id);
    void wifiConnection(bool succesful);
    bool getIsWiFiConnected();
    wifiData getCurrentConnectedWiFiData();
private:
    WiFiConnectingPresenter();

    WiFiConnectingView& view;
};

#endif // WIFICONNECTINGPRESENTER_HPP
