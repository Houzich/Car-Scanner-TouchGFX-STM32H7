#ifndef CC_WIFIINFOCONTAINER_HPP
#define CC_WIFIINFOCONTAINER_HPP

#include <gui_generated/containers/CC_WiFiInfoContainerBase.hpp>

class CC_WiFiInfoContainer : public CC_WiFiInfoContainerBase
{
public:
    CC_WiFiInfoContainer();
    virtual ~CC_WiFiInfoContainer() {}

    virtual void initialize();
    void setWifiSSID(touchgfx::Unicode::UnicodeChar* name);
    void setEncryption(const touchgfx::Unicode::UnicodeChar* encryption);
    void setSignalStrength(uint16_t strength);

    virtual void elementSelected();
    void setAction(GenericCallback< CC_WiFiInfoContainer& >& callback);

    void setId(int newId);
    int getId();
    void setIsConnected(bool conn);
    bool getIsConnected();

protected:
    GenericCallback< CC_WiFiInfoContainer& >* viewCallback;
    int id;
    bool isConnected;
};

#endif // CC_WIFIINFOCONTAINER_HPP
