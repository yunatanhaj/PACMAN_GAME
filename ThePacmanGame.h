#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Board.h"
#include "fruits.h"
#include <vector>
#include <string>
static bool flag = true;
static int ghostNumber = 0;
static int fruitsnumber = 0;
static int breadcount = 0;
static int level = 1;
static int clock1 = 0; // clock for the game , to count how many moves have been done in the game 
class ThePacmanGame {
	enum { ESC = 27 };
	//enum { ROWS = 24, COLS = 80 };
	Pacman s;
	vector<Ghost> g;
	vector< Fruits> f;
	char originalBoard[ROWS][COLS + 1];	// this is the original board that we got (we need COLS+1 because we handle it as null terminated char*)
	char board[ROWS][COLS + 1];	// this is the actual board we play on, i.e. changes on board are done here
	void handleObjectCreationFromBoard(int row, int col); // '@'  are the start points of the pacman
	char ghostLevel;
public:
	void setBoard(string s); //copy board sent to us into originalBoard, setArrowKeys, setColor
	void init(); //copy original board to actual board and set Snakes Start point
	bool isWall(const Point& p);
	void run(); // run pacman with Keyboard
	void breadcrumbs();//check if the pacman eat beardcrumbs and adding the score 
	void ghost();//checking if the ghoszt eat the pacman and reduce the lifes 
	void GameOver();
	void Win();
	void Menu();
	void instructionsandkeys();
	bool isEnd(const Point& p);
	void setghostlevel(char ch)
	{
		ghostLevel = ch;
	}
	char getghostlevel()
	{
		return ghostLevel;
	}
};

#endif