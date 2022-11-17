#ifndef CC_TOPMENU_ECUS_HPP
#define CC_TOPMENU_ECUS_HPP

#include <gui_generated/containers/CC_TopMenu_ECUsBase.hpp>

class CC_TopMenu_ECUs : public CC_TopMenu_ECUsBase
{
public:
    CC_TopMenu_ECUs();
    virtual ~CC_TopMenu_ECUs() {}

    virtual void initialize();
    void setPath(const Unicode::UnicodeChar* value);
protected:
};

#endif // CC_TOPMENU_ECUS_HPP
