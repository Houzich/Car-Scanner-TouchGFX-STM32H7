#include <gui/wificonnecting_screen/WiFiConnectingView.hpp>

#include <gui/common/enums.hpp>
#include <gui/common/structs.hpp>
#include "../../../Data/Widget.hpp"
#include "../../../Data/Data.hpp"
using namespace Data;


WiFiConnectingView::WiFiConnectingView() :
    wifiAccessPointSelectedCallback(this, &WiFiConnectingView::wifiAccessPointSelected),
    keyboardDonePressedCallback(this, &WiFiConnectingView::keyboardDonePressed)
{

}

void WiFiConnectingView::setupScreen()
{
    WiFiConnectingViewBase::setupScreen();
    cC_WiFiMenuContainer.setAction(wifiAccessPointSelectedCallback);
    presenter->setInWiFiMenu(true);
    presenter->setGetWifiData(true);

#ifndef SIMULATOR
    wifiKeyboard.setPosition(0, 20, 800, 460);
    wifiKeyboard.setKeyboardDoneReturnPressedAction(keyboardDonePressedCallback);
    wifiKeyboard.setVisible(false);
    add(wifiKeyboard);
#endif //SIMULATOR

    remove(button_Back);
    add(button_Back);

#ifndef SIMULATOR
    cC_WiFiListennigContainer.listenningStart();
	cC_WiFiListennigContainer.setVisible(true);
	cC_WiFiListennigContainer.invalidate();
#endif //SIMULATOR



    //remove(cC_WiFiMenuContainer);
    //add(cC_WiFiMenuContainer);

}

void WiFiConnectingView::tearDownScreen()
{
    WiFiConnectingViewBase::tearDownScreen();
    presenter->setInWiFiMenu(false);
}

void WiFiConnectingView::updateWiFiInformaion(struct  wifiData data[], uint16_t numberOfPoints)
{
	if (cC_WiFiListennigContainer.isVisible()&&(numberOfPoints))
    {
    	cC_WiFiListennigContainer.listenningStop();
    	cC_WiFiListennigContainer.setVisible(false);
    	cC_WiFiListennigContainer.invalidate();
    	cC_WiFiMenuContainer.setVisible(true);
    	cC_WiFiMenuContainer.invalidate();
    }

	if(presenter->getIsWiFiConnected()){
    for (int cnt = 0; cnt< numberOfPoints; cnt++)
    {
    	if(Unicode::strncmp(presenter->getCurrentConnectedWiFiData().ssid, data[cnt].ssid, _countof(data[cnt].ssid))==0){
    		data[cnt].connected = true;
    	} else {
    		data[cnt].connected = false;
    	}
    }
}

    cC_WiFiMenuContainer.updateWifiList(data, numberOfPoints);
}

void WiFiConnectingView::updateWifiIcon(int8_t strength)
{
//    switch (strength)
//    {
//    case WIFI_STRENGTH::NONE:
//        wifiIcon.setBitmap(Bitmap(BITMAP_NO_WIFI_ID));
//        break;
//
//    case WIFI_STRENGTH::MINIMAL:
//        wifiIcon.setBitmap(Bitmap(BITMAP_WIFI_DOT_ID));
//        break;
//
//    case WIFI_STRENGTH::LOW:
//        wifiIcon.setBitmap(Bitmap(BITMAP_WIFI_LOW_ID));
//        break;
//
//    case WIFI_STRENGTH::MEDIUM:
//        wifiIcon.setBitmap(Bitmap(BITMAP_WIFI_MID_ID));
//        break;
//
//    case WIFI_STRENGTH::HIGH:
//        wifiIcon.setBitmap(Bitmap(BITMAP_WIFI_FULL_ID));
//        break;
//    }
//    wifiIcon.invalidate();
}

void WiFiConnectingView::keyboardDonePressed(Unicode::UnicodeChar buffer[])
{
#ifndef SIMULATOR
    presenter->setSelectedWifi(buffer, selectedWiFiID);
    cC_WiFiConnectingContainer.resetContainer();

    wifiKeyboard.clearBuffer();

    wifiKeyboard.setVisible(false);
    cC_WiFiConnectingContainer.setVisible(true);


    /*added by GHA*/
    button_Back.setVisible(false);
    button_Back.invalidate();
    box_BackgroundBtnBack.setVisible(false);
    box_BackgroundBtnBack.invalidate();

    cC_BackGround.setVisible(true);
    cC_BackGround.invalidate();
    cC_BackGround_Keyboard.setVisible(false);
    cC_BackGround_Keyboard.invalidate();

    /**/

    wifiKeyboard.invalidate();
    cC_WiFiConnectingContainer.invalidate();
#endif //SIMULATOR
}

void WiFiConnectingView::closeWiFiConnectingMenu()
{
#ifndef SIMULATOR
    cC_WiFiMenuContainer.setVisible(false);
    wifiKeyboard.setVisible(false);
    cC_WiFiConnectingContainer.setVisible(false);


    cC_WiFiMenuContainer.invalidate();
    wifiKeyboard.invalidate();
    cC_WiFiConnectingContainer.invalidate();

    wifiKeyboard.clearBuffer();
#endif //SIMULATOR
}
void WiFiConnectingView::wifiAccessPointSelected(int id)
{
#ifndef SIMULATOR
    wifiData selectedAP;
    presenter->getWifiAccessPoints(selectedAP, id);
    selectedWiFiID = id;

    cC_WiFiMenuContainer.setVisible(false);
    cC_WiFiMenuContainer.invalidate();

    button_Back.setVisible(true);
    button_Back.invalidate();
    //box_BackgroundBtnBack.setVisible(true);
    //box_BackgroundBtnBack.invalidate();

    cC_LeftMenu_Back.setVisible(false);
    cC_LeftMenu_Back.invalidate();

    presenter->setInWiFiMenu(false);

    if (selectedAP.encrypted)
    {
        wifiKeyboard.setVisible(true);
        wifiKeyboard.invalidate();
        cC_BackGround.setVisible(false);
        cC_BackGround.invalidate();
        cC_BackGround_Keyboard.setVisible(true);
        cC_BackGround_Keyboard.invalidate();
    }
    else
    {
        keyboardDonePressed(0);
    }
#endif //SIMULATOR
}

void WiFiConnectingView::handleClickEvent(const ClickEvent& evt)
{
    WiFiConnectingViewBase::handleClickEvent(evt);
}

void WiFiConnectingView::handleTickEvent()
{
    cC_WiFiConnectingContainer.tickEvent();
    cC_WiFiListennigContainer.tickEvent();
}

void WiFiConnectingView::wifiConnection(bool succesful)
{
    if (cC_WiFiConnectingContainer.isVisible())
    {
        if (succesful)
        {
        	closeWiFiConnectingMenu();
        	application().gotoWiFiConnectingScreenNoTransition();

        }
        else
        {
            updateWifiIcon(WIFI_STRENGTH::NONE);
            cC_WiFiConnectingContainer.connectionUnsuccesfull();
        }
    }
}

