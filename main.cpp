#include <iostream>
#include <conio.h>
#include <vector>
#include "Train.h"

int main()
{
	std::vector<Train> trains;

	char c;
	int index;

menu:
	std::cout
		<< "1. Add a train\n"
		<< "2. Remove a train\n"
		<< "3. Display train info\n"
		<< "4. Remove 3D figure\n"
		<< "5. Display contents\n"
		<< "6. Save to file\n"
		<< "7. Load from file\n"
		<< "8. Copy last 2D figure (copy constructor)\n"
		<< "0. Exit\n\n";


keyscan:
	switch (c = _getch())
	{
	case '1':
		keeper.addFigure2D();

		break;
	case '2':
		keeper.addFigure3D();

		break;
	case '3':
		std::cout << "Enter index of 2D figure to be removed: ";
		std::cin >> index;
		keeper.removeFigure2D(index);

		break;
	case '4':
		std::cout << "Enter index of 3D figure to be removed: ";
		std::cin >> index;
		keeper.removeFigure3D(index);

		break;
	case '5':
		if (!keeper.describe()) std::cout << "Nothing to display!\n";

		break;
	case '6':
		keeper.save();

		std::cout << "Saved!\n";

		break;
	case '7':
		if (keeper.load())
			std::cout << "Loaded!\n";
		else
			std::cout << "Invalid save file!\n";

		break;
	case '8':
		if (keeper.copyLastFigure2D())
			std::cout << "Copied!\n";
		else
			std::cout << "No 2D figures to copy!\n";

		break;
	case '0':
		exit(0);
	default:
		goto keyscan;
	}

	goto menu;
}