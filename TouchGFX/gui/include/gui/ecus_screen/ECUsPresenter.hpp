#ifndef ECUS_PRESENTER_HPP
#define ECUS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ECUsView;

class ECUsPresenter : public Presenter, public ModelListener
{
public:
    ECUsPresenter(ECUsView& v);

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

    virtual ~ECUsPresenter() {};

private:
    ECUsPresenter();

    ECUsView& view;
};


#endif // ECUS_PRESENTER_HPP
