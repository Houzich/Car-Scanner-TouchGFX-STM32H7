#ifndef MODELYEARVIEW_HPP
#define MODELYEARVIEW_HPP

#include <gui_generated/modelyear_screen/ModelYearViewBase.hpp>
#include <gui/modelyear_screen/ModelYearPresenter.hpp>


class ModelYearView : public ModelYearViewBase
{
public:
    ModelYearView();
    virtual ~ModelYearView() {}
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
    touchgfx::Callback<ModelYearView, const touchgfx::AbstractButtonContainer&> SelectButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void SelectButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // MODELYEARVIEW_HPP
