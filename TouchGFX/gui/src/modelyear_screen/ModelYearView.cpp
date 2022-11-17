#include <gui/modelyear_screen/ModelYearView.hpp>



ModelYearView::ModelYearView():SelectButtonCallback(this, &ModelYearView::SelectButtonCallbackHandler)
{
	CarBrandClass* carbrand = pCars->getCurrentBrand();
	new (pFramesSelect)CC_FrameSelect[NUMBER_FRAMESELECT_MAX];
	for (int i = 0; i < carbrand->getModelYearsLen(); i++)
	{
		CC_FrameSelect* frame = &pFramesSelect[i];
		frame->initialize();
		frame->setXY(0, i * frame->getHeight() + 3 * i);
		frame->flexButton_Main_Name_setWildcard(carbrand->getModelYear(i)->getName());
		frame->flexButton_Main_setAction(SelectButtonCallback);
		//frame->invalidate();
		cC_scrollableContainer1.scrollableContainer_Main_add(*frame);
	}
	ScreenPath.sprintf_curr_path(Data::CURRENT_STATE_PAGE::MODEL_YEAR, pCars);
	cC_TopMenu1.textArea_Path_setWildcard(ScreenPath.disp_path);
}

void ModelYearView::setupScreen()
{
    ModelYearViewBase::setupScreen();
}

void ModelYearView::tearDownScreen()
{
    ModelYearViewBase::tearDownScreen();
}


void ModelYearView::SelectButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
	CarBrandClass* carbrand = pCars->getCurrentBrand();
	for (int i = 0; i < carbrand->getModelYearsLen(); i++) {
		CC_FrameSelect* frame = &pFramesSelect[i];
		if (frame == src.getParent())
		{
			carbrand->setCurrentModelYearIndex(i);
			application().gotoModelSeriesScreenNoTransition();
		}
	}
}

void ModelYearView::action_Back_Click()
{

}
