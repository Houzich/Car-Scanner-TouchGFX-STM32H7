#include <gui/containers/CC_scrollableContainer.hpp>

CC_scrollableContainer::CC_scrollableContainer()
{

}

void CC_scrollableContainer::initialize()
{
    CC_scrollableContainerBase::initialize();
}

void CC_scrollableContainer::scrollableContainer_Main_add(Drawable& d)
{
	listLayout_Main.add(d);
}

void CC_scrollableContainer::scrollableContainer_Invalidate_List()
{
	scrollableContainer_Main.invalidate();
}
