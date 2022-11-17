/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDHEAPBASE_HPP
#define FRONTENDHEAPBASE_HPP

#include <common/Meta.hpp>
#include <common/Partition.hpp>
#include <mvp/MVPHeap.hpp>

#include <touchgfx/transitions/NoTransition.hpp>
#include <touchgfx/transitions/SlideTransition.hpp>

#include <gui/common/FrontendApplication.hpp>
#include <gui/model/Model.hpp>

#include <gui/ecus_screen/ECUsView.hpp>
#include <gui/ecus_screen/ECUsPresenter.hpp>
#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <gui/carbrands_screen/CarBrandsView.hpp>
#include <gui/carbrands_screen/CarBrandsPresenter.hpp>
#include <gui/functionselection_screen/FunctionSelectionView.hpp>
#include <gui/functionselection_screen/FunctionSelectionPresenter.hpp>
#include <gui/livedata_screen/LiveDataView.hpp>
#include <gui/livedata_screen/LiveDataPresenter.hpp>
#include <gui/automaticsearch_screen/AutomaticSearchView.hpp>
#include <gui/automaticsearch_screen/AutomaticSearchPresenter.hpp>
#include <gui/waitingcar_screen/WaitingCarView.hpp>
#include <gui/waitingcar_screen/WaitingCarPresenter.hpp>
#include <gui/havefoundcar_screen/HaveFoundCarView.hpp>
#include <gui/havefoundcar_screen/HaveFoundCarPresenter.hpp>
#include <gui/waitingdata_screen/WaitingDataView.hpp>
#include <gui/waitingdata_screen/WaitingDataPresenter.hpp>
#include <gui/zostawka_screen/ZostawkaView.hpp>
#include <gui/zostawka_screen/ZostawkaPresenter.hpp>
#include <gui/modelyear_screen/ModelYearView.hpp>
#include <gui/modelyear_screen/ModelYearPresenter.hpp>
#include <gui/modelseries_screen/ModelSeriesView.hpp>
#include <gui/modelseries_screen/ModelSeriesPresenter.hpp>
#include <gui/modelnumber_screen/ModelNumberView.hpp>
#include <gui/modelnumber_screen/ModelNumberPresenter.hpp>
#include <gui/settings_screen/SettingsView.hpp>
#include <gui/settings_screen/SettingsPresenter.hpp>
#include <gui/wificonnecting_screen/WiFiConnectingView.hpp>
#include <gui/wificonnecting_screen/WiFiConnectingPresenter.hpp>
#include <gui/display_screen/DisplayView.hpp>
#include <gui/display_screen/DisplayPresenter.hpp>
#include <gui/testdisplay_screen/TestDisplayView.hpp>
#include <gui/testdisplay_screen/TestDisplayPresenter.hpp>


/**
 * This class provides the memory that shall be used for memory allocations
 * in the frontend. A single instance of the FrontendHeap is allocated once (in heap
 * memory), and all other frontend objects such as views, presenters and data model are
 * allocated within the scope of this FrontendHeap. As such, the RAM usage of the entire
 * user interface is sizeof(FrontendHeap).
 *
 * @note The FrontendHeap reserves memory for the most memory-consuming presenter and
 * view only. The largest of these classes are determined at compile-time using template
 * magic. As such, it is important to add all presenters, views and transitions to the
 * type lists in this class.
 *
 */
class FrontendHeapBase : public touchgfx::MVPHeap
{
public:
    /**
     * A list of all view types. Must end with meta::Nil.
     * @note All view types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< ECUsView,
            touchgfx::meta::TypeList< MainView,
            touchgfx::meta::TypeList< CarBrandsView,
            touchgfx::meta::TypeList< FunctionSelectionView,
            touchgfx::meta::TypeList< LiveDataView,
            touchgfx::meta::TypeList< AutomaticSearchView,
            touchgfx::meta::TypeList< WaitingCarView,
            touchgfx::meta::TypeList< HaveFoundCarView,
            touchgfx::meta::TypeList< WaitingDataView,
            touchgfx::meta::TypeList< ZostawkaView,
            touchgfx::meta::TypeList< ModelYearView,
            touchgfx::meta::TypeList< ModelSeriesView,
            touchgfx::meta::TypeList< ModelNumberView,
            touchgfx::meta::TypeList< SettingsView,
            touchgfx::meta::TypeList< WiFiConnectingView,
            touchgfx::meta::TypeList< DisplayView,
            touchgfx::meta::TypeList< TestDisplayView,
            touchgfx::meta::Nil > > > > > > > > > > > > > > > >
            > GeneratedViewTypes;

    /**
     * Determine (compile time) the View type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedViewTypes >::type MaxGeneratedViewType;

    /**
     * A list of all presenter types. Must end with meta::Nil.
     * @note All presenter types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< ECUsPresenter,
            touchgfx::meta::TypeList< MainPresenter,
            touchgfx::meta::TypeList< CarBrandsPresenter,
            touchgfx::meta::TypeList< FunctionSelectionPresenter,
            touchgfx::meta::TypeList< LiveDataPresenter,
            touchgfx::meta::TypeList< AutomaticSearchPresenter,
            touchgfx::meta::TypeList< WaitingCarPresenter,
            touchgfx::meta::TypeList< HaveFoundCarPresenter,
            touchgfx::meta::TypeList< WaitingDataPresenter,
            touchgfx::meta::TypeList< ZostawkaPresenter,
            touchgfx::meta::TypeList< ModelYearPresenter,
            touchgfx::meta::TypeList< ModelSeriesPresenter,
            touchgfx::meta::TypeList< ModelNumberPresenter,
            touchgfx::meta::TypeList< SettingsPresenter,
            touchgfx::meta::TypeList< WiFiConnectingPresenter,
            touchgfx::meta::TypeList< DisplayPresenter,
            touchgfx::meta::TypeList< TestDisplayPresenter,
            touchgfx::meta::Nil > > > > > > > > > > > > > > > >
            > GeneratedPresenterTypes;

    /**
     * Determine (compile time) the Presenter type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedPresenterTypes >::type MaxGeneratedPresenterType;

    /**
     * A list of all transition types. Must end with meta::Nil.
     * @note All transition types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< touchgfx::NoTransition,
            touchgfx::meta::TypeList< SlideTransition<EAST>,
            touchgfx::meta::Nil >
            > GeneratedTransitionTypes;

    /**
     * Determine (compile time) the Transition type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedTransitionTypes >::type MaxGeneratedTransitionType;

    virtual void gotoStartScreen(FrontendApplication& app)
    {
        app.gotoMainScreenNoTransition();
    }
protected:
    FrontendHeapBase(touchgfx::AbstractPartition& presenters, touchgfx::AbstractPartition& views, touchgfx::AbstractPartition& transitions, FrontendApplication& app)
        : MVPHeap(presenters, views, transitions, app)
    {

    }

};

#endif // FRONTENDHEAPBASE_HPP