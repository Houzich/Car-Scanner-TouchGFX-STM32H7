#ifndef CC_WIFICONNECTINGCONTAINER_HPP
#define CC_WIFICONNECTINGCONTAINER_HPP

#include <gui_generated/containers/CC_WiFiConnectingContainerBase.hpp>

class CC_WiFiConnectingContainer : public CC_WiFiConnectingContainerBase
{
public:
    CC_WiFiConnectingContainer();
    virtual ~CC_WiFiConnectingContainer() {}

    virtual void initialize();

    void tickEvent();
    void resetContainer();
    void connectionUnsuccesfull();
protected:

    int tickCnt;
    int animationCnt;
    bool connecting;

};

#endif // CC_WIFICONNECTINGCONTAINER_HPP
