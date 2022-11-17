#ifndef WAITINGCARVIEW_HPP
#define WAITINGCARVIEW_HPP

#include <gui_generated/waitingcar_screen/WaitingCarViewBase.hpp>
#include <gui/waitingcar_screen/WaitingCarPresenter.hpp>

class WaitingCarView : public WaitingCarViewBase
{
public:
    WaitingCarView();
    virtual ~WaitingCarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // WAITINGCARVIEW_HPP
