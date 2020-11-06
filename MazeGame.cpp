#include "MazeGame.h"



MazeGame::~MazeGame()
{
	delete[] player;
}

void MazeGame::GenerteMaze()
{
	Maze::GenerteMaze();

	maze[width * (height / 2) + (width / 2)] = 'F';

	for(int i=0; i<path->size();i++)
		maze[((path->at(i).y) * width) + path->at(i).x] = ' ';

	PlaceExits();
}
