#include <gui/display_screen/DisplayView.hpp>

DisplayView::DisplayView() :
    sliderValueStartedChangeCallback(this, &DisplayView::sliderValueStartedChangeCallbackHandler),
    sliderValueChangedCallback(this, &DisplayView::sliderValueChangedCallbackHandler),
    sliderValueConfirmedCallback(this, &DisplayView::sliderValueConfirmedCallbackHandler)
{

}

void DisplayView::setupScreen()
{
    DisplayViewBase::setupScreen();
    slider_Brightness.setStartValueCallback(sliderValueStartedChangeCallback);
    slider_Brightness.setNewValueCallback(sliderValueChangedCallback);
    slider_Brightness.setStopValueCallback(sliderValueConfirmedCallback);
}

void DisplayView::tearDownScreen()
{
    DisplayViewBase::tearDownScreen();
}

void DisplayView::sliderValueStartedChangeCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider_Brightness)
    {
        //execute code whenever the slider starts changing value.
    }
}

void DisplayView::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider_Brightness)
    {
    	updateBrightnessText(value);
        presenter->newBrightnessValue(value);
        //execute code whenever the value of the slider changes.
    }
}

void DisplayView::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider_Brightness)
    {
        presenter->newBrightnessValue(value);
        //execute code whenever the slider stops the changing value.
    }
}


void DisplayView::updateBrightnessText(int value)
{
    Unicode::snprintf(textArea_Brightness_PercentageBuffer, TEXTAREA_BRIGHTNESS_PERCENTAGE_SIZE, "%d", value);
    textArea_Brightness_Percentage.invalidate();
}

void DisplayView::setBrightnessValue(int value)
{
    slider_Brightness.setValue(value);
    slider_Brightness.invalidate();
}



