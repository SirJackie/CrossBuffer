#include <stdio.h>
#include "SDLHelper.h"
#include "KeyboardHelper.h"
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "../Main.h"

// LinuxSimuLayer Variables and Declarations
LSL_SDLHelper       sdlHelper;
LSL_KeyboardHelper  keyboardHelper;
CS_Mouse            mouse;
bool quit = false;
SDL_Event e;

// CrossBufferLayer Variables
CS_FrameBuffer fb;

// Time Counting Variables
csbool FirstTimeRunning;
clock_t lastTime;
clock_t thisTime;

i32 mouseX,mouseY;
csbool lBtnState = csFalse, mBtnState = csFalse, rBtnState = csFalse;




/*
** Main Function
*/

int main( int argc, char* args[] )
{
    // sdlHelper = LSL_SDLHelper();
    sdlHelper.CreateWindow(WindowTitle);

    // While it's not the time to quit
    while(!quit)
    {
        /* Process the Message Queue */
        while(SDL_PollEvent(&e) != 0)
        {
            // If exit
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }

            // If key pressed
            if(e.type == SDL_KEYDOWN)
            {
                int keycode = e.key.keysym.sym;
                if(keycode > 1073740000) keycode -= 1073740000;
                keyboardHelper.linuxKeyBuffer[keycode] = 1;
                keyboardHelper.MoveLnxBufIntoKeyBuf();
            }
            
            // If key released
            if(e.type == SDL_KEYUP){
                int keycode = e.key.keysym.sym;
                if(keycode > 1073740000) keycode -= 1073740000;
                keyboardHelper.linuxKeyBuffer[keycode] = 0;
                keyboardHelper.MoveLnxBufIntoKeyBuf();
            }

            // If mouse moved
            else if (SDL_MOUSEMOTION == e.type)
			{
                mouse.x = e.motion.x;
				mouse.y = e.motion.y;
            }

            if (SDL_MOUSEBUTTONDOWN == e.type) 
            {
                if(SDL_BUTTON_LEFT == e.button.button)
                {
                    lBtnState = csTrue;
                }
                else if(SDL_BUTTON_MIDDLE == e.button.button)
                {
                    mBtnState = csTrue;
                }
                else if(SDL_BUTTON_RIGHT == e.button.button)
                {
                    rBtnState = csTrue;
                }
            }

            if (SDL_MOUSEBUTTONUP == e.type) 
            {
                if(SDL_BUTTON_LEFT == e.button.button)
                {
                    lBtnState = csFalse;
                }
                else if(SDL_BUTTON_MIDDLE == e.button.button)
                {
                    mBtnState = csFalse;
                }
                else if(SDL_BUTTON_RIGHT == e.button.button)
                {
                    rBtnState = csFalse;
                }
            }
        }

        /* Process our Game Loop */
        // Update Time Counting Variables
        thisTime = clock();

        // Lock Surface
        sdlHelper.LockSurface();

        fb = CS_FrameBuffer
        (
            sdlHelper.windowWidth, sdlHelper.windowHeight
        );

        // If it is the First Time Running
        if (FirstTimeRunning) {
            Setup (fb, keyboardHelper.kb, mouse, 0);                     // Call the Setup()  in Main.h
            FirstTimeRunning = csFalse;
        }

        // If it is not the First Time Running
        else {
            Update(fb, keyboardHelper.kb, mouse, (thisTime - lastTime) / 1000);  // Call the Update() in Main.h
        }

        // Paint FrameBuffer on SDL Surface
        sdlHelper.PaintFrameBufferHere(fb);

        // Unlock Surface
        sdlHelper.UnlockSurface();

        // Update Time Counting Variables
        // lastTime in next frame = thisTime in this frame
        lastTime = thisTime;
    }

    // After Main Loop
    sdlHelper.Close();

    return 0;
}