#ifndef AUTOMATICSEARCHVIEW_HPP
#define AUTOMATICSEARCHVIEW_HPP

#include <gui_generated/automaticsearch_screen/AutomaticSearchViewBase.hpp>
#include <gui/automaticsearch_screen/AutomaticSearchPresenter.hpp>

using namespace Data;

class AutomaticSearchView : public AutomaticSearchViewBase
{
public:
    AutomaticSearchView();
    virtual ~AutomaticSearchView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    /*
 * Custom Actions
 */
    virtual void action_Automatically_Click();
    virtual void action_Manually_Click();
    virtual void action_Back_Click();

protected:
};

#endif // AUTOMATICSEARCHVIEW_HPP
