#ifndef CARBRANDSVIEW_HPP
#define CARBRANDSVIEW_HPP

#include <gui_generated/carbrands_screen/CarBrandsViewBase.hpp>
#include <gui/carbrands_screen/CarBrandsPresenter.hpp>

#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/ScrollableContainer.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>



#define CARBRANDS_FLEXBUTTON_WIDTH 180
#define CARBRANDS_FLEXBUTTON_HEIGHT 237


class CarBrandsView : public CarBrandsViewBase
{
public:
	CarBrandsView();
	virtual ~CarBrandsView() {}
	virtual void setupScreen();
	virtual void tearDownScreen();
	/*
 * Custom Actions
 */
	virtual void action_Back_Click();
private:
	touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButton[DATA_NUM_BRANDS];
	/*
	 * Callback Declarations
	 */
	touchgfx::Callback<CarBrandsView, const touchgfx::AbstractButtonContainer&> CarBrandsButtonCallback;
	/*
	 * Callback Handler Declarations
	 */
	void CarBrandsButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
protected:

};

#endif // CARBRANDSVIEW_HPP
