#ifndef TESTDISPLAYVIEW_HPP
#define TESTDISPLAYVIEW_HPP

#include <gui_generated/testdisplay_screen/TestDisplayViewBase.hpp>
#include <gui/testdisplay_screen/TestDisplayPresenter.hpp>

class TestDisplayView : public TestDisplayViewBase
{
public:
    TestDisplayView();
    virtual ~TestDisplayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleClickEvent(const ClickEvent& evt);

protected:
};

#endif // TESTDISPLAYVIEW_HPP
