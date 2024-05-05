#include "Board.h"
#include <iostream>

void Board::print() const {
    for (int i = 0; i < 24; i++)
        std::cout << board[i]<<std::endl;
    
}
char Board::get(int x, int y) const {
    return board[x][y];
}
Board::Board()
{
}