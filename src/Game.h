#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Collisions.h"
#include "FileIO.h"

class Game{
public:
	Game();
	//void init(int level = 1);
	void start();
	//void save();
	bool isNextLevel();
	void nextLevel();
	void loadMap();
	void move(int x, int y);
	void render();
	bool gameOver();

private:

	bool m_isOver;			//��־������Ϸ�Ƿ�ͨ��true=���ùؿ���ͨ����false=û��ͨ��
	bool m_isNextLevel;		//��־�Ƿ�Ҫ������һ�أ�true=�ǣ�false=��

	int m_level;			//��Ϸ�Ĺؿ�
	int m_curMap[10][10];	
	
	FileIO m_fs;
	
	SDL_Point m_manPos;
	Cell *m_man;
	Board *m_board;
	//Collisions collisions;
};

#endif