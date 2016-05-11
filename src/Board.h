#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

#include <SDL/SDL.h>

#include "Cell.h"

//�ⲿ����
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
	SDL_Point m_position;		//����λ������
	int m_width;				//���Ŀ��
	int m_height;				//���ĸ߶�
	Cell *m_cells[10][10];		//ָ����嵥Ԫ���ָ��

};

#endif