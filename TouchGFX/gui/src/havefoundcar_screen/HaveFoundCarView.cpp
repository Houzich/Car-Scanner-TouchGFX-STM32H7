#include <gui/havefoundcar_screen/HaveFoundCarView.hpp>

HaveFoundCarView::HaveFoundCarView()
{

}

void HaveFoundCarView::setupScreen()
{
    HaveFoundCarViewBase::setupScreen();
    cC_CarItemScrollList1.textArea1_setWildcard(pCars->getCurrentBrand()->getName());
    cC_CarItemScrollList2.textArea1_setWildcard(pCars->getCurrentModelYear()->getName());
    cC_CarItemScrollList3.textArea1_setWildcard(pCars->getCurrentModelSeries()->getName());
    cC_CarItemScrollList4.textArea1_setWildcard(pCars->getCurrentCar()->getName());
    cC_CarItemScrollList1.invalidate();
    cC_CarItemScrollList2.invalidate();
    cC_CarItemScrollList3.invalidate();
    cC_CarItemScrollList4.invalidate();
    ScreenPath.sprintf_curr_path(Data::CURRENT_STATE_PAGE::MODEL_NAME, pCars);
    cC_TopMenu1.textArea_Path_setWildcard(ScreenPath.disp_path);
}

void HaveFoundCarView::tearDownScreen()
{
    HaveFoundCarViewBase::tearDownScreen();
}


void HaveFoundCarView::action_Back_Click()
{
}




