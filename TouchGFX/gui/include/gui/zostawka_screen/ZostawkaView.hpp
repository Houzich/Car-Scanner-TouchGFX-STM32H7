#ifndef ZOSTAWKA_VIEW_HPP
#define ZOSTAWKA_VIEW_HPP

#include <gui_generated/zostawka_screen/ZostawkaViewBase.hpp>
#include <gui/zostawka_screen/ZostawkaPresenter.hpp>

class ZostawkaView : public ZostawkaViewBase
{
public:
    ZostawkaView();
    virtual ~ZostawkaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ZOSTAWKA_VIEW_HPP
