#include <gui/containers/CC_WiFiConnectingContainer.hpp>
#include "BitmapDatabase.hpp"

CC_WiFiConnectingContainer::CC_WiFiConnectingContainer()
{

}

void CC_WiFiConnectingContainer::initialize()
{
    CC_WiFiConnectingContainerBase::initialize();
}

void CC_WiFiConnectingContainer::resetContainer()
{
    tickCnt = 0;
    animationCnt = 0;
    connecting = true;

    image_Connecting.setBitmap(Bitmap(BITMAP_WIFI_LEVEL_1_ID));
    image_Connecting.setVisible(true);

    Unicode::snprintf(textArea_ConnectingBuffer, TEXTAREA_CONNECTING_SIZE, ".");
    textArea_Connecting.setVisible(true);

    image_Connecting.invalidate();
    textArea_Connecting.invalidate();

    textArea_WiFiConnectionStatus1.setVisible(false);
    image_Error.setVisible(false);
    buttonWithLabel_WiFiRetry.setVisible(false);

    textArea_WiFiConnectionStatus1.invalidate();
    image_Error.invalidate();
    buttonWithLabel_WiFiRetry.invalidate();
}

void CC_WiFiConnectingContainer::connectionUnsuccesfull()
{
    connecting = false;

    image_Connecting.setVisible(false);
    textArea_Connecting.setVisible(false);

    image_Connecting.invalidate();
    textArea_Connecting.invalidate();

    textArea_WiFiConnectionStatus1.setVisible(true);
    image_Error.setVisible(true);
    buttonWithLabel_WiFiRetry.setVisible(true);

    textArea_WiFiConnectionStatus1.invalidate();
    image_Error.invalidate();
    buttonWithLabel_WiFiRetry.invalidate();

}

void CC_WiFiConnectingContainer::tickEvent()
{
    if (tickCnt == 30 && connecting)
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
    else if (connecting)
    {
        tickCnt++;
    }
}