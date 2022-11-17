#ifndef WAITINGDATAPRESENTER_HPP
#define WAITINGDATAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class WaitingDataView;

class WaitingDataPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    WaitingDataPresenter(WaitingDataView& v);

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

    virtual ~WaitingDataPresenter() {};

private:
    WaitingDataPresenter();

    WaitingDataView& view;
};

#endif // WAITINGDATAPRESENTER_HPP
