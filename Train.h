#pragma once
#include <string>
#include <iostream>
#include <tuple>
class Train
{
public:
	std::string trainNumber, destination;
	unsigned short departureHours, departureMinutes;
public:
	Train();
	Train(std::string trainNumber, std::string destination,
		unsigned short departureHours, unsigned short departureMinutes);
	Train(Train* copyFrom);

	~Train();

	void setTrainNumber(std::string trainNumber);
	void setDestination(std::string destination);
	void setDepartureTime(unsigned short departureHours, unsigned short departureMinutes);

	std::string getTrainNumber();
	std::string getDestination();
	std::pair<unsigned short, unsigned short> getDepartureTime();

	friend std::ostream& operator<<(std::ostream& leftHandSide, const Train& rightHandSide);
	friend std::istream& operator>>(Train& leftHandSide,
		std::tuple<std::string, std::string, unsigned short, unsigned short> rightHandSide);
};

std::ostream& operator<<(std::ostream& leftHandSide, const Train& rightHandSide);
std::istream& operator>>(Train& leftHandSide,
	std::tuple<std::string, std::string, unsigned short, unsigned short> rightHandSide);
std::istream& operator>>(Train& leftHandSide,
	std::tuple<std::string, std::string, std::pair<unsigned short, unsigned short>> rightHandSide);