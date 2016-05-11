#ifndef CELL_H
#define CELL_H

#include <SDL/SDL.h>

#include "Texture.h"
#include "SDLUtils.h"

//自定义类型
enum CellType{
	BLANK,				//空地
	MAN,				//人
	BOX,				//箱子
	WALL,				//墙
	DESTINATION,		//目的地
	MAN_DESTINATION,	//人在目的地上
	BOX_DESTINATION		//箱子在目的地上
};

//外部常量
extern const int CellWidth;
extern const int CellHeight;

//函数声明
void loadMetaTexture();

class Cell{
public:
	Cell(){};
	Cell(int row, int col, CellType type);
	
	void setTexture(Texture *texture);
	void setRow(int row){ m_row = row; }
	void setCol(int col){ m_col = col; }
	void setType(CellType type);
	int getRow(){ return m_row; }
	int getCol(){ return m_col; }
	CellType getType(){ return m_type; }
	Texture *getTexture(){ return m_texture; }
	
	void render();

private:
	void calculatePosition(int row, int col);

private:

	SDL_Point m_position;		//cell的位置（坐标）
	int m_row;					//cell的位置（行）
	int m_col;					//cell的位置（列）
	CellType m_type;					//cell的类型（人，墙，空地......）
	Texture *m_texture;			//cell单元显示的内容
};



#endif