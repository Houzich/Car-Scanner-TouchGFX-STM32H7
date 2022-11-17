#include <gui/carbrands_screen/CarBrandsView.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"


CarBrandsView::CarBrandsView() : CarBrandsButtonCallback(this, &CarBrandsView::CarBrandsButtonCallbackHandler)
{
    int row1_position = 0;
    int row2_position = 0;
    for (uint32_t i = 0; i < DATA_NUM_BRANDS; i++) {
        flexButton[i].setBoxWithBorderPosition(0, 0, CARBRANDS_FLEXBUTTON_WIDTH, CARBRANDS_FLEXBUTTON_HEIGHT);
        flexButton[i].setBorderSize(5);
        flexButton[i].setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(0, 102, 153), touchgfx::Color::getColorFrom24BitRGB(0, 153, 204), touchgfx::Color::getColorFrom24BitRGB(0, 51, 102), touchgfx::Color::getColorFrom24BitRGB(51, 102, 153));
        if (i % 2 == 0) {
            flexButton[i].setPosition(row1_position, 0, CARBRANDS_FLEXBUTTON_WIDTH, CARBRANDS_FLEXBUTTON_HEIGHT);
            row1_position += CARBRANDS_FLEXBUTTON_WIDTH;
        }
        else
        {
            flexButton[i].setPosition(row2_position, CARBRANDS_FLEXBUTTON_HEIGHT, CARBRANDS_FLEXBUTTON_WIDTH, CARBRANDS_FLEXBUTTON_HEIGHT);
            row2_position += CARBRANDS_FLEXBUTTON_WIDTH;
        }

        flexButton[i].setAlpha(0);

        //flexButton1.setBitmaps(Bitmap(BITMAP_BUTON4_ID), Bitmap(BITMAP_BUTON4_ID));
        //flexButton1.setBitmapXY(0, 0);
        // 
        //CarBrandsButtonCallback = touchgfx::Callback(this, &CarBrandsView::CarBrandsButtonCallbackHandler);
        flexButton[i].setAction(CarBrandsButtonCallback);
        scrollableContainer1.add(flexButton[i]);
    }

}

void CarBrandsView::setupScreen()
{
    CarBrandsViewBase::setupScreen();
}

void CarBrandsView::tearDownScreen()
{
    CarBrandsViewBase::tearDownScreen();
}

void CarBrandsView::CarBrandsButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    for (uint32_t i = 0; i < DATA_NUM_BRANDS; i++) {
        if (&src == &flexButton[i])
        {
            pCars->setCurrentBrandIndex(i);
            //When flexButton clicked change screen to AutomaticSearch
            //Go to AutomaticSearch with no screen transition
            application().gotoAutomaticSearchScreenNoTransition();
        }
    }
}


void CarBrandsView::action_Back_Click()
{

}
