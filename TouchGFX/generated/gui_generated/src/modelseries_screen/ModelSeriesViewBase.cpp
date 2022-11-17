/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/modelseries_screen/ModelSeriesViewBase.hpp>
#include <touchgfx/Color.hpp>

ModelSeriesViewBase::ModelSeriesViewBase() :
    cC_LeftMenu1Trigger_BackCallback(this, &ModelSeriesViewBase::cC_LeftMenu1Trigger_BackCallbackHandler)
{

    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    cC_LeftMenu1.setXY(0, 0);
    cC_LeftMenu1.setTrigger_BackCallback(cC_LeftMenu1Trigger_BackCallback);
    cC_LeftMenu1.setTrigger_BackCallback(cC_LeftMenu1Trigger_BackCallback);

    cC_scrollableContainer1.setXY(100, 80);

    cC_TopMenu1.setXY(81, 0);

    add(__background);
    add(cC_LeftMenu1);
    add(cC_scrollableContainer1);
    add(cC_TopMenu1);
}

void ModelSeriesViewBase::setupScreen()
{
    cC_LeftMenu1.initialize();
    cC_scrollableContainer1.initialize();
    cC_TopMenu1.initialize();
}

void ModelSeriesViewBase::cC_LeftMenu1Trigger_BackCallbackHandler()
{
    //Interaction_Button_Back_Clicked
    //When cC_LeftMenu1 trigger_Back change screen to ModelYear
    //Go to ModelYear with no screen transition
    application().gotoModelYearScreenNoTransition();

    //Interaction_Action_Back_Clicked
    //When cC_LeftMenu1 trigger_Back call action_Back_Click on ModelSeries
    //Call action_Back_Click
    action_Back_Click();
}

void ModelSeriesViewBase::action_Back_Click()
{

}