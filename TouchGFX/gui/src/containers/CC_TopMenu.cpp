#include <gui/containers/CC_TopMenu.hpp>

CC_TopMenu::CC_TopMenu()
{

}

void CC_TopMenu::initialize()
{
    CC_TopMenuBase::initialize();
}


void CC_TopMenu::textArea_Path_setWildcard(const Unicode::UnicodeChar* value)
{
    textArea_Path.setWildcard(value);
    textArea_Path.invalidate();
}

