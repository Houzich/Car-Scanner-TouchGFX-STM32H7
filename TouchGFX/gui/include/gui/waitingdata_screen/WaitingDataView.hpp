#ifndef WAITINGDATAVIEW_HPP
#define WAITINGDATAVIEW_HPP

#include <gui_generated/waitingdata_screen/WaitingDataViewBase.hpp>
#include <gui/waitingdata_screen/WaitingDataPresenter.hpp>

class WaitingDataView : public WaitingDataViewBase
{
public:
    WaitingDataView();
    virtual ~WaitingDataView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // WAITINGDATAVIEW_HPP
