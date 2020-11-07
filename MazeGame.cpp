#include "MazeGame.h"



void MazeGame::MovePlayer(int playerID)
{
	int nextPoint = 0;
	maze[player[playerID].GetPosition().y * width + player[playerID].GetPosition().x] = ' ';

	while (path->at(nextPoint).x != Exit[playerID].x || path->at(nextPoint).y != Exit[playerID].y)
		nextPoint++;

	int stepWalked = player[playerID].GetStepNumber();
	int nextPathIndex = nextPoint + 2 + stepWalked;
	
	if (nextPathIndex == path->size())
	{
		player[playerID].Disactivate();
		return;
	}
	if (path->at(nextPathIndex).x == Exit[playerID + 1].x && path->at(nextPathIndex).y == Exit[playerID + 1].y)
	{
		player[playerID].Disactivate();
		return;
	}
	
	if (IsAnyPlayerAt(nextPathIndex))
		player[playerID].Wait();
	else
		player[playerID].MoveTo(path->at(nextPathIndex));
	


	maze[player[playerID].GetPosition().y * width + player[playerID].GetPosition().x] = 'P';
}

bool MazeGame::IsAnyPlayerAt(int positionIndex)
{
	for (int j = 0; j < exitNumber; j++)
		if (player[j].GetPosition().x == path->at(positionIndex).x && player[j].GetPosition().y == path->at(positionIndex).y&&player[j].GetState())
			return true;
	return false;
}

MazeGame::~MazeGame()
{
	delete[] player;
}

void MazeGame::Round()
{

	MovePlayer(0);
	MovePlayer(1);
}

void MazeGame::GenerteMaze()
{
	if (maze != nullptr)
	{
		std::cout << "Maze has been already generated" << std::endl;
		return;
	}
	if (height < 8 || width < 8)
	{
		std::cout << "Nither height nor width can be smaller than 8" << std::endl;
		return;
	}
	if (height % 2 == 0 || width % 2 == 0)
	{
		std::cout << "Nither height nor width can be even" << std::endl;
		return;
	}
	if (exitNumber == 0 || exitNumber > 4)
	{
		std::cout << "Exit number must be higher than 0 and smaller than 8!" << std::endl;
		return;
	}


	maze = new char[height * width];
	for (int i = 0; i < height * width; i++)
		maze[i] = 'X';

	Center.y = height / 2;
	Center.x = width / 2;

	RecursiveMazeGenerator({ 1,1 });
	PlaceExits();
	CenterSquereGenerator();

	maze[width * (height / 2) + (width / 2)] = 'S';

	if (Exit == nullptr)
		return;
	for (int i = 0; i < exitNumber; i++)
	{
		RecursivePathFinder(Exit[i]);
		for (int i = 0; i < path->size(); i++)
			maze[((path->at(i).y) * width) + path->at(i).x] = ' ';
	}
	for (int i = 0; i < path->size(); i++)
		maze[((path->at(i).y) * width) + path->at(i).x] = 'o';
	PlaceExits();
	maze[width * (height / 2) + (width / 2)] = 'F';
}

int MazeGame::SetExitNumber(int _exitNumber)
{
	if (_exitNumber < 2 || _exitNumber>4)
	{
		std::cout << "Exit number must be bigger than 1 and smaller than 5!" << std::endl;
		return -1;
	}
	if (maze != nullptr)
	{
		std::cout << "Maze has been already generated" << std::endl;
		return 0;
	}

	exitNumber = _exitNumber;
	return 0;
}

void MazeGame::GeneratePlayers()
{
	player = new Player[exitNumber];
	
	for (int i = 0; i < exitNumber; i++)
	{
		switch (i)
		{
		case 0:
			player[i].SetPosition(1, 1);
			break;
		case 1:
			player[i].SetPosition( width - 2, 1);
			break;
		case 2:
			player[i].SetPosition(1, height - 2);
			break;
		case 3:
			player[i].SetPosition(width - 2, height - 2);
			break;
		default:
			std::cout << "Error: playerNumber to big" << std::endl;
			break;
		}
		maze[player[i].GetPosition().y * width + player[i].GetPosition().x]= 'P';
	}
	
}
