#include <gui/wificonnecting_screen/WiFiConnectingView.hpp>
#include <gui/wificonnecting_screen/WiFiConnectingPresenter.hpp>

WiFiConnectingPresenter::WiFiConnectingPresenter(WiFiConnectingView& v)
    : view(v)
{

}

void WiFiConnectingPresenter::activate()
{

}

void WiFiConnectingPresenter::deactivate()
{

}

void WiFiConnectingPresenter::setInWiFiMenu(bool inWiFiMenu)
{
    model->setInWiFiMenu(inWiFiMenu);
}

void WiFiConnectingPresenter::setGetWifiData(bool getWifiData)
{
    model->wifi->setGetWifiData(getWifiData);
}

void WiFiConnectingPresenter::updateWiFiInformaion(struct wifiData data[], int numberOfPoints)
{
    view.updateWiFiInformaion(data, numberOfPoints);
}

void WiFiConnectingPresenter::setSelectedWifi(Unicode::UnicodeChar* password, int id)
{
    model->wifi->setWifiPassword(password, id);
}


void WiFiConnectingPresenter::updateWifiIcon(int strength)
{
    view.updateWifiIcon(strength);
}

void WiFiConnectingPresenter::getWifiAccessPoints(wifiData& ap, int id)
{
    model->wifi->getWifiAccessPoints(ap, id);
}

void WiFiConnectingPresenter::wifiConnection(bool succesful)
{
    view.wifiConnection(succesful);
}

bool WiFiConnectingPresenter::getIsWiFiConnected()
{
	return model->wifi->getIsWifiConected();
}

wifiData WiFiConnectingPresenter::getCurrentConnectedWiFiData()
{
	return model->wifi->getCurrentConnectedWiFiData();
}




