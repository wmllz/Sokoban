#include "Board.h"
#include <iostream>

using namespace std;

const int GridSpace = 5;
const int BoardRows = 10;
const int BoardCols = 10;


/*
**���캯��
**@param	pos		�趨��λ������
*/
Board::Board(const SDL_Point &pos){
	
	m_position.x = pos.x;
	m_position.y = pos.y;
	calcW_H();
}

/*
**���ܣ����ص�ͼ�������������ڵĵ�Ԫ
**@param	map		��ͼ��Ϣ
**@return	ret		ָ���������ڵ�Ԫ���ָ��
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
**���ܣ���������Ԫ����ĳ�������ϵ��ƶ�
**�ú�����һ���ݹ麯�����ݹ��ԭ����Ϊ�˴��������ӵĲ���
**���ƶ�һ�����Է�3�����(�жϵ�ǰcell�Ƿ���man)��
**1.r->b, r->d	����Ҫ�ݹ�����,���˿����ƶ�
**2.r->w, r->B->B, r->B->B_d, r->B->w, r->B_d->w, r->B_d->B_d, r->B_d->B����Ҫ�ݹ飬�˲����ƶ�
**3.r->B->b, r->B->d, r->B_d->b, r->B_d->d
**ע��r=�ˣ�b=�հף�B=���ӣ�d=Ŀ�ĵأ�B_d=����+Ŀ�ĵ�
**@param	cell	��ǰҪ�ƶ��ĵ�Ԫ��
**@param	x		�������ƶ��ķ���ͳ���
**@param	y		�������ƶ��ķ���ͳ���
**@return	(bool)	������ʶ�ƶ��Ƿ�ɹ�
*/
bool Board::moveCell(Cell *&cell, int x, int y){

	//��־��ǰ�ƶ���cell���������ӻ����ˣ�true=�ˣ�false=����
	static bool isMan = true;			

	CellType curType = cell->getType();

	//�����ƶ������Ͻ���cell����һ����Ԫ��nextCell1
	Cell *nextCell1 = m_cells[cell->getRow() - 1 + x][cell->getCol() - 1 + y];
	CellType type1 = nextCell1->getType();
	
	//�����ƶ������Ͻ���nextCell����һ����Ԫ��nextCell2
	int x2 = cell->getRow() - 1 + x * 2;
	int y2 = cell->getCol() - 1 + y * 2;
	if (x2 < 0 || y2 < 0 || x2 >= BoardRows || y2 >= BoardCols){
		return false;
	}
	Cell *nextCell2 = m_cells[x2][y2];
	CellType type2 = nextCell2->getType();

	//�ж���һ��cell������,������Ӧ�Ĵ���
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
**���ܣ��жϵ�ǰ�ؿ��Ƿ�ͨ��
**@return	(bool)	���Ŀ�ĵ����Ͷ���BOX_DESTINATION��ͨ��������ͨ��
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
**���ܣ��������ĸ߶ȺͿ��
*/
void Board::calcW_H(){
	m_width = BoardCols * 50;
	m_height = BoardRows * 50;
}