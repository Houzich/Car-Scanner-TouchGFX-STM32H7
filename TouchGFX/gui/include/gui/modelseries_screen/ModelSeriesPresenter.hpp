#ifndef MODELSERIESPRESENTER_HPP
#define MODELSERIESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ModelSeriesView;

class ModelSeriesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ModelSeriesPresenter(ModelSeriesView& v);

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

    virtual ~ModelSeriesPresenter() {};

private:
    ModelSeriesPresenter();

    ModelSeriesView& view;
};

#endif // MODELSERIESPRESENTER_HPP
