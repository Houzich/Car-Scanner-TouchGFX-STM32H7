#include <gui/functionselection_screen/FunctionSelectionView.hpp>
#include <touchgfx/Color.hpp>


FunctionSelectionView::FunctionSelectionView()
{
    ScreenPath.sprintf_curr_path(Data::CURRENT_STATE_PAGE::ECU, pCars);
    cC_TopMenu1.textArea_Path_setWildcard(ScreenPath.disp_path);
}

void FunctionSelectionView::setupScreen()
{
    FunctionSelectionViewBase::setupScreen();
}

void FunctionSelectionView::tearDownScreen()
{
    FunctionSelectionViewBase::tearDownScreen();
}


void FunctionSelectionView::action_Back_Click()
{

    if (pCars->automaticallyScan) {
        application().gotoECUsScreenNoTransition();
    }
    else {
        application().gotoModelNumberScreenNoTransition();
    }
}


