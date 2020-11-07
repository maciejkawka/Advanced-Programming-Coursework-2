#pragma once
#include"Maze.h"
#include"Player.h"



class MazeGame : public Maze {

private:
	Player* player;
	void MovePlayer(int playerID);
	bool IsAnyPlayerAt(int positionIndex);


public:
	MazeGame(): player(nullptr) {}
	MazeGame(int _height, int _width, int _extiNumber): player(nullptr), Maze(_height, _width, _extiNumber) {}
	~MazeGame();
	void Round();
	void GenerteMaze() override;
	int SetExitNumber(int _exitNumber) override;
	void GeneratePlayers();
	



};