#ifndef CARBRANDSPRESENTER_HPP
#define CARBRANDSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class CarBrandsView;

class CarBrandsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CarBrandsPresenter(CarBrandsView& v);

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

    virtual ~CarBrandsPresenter() {};

private:
    CarBrandsPresenter();

    CarBrandsView& view;
};

#endif // CARBRANDSPRESENTER_HPP
