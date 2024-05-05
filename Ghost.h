#pragma once
#include "Point.h"
class ThePacmanGame;
class Ghost:public Point
{
public:
	void setGame(ThePacmanGame* _theGame) {
		theGame = _theGame;
	}
	void setPosition(int y, int x);
	//void setArrowKeys(const char* keys) {
	//	arrowKeys[0] = keys[0];
	//	arrowKeys[1] = keys[1];
	//	arrowKeys[2] = keys[2];
	//	arrowKeys[3] = keys[3];
	//	arrowKeys[4] = keys[4];
	//}
	/*void setColor(Color c) {
		color = c;
	}*/
	void move();
	//int getDirection(char key);
	void setDirection(int dir) {
		direction = dir;
	}
	//void incresScore()
	//{
	//	score++;
	//}
	//int getscore()
	//{
	//	return score;
	//}
	//void decreslife()
	//{
	//	lives--;
	//}
	//int getlifes()
	//{
	//	return lives;
	//}
	Point& getposition()
	{
		
		return getPoint();
	}

private:
	 //  Point body;
	   int direction = 3;
	   ThePacmanGame* theGame;

};

