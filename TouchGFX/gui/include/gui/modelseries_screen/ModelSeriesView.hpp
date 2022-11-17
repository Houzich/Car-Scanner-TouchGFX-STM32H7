#ifndef MODELSERIESVIEW_HPP
#define MODELSERIESVIEW_HPP

#include <gui_generated/modelseries_screen/ModelSeriesViewBase.hpp>
#include <gui/modelseries_screen/ModelSeriesPresenter.hpp>


class ModelSeriesView : public ModelSeriesViewBase
{
public:
    ModelSeriesView();
    virtual ~ModelSeriesView() {}
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
    touchgfx::Callback<ModelSeriesView, const touchgfx::AbstractButtonContainer&> SelectButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void SelectButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
};

#endif // MODELSERIESVIEW_HPP
