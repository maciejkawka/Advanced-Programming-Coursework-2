#include"MazeGame.h"

int main()
{
	srand(time(NULL));


	MazeGame game(21, 21, 4);
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