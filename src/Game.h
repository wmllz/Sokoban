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

	bool m_isOver;			//标志整个游戏是否通关true=所用关卡都通过，false=没有通关
	bool m_isNextLevel;		//标志是否要进入下一关，true=是，false=否

	int m_level;			//游戏的关卡
	int m_curMap[10][10];	
	
	FileIO m_fs;
	
	SDL_Point m_manPos;
	Cell *m_man;
	Board *m_board;
	//Collisions collisions;
};

#endif