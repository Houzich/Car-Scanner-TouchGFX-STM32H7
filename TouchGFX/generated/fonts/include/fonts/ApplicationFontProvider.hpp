/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId LARGE = 1;
    static const touchgfx::FontId SMALL = 2;
    static const touchgfx::FontId KEYBOARD = 3;
    static const touchgfx::FontId DISPLAY = 4;
    static const touchgfx::FontId WIFI_LARGE = 5;
    static const touchgfx::FontId WIFI_DEFAULT = 6;
    static const touchgfx::FontId DATA = 7;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0;      // calibri_20_4bpp
    static const touchgfx::FontId LARGE = 1;        // calibri_40_4bpp
    static const touchgfx::FontId SMALL = 2;        // calibri_10_4bpp
    static const touchgfx::FontId KEYBOARD = 3;     // calibri_34_4bpp
    static const touchgfx::FontId DISPLAY = 4;      // calibri_56_4bpp
    static const touchgfx::FontId WIFI_LARGE = 5;   // ariblk_25_4bpp
    static const touchgfx::FontId WIFI_DEFAULT = 6; // arial_20_4bpp
    static const touchgfx::FontId DATA = 7;         // arialbd_30_4bpp
    static const uint16_t NUMBER_OF_FONTS = 8;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /* flashReader */)
    {
    }
    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP