#ifndef FUNCTIONSELECTIONPRESENTER_HPP
#define FUNCTIONSELECTIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class FunctionSelectionView;

class FunctionSelectionPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    FunctionSelectionPresenter(FunctionSelectionView& v);

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

    virtual ~FunctionSelectionPresenter() {};

private:
    FunctionSelectionPresenter();

    FunctionSelectionView& view;
};

#endif // FUNCTIONSELECTIONPRESENTER_HPP
