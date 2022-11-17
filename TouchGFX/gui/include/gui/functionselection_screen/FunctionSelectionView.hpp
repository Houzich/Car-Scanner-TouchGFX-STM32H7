#ifndef FUNCTIONSELECTIONVIEW_HPP
#define FUNCTIONSELECTIONVIEW_HPP

#include <gui_generated/functionselection_screen/FunctionSelectionViewBase.hpp>
#include <gui/functionselection_screen/FunctionSelectionPresenter.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>


//#define FUNCTIONSELECTION_FLEXBUTTON_WIDTH 240
//#define FUNCTIONSELECTION_FLEXBUTTON_HEIGHT 200
//#define NUMBER_OF_FUNCTIONSELECTION_BUTTONS  _countof(CarClass::Functions)

class FunctionSelectionView : public FunctionSelectionViewBase
{
public:
    FunctionSelectionView();
    virtual ~FunctionSelectionView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	/*
* Custom Actions
*/
	virtual void action_Back_Click();
protected:
};

#endif // FUNCTIONSELECTIONVIEW_HPP
