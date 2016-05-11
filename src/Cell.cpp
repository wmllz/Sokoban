#include "Cell.h"

const int CellWidth = 50;
const int CellHeight = 50;

Texture metaTexture[7];

/*
**功能：加载程序中用到的图片，每一个单元格可能现实的图片
*/
void loadMetaTexture(){
	const std::string blankPath("blank.png");
	const std::string manPath("man.png");
	const std::string boxPath("box.png");
	const std::string wallPath("wall.png");
	const std::string destinationPath("destination.png");
	const std::string manDestinationPath("man_destination.png");
	const std::string boxDestinationPath("box_destination.png");
	
	metaTexture[BLANK].loadFromFile(blankPath.c_str());
	metaTexture[MAN].loadFromFile(manPath.c_str());
	metaTexture[BOX].loadFromFile(boxPath.c_str());
	metaTexture[WALL].loadFromFile(wallPath.c_str());
	metaTexture[DESTINATION].loadFromFile(destinationPath.c_str());
	metaTexture[MAN_DESTINATION].loadFromFile(manDestinationPath.c_str());
	metaTexture[BOX_DESTINATION].loadFromFile(boxDestinationPath.c_str());
}

/*
**构造函数
*/
Cell::Cell(int row, int col, CellType type){

	m_row = row;
	m_col = col;
	m_type = type;
	calculatePosition(row, col);

	m_texture = &metaTexture[m_type];
	/*if (type == BOX_DESTINATION){
		m_texture = &metaTexture[m_type - 1];
	}
	else{
		m_texture = &metaTexture[m_type];
	}*/
	render();
}

/*
**功能：改变单元格的texture（显示的内容）
*/
void Cell::setTexture(Texture *texture){
	m_texture = texture;
	render();
}

/*
**功能：用于设置当前cell的类型，并且重新渲染
*/
void Cell::setType(CellType type){
	m_type = type;
	
	m_texture = &metaTexture[m_type];
	/*if (type == BOX_DESTINATION){
		m_texture = &metaTexture[m_type - 1];
	}
	else{
		m_texture = &metaTexture[m_type];
	}*/
	render();
}

/*
**功能：渲染单元格
*/
void Cell::render(){
	m_texture->render(m_position.x, m_position.y);
}

/*
**功能：根据单元格的行列号计算出单元格的位置坐标
**@param	row		单元格的行号
**@param	col		单元格的列号
*/
void Cell::calculatePosition(int row, int col){

	m_position.x = (col - 1) * CellWidth + BOARD_POS.x;
	m_position.y = (row - 1) * CellHeight + BOARD_POS.y;
}