#ifndef TESTDISPLAYPRESENTER_HPP
#define TESTDISPLAYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TestDisplayView;

class TestDisplayPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TestDisplayPresenter(TestDisplayView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~TestDisplayPresenter() {};

private:
    TestDisplayPresenter();

    TestDisplayView& view;
};

#endif // TESTDISPLAYPRESENTER_HPP
