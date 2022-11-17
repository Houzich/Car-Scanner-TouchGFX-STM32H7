#ifndef CC_CARITEMSCROLLLIST_HPP
#define CC_CARITEMSCROLLLIST_HPP

#include <gui_generated/containers/CC_CarItemScrollListBase.hpp>

class CC_CarItemScrollList : public CC_CarItemScrollListBase
{
public:
    CC_CarItemScrollList();
    virtual ~CC_CarItemScrollList() {}

    virtual void initialize();
    void textArea1_setWildcard(const Unicode::UnicodeChar* value);
protected:
};

#endif // CC_CARITEMSCROLLLIST_HPP
