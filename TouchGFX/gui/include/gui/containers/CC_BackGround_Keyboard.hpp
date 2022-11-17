#ifndef CC_BACKGROUND_KEYBOARD_HPP
#define CC_BACKGROUND_KEYBOARD_HPP

#include <gui_generated/containers/CC_BackGround_KeyboardBase.hpp>

class CC_BackGround_Keyboard : public CC_BackGround_KeyboardBase
{
public:
    CC_BackGround_Keyboard();
    virtual ~CC_BackGround_Keyboard() {}

    virtual void initialize();
protected:
};

#endif // CC_BACKGROUND_KEYBOARD_HPP
