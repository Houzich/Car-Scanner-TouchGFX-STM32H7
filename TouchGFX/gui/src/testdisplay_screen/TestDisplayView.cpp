#include <gui/testdisplay_screen/TestDisplayView.hpp>
#include <touchgfx/Color.hpp>

TestDisplayView::TestDisplayView()
{

}

void TestDisplayView::setupScreen()
{
    TestDisplayViewBase::setupScreen();
}

void TestDisplayView::tearDownScreen()
{
    TestDisplayViewBase::tearDownScreen();
}

#define TEST_DISPLAY_BACKGROUND_COLOR 255 
void TestDisplayView::handleClickEvent(const ClickEvent& evt)
{
    //WiFiConnectingViewBase::handleClickEvent(evt);
    static int color_num = 0;
    static int color_type = 0;
    uint8_t red, green, blue;
    
    if ((color_num >= 0) && (color_num < 8)) 
    {
        color_type = 0;
        red = 1 << color_num;
        green = TEST_DISPLAY_BACKGROUND_COLOR;
        blue = TEST_DISPLAY_BACKGROUND_COLOR;
    }
    if ((color_num >= 8) && (color_num < 16))
    {
        color_type = 1;
        green = 1 << (color_num - 8);
        red = TEST_DISPLAY_BACKGROUND_COLOR;
        blue = TEST_DISPLAY_BACKGROUND_COLOR;
    }
    if ((color_num >= 16) && (color_num < 24))
    {
        color_type = 2;
        blue = 1 << (color_num - 16);
        red = TEST_DISPLAY_BACKGROUND_COLOR;
        green = TEST_DISPLAY_BACKGROUND_COLOR;
    }

    if (evt.getType() == ClickEvent::RELEASED)
    {
        if(color_type == 0)
            Unicode::snprintf(textArea_Info_ColorBuffer, TEXTAREA_INFO_COLOR_SIZE, "Red num %d", (color_num + 1));
        if (color_type == 1)
            Unicode::snprintf(textArea_Info_ColorBuffer, TEXTAREA_INFO_COLOR_SIZE, "Green num %d", ((color_num + 1) - 8));
        if (color_type == 2)
            Unicode::snprintf(textArea_Info_ColorBuffer, TEXTAREA_INFO_COLOR_SIZE, "Blue num %d", ((color_num + 1) - 16));

        textArea_Info_Color.setWildcard(textArea_Info_ColorBuffer);
        box_Color.setColor(touchgfx::Color::getColorFromRGB(red, green, blue));
        textArea_Info_Color.invalidate();
        box_Color.invalidate();
        color_num++;
        if (color_num == 24) color_num = 0;
    }
    else if (evt.getType() == ClickEvent::PRESSED)
    {

        box_Color.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        box_Color.invalidate();
    }

}
