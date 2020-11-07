#include "UI.h"

void UI::Welcome()
{
	system("CLS");
	std::cout << "Maciej's Maze Generator!!" << std::endl << "Select correct option" << std::endl;

	std::cout << "1. Set Dimensions" << std::endl;
	std::cout << "2. Set Exits Number" << std::endl;
	std::cout << "3. Generate Maze with players" << std::endl;
	std::cout << "4. Save Maze" << std::endl;
	std::cout << "5. Load Maze" << std::endl;
	std::cout << "6. Reset Maze" << std::endl;
	std::cout << "7. Analyse Random Mazes" << std::endl;
	std::cout << "8. Next Round" << std::endl;
	std::cout << "9. Series of Mazes" << std::endl;
	std::cout << "0. Exit" << std::endl;

}

void UI::Print()
{

	std::cout << "MAZE:" << std::endl << std::endl;
	mainMaze->Print();
}

void UI::Analyse()
{
	return;
	/*system("CLS");

	std::cout << "Enter maximum height: ";
	int inputHeight = InputInt();
	std::cout << "Enter maximum width: ";
	int inputWidth = InputInt();
	std::cout << "Enter maximum players: ";
	int inputPlayers = InputInt();

	struct Data {
		int steps;
		int waits;
	};*/

	//TO BE IMPLEMENTED
}

void UI::NextRound()
{
	int state = mainMaze->Round();
	if (state == -1)
	{	
		std::cout << "GAME OVER!" << std::endl;
		std::cout << "A maze is not solvable due to all players blocking each other" << std::endl;
		system("pause");
	}
	else if (state == -2)
	{
		std::cout << "GAME OVER!" << std::endl;
		std::cout << "A maze is fully solvable as all players can reach the finishing point" << std::endl;
		system("pause");
	}
	else if (state == -3)
	{
		std::cout << "GAME OVER!" << std::endl;
		std::cout << "A maze is partially solvable as some players can reach the finishing point" << std::endl;
		system("pause");
	}
	else if (state == -4)
	{
		std::cout << "Maze is not generated properly!!" << std::endl;
		system("pause");
	}
}

void UI::SeriesOfMazes()
{
	int state;
	do{
		state = mainMaze->Round();
		mainMaze->Print();
		std::cout << std::endl;
	}while (!state);

	if (state == -1)
	{
		std::cout << "GAME OVER!" << std::endl;
		std::cout << "A maze is not solvable due to all players blocking each other" << std::endl;
		system("pause");
	}
	else if (state == -2)
	{
		std::cout << "GAME OVER!" << std::endl;
		std::cout << "A maze is fully solvable as all players can reach the finishing point" << std::endl;
		system("pause");
	}
	else if (state == -3)
	{
		std::cout << "GAME OVER!" << std::endl;
		std::cout << "A maze is partially solvable as some players can reach the finishing point" << std::endl;
		system("pause");
	}
	else if (state == -4)
	{
		std::cout << "Maze is not generated properly!!" << std::endl;
		system("pause");
	}
}

int UI::InputInt()
{
	int input;

	while (!(std::cin >> input))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}

UI::UI() : mainMaze(nullptr)
{
	mainMaze = new MazeGame();
}

UI::~UI()
{
	delete mainMaze;
}

void UI::SetDimentions()
{

	system("CLS");
	std::cout << "Set Dimensions." << std::endl;
	std::cout << "Width: ";
	while (mainMaze->SetWidth(InputInt()));
	std::cout << "Height: ";
	while (mainMaze->SetHeight(InputInt()));
}

void UI::SetExitsNumber()
{
	system("CLS");
	std::cout << "Set Number of Exits" << std::endl;
	while (mainMaze->SetExitNumber(InputInt()));
}

void UI::GenerateMaze()
{
	system("CLS");
	mainMaze->GenerteMaze();
	mainMaze->GeneratePlayers();
	system("pause");
}

void UI::Reset()
{
	system("CLS");
	mainMaze->Reset();
	system("pause");
}

void UI::Load()
{

	system("CLS");
	std::cout << "Enter tile name ";
	std::string input;
	std::cin >> input;
	input += ".txt";
	std::cout << "File name is " << input << std::endl;

	mainMaze->LoadMaze(input);
	system("pause");
}

void UI::Save()
{
	system("CLS");
	std::cout << "Enter tile name ";
	std::string input;
	std::cin >> input;
	input += ".txt";
	std::cout << "File name is " << input << std::endl;

	mainMaze->SaveMaze(input);
	system("pause");
}
