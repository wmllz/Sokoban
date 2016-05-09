#include "Board.h"

const int GridSpace = 5;
const int BoardRows = 10;
const int BoardCols = 10;



Board::Board(const SDL_Point &pos){
	
	m_position.x = pos.x;
	m_position.y = pos.y;
	calcW_H();
}

void Board::loadMap(int map[10][10]){
	
	render();
	
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			m_board[i][j] = new Cell(i + 1, j + 1, map[i][j]);
		}
	}
	
}

void Board::render(){
	gRender.setRenderDrawColor(0xff, 0xff, 0xff, 0xff);
	gRender.renderClear();
	gRender.setRenderDrawColor(0x00, 0xff, 0xff, 0xff);
	SDL_Rect temp;

	temp.x = m_position.x;
	temp.y = m_position.y;
	temp.w = m_width;
	temp.h = m_height;
	gRender.drawRect(temp);
	gRender.renderPresent();
}

void Board::calcW_H(){
	m_width = BoardCols * 50;
	m_height = BoardRows * 50;
}