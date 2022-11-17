#ifndef ECUS_VIEW_HPP
#define ECUS_VIEW_HPP

#include <gui_generated/ecus_screen/ECUsViewBase.hpp>
#include <gui/ecus_screen/ECUsPresenter.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>


class ECUsView : public ECUsViewBase
{
public:
    ECUsView();
    virtual ~ECUsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    /*
* Custom Actions
*/
    virtual void action_Back();
private:
    /*
     * Callback Declarations
     */
    touchgfx::Callback<ECUsView, const touchgfx::AbstractButtonContainer&> ECUsButtonCallback;
    /*
     * Callback Handler Declarations
     */
    void ECUsButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

protected:
};

#endif // ECUS_VIEW_HPP
