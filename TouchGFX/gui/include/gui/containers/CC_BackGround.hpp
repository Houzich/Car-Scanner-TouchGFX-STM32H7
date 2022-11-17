#ifndef CC_BACKGROUND_HPP
#define CC_BACKGROUND_HPP

#include <gui_generated/containers/CC_BackGroundBase.hpp>

class CC_BackGround : public CC_BackGroundBase
{
public:
    CC_BackGround();
    virtual ~CC_BackGround() {}

    virtual void initialize();
protected:
};

#endif // CC_BACKGROUND_HPP
