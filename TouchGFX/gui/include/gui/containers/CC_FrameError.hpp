#ifndef CC_FRAMEERROR_HPP
#define CC_FRAMEERROR_HPP

#include <gui_generated/containers/CC_FrameErrorBase.hpp>

class CC_FrameError : public CC_FrameErrorBase
{
public:
    CC_FrameError();
    virtual ~CC_FrameError() {}

    virtual void initialize();
    void setName(const Unicode::UnicodeChar* value);
    void setValue(const Unicode::UnicodeChar* value);
    void setErr(bool err);
    void setAction(GenericCallback<const AbstractButtonContainer&>& callback);
    void setIcon(const Bitmap& icon);
protected:
};

#endif // CC_FRAMEERROR_HPP
