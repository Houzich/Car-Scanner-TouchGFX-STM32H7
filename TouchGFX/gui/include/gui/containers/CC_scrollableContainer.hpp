#ifndef CC_SCROLLABLECONTAINER_HPP
#define CC_SCROLLABLECONTAINER_HPP

#include <gui_generated/containers/CC_scrollableContainerBase.hpp>

class CC_scrollableContainer : public CC_scrollableContainerBase
{
public:
    CC_scrollableContainer();
    virtual ~CC_scrollableContainer() {}

    virtual void initialize();

    void scrollableContainer_Main_add(Drawable& d);
    void scrollableContainer_Invalidate_List();
protected:
};

#endif // CC_SCROLLABLECONTAINER_HPP
