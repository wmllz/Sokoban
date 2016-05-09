#include <iostream>
#include <string>

#include "SDLUtils.h"
#include "Renderer.h"
#include "Texture.h"
#include "Cell.h"
#include "Board.h"

using namespace std;
 
int main(int argc, char *argv[]){

	string winName("Sokoban");

	int map[10][10] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
		{ 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
	};

	int map2[2][2] = { { 0, 0 }, { 1, 1 } };
	bool quit = false;
	SDL_Event e;

	if (!initSDL(winName)){
		return -1;
	}

	loadMetaTexture();
	Board board(BOARD_POS);
	board.loadMap(map);

	while (!quit){
		while (SDL_PollEvent(&e) != 0){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			else{
			
			}
		}
	}
	
	closeSDL();
	return 0;
}