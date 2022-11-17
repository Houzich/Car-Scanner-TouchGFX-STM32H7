#include <gui/containers/CC_FrameError.hpp>
#include <touchgfx/Color.hpp>

CC_FrameError::CC_FrameError()
{

}

void CC_FrameError::initialize()
{
    CC_FrameErrorBase::initialize();
}

void CC_FrameError::setName(const Unicode::UnicodeChar* value)
{
    flexButton_Main.setWildcardTextBuffer(value);
    flexButton_Main.invalidate();
}

void CC_FrameError::setValue(const Unicode::UnicodeChar* value)
{
    textArea_Value.setWildcard(value);
    textArea_Value.invalidate();
}

void CC_FrameError::setErr(bool err)
{
    if (err)
        box_Err.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    else
        box_Err.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
}

void CC_FrameError::setAction(GenericCallback<const AbstractButtonContainer&>& callback)
{
    flexButton_Main.setAction(callback);
}


void CC_FrameError::setIcon(const Bitmap& icon)
{
    flexButton_Main.setIconBitmaps(icon, icon);
    flexButton_Main.setIconXY(17, 1);
}

