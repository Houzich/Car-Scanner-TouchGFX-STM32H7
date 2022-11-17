#include <gui/modelseries_screen/ModelSeriesView.hpp>


ModelSeriesView::ModelSeriesView() :SelectButtonCallback(this, &ModelSeriesView::SelectButtonCallbackHandler)
{
	ModelYearClass* modelyear = pCars->getCurrentModelYear();
	new (pFramesSelect)CC_FrameSelect[NUMBER_FRAMESELECT_MAX];
	for (int i = 0; i < modelyear->getModelSeriesLen(); i++)
	{
		CC_FrameSelect* frame = &pFramesSelect[i];
		//frame = new CC_FrameSelect();
		frame->initialize();
		frame->setXY(0, i * frame->getHeight() + 3 * i);
		frame->flexButton_Main_Name_setWildcard(modelyear->getModelSeries(i)->getName());
		frame->flexButton_Main_setAction(SelectButtonCallback);
		//frame->invalidate();
		cC_scrollableContainer1.scrollableContainer_Main_add(pFramesSelect[i]);
	}
	ScreenPath.sprintf_curr_path(Data::CURRENT_STATE_PAGE::MODEL_SERIES, pCars);
	cC_TopMenu1.textArea_Path_setWildcard(ScreenPath.disp_path);
}

void ModelSeriesView::setupScreen()
{
    ModelSeriesViewBase::setupScreen();
}

void ModelSeriesView::tearDownScreen()
{
    ModelSeriesViewBase::tearDownScreen();
}

void ModelSeriesView::SelectButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
	ModelYearClass* modelyear = pCars->getCurrentModelYear();
	for (int i = 0; i < modelyear->getModelSeriesLen(); i++)
	{
		CC_FrameSelect* frame = &pFramesSelect[i];
		if (frame == src.getParent())
		{
			modelyear->setCurrentModelSeriesIndex(i);
			application().gotoModelNumberScreenNoTransition();
		}
	}
}

void ModelSeriesView::action_Back_Click()
{
}

