#include "Train.h"

Train::Train()
{
	trainNumber = "";
	destination = "";
	departureHours = -1;
	departureMinutes = -1;

	std::cout << "Standard constructor called.\n";
}

Train::Train(std::string trainNumber, std::string destination,
	unsigned short departureHours, unsigned short departureMinutes)
{
	this->trainNumber = trainNumber;
	this->destination = destination;
	this->departureHours = departureHours;
	this->departureMinutes = departureMinutes;

	std::cout << "Parameterized constructor called.\n";
}

Train::Train(Train* copyFrom)
{
	trainNumber = copyFrom->trainNumber;
	destination = copyFrom->destination;
	departureHours = copyFrom->departureHours;
	departureMinutes = copyFrom->departureMinutes;

	std::cout << "Copy constructor called.\n";
}

Train::~Train()
{
	std::cout << "Destructor called.\n";
}

void Train::setTrainNumber(std::string trainNumber)
{
	this->trainNumber = trainNumber;
}

void Train::setDestination(std::string destination)
{
	this->destination = destination;
}

void Train::setDepartureTime(unsigned short departureHours, unsigned short departureMinutes)
{
	this->departureHours = departureHours;
	this->departureMinutes = departureMinutes;
}


std::string Train::getTrainNumber()
{
	return trainNumber;
}

std::string Train::getDestination()
{
	return destination;
}

std::pair<unsigned short, unsigned short> Train::getDepartureTime()
{
	return std::pair<unsigned short, unsigned short>(departureHours, departureMinutes);
}


std::ostream& operator<<(std::ostream& leftHandSide, const Train& rightHandSide)
{
	leftHandSide
		<< rightHandSide.trainNumber << " "
		<< rightHandSide.destination << " "
		<< rightHandSide.departureHours << " "
		<< rightHandSide.departureMinutes << '\n';

	return leftHandSide;
}

std::istream& operator>>(Train& leftHandSide,
	std::tuple<std::string, std::string, unsigned short, unsigned short> rightHandSide)
{
	leftHandSide.trainNumber = std::get<0>(rightHandSide);
	leftHandSide.destination = std::get<1>(rightHandSide);
	leftHandSide.departureHours = std::get<2>(rightHandSide);
	leftHandSide.departureMinutes = std::get<3>(rightHandSide);
}

std::istream& operator>>(Train& leftHandSide,
	std::tuple<std::string, std::string, std::pair<unsigned short, unsigned short>> rightHandSide)
{
	leftHandSide.trainNumber = std::get<0>(rightHandSide);
	leftHandSide.destination = std::get<1>(rightHandSide);
	leftHandSide.departureHours = std::get<2>(rightHandSide).first;
	leftHandSide.departureMinutes = std::get<2>(rightHandSide).second;
}
