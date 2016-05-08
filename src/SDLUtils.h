/*
**封装SDL的初始化工作，并且包含一些工具函数
*/
#ifndef SDLUTILS_H
#define SDLUTILS_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>

#include "Renderer.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

bool initSDL(const std::string &winName);
void closeSDL();

#endif