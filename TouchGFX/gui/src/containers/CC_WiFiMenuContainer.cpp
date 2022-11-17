#include <gui/containers/CC_WiFiMenuContainer.hpp>

#include<gui/common/structs.hpp>

CC_WiFiMenuContainer::CC_WiFiMenuContainer() :
    wifiListElementClickedCallback(this, &CC_WiFiMenuContainer::wifiListElementClicked)
{

}

void CC_WiFiMenuContainer::initialize()
{
    CC_WiFiMenuContainerBase::initialize();
    listLayout_wifiList.setWidth(wifiListElements[0].getWidth());
    scrollableContainer_WiFiList.setScrollbarPadding(4);
    scrollableContainer_WiFiList.setScrollbarsAlpha(100);
    scrollableContainer_WiFiList.setScrollbarWidth(5);
}

void CC_WiFiMenuContainer::updateWifiList(struct  wifiData* data, uint16_t numberOfPoints)
{
    listLayout_wifiList.removeAll();

    for (int cnt = 0; cnt < numberOfPoints; cnt++)
    {
        wifiListElements[cnt].setWifiSSID(data[cnt].ssid);
        wifiListElements[cnt].setEncryption(data[cnt].encryption);
        wifiListElements[cnt].setSignalStrength(data[cnt].signalStrength);
        wifiListElements[cnt].setId(cnt);
        wifiListElements[cnt].setIsConnected(data[cnt].connected);
        listLayout_wifiList.add(wifiListElements[cnt]);

        wifiListElements[cnt].setAction(wifiListElementClickedCallback);
    }

    scrollableContainer_WiFiList.invalidate();
}

void CC_WiFiMenuContainer::wifiListElementClicked(CC_WiFiInfoContainer& element)
{
    if (viewCallback->isValid())
    {
        viewCallback->execute(element.getId());
    }
}

void CC_WiFiMenuContainer::setAction(GenericCallback< int >& callback)
{
    viewCallback = &callback;
}
