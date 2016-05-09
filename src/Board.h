#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

#include <SDL/SDL.h>

#include "Cell.h"

extern const int BoardRows;
extern const int BoardCols;

enum CellType{
	Man, Wall, Box, Destination, Mixed
};

class Board{
public:
	Board(const SDL_Point &pos);
	
	void loadMap(int map[10][10]);
	void render();
	void calcW_H();
private:

private:
	SDL_Point m_position;
	int m_width;
	int m_height;
	Cell *m_board[10][10];

};

#endif