#include <gui/containers/CC_FrameData.hpp>

CC_FrameData::CC_FrameData()
{

}

void CC_FrameData::initialize()
{
    CC_FrameDataBase::initialize();
}


void CC_FrameData::textArea_Name_setWildcard(const Unicode::UnicodeChar* value)
{
    textArea_Name.setWildcard(value);
    textArea_Name.invalidate();
}

void CC_FrameData::textArea_Value_Invalidate()
{
    textArea_Value.invalidate();
}

int CC_FrameData::getTextArea_ValueBufferSize()
{
    return TEXTAREA_VALUE_SIZE;
}

touchgfx::Unicode::UnicodeChar* CC_FrameData::getTextArea_ValueBuffer()
{
    return textArea_ValueBuffer;
}

void CC_FrameData::box_Err_setColor(colortype color)
{
    box_Err.setColor(color);
}

void CC_FrameData::box_Err_setAlpha(uint8_t newAlpha)
{
    box_Err.setAlpha(newAlpha);
}


