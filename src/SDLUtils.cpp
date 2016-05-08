#include "SDLUtils.h"

//全局变量
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
static SDL_Window *gWindow = nullptr;
static SDL_Renderer *gRenderer = nullptr;

/*
**SDL的初始化
*/
bool initSDL(const std::string &winName){
	
	bool success = true;
	
	//load SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}else{

		//create window
		gWindow = SDL_CreateWindow(
			winName.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH,
			SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN);
		
		if (gWindow ==  nullptr){
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}else{

			//create renderer
			gRenderer = SDL_CreateRenderer(gWindow, -1, 
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			
			if (gRenderer == nullptr){
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}

			gRender.init(gRenderer);
			
			//load SDL_image
			int imageFlag = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlag) & imageFlag)){
				printf("SDL_image could not initialize! SDL Error: %s\n", SDL_GetError());
				success = false;
			}

			//load SDL_ttf
			if(TTF_Init()==-1) {
				printf("TTF_Init: %s\n", TTF_GetError());
				success = false;
			}
			//load other SDL_*

		}
	}
	return success;
}

/*
**SDL的卸载
*/
void closeSDL(){
	
	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	
	//other SDL_*'s Quit
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}