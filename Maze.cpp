#include "Maze.h"

int Maze::GetRandomInt(int floor, int ceiling)
{	
	return (rand() % (ceiling-floor+1)) + floor;
}

void Maze::SuffleArray(int *arra)
{
	for (int i = 3; i > 0; i--)
	{
		int j = rand() % (i + 1);
		std::swap(arra[i], arra[j]);
	}
}

void Maze::RecursiveMazeGenerator(Point step)
{
		int direction[4] = { 0,1,2,3 };
		SuffleArray(direction);

		for (int i = 0; i < 4; i++)
		{
			switch (direction[i])
			{
			case 0:
				if (step.y - 2 <= 0)
					continue;
				if (maze[((step.y - 2) * width) + step.x] == ' ')
					continue;
				maze[((step.y - 1) * width) + step.x] = ' ';
				maze[((step.y - 2) * width) + step.x] =  ' ';
				RecursiveMazeGenerator({ step.x, step.y - 2 });
				break;
			case 1:
				if (step.x + 2 >= width - 1)
					continue;
				if (maze[((step.y) * width) + step.x + 2] == ' ')
					continue;
				maze[((step.y) * width) + step.x + 1] = ' ';
				maze[((step.y) * width) + step.x + 2] = ' ';
				RecursiveMazeGenerator({ step.x + 2, step.y });
				break;
			case 2:
				if (step.y + 2 >= height - 1)
					continue;
				if (maze[((step.y + 2) * width) + step.x] == ' ')
					continue;
				maze[((step.y + 1) * width) + step.x] = ' ';
				maze[((step.y + 2) * width) + step.x] = ' ';
				RecursiveMazeGenerator({ step.x, step.y + 2 });
				break;
			case 3:
				if (step.x - 2 <= 0)
					continue;
				if (maze[((step.y) * width) + step.x - 2] == ' ')
					continue;
				maze[((step.y) * width) + step.x - 1] = ' ';
				maze[((step.y) * width) + step.x - 2] = ' ';
				RecursiveMazeGenerator({ step.x - 2, step.y });
				break;
			}
		}
}

bool Maze::RecursivePathFinder(Point step)
{  
	if (step.x<0 || step.x>width - 1 || step.y<0 || step.y>height - 1)
		return false;
	if (maze[((step.y) * width) + step.x] == 'X' || maze[((step.y) * width) + step.x] == 'o')
		return false;	
	if (maze[((step.y) * width) + step.x] == 'S')
		return true;
	
	maze[((step.y) * width) + step.x] = 'o';
	path->push_back(step);

	Point vector;
	vector.x = Center.x - step.x;
	vector.y = -(Center.y - step.y);

	if (vector.x <= 0 && vector.y < 0)
	{
		if (RecursivePathFinder({ step.x, step.y + 1 }) == true) return true;
		if (RecursivePathFinder({ step.x - 1, step.y }) == true)  return true;
		if (RecursivePathFinder({ step.x, step.y - 1 }) == true)  return true;
		if (RecursivePathFinder({ step.x + 1  , step.y }) == true)  return true;
	}
	else if (vector.x < 0 && vector.y >= 0)
	{
		if (RecursivePathFinder({ step.x - 1, step.y }) == true)  return true;
		if (RecursivePathFinder({ step.x, step.y - 1 }) == true)  return true;
		if (RecursivePathFinder({ step.x, step.y + 1 }) == true)  return true;
		if (RecursivePathFinder({ step.x + 1  , step.y }) == true)  return true;
	}
	else if (vector.x >= 0 && vector.y > 0)
	{
		if (RecursivePathFinder({ step.x, step.y - 1 }) == true)   return true;
		if (RecursivePathFinder({ step.x + 1  , step.y }) == true)  return true;
		if (RecursivePathFinder({ step.x - 1, step.y }) == true)  return true;
		if (RecursivePathFinder({ step.x, step.y + 1 }) == true)  return true;
	}
	else if (vector.x > 0 && vector.y <= 0)
	{
		if (RecursivePathFinder({ step.x + 1  , step.y }) == true)  return true;
		if (RecursivePathFinder({ step.x, step.y + 1 }) == true)  return true;
		if (RecursivePathFinder({ step.x, step.y - 1 }) == true)  return true;
		if (RecursivePathFinder({ step.x - 1, step.y }) == true)  return true;
	}

	maze[((step.y) * width) + step.x] = ' ';
	path->pop_back();

	return false;
	
}

void Maze::PlaceExits()
{
	if (Exit != nullptr)
	{
		for(int i=0;i<exitNumber;i++)
			maze[Exit[i].y * width + Exit[i].x] = 'E';
		return;
	}
	
	Exit = new Point[exitNumber];

	for (int i = 0; i < exitNumber; i++)
	{
		switch (i)
		{
		case 0:
			Exit[i].x = 1;
			Exit[i].y = 0;
			break;
		case 1:
			Exit[i].x = width - 1;
			Exit[i].y = 1;
			break;
		case 2:
			Exit[i].x = 0;
			Exit[i].y = height - 2;
			break;
		case 3:
			Exit[i].x = width - 2;
			Exit[i].y = height - 1;
			break;
		default:
			std::cout << "Error: ExitNumber to big" << std::endl;
			break;
		}	
		maze[Exit[i].y * width + Exit[i].x] = 'E';
	}
}

