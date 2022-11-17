#include <gui/automaticsearch_screen/AutomaticSearchView.hpp>


AutomaticSearchView::AutomaticSearchView()
{

}

void AutomaticSearchView::setupScreen()
{
    AutomaticSearchViewBase::setupScreen();
}

void AutomaticSearchView::tearDownScreen()
{
    AutomaticSearchViewBase::tearDownScreen();
}

void AutomaticSearchView::action_Automatically_Click()
{
    pCars->automaticallyScan = true;
}

void AutomaticSearchView::action_Manually_Click()
{
    pCars->automaticallyScan = false;
}

void AutomaticSearchView::action_Back_Click()
{
}


