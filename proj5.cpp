/*
	Taylor Ray Shuster
	CSCI 3110-001
	Project #5
	Due: 10/31/18 
	proj5.cpp
	Description: Write a C++ program that, given a starting point, finds its way out of a maze. The maze’s map will be read from a file at
	the start of the program. Your code must work for all legal mazes. The maze is a rectangular grid represented as a 2D
	array, and the exit (if there is one) should be placed on an outer row or column of the play area (non-red cells below).
	The program should run until the exit to the maze is found or until it determines that there is no exit (after exploring all
	traversable cells). Exploration of the maze is done by recursively invoking a function and marking the cells visited with a
	special character (an electronic bread crumb to keep from reprocessing explored cells). The legal moves are to cells
	adjacent, but not diagonal, to the current cell. The maze should be solved through recursive calls and backtracking, and
	not by looking ahead. If the specially marked exit cell is encountered the game should exit with a message that the exit
	was found. Otherwise, after exploring the whole maze, a message is output stating that there is no exit. 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include "maze.h"

int main()
{
	srand(1000);
	bool exit = false;

	std::ifstream is;
	is.open("maze.txt", std::ifstream::in);

	Maze maze = Maze(is);
	Coordinate start = maze.GetStartPt();
	maze.Print();
	std::cout << "Start position: " << start.x << "," << start.y << std::endl;
	maze.FindExit((int)start.x, (int)start.y, exit);

	if (exit == true)
		std::cout << "Exit Found!" << std::endl;
	else
		std::cout << "There is no exit." << std::endl;

	is.close();
	return 0;
}