#include <iostream>
#include <string>

#include "SDLUtils.h"
#include "Renderer.h"
#include "Texture.h"
#include "Cell.h"
#include "Game.h"
#include "Board.h"

using namespace std;
 
Game g;

int main(int argc, char *argv[]){

	string winName("Sokoban");
	bool quit = false;
	SDL_Event e;

	if (!initSDL(winName)){
		return -1;
	}

	loadMetaTexture();			

	g.start();

	while (!quit){
		while (SDL_PollEvent(&e) != 0){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN){
				switch (e.key.keysym.sym){
				case SDLK_UP:
					g.move(-1, 0);
					break;
				case SDLK_DOWN:
					g.move(1, 0);
					break;
				case SDLK_LEFT:
					g.move(0, -1);
					break;
				case SDLK_RIGHT:
					g.move(0, 1);
					break;
				default:
					break;
				}
			}
			gRender.renderPresent();
			if (g.gameOver()){
				break;
			}
			if (g.isNextLevel()){
				g.nextLevel();
				g.start();
			}
		}
	}
	
	closeSDL();
	return 0;
}