#include <gui/containers/CC_WiFiInfoContainer.hpp>
#include "BitmapDatabase.hpp"
#include "../../../Data/CarModels.hpp"
using namespace Data;

CC_WiFiInfoContainer::CC_WiFiInfoContainer()
{

}

void CC_WiFiInfoContainer::initialize()
{
    CC_WiFiInfoContainerBase::initialize();
}

void CC_WiFiInfoContainer::setWifiSSID(touchgfx::Unicode::UnicodeChar* name)
{
    Unicode::strncpy(textAreaWiFiSSIDBuffer, name, TEXTAREAWIFISSID_SIZE);
    textAreaWiFiSSID.invalidate();
}

void CC_WiFiInfoContainer::setEncryption(const touchgfx::Unicode::UnicodeChar* encryptionType)
{
    Unicode::strncpy(textAreaEncryptionBuffer, encryptionType, TEXTAREAENCRYPTION_SIZE);
    textAreaEncryption.invalidate();
}

void CC_WiFiInfoContainer::setSignalStrength(uint16_t strength)
{
    switch (strength)
    {
    case WIFI_STRENGTH::MINIMAL:
        imageSignalStrengthIcon.setBitmap(Bitmap(BITMAP_WIFI_DOT_SETTINGS_ID));
        break;

    case WIFI_STRENGTH::LOW:
        imageSignalStrengthIcon.setBitmap(Bitmap(BITMAP_WIFI_LOW_SETTINGS_ID));
        break;

    case WIFI_STRENGTH::MEDIUM:
        imageSignalStrengthIcon.setBitmap(Bitmap(BITMAP_WIFI_MID_SETTINGS_ID));
        break;

    case WIFI_STRENGTH::HIGH:
        imageSignalStrengthIcon.setBitmap(Bitmap(BITMAP_WIFI_FULL_SETTINGS_ID));
        break;
    }
    imageSignalStrengthIcon.invalidate();
}

void CC_WiFiInfoContainer::elementSelected()
{
    // Inform the view of the event
    if (viewCallback->isValid())
    {
        viewCallback->execute(*this);
    }
}

void CC_WiFiInfoContainer::setAction(GenericCallback< CC_WiFiInfoContainer& >& callback)
{
    viewCallback = &callback;
}

void CC_WiFiInfoContainer::setId(int newId)
{
    id = newId;
}

int CC_WiFiInfoContainer::getId()
{
    return id;
}

void CC_WiFiInfoContainer::setIsConnected(bool conn)
{
	isConnected = conn;
	if(conn){
		box_Background.setAlpha(50);
		box_Background.invalidate();
	}
    textAreaConnected.setVisible(conn);
    textAreaConnected.invalidate();

}
bool CC_WiFiInfoContainer::getIsConnected()
{
    return isConnected;
}
