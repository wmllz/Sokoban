#ifndef CELL_H
#define CELL_H

#include <SDL/SDL.h>
#include "Texture.h"
class Cell{

private:
	SDL_Point m_position;
	int m_row;
	int m_col;
	int type;
	
};
#endif