#pragma once
#include<iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include<algorithm>
#include<vector>
#include <fstream>
#include<string>


#ifndef POINT_STR
#define POINT_STR

struct Point {
	int x;
	int y;
};

#endif



class Maze {

protected:

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
	virtual void GenerteMaze();
	int SetHeight(int _height);
	int SetWidth(int _width);
	virtual int SetExitNumber(int _exitNumber);
	void Reset();
	void Print() const;

	virtual void LoadMaze(std::string filePath);
	virtual void SaveMaze(std::string filePath) const;



};
