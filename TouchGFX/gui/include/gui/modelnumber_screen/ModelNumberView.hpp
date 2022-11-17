#ifndef MODELNUMBERVIEW_HPP
#define MODELNUMBERVIEW_HPP

#include <gui_generated/modelnumber_screen/ModelNumberViewBase.hpp>
#include <gui/modelnumber_screen/ModelNumberPresenter.hpp>


class ModelNumberView : public ModelNumberViewBase
{
public:
    ModelNumberView();
    virtual ~ModelNumberView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    /*
 * Custom Actions
 */
    virtual void action_Back_Click();
protected:

private:

    /*
 * Callback Declarations
 */
    touchgfx::Callback<ModelNumberView, const touchgfx::AbstractButtonContainer&> SelectButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void SelectButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // MODELNUMBERVIEW_HPP
