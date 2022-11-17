#ifndef ZOSTAWKA_PRESENTER_HPP
#define ZOSTAWKA_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ZostawkaView;

class ZostawkaPresenter : public Presenter, public ModelListener
{
public:
    ZostawkaPresenter(ZostawkaView& v);

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

    virtual ~ZostawkaPresenter() {};

private:
    ZostawkaPresenter();

    ZostawkaView& view;
};


#endif // ZOSTAWKA_PRESENTER_HPP
