#ifndef CELL_H
#define CELL_H

#include <SDL/SDL.h>

#include "Texture.h"
#include "SDLUtils.h"

extern void loadMetaTexture();

class Cell{
public:
	Cell(){};
	Cell(int row, int col, int type);
	int getRow(){ return m_row; }
	int getCol(){ return m_col; }
	int getType(){ return m_type; }
	void render();

private:
	void calculatePosition(int row, int col, SDL_Point &pos);

private:
	SDL_Point m_position;
	int m_row;
	int m_col;
	int m_type;
	Texture *m_texture;
};

extern const int CellWidth;
extern const int CellHeight;

#endif