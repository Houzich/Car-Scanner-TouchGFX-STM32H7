#include <gui/containers/CC_FrameSelect.hpp>

CC_FrameSelect::CC_FrameSelect()
{

}

void CC_FrameSelect::initialize()
{
    CC_FrameSelectBase::initialize();
}

void CC_FrameSelect::flexButton_Main_Name_setWildcard(const Unicode::UnicodeChar* value)
{
    flexButton_Main.setWildcardTextBuffer(value);
    flexButton_Main.invalidate();
}


void CC_FrameSelect::flexButton_Main_setAction(GenericCallback<const AbstractButtonContainer&>& callback)
{
    flexButton_Main.setAction(callback);
}


void* CC_FrameSelect::getflexButton_Main()
{
    return &flexButton_Main;
}
