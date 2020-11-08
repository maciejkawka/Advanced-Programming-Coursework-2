#pragma once
#include"Maze.h"
#include"Player.h"



class MazeGame : public Maze {

private:
	Player* player;

	void MovePlayer(int playerID);
	bool CheckCollision(int positionIndex);

public:
	MazeGame(): player(nullptr) {}
	MazeGame(int _height, int _width, int _extiNumber): player(nullptr), Maze(_height, _width, _extiNumber) {}
	~MazeGame();
	
	int Round();
	void GenerteMaze() override;
	int SetExitNumber(int _exitNumber) override;
	void Reset() override;
	void GeneratePlayers();
	
	inline int GetPlayerSteps(int playerID) const { return player[playerID].GetStepNumber(); }
	inline int GetPlayerRounds(int playerID) const { return player[playerID].GetRoundNumber(); }
	inline int GetPlayerWaitings(int playerID) const { return player[playerID].GetRoundNumber()-player[playerID].GetStepNumber(); }
};