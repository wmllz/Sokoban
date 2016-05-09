#include "Cell.h"

const int CellWidth = 50;
const int CellHeight = 50;

enum CellType{
	BLANK,				//空地
	MAN,				//人
	BOX,				//箱子
	WALL,				//墙
	DESTINATION,		//目的地
	MAN_DESTINATION,	//人在目的地上
	BOX_DESTINATION		//箱子在目的地上
};

//const int BLANK = 0;
//const int MAN = 1;
//const int BOX = 2;
//const int DESTINATION = 4;
//const int MAN_DESTINATION = 5;
//const int BOX_DESTINATION = 6;
//const int WALL = 7;

Texture metaTexture[5];

void loadMetaTexture(){
	const std::string manPath("man.png");
	const std::string blankPath("blank.png");
	const std::string boxPath("box.png");
	const std::string destinationPath("destination.png");
	const std::string wallPath("wall.png");
	
	metaTexture[DESTINATION].loadFromFile(destinationPath.c_str());
	metaTexture[BOX].loadFromFile(boxPath.c_str());
	metaTexture[BLANK].loadFromFile(blankPath.c_str());
	metaTexture[MAN].loadFromFile(manPath.c_str());
	metaTexture[WALL].loadFromFile(wallPath.c_str());
}


Cell::Cell(int row, int col, int type){

	m_row = row;
	m_col = col;
	m_type = type;
	calculatePosition(row, col, m_position);

	switch (type)
	{
	case BLANK:
		m_texture = &metaTexture[BLANK];
		break;
	case MAN:
	case MAN_DESTINATION:
		m_texture = &metaTexture[MAN];
		break;
	case BOX:
	case BOX_DESTINATION:
		m_texture = &metaTexture[BOX];
		break;
	case DESTINATION:
		m_texture = &metaTexture[DESTINATION];
		break;
	case WALL:
		m_texture = &metaTexture[WALL];
		break;
	default:
		break;
	}
	render();
}


void Cell::calculatePosition(int row, int col, SDL_Point &pos){
	m_position.x = (col - 1) * CellWidth + BOARD_POS.x;
	m_position.y = (row - 1) * CellHeight + BOARD_POS.y;
}

void Cell::render(){
	m_texture->render(m_position.x, m_position.y);
}