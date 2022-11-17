#include <gui/ecus_screen/ECUsView.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/Utils.hpp>

#include "../../../Data/CarModels.hpp"
using namespace Data;

ECUsView::ECUsView() : ECUsButtonCallback(this, &ECUsView::ECUsButtonCallbackHandler)
{

}

void ECUsView::setupScreen()
{
    ECUsViewBase::setupScreen();
    CarClass *car = pCars->getCurrentCar();
    new (pFramesError)CC_FrameError[NUMBER_FRAMEERROR_MAX];
    for (int32_t i = 0; (i < car->getDiagnosticsLen())&&(i < NUMBER_FRAMEERROR_MAX); i++)
    {
        DiagnosticsClass* diagnostic = car->getDiagnostic(i);
        CC_FrameError* frame = &pFramesError[i];
        frame->initialize();
        frame->setName(diagnostic->getName());
        //frame->setValue(diagnostic->getStrError());
        frame->setErr(diagnostic->getError());
        frame->setAction(ECUsButtonCallback);
        frame->setIcon(Bitmap(diagnostic->icon_ID));
        cC_scrollableContainer1.scrollableContainer_Main_add(*frame);
        cC_scrollableContainer1.scrollableContainer_Invalidate_List();
    }   

    cC_scrollableContainer1.invalidate();
    ScreenPath.sprintf_curr_path(Data::CURRENT_STATE_PAGE::MODEL_NAME, pCars);
    cC_TopMenu_ECUs1.setPath(ScreenPath.disp_path);
}

void ECUsView::tearDownScreen()
{
    ECUsViewBase::tearDownScreen();
}


void ECUsView::ECUsButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    CarClass* car = pCars->getCurrentCar();
    for (int32_t i = 0; i < car->getDiagnosticsLen(); i++)
    {
        CC_FrameError* frame = &pFramesError[i];
        if (frame == src.getParent())
        {
            pCars->getCurrentCar()->setCurrentDiagnosticsIndex(i);
            application().gotoFunctionSelectionScreenNoTransition();
        }
    }
}


void ECUsView::action_Back()
{
    if (pCars->automaticallyScan) {
        application().gotoAutomaticSearchScreenNoTransition();
    }
    else {
        application().gotoFunctionSelectionScreenNoTransition();
    }
}
