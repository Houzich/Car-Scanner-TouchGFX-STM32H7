#ifndef HAVEFOUNDCARPRESENTER_HPP
#define HAVEFOUNDCARPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class HaveFoundCarView;

class HaveFoundCarPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    HaveFoundCarPresenter(HaveFoundCarView& v);

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

    virtual ~HaveFoundCarPresenter() {};

private:
    HaveFoundCarPresenter();

    HaveFoundCarView& view;
};

#endif // HAVEFOUNDCARPRESENTER_HPP
