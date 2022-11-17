#ifndef AUTOMATICSEARCHPRESENTER_HPP
#define AUTOMATICSEARCHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AutomaticSearchView;

class AutomaticSearchPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AutomaticSearchPresenter(AutomaticSearchView& v);

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

    virtual ~AutomaticSearchPresenter() {};

private:
    AutomaticSearchPresenter();

    AutomaticSearchView& view;
};

#endif // AUTOMATICSEARCHPRESENTER_HPP
