#include "Ghost.h"
#include "ThePacmanGame.h"

void Ghost::setPosition(int y, int x)
{
	Point::set(x, y);
}
void Ghost::move()
{ 
	//body[SIZE - 1].draw(' ');
	int x = getX(), y = getY();
	if(board_example[y][x]!='*')
	draw(' ');/*
	for (int i = SIZE - 1; i > 0; --i)
		body[i] = body[i - 1];*/
	
	if (theGame->isWall(Point::next(direction))||theGame->isEnd(Point::next(direction)))
	{
		direction = 4;
		Point::move(direction);
	}

	else Point::move(direction);

	
	//setTextColor(color);
	draw('$');
}