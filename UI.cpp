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
	mainMaze->Reset();
	system("CLS");

	std::cout << "Enter maximum height smaller than 52 and bigger than 8: ";
	int inputHeight;
	do {
		inputHeight = InputInt();
	} while (inputHeight > 51 || inputHeight < 9);

	std::cout << "Enter maximum width smaller than 52 and bigger than 8: ";
	int inputWidth;
	do {
		inputWidth = InputInt();
	} while (inputWidth > 51 || inputWidth < 9);

	std::cout << "Enter maximum players smaller than 5 and bigger than 1: ";
	int inputPlayers;
	do {
		inputPlayers = InputInt();
	} while (inputPlayers > 5 || inputPlayers < 2);
	std::cout << std::endl;

	for (int i = 9; i <= inputHeight; i += 2)
	{
		for (int j = 9; j <= inputWidth; j += 2)
		{
			for (int k = 2; k <= inputPlayers; k++)
			{
				int solved = 0, notSolved = 0, partSolved = 0;
				
				for (int l = 0; l < 100; l++)
				{
					
					mainMaze->SetHeight(i);
					mainMaze->SetWidth(j);
					mainMaze->SetExitNumber(k);
					mainMaze->GenerteMaze();
					mainMaze->GeneratePlayers();
					
					int state;
					do {
						state = mainMaze->Round();
						if (state == -1)
							notSolved++;
						else if (state == -2)
							solved++;
						else if (state == -3)
							partSolved++;

					} while (!state);

					mainMaze->Reset();
				}

			std::cout << "Generated 100 mazes." << std::endl
				<< "Width: " << j << std::endl
				<< "Height: " << i << std::endl
				<< "Players: " << k << std::endl
				<< "Number of solved mazes: " << solved << std::endl
				<< "Number of part solved mazes: " << partSolved << std::endl
				<< "Number of not solved mazes: " << notSolved << std::endl << std::endl;

			}
		}
	}

	system("pause");
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
