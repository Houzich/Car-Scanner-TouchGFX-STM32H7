#include <gui/display_screen/DisplayView.hpp>
#include <gui/display_screen/DisplayPresenter.hpp>

DisplayPresenter::DisplayPresenter(DisplayView& v)
    : view(v)
{

}

void DisplayPresenter::activate()
{
	view.setBrightnessValue(model->getBrightnessValue());
	view.updateBrightnessText(model->getBrightnessValue());
}

void DisplayPresenter::deactivate()
{

}

void DisplayPresenter::newBrightnessValue(int value)
{
    model->setBrightnessValue(value);
}


