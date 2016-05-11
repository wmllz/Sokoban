#include "Game.h"

/*
**���캯��
*/
Game::Game(){

	m_level = 1;
	m_board = nullptr;
	m_man = nullptr;
	loadMap();
}

//void Game::init(int level){
//	m_level = level;
//
//	//load ��Ӧ��map
//}

/*
**���ܣ���ʼ��Ϸ��������Ϸ��壬
**��������Ϸ����ϼ��ص�ͼ�������ص�ǰ�������ڵĵ�Ԫ��
*/
void Game::start(){
	m_board = new Board(BOARD_POS);
	m_man = m_board->loadMap(m_curMap);
}

//void Game::save(){
//
//}

//void Game::nextLevel(){
//
//}

/*
**���ܣ����ļ��м��ص�ͼ
*/
void Game::loadMap(){
	
	CSVTable table;
	string path = "map.csv";

	FileIO input(path, FORMAT_CSV);
	input.open();
	table = input.getTable();

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
	//m_man->setRow(m_man->getRow() + x);
	//m_man->setCol(m_man->getCol() + y);
}

Cell *Game::findMan(){
	return nullptr;
}

void Game::render(){

}

void Game::gameOver(){

}

