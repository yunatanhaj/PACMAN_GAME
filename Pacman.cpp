#include "Pacman.h"
#include "ThePacmanGame.h"
void Pacman::setPosition(int y, int x)
{
		Point::set(x, y);
}
void Pacman::move()
{
	//body[SIZE - 1].draw(' ');
	Point::draw(' ');/*
	for (int i = SIZE - 1; i > 0; --i)
		body[i] = body[i - 1];*/

	if (theGame->isWall(Point::next(direction)))
		direction = 4;

	Point::move(direction);
	setTextColor(color);
	Point::draw('@');
}
int Pacman::getDirection(char key)
{
	for (int i = 0; i < SIZE ; i++)
	{
		if (key == arrowKeys[i]||key+32== arrowKeys[i])
			return i;
	}
	return -1;
}