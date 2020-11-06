#pragma once
#include"Maze.h"
#include"Player.h"



class MazeGame : public Maze {

private:
	Player* player;

	
	//void LoadMaze(std::string filePath) override;
	//void SaveMaze(std::string filePath) const override;

	void MovePlayer(int i);
	

public:
	MazeGame(): player(nullptr) {}
	MazeGame(int _height, int _width, int _extiNumber): player(nullptr), Maze(_height, _width, _extiNumber) {}
	~MazeGame();
	//void Round();
	void GenerteMaze() override;
	



};