#include <algorithm>
#include <conio.h>
#include <vector>
#include "Train.h"
#include "streamstask.h"

int main()
{
	std::vector<Train> trains;
	Train newTrain;
	std::string newTrainNumber, newTrainDestination;
	
	std::pair<unsigned short, unsigned short> currentDepartureTime;

	unsigned short
		newTrainDepartureHours, newTrainDepartureMinutes,
		filterDepartureHours, filterDepartureMinutes,
		currentDepartureHours, currentDepartureMinutes;

	bool filterEmpty = true;

	char c;
	int index, option;

menu:
	std::cout
		<< "1. Add a train\n"
		<< "2. Remove a train\n"
		<< "3. Display train info\n"
		<< "4. Display trains departing after specific time\n"
		<< "5. Edit train info\n"
		<< "6. Scan file\n"
		<< "0. Exit\n\n";


keyscan:
	switch (c = _getch())
	{
	case '1':
		std::cout << "Enter train number: ";
		std::cin >> newTrainNumber;
		std::cout << "Enter train destination: ";
		std::cin >> newTrainDestination;
		std::cout << "Enter the hour of the train's departure: ";
		std::cin >> newTrainDepartureHours;
		std::cout << "Enter the minute of the train's departure: ";
		std::cin >> newTrainDepartureMinutes;

		newTrain >> std::tuple<std::string, std::string, unsigned short, unsigned short>
			(newTrainNumber, newTrainDestination, newTrainDepartureHours, newTrainDepartureMinutes);

		trains.push_back(newTrain);

		std::sort(trains.begin(), trains.end());

		break;
	case '2':
		std::cout << "Enter index of the train to be removed: ";
		std::cin >> index;
		trains.erase(trains.begin() + index);

		break;
	case '3':
		if (trains.empty())
			std::cout << "Nothing to display!\n";
		else
			for (Train a : trains) std::cout << a;

		break;
	case '4':
		std::cout << "Enter the hour of departure: ";
		std::cin >> filterDepartureHours;
		std::cout << "Enter the minute of departure: ";
		std::cin >> filterDepartureMinutes;

		for (Train a : trains)
		{
			currentDepartureTime = a.getDepartureTime();
			unsigned short currentDepartureHours = currentDepartureTime.first, 
				currentDepartureMinutes = currentDepartureTime.second;

			if (currentDepartureHours - filterDepartureHours > 1
				|| (currentDepartureHours == filterDepartureHours && currentDepartureMinutes >= filterDepartureMinutes))
			{
				std::cout << a;

				filterEmpty = false;
			}
		}

		if (filterEmpty) std::cout << "No trains leaving after this time!\n";
		break;
	case '5':
		std::cout << "Enter the index of the train you wish to edit: ";
		std::cin >> index;

		if (index < 0 || index >= trains.size())
		{
			std::cout << "No train with this index!\n";

			break;
		}

		std::cout << "Edit:\n"
			"1. Train number\n"
			"2. Train destination\n"
			"3. Train departure hour\n"
			"4. Train departure minute\n";
		std::cin >> option;

		std::cout << "Enter new value: ";

		switch (option)
		{
		case '1':
			std::cin >> newTrainNumber;
			trains[index].setTrainNumber(newTrainNumber);

			break;
		case '2':
			std::cin >> newTrainDestination;
			trains[index].setDestination(newTrainDestination);

			break;
		case '3':
			std::cin >> newTrainDepartureHours;
			trains[index].setDepartureHours(newTrainDepartureHours);

			break;
		case '4':
			std::cin >> newTrainDepartureMinutes;
			trains[index].setDepartureMinutes(newTrainDepartureMinutes);

			break;

		default:
			std::cout << "Nothing edited, returning to menu!\n";

			break;
		}

		std::sort(trains.begin(), trains.end());

		break;
	case '6':
		std::cout << "There are " << task() << " four-letter words in the file.\n";

		break;
	case '0':
		exit(0);
	default:
		goto keyscan;
	}

	goto menu;
}