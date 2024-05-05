#include "ThePacmanGame.h"
#include <fstream>
void ThePacmanGame::handleObjectCreationFromBoard(int row, int col)
{
	char ch = board[row][col];
	if (ch == '@')
		s.setPosition(row, col);
	else if (ch == '$')
	{
		Ghost ghost;
		ghost.setGame(this);
		ghost.setPosition(row, col);
		g.push_back(ghost);
		//flag = false;
		ghostNumber++;
	}
	else if (ch == '*')
	{
		breadcount++;
	}
	//else {
	//	if (ch == '$' && !flag)
	//	{
	//		g[1].setPosition(row, col);
	//		flag = true;
	//	}
	//}
	/*if (ch == '#')
		s[1].setPosition(row, col);*/
}
void ThePacmanGame::setBoard(string s)
{
	std::ifstream file(s); // Open the file for reading
	if (!file) {
		std::cout << "Failed to open the file." << std::endl;
		return;
	}

	// Read the matrix elements from the file
	for (int i = 0; i < ROWS; i++) {

			std::string line;
			std::getline(file, line);

			// Copy characters from the string to the character array
			for (int j = 0; j < COLS; ++j) {
				originalBoard[i][j] = line[j];
			}
		}
	

	file.close(); // Close the file
}
void ThePacmanGame::init()
{
	clear_screen();
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j, i);
			if (originalBoard[i][j] != '%')
				std::cout << originalBoard[i][j];
			else std::cout << ' ';
			std::cout.flush();
			board[i][j] = originalBoard[i][j];
			handleObjectCreationFromBoard(i, j);
		}
		board[i][COLS] = '\0';
	}

	s.setGame(this);
	/*g[0].setGame(this);
	g[1].setGame(this);*/
	 s.setColor(WHITE);
	//s[1].setColor(LIGHTBLUE);
	s.setArrowKeys("wxads");
	//s[1].setArrowKeys("8246");
}

void ThePacmanGame::run()
{
	char key = 0;
	int dir;
	int tomove = 1;
	do
	{
		
		if (_kbhit())
		{
			key = _getch();
			if ((dir = s.getDirection(key)) != -1)
			{

				s.setDirection(dir);
				//g[0].setDirection(dir);
				//g[1].setDirection(dir);
			}
			if (ghostLevel == 'a')
			{
				for (int r = 0; r < g.size(); r++)
				{
					if (s.getX() > g[r].getX())
						g[r].setDirection(3);
					else if (s.getY() > g[r].getY())
						g[r].setDirection(1);
					else if (s.getX() < g[r].getX())
						g[r].setDirection(2);
					else if (s.getY() < g[r].getY())
						g[r].setDirection(0);
				}
			}
			else if (ghostLevel == 'b')
			{
				int clock2 = clock1 % 25;
				if (clock2 == 0)
				{
					for (int r = 0; r < g.size(); r++)
					{
						g[r].setDirection(rand() % 5);
					}
				}
				else if (clock2 != 1 || clock2 != 2 || clock2 != 3 || clock2 != 4)
				{
					for (int r = 0; r < g.size(); r++)
					{
						if (s.getX() > g[r].getX())
							g[r].setDirection(3);
						else if (s.getY() > g[r].getY())
							g[r].setDirection(1);
						else if (s.getX() < g[r].getX())
							g[r].setDirection(2);
						else if (s.getY() < g[r].getY())
							g[r].setDirection(0);
					}
				}
			}
			else if (ghostLevel == 'c')
			{
				if (clock1 % 20 == 0)
				{
					for (int r = 0; r < g.size(); r++)
					{
						g[r].setDirection(rand() % 5);
					}
				}
			}
			if (key == ESC)
			{
				while (!_kbhit||_getch()!=ESC)
				{ }
			}
		}
		for (int z = 0; z < f.size(); z++)
		{
			f[z].decTime();
			if (f[z].gettime() <= 0)
			{
				f[z].erasefruit();
				originalBoard[f[z].getY()][f[z].getX()] = ' ';
			}
		}
		s.move();
		if (tomove == 1)
		{
			for(int r =0 ; r< g.size();r++)
			g[r].move();
		}
		Point p = g[0].getposition();
		if (originalBoard[p.getY()][p.getX()] == '*')
		{
			gotoxy(p.getX(), p.getY());
			std::cout << '*';
		}
		 p = g[1].getposition();
		if (originalBoard[p.getY()][p.getX()] == '*')
		{
			gotoxy(p.getX(), p.getY());
			std::cout << '*';
		}
		tomove *= -1;
		breadcrumbs();
		ghost();
		gotoxy(0, 24);
		std::cout << "    score: " << s.getscore() << "     lifes:" << s.getlifes();
		if (s.getlifes() == 0) GameOver();
		if (breadcount == 0) { 
			level++;
			Win(); }
		//s[1].move();
		clock1++;
		Sleep(400);
		if (clock1 % 10 == 0)
		{
			int x= rand() %79;// X in the range 0-79 
			int y = rand() % 23; // Y in the range 0-23
			if (originalBoard[y][x] == ' ')
			{
				f.push_back(Fruits(x, y));
				originalBoard[y][x] == f[fruitsnumber].getscore() + 48;
				f[fruitsnumber].draw();
				fruitsnumber++;
			}
		}
	} while (1);

}
bool ThePacmanGame::isWall(const Point& p)
{
	return originalBoard[p.getY()][p.getX()] == '+';

}
void ThePacmanGame::breadcrumbs()
{
	Point p = s.getposition();
	if (originalBoard[p.getY()][p.getX()] == '*')
	{
		s.incresScore(1);
		originalBoard[p.getY()][p.getX()] = ' ';
		breadcount--;
	}
	else if(originalBoard[p.getY()][p.getX()] == '5')
	{
		s.incresScore(5);
		originalBoard[p.getY()][p.getX()] = ' ';
	}

	else if (originalBoard[p.getY()][p.getX()] == '6')
	{
		s.incresScore(6);
		originalBoard[p.getY()][p.getX()] = ' ';
	}

	else if (originalBoard[p.getY()][p.getX()] == '7')
	{
		s.incresScore(7);
		originalBoard[p.getY()][p.getX()] = ' ';
	}

	else if (originalBoard[p.getY()][p.getX()] == '8')
	{
		s.incresScore(8);
		originalBoard[p.getY()][p.getX()] = ' ';
	}

	else if (originalBoard[p.getY()][p.getX()] == '9')
	{
		s.incresScore(9);
		originalBoard[p.getY()][p.getX()] = ' ';
	}
}
void ThePacmanGame::ghost() {
	Point pacmanP, ghostP1, ghostP2;
	pacmanP = s.getposition();
	
	for (int i = 0; i < g.size(); i++)
	{
		ghostP1 = g[i].getposition();
		//ghostP2 = g[1].getposition();
		if ((pacmanP.getX() == ghostP1.getX() && pacmanP.getY() == ghostP1.getY()))
		{
			s.decreslife();
		}

	}
}
void ThePacmanGame::Menu()
{
	do {
		std::cout << "Choose level: (a) BEST , (b) GOOD , (c) NOVICE : " << std::endl;
		std::cin >> ghostLevel;
		std::cout << "(1) Start a new game" << std::endl;
		std::cout << "(2) Pick a map" << std::endl;
		std::cout << "(8) Present instructions and keys" << std::endl;
		std::cout << "(9) EXIT" << std::endl;
		int x;
		std::cin >> x;
		switch (x)
		{
		case 1:
			setBoard("pacman_01.txt");
			s.setlife();
			s.setscore();
			s.setDirection(4);
			init();
			g[0].setDirection(2);
			g[1].setDirection(1);
			
			run();
			break;
		case 2:
			std::cout << "which map you want (pick a number from 1 to 3):" << std::endl;
			int map;
			std::cin >> map;
			switch (map)
			{
			case 1:
				level = 4;
				setBoard("pacman_01.txt");
				s.setlife();
				s.setscore();
				s.setDirection(4);
				init();
				g[0].setDirection(2);
				g[1].setDirection(1);
				
				run();
				break;
			case 2:
				level = 4;
				setBoard("pacman_02.txt");
				s.setlife();
				s.setscore();
				s.setDirection(4);
				init();
				g[0].setDirection(2);
				g[1].setDirection(1);
				
				run();
				break;
			case 3:
				level = 4;
				setBoard("pacman_03.txt");
				s.setlife();
				s.setscore();
				s.setDirection(4);
				init();
				g[0].setDirection(2);
				g[1].setDirection(1);
				
				run();
				break;
			default:
				break;
			}

		case 8:
			instructionsandkeys();
			break;
		case 9:
			return;
			break;

		default:
			break;
		}
	} while (1);
	

}

