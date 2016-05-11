#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

#include <SDL/SDL.h>

#include "Cell.h"

//外部常量
extern const int BoardRows;
extern const int BoardCols;

class Board{

public:
	Board(const SDL_Point &pos);
	Cell *loadMap(int map[10][10]);
	bool moveCell(Cell *&cell, int x, int y);
	void render();

private:
	void calcW_H();

private:
	SDL_Point m_position;		//面板的位置坐标
	int m_width;				//面板的宽度
	int m_height;				//面板的高度
	Cell *m_cells[10][10];		//指向面板单元格的指针

};

#endif