void Maze::CenterSquereGenerator()
{
	int squareSide = GetRandomInt(3, std::min(height, width) - 5);
	int squareCenter = squareSide * (squareSide / 2) + (squareSide / 2);
	int mazeCenter = Center.x + (Center.y) * width;
	int startPoint = mazeCenter - (squareCenter % squareSide) - width * (squareSide/2);

	for (int i=0; i<squareSide;i++)
	{
		for (int j = 0; j < squareSide; j++)
			maze[startPoint + i * width + j] = 0;
	}
}

Maze::Maze() : height(0), width(0), exitNumber(0), maze(nullptr), Exit(nullptr),path(nullptr)
{
	Center.x = 0;
	Center.y = 0;
	path = new std::vector<Point>();
}

Maze::Maze(int _height, int _width, int _extitNumber) :height(_height), width(_width), exitNumber(_extitNumber), maze(nullptr), Exit(nullptr), path(nullptr)
{
	Center.x = 0;
	Center.y = 0;
	path = new std::vector<Point>();
}

Maze::~Maze()
{
	delete[] Exit;
	delete[] maze;
}

void Maze::GenerteMaze()
{
	if (maze != nullptr)
	{
		std::cout << "Maze has been already generated" << std::endl;
		return;
	}
	if (height < 8|| width < 8 )
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
}

int Maze::SetHeight(int _height)
{
	if (_height % 2 == 0)
	{
		std::cout << "Height cannot be even!" << std::endl;
		return -1;
	}
	if (_height < 8)
	{
		std::cout << "Height must be bigger than 7!" << std::endl;
		return -1;
	}
	if (maze != nullptr)
	{
		std::cout << "Maze has been already generated" << std::endl;
		return 0;
	}
	if (_height > 51)
	{
		std::cout << "Width must be smaller than 52!" << std::endl;
		return -1;
	}
	height = _height;
	return 0;
}

int Maze::SetWidth(int _width)
{
	if (_width % 2 == 0)
	{
		std::cout << "Width cannot be even!" << std::endl;
		return -1;
	}
	if (_width < 8)
	{
		std::cout << "Width must be bigger than 7!" << std::endl;
		return -1;
	}
	if (maze != nullptr)
	{
		std::cout << "Maze has been already generated" << std::endl;
		return -1;
	}
	if (_width > 51)
	{
		std::cout << "Width must be smaller than 52!" << std::endl;
		return -1;
	}
	width = _width;
	return 0;
}

int Maze::SetExitNumber(int _exitNumber)
{
	if (_exitNumber < 0 || _exitNumber>4)
	{
		std::cout << "Exit number must be bigger than 0 and smaller than 5!" << std::endl;
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

void Maze::Reset()
{
	if (maze == nullptr)
		std::cout << "Maze is not generated!!" << std::endl;
	
	delete[] maze;
	maze = nullptr;
	delete[] Exit;
	Exit = nullptr;
	path->clear();
	height = 0;
	width = 0;
	Center.x = 0;
	Center.y = 0;
	exitNumber = 0;
}

void Maze::Print() const
{
	if (maze == nullptr)
	{
		std::cout << "Maze cannot be printed!!" << std::endl;
		return;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			std::cout << maze[i * width + j];
		std::cout << std::endl;
	}
}

void Maze::LoadMaze(std::string filePath)
{
	if (maze != nullptr|| height != 0 || width != 0)
	{
		std::cout << "Maze has been already generated" << std::endl;
		return;
	}

	std::ifstream file;
	
	file.open(filePath, std::ios::in);
	if (file.good())
	{
		std::string buffor;
		std::string inputMaze;
		
		while (std::getline(file, buffor))
		{
			width++;
			inputMaze += buffor;
			if (inputMaze.size() / width != buffor.size())
			{
				std::cout << "This is not a maze!! File:" << filePath << std::endl;
				file.close();
				return;
			}
		}
		//Ask which one is better
		height = inputMaze.size() / width;
		//GetHeight(inputMaze.size() / width);
		Center.y = height / 2;
		Center.x = width / 2;
		maze = new char[height * width];

		for (int i = 0; i < width * height; i++)
			maze[i] = inputMaze[i];
		
		file.close();
	}
	else
	{
		std::cout << "The file doesn't exits: " << filePath << std::endl;
		return;
	}

}

void Maze::SaveMaze(std::string filePath) const
{
	if (maze == nullptr)
	{
		std::cout << "Maze is not generated!!" << std::endl;
		return;
	}

	std::ofstream file;

	file.open(filePath, std::ios::trunc| std::ios::out);
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			file << maze[i * width + j];
		file << std::endl;
	}
	file.close();
}

inline Point Maze::GetExit(int _exit) const
{
	if (_exit > exitNumber - 1)
		return { 0,0 };

	return Exit[_exit];

}
