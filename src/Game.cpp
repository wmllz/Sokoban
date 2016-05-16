#include "Game.h"

/*
**构造函数
*/
Game::Game(){

	string path = "map.csv";
	m_isOver = false;
	m_isNextLevel = false;
	m_level = 1;
	m_board = nullptr;
	m_man = nullptr;
	m_board = new Board(BOARD_POS);
	m_fs.init(path, FORMAT_CSV);
	loadMap();
}

//void Game::init(int level){
//	m_level = level;
//
//	//load 相应的map
//}

/*
**功能：开始游戏，创建游戏面板，
**并在在游戏面板上加载地图，并返回当前人物所在的单元格
*/
void Game::start(){
	m_man = m_board->loadMap(m_curMap);
}

//void Game::save(){
//
//}

bool Game::isNextLevel(){
	return m_isNextLevel;
}

void Game::nextLevel(){
	loadMap();
	m_isNextLevel = false;
}

/*
**功能：从文件中加载地图
*/
void Game::loadMap(){
	
	CSVTable table;
	
	m_fs.open(m_fs.getPosition());
	
	table = m_fs.getTable();

	if (table.size() == 0){
		m_isOver = true;
		return;
	}

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			m_curMap[i][j] = atoi(table[i][j].c_str());
			cout << m_curMap[i][j] << ends;
		}
		cout << endl;
	}
}

void Game::move(int x, int y){
	m_board->moveCell(m_man, x, y);
	m_isNextLevel = m_board->isOver();
}


void Game::render(){

}

bool Game::gameOver(){
	return m_isOver;
}

