#ifndef CC_WIFIMENUCONTAINER_HPP
#define CC_WIFIMENUCONTAINER_HPP

#include <gui_generated/containers/CC_WiFiMenuContainerBase.hpp>
#include <gui/containers/CC_WiFiInfoContainer.hpp>

class CC_WiFiMenuContainer : public CC_WiFiMenuContainerBase
{
public:
    CC_WiFiMenuContainer();
    virtual ~CC_WiFiMenuContainer() {}

    virtual void initialize();

    void updateWifiList(struct  wifiData* data, uint16_t numberOfPoints);

    void setAction(GenericCallback<int>& callback);

    void wifiListElementClicked(CC_WiFiInfoContainer& element);

protected:
    GenericCallback<int>* viewCallback;

    static const int numberOfListElements = 40;
    CC_WiFiInfoContainer wifiListElements[numberOfListElements];

    // Callback that is assigned to each list element
    Callback<CC_WiFiMenuContainer, CC_WiFiInfoContainer&> wifiListElementClickedCallback;


};

#endif // CC_WIFIMENUCONTAINER_HPP
