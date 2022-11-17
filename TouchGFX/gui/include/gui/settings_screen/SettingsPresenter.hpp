#ifndef SETTINGS_PRESENTER_HPP
#define SETTINGS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SettingsView;

class SettingsPresenter : public Presenter, public ModelListener
{
public:
    SettingsPresenter(SettingsView& v);

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

    virtual ~SettingsPresenter() {};

private:
    SettingsPresenter();

    SettingsView& view;
};


#endif // SETTINGS_PRESENTER_HPP
