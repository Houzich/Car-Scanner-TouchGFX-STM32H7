/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/CC_LeftMenuBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

CC_LeftMenuBase::CC_LeftMenuBase() :
    buttonCallback(this, &CC_LeftMenuBase::buttonCallbackHandler),
    trigger_BackCallback(0)
{
    setWidth(79);
    setHeight(480);
    box1.setPosition(0, 0, 79, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(36, 28, 28));

    button_Back.setXY(0, 0);
    button_Back.setBitmaps(touchgfx::Bitmap(BITMAP_BUTTON_BACK_ID), touchgfx::Bitmap(BITMAP_BUTTON_BUTTON_BACK_S_ID));
    button_Back.setAction(buttonCallback);

    button_Home.setXY(0, 82);
    button_Home.setBitmaps(touchgfx::Bitmap(BITMAP_BUTTON_HOME_ID), touchgfx::Bitmap(BITMAP_BUTTON_HOME_S_ID));
    button_Home.setAction(buttonCallback);

    button_Settings.setXY(0, 390);
    button_Settings.setBitmaps(touchgfx::Bitmap(BITMAP_BUTTON_SETTINGS_ID), touchgfx::Bitmap(BITMAP_BUTTON_SETTINGS_S_ID));
    button_Settings.setAction(buttonCallback);

    add(box1);
    add(button_Back);
    add(button_Home);
    add(button_Settings);
}

void CC_LeftMenuBase::initialize()
{

}

void CC_LeftMenuBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button_Back)
    {
        //Interaction_Back
        //When button_Back clicked emit trigger_Back callback
        //Emit callback
        emitTrigger_BackCallback();
    }
    else if (&src == &button_Home)
    {
        //Interaction_Home
        //When button_Home clicked change screen to Main
        //Go to Main with no screen transition
        application().gotoMainScreenNoTransition();
    }
    else if (&src == &button_Settings)
    {
        //Interaction_Settings
        //When button_Settings clicked change screen to Settings
        //Go to Settings with no screen transition
        application().gotoSettingsScreenNoTransition();
    }
}
