#pragma once
#include "Point.h"

class ThePacmanGame;
class Fruits:public Point {

	int time;
	int score;
	ThePacmanGame* theGame;
public:
	Fruits(int x,int y)
	{
			score = rand() % 5 + 5;   // score in the range 5-9
			time = rand() % 10 ;   // v3 in the range 1985-2014
			Point::set(x, y);
	}
	void setGame(ThePacmanGame* _theGame) {
		theGame = _theGame;
	}
	int gettime()
	{
		return time;
	}
	void decTime()
	{
		this->time--;
	}

	void draw()
	{
		Point::draw(score+48);
	}
	void erasefruit()
	{
		Point::draw(' ');
	}
	int getscore()
	{
		return score;
	}
};