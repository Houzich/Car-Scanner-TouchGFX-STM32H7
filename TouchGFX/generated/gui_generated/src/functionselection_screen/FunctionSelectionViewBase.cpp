/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/functionselection_screen/FunctionSelectionViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

FunctionSelectionViewBase::FunctionSelectionViewBase() :
    flexButtonCallback(this, &FunctionSelectionViewBase::flexButtonCallbackHandler),
    cC_LeftMenu1Trigger_BackCallback(this, &FunctionSelectionViewBase::cC_LeftMenu1Trigger_BackCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    cC_LeftMenu1.setXY(0, 0);
    cC_LeftMenu1.setTrigger_BackCallback(cC_LeftMenu1Trigger_BackCallback);

    flexButton_ReadErrors.setIconBitmaps(Bitmap(BITMAP_BUTTON_READ_ERRORS_ID), Bitmap(BITMAP_BUTTON_LIGHT_SELECTOR_ID));
    flexButton_ReadErrors.setIconXY(0, 0);
    flexButton_ReadErrors.setText(TypedText(T_SINGLEUSEID18));
    flexButton_ReadErrors.setTextPosition(0, 170, 239, 199);
    flexButton_ReadErrors.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton_ReadErrors.setPosition(80, 63, 239, 199);

    flexButton_DeleteErrors.setText(TypedText(T_SINGLEUSEID19));
    flexButton_DeleteErrors.setTextPosition(0, 170, 239, 199);
    flexButton_DeleteErrors.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton_DeleteErrors.setIconBitmaps(Bitmap(BITMAP_BUTTON_DELETE_ERRORS_ID), Bitmap(BITMAP_BUTTON_LIGHT_SELECTOR_ID));
    flexButton_DeleteErrors.setIconXY(0, 0);
    flexButton_DeleteErrors.setPosition(320, 63, 239, 199);

    flexButton_Coding.setText(TypedText(T_SINGLEUSEID20));
    flexButton_Coding.setTextPosition(0, 170, 239, 199);
    flexButton_Coding.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton_Coding.setIconBitmaps(Bitmap(BITMAP_BUTTON_CODING_ID), Bitmap(BITMAP_BUTTON_LIGHT_SELECTOR_ID));
    flexButton_Coding.setIconXY(0, 0);
    flexButton_Coding.setPosition(560, 63, 239, 199);

    flexButton_LiveData.setText(TypedText(T_SINGLEUSEID21));
    flexButton_LiveData.setTextPosition(0, 170, 239, 199);
    flexButton_LiveData.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton_LiveData.setIconBitmaps(Bitmap(BITMAP_BUTTON_LIVE_DATA_ID), Bitmap(BITMAP_BUTTON_LIGHT_SELECTOR_ID));
    flexButton_LiveData.setIconXY(0, 0);
    flexButton_LiveData.setPosition(80, 262, 239, 199);
    flexButton_LiveData.setAction(flexButtonCallback);

    flexButton_Actuator.setText(TypedText(T_SINGLEUSEID22));
    flexButton_Actuator.setTextPosition(0, 170, 239, 199);
    flexButton_Actuator.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton_Actuator.setIconBitmaps(Bitmap(BITMAP_BUTTON_ACTUATOR_ID), Bitmap(BITMAP_BUTTON_LIGHT_SELECTOR_ID));
    flexButton_Actuator.setIconXY(0, 0);
    flexButton_Actuator.setPosition(320, 262, 239, 199);

    flexButton_ServiceFunctions.setText(TypedText(T_SINGLEUSEID23));
    flexButton_ServiceFunctions.setTextPosition(0, 170, 239, 199);
    flexButton_ServiceFunctions.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    flexButton_ServiceFunctions.setIconBitmaps(Bitmap(BITMAP_BUTTON_SERVICE_FUNCTIONS_ID), Bitmap(BITMAP_BUTTON_LIGHT_SELECTOR_ID));
    flexButton_ServiceFunctions.setIconXY(0, 0);
    flexButton_ServiceFunctions.setPosition(560, 262, 239, 199);

    cC_TopMenu1.setXY(81, 0);

    flexButton_Back_ECUs.setBoxWithBorderPosition(0, 0, 50, 50);
    flexButton_Back_ECUs.setBorderSize(5);
    flexButton_Back_ECUs.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton_Back_ECUs.setPosition(749, 262, 50, 50);
    flexButton_Back_ECUs.setAlpha(0);
    flexButton_Back_ECUs.setAction(flexButtonCallback);

    add(__background);
    add(cC_LeftMenu1);
    add(flexButton_ReadErrors);
    add(flexButton_DeleteErrors);
    add(flexButton_Coding);
    add(flexButton_LiveData);
    add(flexButton_Actuator);
    add(flexButton_ServiceFunctions);
    add(cC_TopMenu1);
    add(flexButton_Back_ECUs);
}

void FunctionSelectionViewBase::setupScreen()
{
    cC_LeftMenu1.initialize();
    cC_TopMenu1.initialize();
}

void FunctionSelectionViewBase::cC_LeftMenu1Trigger_BackCallbackHandler()
{
    //Interaction_Action_Back_Clicked
    //When cC_LeftMenu1 trigger_Back call action_Back_Click on FunctionSelection
    //Call action_Back_Click
    action_Back_Click();
}

void FunctionSelectionViewBase::action_Back_Click()
{

}

void FunctionSelectionViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton_LiveData)
    {
        //InteractionLiveData
        //When flexButton_LiveData clicked change screen to LiveData
        //Go to LiveData with no screen transition
        application().gotoLiveDataScreenNoTransition();
    }
    else if (&src == &flexButton_Back_ECUs)
    {
        //Interaction_ECUs
        //When flexButton_Back_ECUs clicked change screen to ECUs
        //Go to ECUs with no screen transition
        application().gotoECUsScreenNoTransition();
    }
}
