#include "Cell.h"

const int Cell_Width = 60;
const int Cell_Height = 60;

Cell::Cell(int row, int col, int type){

	m_row = row;
	m_col = col;
	m_type = type;
	m_texture = nullptr;
	calculatePosition(row, col, m_position);
}

void Cell::calculatePosition(int row, int col, SDL_Point &pos){
	m_position.x = (col - 1) * Cell_Width;
	m_position.y = (row - 1) * Cell_Height;
}