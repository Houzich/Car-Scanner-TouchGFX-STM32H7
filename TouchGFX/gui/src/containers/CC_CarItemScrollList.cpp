#include <gui/containers/CC_CarItemScrollList.hpp>

CC_CarItemScrollList::CC_CarItemScrollList()
{

}

void CC_CarItemScrollList::initialize()
{
    CC_CarItemScrollListBase::initialize();
}



void CC_CarItemScrollList::textArea1_setWildcard(const Unicode::UnicodeChar* value)
{
    textArea1.setWildcard(value);
    textArea1.invalidate();
}