void ThePacmanGame::instructionsandkeys()
{
	std::cout << "Pacman Game" << std::endl;
	std::cout << "The screen is consisted of:" << std::endl;
	std::cout << "walls(+)" << std::endl;
	std::cout << "pacman(@)" << std::endl;
	std::cout << "2 ghosts($)" << std::endl;
	std::cout << "“breadcrumbs”(*)" << std::endl;
	std::cout << "The pacman travels on screen and “eats the breadcrumbs”. Each eaten breadcrumb equals a point to be earned. Once all breadcrumbs on screen are eaten the game ends" << std::endl;
	std::cout << "keys:" << std::endl;
	std::cout << "Left : a or A" << std::endl;
	std::cout << "Right : d or D" << std::endl;
	std::cout << "Up : w or W" << std::endl;
	std::cout << "Down : x or X" << std::endl;
	std::cout << "Stay : s or S" << std::endl;
		

}
void ThePacmanGame::GameOver()
{
	clear_screen();
	std::cout << "Game Over you lost,good luck next time " << std::endl;
	while (!_kbhit()){}
	clear_screen();
	Menu();
}
void ThePacmanGame::Win()
{
	if (level < 4)
	{
		switch (level)
		{
		case 2:	
			setBoard("pacman_02.txt"); 
			break;
		case 3: 
			setBoard("pacman_03.txt");

		default:
			break;
		}
		clock1 = 0;
		ghostNumber = 0;
		fruitsnumber = 0;
		breadcount = 0;
		s.setDirection(4);
		init();
		g[0].setDirection(2);
		g[1].setDirection(1);
		
		run();

	}
	else
	{
		clear_screen();
		std::cout << "You won!!" << std::endl;
		while (!_kbhit()) {}
		clear_screen();
		Menu();
	}
	}
bool ThePacmanGame::isEnd(const Point& p)
{
	int x = p.getX(); 
	int y = p.getY();
	if ((y == 23) || (y == 0) || (x == 0) || (x == 80))
	{
		return true;
	}
	else
		return false;
}
