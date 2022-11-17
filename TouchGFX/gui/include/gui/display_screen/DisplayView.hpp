#ifndef DISPLAYVIEW_HPP
#define DISPLAYVIEW_HPP

#include <gui_generated/display_screen/DisplayViewBase.hpp>
#include <gui/display_screen/DisplayPresenter.hpp>

class DisplayView : public DisplayViewBase
{
public:
    DisplayView();
    virtual ~DisplayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    /*
     * MY
     */
    void setBrightnessValue(int value);
    void updateBrightnessText(int value);
protected:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<DisplayView, const touchgfx::Slider&, int> sliderValueStartedChangeCallback;
    touchgfx::Callback<DisplayView, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<DisplayView, const touchgfx::Slider&, int> sliderValueConfirmedCallback;

    /*
     * Callback Handler Declarations
     */
    void sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value);
};

#endif // DISPLAYVIEW_HPP
