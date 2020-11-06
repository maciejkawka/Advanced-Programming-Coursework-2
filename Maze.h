#pragma once
#include<iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include<algorithm>
#include<vector>
#include <fstream>
#include<string>

struct Point {

	int x;
	int y;
};

class Maze {

private:

	int height;
	int width;
	int exitNumber;
	Point* Exit;
	Point Center;
	char* maze;
	std::vector<Point>* path;

	int GetRandomInt(int floor, int ceiling);
	void SuffleArray(int*arra);
	void RecursiveMazeGenerator(Point step);
	bool RecursivePathFinder(Point step);
	void PlaceExits();
	void CenterSquereGenerator();



public:
	Maze();
	Maze(int _height, int _width, int _extiNumber);
	~Maze();
	void GenerteMaze();
	int SetHeight(int _height);
	int SetWidth(int _width);
	int SetExitNumber(int _exitNumber);
	void Reset();
	void Print() const;

	void LoadMaze(std::string filePath);
	void SaveMaze(std::string filePath) const;
	
	inline int GetHeight() const { return height; } //Not used
	inline int GetWidht() const { return width; } //Not used
	inline int GetExitNumer() const { return exitNumber; }//Not used
	inline std::vector<Point>* GetPath() const { return path; }
	inline Point GetExit(int _exit) const;
};
