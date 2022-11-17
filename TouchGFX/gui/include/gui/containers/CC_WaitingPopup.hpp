#ifndef CC_WAITINGPOPUP_HPP
#define CC_WAITINGPOPUP_HPP

#include <gui_generated/containers/CC_WaitingPopupBase.hpp>

class CC_WaitingPopup : public CC_WaitingPopupBase
{
public:
    CC_WaitingPopup();
    virtual ~CC_WaitingPopup() {}

    virtual void initialize();
protected:
};

#endif // CC_WAITINGPOPUP_HPP
