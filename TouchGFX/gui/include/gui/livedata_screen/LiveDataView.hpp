#ifndef LIVEDATAVIEW_HPP
#define LIVEDATAVIEW_HPP

#include <gui_generated/livedata_screen/LiveDataViewBase.hpp>
#include <gui/livedata_screen/LiveDataPresenter.hpp>

using namespace Data;


class LiveDataView : public LiveDataViewBase
{
public:
    LiveDataView();
    virtual ~LiveDataView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LIVEDATAVIEW_HPP
