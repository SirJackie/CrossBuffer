#include <stdio.h>
#include "SDLHelper.h"
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "../Main.h"

// LinuxSimuLayer Variables and Declarations
LSM_SDLHelper sdlHelper;
bool quit = false;
SDL_Event e;

// CrossBufferLayer Variables
CS_FrameBuffer fb;
CS_Keyboard    kb;

// Time Counting Variables
csbool FirstTimeRunning;
clock_t lastTime;
clock_t thisTime;




/*
** Main Function
*/

int main( int argc, char* args[] )
{
    // sdlHelper = LSM_SDLHelper();
    sdlHelper.CreateWindow((const i8*)"Test");

    // While it's not the time to quit
    while(!quit)
    {
        /* Process the Message Queue */
        while(SDL_PollEvent(&e) != 0)
        {
            // If exit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }

            // If key pressed
            if( e.type == SDL_KEYDOWN )
            {
                e.key.keysym.sym;
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
            Setup(fb, kb, 0);                     // Call the Setup()  in Main.h
            FirstTimeRunning = csFalse;
        }

        // If it is not the First Time Running
        else {
            Update(fb, kb, thisTime - lastTime);  // Call the Update() in Main.h
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