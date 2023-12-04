#include "streamstask.h"

int task()
{
	int counter = 0;
	std::ifstream file("file.txt");
	std::string line, word;

	if (!file.is_open())
	{
		throw std::exception("Failed to open file!\n");
	}

	while (!(file.eof()))
	{
		std::getline(file, line);

		std::stringstream stringStream(line);

		while (stringStream >> word)
		{
			if (word.size() == 4) counter++;
		}
	}

	return counter;
}