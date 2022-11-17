#include <platform/hal/simulator/sdl2/HALSDL2.hpp>
#include <touchgfx/hal/NoDMA.hpp>
#include <common/TouchGFXInit.hpp>
#include <gui_generated/common/SimConstants.hpp>
#include <platform/driver/touch/SDL2TouchController.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <stdlib.h>
#include <simulator/mainBase.hpp>
#include <iostream>

//T_RESOURCEIDVALUELEFT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_shape.h>
#include <SDL2/SDL_syswm.h>

#include "../App/App.hpp"
#include "Test_CSV.h"

static int wifiThreadFunc(void* ptr);

//#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
//#define CANVAS_BUFFER_SIZE (3600)

using namespace touchgfx;

//#ifdef WIN32
//char string[2048];
//#define printf(...)  sprintf_s(string, sizeof(string), __VA_ARGS__);  OutputDebugString(string);
//#endif

PassengerCarsClass Cars;

#ifdef __linux__
int main(int argc, char** argv)
{
#else
#include <shellapi.h>
#ifdef _UNICODE
#error Cannot run in unicode mode
#endif
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int argc;
    char** argv = touchgfx::HALSDL2::getArgv(&argc);
#endif

    touchgfx::NoDMA dma; //For windows/linux, DMA transfers are simulated
    LCD& lcd = setupLCD();
    touchgfx::SDL2TouchController tc;

    touchgfx::HAL& hal = touchgfx::touchgfx_generic_init<touchgfx::HALSDL2>(dma, lcd, tc, SIM_WIDTH, SIM_HEIGHT, 0, 0);

    setupSimulator(argc, argv, hal);

    // Ensure there is a console window to print to using printf() or
    // std::cout, and read from using e.g. fgets or std::cin.
    // Alternatively, instead of using printf(), always use
    // touchgfx_printf() which will ensure there is a console to write
    // to.
    touchgfx_enable_stdio();

    // Setup the CanvasWidgetRenderer. ONLY needed if you use CanvasWidgets
    // in your application. The CANVAS_BUFFER_SIZE can be adjusted to match
    // your needs in performance vs. RAM usage. Read more on this in the
    // TouchGFX Manual.
    //static uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
    //touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    //pFrameError = new CC_FrameError[DIAGNOSTICS_NUM_MAX];
    
    //FILE* fp;
    //AllocConsole();
    //fp = freopen("CONIN$", "r", stdin);
    //fp = freopen("CONOUT$", "w", stdout);
    //fp = freopen("CONOUT$", "w", stderr);
    //fclose(fp);

    Parse_Test_CSV();

    pCars = &Cars;
    pFramesData = new CC_FrameData[NUMBER_FRAMEDATA_MAX];
    pFramesSelect = new CC_FrameSelect[NUMBER_FRAMESELECT_MAX];
    pFramesError = new CC_FrameError[NUMBER_FRAMEERROR_MAX];


    touchgfx_printf("Size PassengerCarsClass: %d\n", sizeof(PassengerCarsClass));
    touchgfx_printf("Size CarBrandClass: %d, num: %d\n", sizeof(CarBrandClass), pCars->getBrandsLen());
    touchgfx_printf("Size ModelYearClass: %d, num: %d\n", sizeof(ModelYearClass), pCars->getModelYearLen());
    touchgfx_printf("Size ModelSeriesClass: %d, num: %d\n", sizeof(ModelSeriesClass), pCars->getModelSeriesLen());
    touchgfx_printf("Size CarClass: %d, num: %d\n", sizeof(CarClass), pCars->getCarLen());
    touchgfx_printf("Size DiagnosticsClass: %d, num: %d\n", sizeof(DiagnosticsClass), pCars->getDiagnosticsLen());
    
    WIFI_Init();
    App_Init();
    SDL_Thread* wifi_thread = SDL_CreateThread(wifiThreadFunc, "wifiThread", (void*)NULL);
    assert(wifi_thread);


    touchgfx::HAL::getInstance()->taskEntry(); //Never returns

    return EXIT_SUCCESS;
}



static int wifiThreadFunc(void* ptr)
{
    //FrameBufferAllocator* fbAllocator = HAL::getInstance()->getFrameBufferAllocator();
    //Bitmap::BitmapFormat framebufferFormat = HAL::getInstance()->lcd().framebufferFormat();
    while (1)
    {
        Sleep(5000);
        ////wait for blocks to transfer
        //SDL_SemWait(sem_transfer_ready);

        //while (fbAllocator->hasBlockReadyForTransfer())
        //{
        //    Rect transfer_rect;
        //    const uint8_t* src = fbAllocator->getBlockForTransfer(transfer_rect);
        //    // touchgfx_printf("transfer: (%d,%d w%d,h%d)\n", transfer_rect.x, transfer_rect.y, transfer_rect.width, transfer_rect.height);

        //    fbAllocator->freeBlockAfterTransfer();
        //}

        ////signal drawing part
        //if (SDL_SemValue(sem_transfer_done) == 0)
        //{
        //    SDL_SemPost(sem_transfer_done);
        //}
    }
}







