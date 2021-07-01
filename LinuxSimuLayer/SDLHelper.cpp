#include "SDLHelper.h"
#include <SDL.h>

LSM_SDLHelper::LSM_SDLHelper(){
    window = NULL;
    screenSurface = NULL;

    GetResolution();

    // Calculate Window Size
    unit = screenHeight / 30;

	windowHeight = 26 * unit;
	windowWidth = windowHeight / 9 * 16;

	leftMargin = (screenWidth - windowWidth) / 2;
	topMargin = (screenHeight - windowHeight) / 2;

    // Deepin Fix
    topMargin -= 50;
    if(topMargin <= 0){
        topMargin = 10;
    }
}

void LSM_SDLHelper::GetResolution(){
    // Make sure we have the right to get resolution (important!)
    system("sudo chmod 777 /dev/fb0");

    // Get Resolution using Framebuffer in Linux
    i32 fd;
    struct fb_var_screeninfo fb_var;
    fd = open("/dev/fb0",O_RDWR);
    ioctl(fd,FBIOGET_VSCREENINFO,&fb_var);
    screenWidth = fb_var.xres;
    screenHeight = fb_var.yres;
    i32 bpp = fb_var.bits_per_pixel;
    printf("Framebuffer %d * %d - %dbpp\n", screenWidth, screenHeight, bpp);
}

i32 LSM_SDLHelper::getWcharLen(const i32* wcharPtr){
    i32 len = 0;
    while(csTrue){
        if(wcharPtr[len] == 0){
            break;
        }
        len++;
    }
    return len + 1;
}

char* LSM_SDLHelper::wchar2char(const i32* wcharPtr){
    i32 length = getWcharLen(wcharPtr);
    char* charPtr = new char[length];
    for(i32 i = 0; i < length; i++){
        charPtr[i] = (i8)wcharPtr[i];
    }
    return charPtr;
}

void LSM_SDLHelper::CreateWindow(const i32* title){
    window = NULL;
    screenSurface = NULL;

    // 初始化 SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    char* charTitle = wchar2char(title);

    // 创建 Window
    window = SDL_CreateWindow
    (
        charTitle,
        leftMargin,
        topMargin,
        windowWidth,
        windowHeight,
        SDL_WINDOW_SHOWN
    );

    delete[] charTitle;

    // 检测 Window 是否可用
    if(window == NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }

    screenSurface = SDL_GetWindowSurface(window);
    if(screenSurface == NULL){
        printf("ScreenSurface could not be gotten! SDL_Error: %s\n", SDL_GetError());
    }
}

void LSM_SDLHelper::Maximize(){
    SDL_MaximizeWindow(window);
}

void LSM_SDLHelper::Minimize(){
    SDL_MinimizeWindow(window);
}

SDL_Surface* LSM_SDLHelper::LoadMedia(const i8* bmpAddress)
{
    //载入 splash image
    SDL_Surface* media = SDL_LoadBMP((const char*)bmpAddress);
    if( media == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", (const char*)bmpAddress, SDL_GetError() );
    }

    return media;
}

void LSM_SDLHelper::ReleaseMedia(SDL_Surface* media){
    SDL_FreeSurface(media);
}

void LSM_SDLHelper::Close()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void LSM_SDLHelper::BlitSurfaceHere(SDL_Surface* from){
    SDL_BlitSurface( from, NULL, screenSurface, NULL );
}

void LSM_SDLHelper::LockSurface(){
    SDL_LockSurface(screenSurface);
}

void LSM_SDLHelper::UnlockSurface(){
    SDL_UnlockSurface(screenSurface);
    SDL_UpdateWindowSurface(window);
}

void LSM_SDLHelper::PaintFrameBufferHere(CS_FrameBuffer& fb){
    i32* pBitsNow = (int*)screenSurface->pixels;
    i32  bufferPitch = screenSurface->pitch / 4;
    i8*  pRed = fb.redBuffer;
    i8*  pGreen = fb.greenBuffer;
    i8*  pBlue = fb.blueBuffer;

    for (i32 y = 0; y < fb.height; y++) {
        for (i32 x = 0; x < fb.width; x++) {
            *pBitsNow =
                (i32)
                (
                    (0xff << 24) |
                    (((*pRed) & 0xff) << 16) |
                    (((*pGreen) & 0xff) << 8) |
                    ((*pBlue) & 0xff)
                    );
            pRed++;
            pGreen++;
            pBlue++;
            pBitsNow++;
        }
        pBitsNow += bufferPitch - fb.width;
    }
}
