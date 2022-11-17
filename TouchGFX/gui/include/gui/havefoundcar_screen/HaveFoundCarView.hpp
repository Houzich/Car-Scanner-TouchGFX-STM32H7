#ifndef HAVEFOUNDCARVIEW_HPP
#define HAVEFOUNDCARVIEW_HPP

#include <gui_generated/havefoundcar_screen/HaveFoundCarViewBase.hpp>
#include <gui/havefoundcar_screen/HaveFoundCarPresenter.hpp>

class HaveFoundCarView : public HaveFoundCarViewBase
{
public:
    HaveFoundCarView();
    virtual ~HaveFoundCarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    /*
 * Custom Actions
 */
    virtual void action_Back_Click();
protected:
};

#endif // HAVEFOUNDCARVIEW_HPP
