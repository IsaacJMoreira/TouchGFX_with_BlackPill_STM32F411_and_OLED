#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    virtual ~MainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    uint16_t tick = 0, FPScounter = 0, step = 1, prevTick = 0, currentTick = 0;

        virtual void handleTickEvent()
        {
           tick++;
           if(currentTick < prevTick){
        	   tick = 65535 - prevTick;
        	   prevTick = 0;
           }
           currentTick = tick;
           if(currentTick - prevTick >= 6){
        	   FPScounter += step;
        	   step = (FPScounter < 1 || FPScounter > 254)? -step : step;
        	   prevTick = currentTick;
           }

           Unicode::snprintf(FPSBuffer, FPS_SIZE, "%d", FPScounter);
           FPS.invalidate();
        }

protected:
};

#endif // MAINSCREENVIEW_HPP
