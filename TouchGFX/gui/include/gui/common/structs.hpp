#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <touchgfx/Unicode.hpp>


struct wifiData
{
    touchgfx::Unicode::UnicodeChar ssid[32];
    touchgfx::Unicode::UnicodeChar encryption[30];
    int     signalStrength;
    int     id;
    bool    encrypted;
    bool    connected;
};

struct selectedWifi
{
    wifiData wifi;
    touchgfx::Unicode::UnicodeChar password[64];
};

#endif // STRUCTS_HPP
