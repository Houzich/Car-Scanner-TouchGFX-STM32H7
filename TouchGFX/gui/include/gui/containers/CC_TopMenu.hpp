#ifndef CC_TOPMENU_HPP
#define CC_TOPMENU_HPP

#include <gui_generated/containers/CC_TopMenuBase.hpp>

class CC_TopMenu : public CC_TopMenuBase
{
public:
    CC_TopMenu();
    virtual ~CC_TopMenu() {}

    virtual void initialize();

    void textArea_Path_setWildcard(const Unicode::UnicodeChar* value);


protected:
};

#endif // CC_TOPMENU_HPP
