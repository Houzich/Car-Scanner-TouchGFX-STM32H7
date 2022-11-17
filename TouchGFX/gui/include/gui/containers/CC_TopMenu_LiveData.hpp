#ifndef CC_TOPMENU_LIVEDATA_HPP
#define CC_TOPMENU_LIVEDATA_HPP

#include <gui_generated/containers/CC_TopMenu_LiveDataBase.hpp>

class CC_TopMenu_LiveData : public CC_TopMenu_LiveDataBase
{
public:
    CC_TopMenu_LiveData();
    virtual ~CC_TopMenu_LiveData() {}

    virtual void initialize();
protected:
};

#endif // CC_TOPMENU_LIVEDATA_HPP
