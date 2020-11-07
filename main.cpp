#include"UI.h"

int main()
{
	srand(time(NULL));

	UI main;

	int input;
	do {
		main.Welcome();
		main.Print();
		std::cin >> input;
		switch (input)
		{
		case 9:
			exit(0);
		case 1:
			main.SetDimentions();
			break;
		case 2:
			main.SetExitsNumber();
			break;
		case 3:
			main.GenerateMaze();
			break;
		case 4:
			main.Save();
			break;
		case 5:
			main.Load();
			break;
		case 6:
			main.Reset();
			break;
		case 7:
			main.Analyse();
			break;
			break;
		case 8:
			main.NextRound();
			break;

		default:
			std::cout << "Enter number 0 to 7";
			system("pause");
			break;
		}
	} while (true);

}