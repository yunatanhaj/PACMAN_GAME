#include "Point.h"

void Point::move() {
	int dir = rand() % 4;
	move(dir);
}

void Point::move(int dir) {
	switch (dir) {
	case 0: // UP
		--y;
		if (y < 0) {
			y = 23;
		}
		break;
	case 1: // DOWN
		++y;
		if (y > 23) {
			y = 1;
		}
		break;
	case 2: // LEFT
		--x;
		if (x < 0) {
			x = 79;
		}
		break;
	case 3: // RIGHT
		++x;
		if (x > 80) {
			x = 1;
		}
		break;
	case 4:{}
		  break;
	}
}