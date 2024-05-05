#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <cstring>
#include "Point.h"

class ThePacmanGame;

class Pacman:public Point {
	enum { SIZE = 5 };
	//Point body;
	int direction = 4;
	char arrowKeys[5];
	Color color;
	int score = 0;
	int lives = 3;
	ThePacmanGame* theGame;
public:
	void setGame(ThePacmanGame* _theGame) {
		theGame = _theGame;
	}
	void setPosition(int y, int x);
	void setArrowKeys(const char* keys) {
		arrowKeys[0] = keys[0];
		arrowKeys[1] = keys[1];
		arrowKeys[2] = keys[2];
		arrowKeys[3] = keys[3];
		arrowKeys[4] = keys[4];
	}
	void setColor(Color c) {
		color = c;
	}
	void move();
	int getDirection(char key);
	void setDirection(int dir) {
		direction = dir;
	}
	void incresScore(int i)
	{
		score+=i;
	}
	int getscore()
	{
		return score;
	}
	void decreslife()
	{
		lives--;
	}
	int getlifes()
	{
		return lives;
	}
	Point& getposition()
	{
		return getPoint();
	}
	void setlife()
	{
		lives = 3;
	}
	void setscore()
	{
		score = 0;
	}
};

#endif