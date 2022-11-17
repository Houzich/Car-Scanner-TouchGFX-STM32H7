/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/automaticsearch_screen/AutomaticSearchViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

AutomaticSearchViewBase::AutomaticSearchViewBase() :
    flexButtonCallback(this, &AutomaticSearchViewBase::flexButtonCallbackHandler),
    cC_LeftMenu1Trigger_BackCallback(this, &AutomaticSearchViewBase::cC_LeftMenu1Trigger_BackCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    cC_LeftMenu1.setXY(0, 0);
    cC_LeftMenu1.setTrigger_BackCallback(cC_LeftMenu1Trigger_BackCallback);
    cC_LeftMenu1.setTrigger_BackCallback(cC_LeftMenu1Trigger_BackCallback);

    flexButton_Automatically.setBoxWithBorderPosition(0, 0, 330, 441);
    flexButton_Automatically.setBorderSize(2);
    flexButton_Automatically.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(20, 20, 20), touchgfx::Color::getColorFromRGB(20, 20, 20), touchgfx::Color::getColorFromRGB(50, 50, 50));
    flexButton_Automatically.setIconBitmaps(Bitmap(BITMAP_DEVICE_ID), Bitmap(BITMAP_DEVICE_ID));
    flexButton_Automatically.setIconXY(51, 163);
    flexButton_Automatically.setText(TypedText(T_SINGLEUSEID26));
    flexButton_Automatically.setTextPosition(0, 45, 330, 441);
    flexButton_Automatically.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(50, 50, 50));
    flexButton_Automatically.setPosition(102, 18, 330, 441);
    flexButton_Automatically.setAction(flexButtonCallback);

    flexButton_Manually.setBoxWithBorderPosition(0, 0, 325, 441);
    flexButton_Manually.setBorderSize(2);
    flexButton_Manually.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(20, 20, 20), touchgfx::Color::getColorFromRGB(20, 20, 20), touchgfx::Color::getColorFromRGB(50, 50, 50));
    flexButton_Manually.setText(TypedText(T_SINGLEUSEID27));
    flexButton_Manually.setTextPosition(0, 45, 325, 441);
    flexButton_Manually.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(50, 50, 50));
    flexButton_Manually.setIconBitmaps(Bitmap(BITMAP_DEVICE_ID), Bitmap(BITMAP_DEVICE_ID));
    flexButton_Manually.setIconXY(51, 163);
    flexButton_Manually.setPosition(452, 18, 325, 441);
    flexButton_Manually.setAction(flexButtonCallback);

    add(__background);
    add(cC_LeftMenu1);
    add(flexButton_Automatically);
    add(flexButton_Manually);
}

void AutomaticSearchViewBase::setupScreen()
{
    cC_LeftMenu1.initialize();
}

void AutomaticSearchViewBase::cC_LeftMenu1Trigger_BackCallbackHandler()
{
    //Button_Back_Clicked
    //When cC_LeftMenu1 trigger_Back change screen to CarBrands
    //Go to CarBrands with no screen transition
    application().gotoCarBrandsScreenNoTransition();

    //Action_Back_Clicked
    //When cC_LeftMenu1 trigger_Back call action_Back_Click on AutomaticSearch
    //Call action_Back_Click
    action_Back_Click();
}

void AutomaticSearchViewBase::action_Automatically_Click()
{

}

void AutomaticSearchViewBase::action_Manually_Click()
{

}

void AutomaticSearchViewBase::action_Back_Click()
{

}

void AutomaticSearchViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton_Automatically)
    {
        //Button_Automatically_Clicked
        //When flexButton_Automatically clicked change screen to WaitingCar
        //Go to WaitingCar with no screen transition
        application().gotoWaitingCarScreenNoTransition();

        //Action_Automatically_Clicked
        //When flexButton_Automatically clicked call action_Automatically_Click on AutomaticSearch
        //Call action_Automatically_Click
        action_Automatically_Click();
    }
    else if (&src == &flexButton_Manually)
    {
        //Button_Manually_Clicked
        //When flexButton_Manually clicked change screen to ModelYear
        //Go to ModelYear with no screen transition
        application().gotoModelYearScreenNoTransition();

        //Action_Manually_Clicked
        //When flexButton_Manually clicked call action_Manually_Click on AutomaticSearch
        //Call action_Manually_Click
        action_Manually_Click();
    }
}