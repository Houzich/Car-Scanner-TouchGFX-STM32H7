#include <gui/containers/CC_WiFiListennigContainer.hpp>
#include "BitmapDatabase.hpp"

CC_WiFiListennigContainer::CC_WiFiListennigContainer()
{

}

void CC_WiFiListennigContainer::initialize()
{
    CC_WiFiListennigContainerBase::initialize();
}

void CC_WiFiListennigContainer::listenningStart()
{
    tickCnt = 0;
    animationCnt = 0;
    listenning = true;

    image_Connecting.setBitmap(Bitmap(BITMAP_WIFI_LEVEL_1_ID));
    Unicode::snprintf(textArea_ConnectingBuffer, TEXTAREA_CONNECTING_SIZE, ".");

    image_Connecting.invalidate();
    textArea_Connecting.invalidate();
	//this->setVisible(true);
	//this->invalidate();
}
void CC_WiFiListennigContainer::listenningStop()
{
	listenning = false;
	//this->setVisible(false);
	//this->invalidate();
}

void CC_WiFiListennigContainer::tickEvent()
{
    if (tickCnt == 30 && listenning)
    {
        switch (animationCnt)
        {
        case 0:
            image_Connecting.setBitmap(Bitmap(BITMAP_WIFI_LEVEL_1_ID));
            Unicode::snprintf(textArea_ConnectingBuffer, TEXTAREA_CONNECTING_SIZE, ".");
            animationCnt++;
            break;

        case 1:
            image_Connecting.setBitmap(Bitmap(BITMAP_WIFI_LEVEL_2_ID));
            Unicode::snprintf(textArea_ConnectingBuffer, TEXTAREA_CONNECTING_SIZE, "..");
            animationCnt++;
            break;

        case 2:
            image_Connecting.setBitmap(Bitmap(BITMAP_WIFI_LEVEL_3_ID));
            Unicode::snprintf(textArea_ConnectingBuffer, TEXTAREA_CONNECTING_SIZE, "...");
            animationCnt++;
            break;

        case 3:
            image_Connecting.setBitmap(Bitmap(BITMAP_WIFI_LEVEL_4_ID));
            Unicode::snprintf(textArea_ConnectingBuffer, TEXTAREA_CONNECTING_SIZE, "....");
            animationCnt = 0;
            break;

        default:
            break;
        }
        image_Connecting.invalidate();
        textArea_Connecting.invalidate();

        tickCnt = 0;
    }
    else if (listenning)
    {
        tickCnt++;
    }
}
