#ifndef CC_WIFILISTENNIGCONTAINER_HPP
#define CC_WIFILISTENNIGCONTAINER_HPP

#include <gui_generated/containers/CC_WiFiListennigContainerBase.hpp>

class CC_WiFiListennigContainer : public CC_WiFiListennigContainerBase
{
public:
    CC_WiFiListennigContainer();
    virtual ~CC_WiFiListennigContainer() {}

    virtual void initialize();

    void tickEvent();
    void listenningStart();
    void listenningStop();
protected:
    int tickCnt;
    int animationCnt;
    bool listenning;
};

#endif // CC_WIFILISTENNIGCONTAINER_HPP
