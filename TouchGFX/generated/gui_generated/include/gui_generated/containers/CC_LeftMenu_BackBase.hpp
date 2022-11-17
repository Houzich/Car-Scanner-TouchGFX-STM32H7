/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CC_LEFTMENU_BACKBASE_HPP
#define CC_LEFTMENU_BACKBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>

class CC_LeftMenu_BackBase : public touchgfx::Container
{
public:
    CC_LeftMenu_BackBase();
    virtual ~CC_LeftMenu_BackBase() {}
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setTrigger_BackCallback(touchgfx::GenericCallback<>& callback)
    {
        this->trigger_BackCallback = &callback;
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitTrigger_BackCallback()
    {
        if (trigger_BackCallback && trigger_BackCallback->isValid())
        {
            this->trigger_BackCallback->execute();
        }
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::Button button_Back;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<CC_LeftMenu_BackBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<>* trigger_BackCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // CC_LEFTMENU_BACKBASE_HPP
