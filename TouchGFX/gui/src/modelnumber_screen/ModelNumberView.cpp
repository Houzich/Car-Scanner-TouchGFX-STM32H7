#include <gui/modelnumber_screen/ModelNumberView.hpp>



ModelNumberView::ModelNumberView() :SelectButtonCallback(this, &ModelNumberView::SelectButtonCallbackHandler)
{
	ModelSeriesClass* modelseries = pCars->getCurrentModelSeries();
	new (pFramesSelect)CC_FrameSelect[NUMBER_FRAMESELECT_MAX];
	for (int i = 0; i < modelseries->getCarsLen(); i++)
	{
		CC_FrameSelect* frame = &pFramesSelect[i];
		frame->initialize();
		frame->setXY(0, i * frame->getHeight() + 3 * i);
		frame->flexButton_Main_Name_setWildcard(modelseries->getCar(i)->getName());
		frame->flexButton_Main_setAction(SelectButtonCallback);
		//frame->invalidate();
		cC_scrollableContainer1.scrollableContainer_Main_add(*frame);
	}
	cC_TopMenu1.textArea_Path_setWildcard(ScreenPath.disp_path);
}

void ModelNumberView::setupScreen()
{
    ModelNumberViewBase::setupScreen();
}

void ModelNumberView::tearDownScreen()
{
    ModelNumberViewBase::tearDownScreen();
}

void ModelNumberView::SelectButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
	ModelSeriesClass* modelseries = pCars->getCurrentModelSeries();
	for (int i = 0; i < modelseries->getCarsLen(); i++)
	{
		CC_FrameSelect* frame = &pFramesSelect[i];
		if (frame == src.getParent())
		{
			modelseries->setCurrentCarIndex(i);
			application().gotoFunctionSelectionScreenNoTransition();
		}
	}
}
void ModelNumberView::action_Back_Click()
{
}
