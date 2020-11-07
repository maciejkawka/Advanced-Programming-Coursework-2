#include"MazeGame.h"

int main()
{
	srand(time(NULL));


	MazeGame game(9, 9, 4);
	game.GenerteMaze();
	game.GeneratePlayers();
	game.Print();

	while (!game.Round())
	{	
		system("CLS");
		game.Print();
	}

	std::cout << "Game Over!!" << std::endl;

}