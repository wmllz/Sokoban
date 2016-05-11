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
	//void nextLevel();
	void loadMap();
	void move(int x, int y);
	void render();
	void gameOver();
	Cell *findMan();
private:
	int m_level;
	int m_curMap[10][10];
	SDL_Point m_manPos;
	Cell *m_man;
	Board *m_board;
	Collisions collisions;
};

#endif