#include "Board.h"
#include <iostream>

using namespace std;

const int GridSpace = 5;
const int BoardRows = 10;
const int BoardCols = 10;


/*
**构造函数
**@param	pos		设定的位置坐标
*/
Board::Board(const SDL_Point &pos){
	
	m_position.x = pos.x;
	m_position.y = pos.y;
	calcW_H();
}

/*
**功能：加载地图，返回人物所在的单元
**@param	map		地图信息
**@return	ret		指向人物所在单元格的指针
*/
Cell *Board::loadMap(int map[10][10]){
	
	Cell *ret = nullptr;
	render();
	
	m_destinations.clear();
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			m_cells[i][j] = new Cell(i + 1, j + 1, static_cast<CellType>(map[i][j]));
			if (map[i][j] == MAN){
				ret = m_cells[i][j];
			}
			else if (map[i][j] == BOX_DESTINATION || map[i][j] == DESTINATION){
				m_destinations.push_back(m_cells[i][j]);
			}
		}
	}
	return ret;
}

/*
**功能：用来处理单元格在某个方向上的移动
**该函数是一个递归函数，递归的原因是为了处理推箱子的操作
**人移动一共可以分3种情况(判断当前cell是否是man)：
**1.r->b, r->d	不需要递归的情况,且人可以移动
**2.r->w, r->B->B, r->B->B_d, r->B->w, r->B_d->w, r->B_d->B_d, r->B_d->B不需要递归，人不能移动
**3.r->B->b, r->B->d, r->B_d->b, r->B_d->d
**注：r=人，b=空白，B=箱子，d=目的地，B_d=箱子+目的地
**@param	cell	当前要移动的单元格
**@param	x		在列上移动的方向和长度
**@param	y		在行上移动的方向和长度
**@return	(bool)	用来标识移动是否成功
*/
bool Board::moveCell(Cell *&cell, int x, int y){

	//标志当前移动的cell类型是箱子还是人，true=人，false=箱子
	static bool isMan = true;			

	CellType curType = cell->getType();

	//人物移动方向上紧邻cell的下一个单元格nextCell1
	Cell *nextCell1 = m_cells[cell->getRow() - 1 + x][cell->getCol() - 1 + y];
	CellType type1 = nextCell1->getType();
	
	//人物移动方向上紧邻nextCell的下一个单元格nextCell2
	int x2 = cell->getRow() - 1 + x * 2;
	int y2 = cell->getCol() - 1 + y * 2;
	if (x2 < 0 || y2 < 0 || x2 >= BoardRows || y2 >= BoardCols){
		return false;
	}
	Cell *nextCell2 = m_cells[x2][y2];
	CellType type2 = nextCell2->getType();

	//判断下一个cell的类型,进行相应的处理
	switch (type1){

	case BLANK:
	case DESTINATION:
		
		if (isMan){
			if (curType == MAN_DESTINATION){
				nextCell1->setType(static_cast<CellType>(type1 + cell->getType() - DESTINATION));
			}
			else{
				nextCell1->setType(static_cast<CellType>(type1 + cell->getType()));
			}
			cell->setType(static_cast<CellType>(cell->getType() - MAN));
			cell = nextCell1;
		}
		else{
			nextCell1->setType(static_cast<CellType>(type1 + BOX));
			cell->setType(static_cast<CellType>(cell->getType() - BOX));
		}
		break;
	case BOX:
	case BOX_DESTINATION:
		switch (type2){
		case BLANK:
		case DESTINATION:
			isMan = false;
			moveCell(nextCell1, x, y);
			isMan = true;
			moveCell(cell, x, y);
			break;

		case BOX:
		case BOX_DESTINATION:
		case WALL:
			break;
		default:
			break;
		}
		break;
	case WALL:
		
		break;
	default:
		break;

	}
	cout << cell->getRow() << ends << cell->getCol() << endl;

	return true;
}

/*
**功能：判断当前关卡是否通过
**@return	(bool)	如果目的地类型都是BOX_DESTINATION则通过，否则不通过
*/
bool Board::isOver(){
	
	vector<Cell *>::iterator it;
	for (it = m_destinations.begin(); it != m_destinations.end(); it++){
		if ((*it)->getType() != BOX_DESTINATION){
			return false;
		}
	}
	return true;
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
	//gRender.renderPresent();
}

/*
**功能：计算面板的高度和宽度
*/
void Board::calcW_H(){
	m_width = BoardCols * 50;
	m_height = BoardRows * 50;
}