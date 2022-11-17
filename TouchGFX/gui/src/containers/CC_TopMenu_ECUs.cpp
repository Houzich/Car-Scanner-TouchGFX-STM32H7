#include <gui/containers/CC_TopMenu_ECUs.hpp>

CC_TopMenu_ECUs::CC_TopMenu_ECUs()
{

}

void CC_TopMenu_ECUs::initialize()
{
    CC_TopMenu_ECUsBase::initialize();
}


void CC_TopMenu_ECUs::setPath(const Unicode::UnicodeChar* value)
{
    textArea_Path.setWildcard(value);
    textArea_Path.invalidate();
}