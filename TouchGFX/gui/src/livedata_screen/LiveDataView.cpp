#include <gui/livedata_screen/LiveDataView.hpp>






LiveDataView::LiveDataView()
{

}




void LiveDataView::setupScreen()
{
	LiveDataViewBase::setupScreen();
	CarClass* car = pCars->getCurrentCar();
	DiagnosticsClass* diagnostics = car->getCurrentDiagnostics();
	DiagnosticsDataClass* data = diagnostics->getData();
	new (pFramesData)CC_FrameData[NUMBER_FRAMEDATA_MAX];
	for (int i = 0; i < diagnostics->getLenData(); i++)
	{
		CC_FrameData* frame = &pFramesData[i];
		frame->initialize();
		//frame->setXY(0, i * frame->getHeight() + 3 * i);
		frame->textArea_Name_setWildcard(data[i].getName());
		if (data[i].error)
			frame->box_Err_setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
		else
			frame->box_Err_setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		frame->box_Err_setAlpha(100);
		Unicode::snprintfFloat(frame->getTextArea_ValueBuffer(), frame->getTextArea_ValueBufferSize(), "%3.2f%%", data[i].getValue());
		frame->textArea_Value_Invalidate();
		//frame->invalidate();
		listLayout_Main.add(*frame);
		//scrollableContainer1.add(*frame);
	}
	scrollableContainer1.invalidate();
}

void LiveDataView::tearDownScreen()
{
	LiveDataViewBase::tearDownScreen();
}
