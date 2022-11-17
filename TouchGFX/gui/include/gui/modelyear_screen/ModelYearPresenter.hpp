#ifndef MODELYEARPRESENTER_HPP
#define MODELYEARPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ModelYearView;

class ModelYearPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ModelYearPresenter(ModelYearView& v);

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

    virtual ~ModelYearPresenter() {};

private:
    ModelYearPresenter();

    ModelYearView& view;
};

#endif // MODELYEARPRESENTER_HPP
