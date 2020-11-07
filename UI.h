#pragma once
#include<iostream>
#include"MazeGame.h"


class UI {

	MazeGame* mainMaze;

	inline int InputInt();

public:

	UI();
	~UI();

	void SetDimentions();
	void SetExitsNumber();
	void GenerateMaze();
	void Reset();
	void Load();
	void Save();
	void Welcome();
	void Print();
	void Analyse();
	void NextRound();
	void SeriesOfMazes();
};