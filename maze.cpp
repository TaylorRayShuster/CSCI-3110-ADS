/*
	Taylor Ray Shuster
	CSCI 3110-001
	Project #5
	Due: 10/31/18 
	maze.cpp
*/
#include "maze.h"
#include <iostream>
#include <algorithm>

Maze::Maze(std::ifstream& is)
{
	Coordinate traversable(0,0);
	is >> maxRows;
	is >> maxCols;
	for (int i = 0; i <= (maxRows + 1); i++)
	{
		for (int j = 0; j <= (maxCols + 1); j++)
		{
			maze[i][j] = 'X';
		}
	}
	for (int i = 1; i <= maxRows; i++)
	{
		for (int j = 1; j <= maxCols; j++)
		{
			is >> maze[i][j];
			if (maze[i][j] == 'O' || maze[i][j] == 'E')
			{
				traversable.x = i;
				traversable.y = j;
				coords.push_back(traversable);
			}
		}
	}
}

void Maze::Print()
{
	std::cout << "Maze State:" << std::endl;
	for (int i = 1; i <= maxRows; i++)
	{
		for (int j = 1; j <= maxCols; j++)
		{
			std::cout << " " << maze[i][j];
		}
		std::cout << std::endl;
	}
	return;
}

Coordinate Maze::GetStartPt()
{
	std::random_shuffle(coords.begin(), coords.end());
	std::vector<Coordinate>::iterator itr = coords.begin();
	return (*itr);
}

void Maze::FindExit(int x, int y, bool& exit)
{
	if (maze[x][y] == 'E')
	{
		std::cout << "Trying: " << x << "," << y << std::endl;
		exit = true;
	}
	else if(exit == false && maze[x][y] != '*')
	{
		std::cout << "Trying: " << x << "," << y << std::endl;
		maze[x][y] = '*';
		Print();
		std::vector<Coordinate>::iterator itr = coords.begin();
		std::vector<Coordinate>::iterator itr2;
		for (itr; itr != coords.end(); itr++)
		{
			if ((itr != coords.end()) && itr->x == x && itr->y == (y - 1))
			{
				itr2 = itr;
				coords.erase(itr2);
				FindExit(x, (y - 1), exit);		
				itr = coords.begin();
			}
			if (exit == true)
				break;
		}
		itr = coords.begin();
		for (itr; itr != coords.end(); itr++)
		{
			if ((itr != coords.end()) && itr->x == (x + 1) && itr->y == y)
			{
				itr2 = itr;
				coords.erase(itr2);
				FindExit((x + 1), y, exit);
				itr = coords.begin();
			}		
			if (exit == true)
				break;
		}
		itr = coords.begin();
		for (itr; itr != coords.end(); itr++)
		{
			if ((itr != coords.end()) && itr->x == x && itr->y == (y + 1))
			{	
				itr2 = itr;
				coords.erase(itr2);
				FindExit(x, (y + 1), exit);
				itr = coords.begin();
			}
			if (exit == true)
				break;
		}
		itr = coords.begin();
		for (itr; itr != coords.end(); itr++)
		{
			if ((itr != coords.end()) && itr->x == (x - 1) && itr->y == y)
			{
				itr2 = itr;
				coords.erase(itr2);
				FindExit((x - 1), y, exit);
				itr = coords.begin();
			}
			if (exit == true)
				break;
		}
	}

}