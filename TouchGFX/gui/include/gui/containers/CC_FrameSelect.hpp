#ifndef CC_FRAMESELECT_HPP
#define CC_FRAMESELECT_HPP

#include <gui_generated/containers/CC_FrameSelectBase.hpp>

class CC_FrameSelect : public CC_FrameSelectBase
{
public:
    CC_FrameSelect();
    virtual ~CC_FrameSelect() {}

    virtual void initialize();
    void flexButton_Main_Name_setWildcard(const Unicode::UnicodeChar* value);
    void flexButton_Main_setAction(GenericCallback<const AbstractButtonContainer&>& callback);
    void* getflexButton_Main();
protected:
};

#endif // CC_FRAMESELECT_HPP
