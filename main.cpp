#include"MazeGame.h"

int main()
{

	MazeGame game(11, 11, 2);
	game.GenerteMaze();
	game.GeneratePlayers();
	game.Print();

	while (1)
	{
		system("CLS");
		game.Round();
		game.Print();

	}

}