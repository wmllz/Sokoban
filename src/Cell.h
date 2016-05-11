#ifndef CELL_H
#define CELL_H

#include <SDL/SDL.h>

#include "Texture.h"
#include "SDLUtils.h"

//�Զ�������
enum CellType{
	BLANK,				//�յ�
	MAN,				//��
	BOX,				//����
	WALL,				//ǽ
	DESTINATION,		//Ŀ�ĵ�
	MAN_DESTINATION,	//����Ŀ�ĵ���
	BOX_DESTINATION		//������Ŀ�ĵ���
};

//�ⲿ����
extern const int CellWidth;
extern const int CellHeight;

//��������
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

	SDL_Point m_position;		//cell��λ�ã����꣩
	int m_row;					//cell��λ�ã��У�
	int m_col;					//cell��λ�ã��У�
	CellType m_type;					//cell�����ͣ��ˣ�ǽ���յ�......��
	Texture *m_texture;			//cell��Ԫ��ʾ������
};



#endif