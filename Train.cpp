#include "Train.h"

Train::Train()
{
	number = "";
	destination = "";
	departureHours = -1;
	departureMinutes = -1;

	std::cout << "Standard constructor called.\n";
}


Train::Train(std::string trainNumber, std::string destination, 
	unsigned short departureHours, unsigned short departureMinutes)
{
	this->number = trainNumber;
	this->destination = destination;
	this->departureHours = departureHours;
	this->departureMinutes = departureMinutes;

	std::cout << "Parameterized constructor called.\n";
}

Train::Train(Train* copyFrom)
{
	number = copyFrom->number;
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
	this->number = trainNumber;
}

void Train::setDestination(std::string destination)
{
	this->destination = destination;
}

void Train::setDepartureHours(unsigned short departureHours)
{
	this->departureHours = departureHours;
}

void Train::setDepartureMinutes(unsigned short departureMinutes)
{
	this->departureMinutes = departureMinutes;
}

void Train::setDepartureTime(unsigned short departureHours, unsigned short departureMinutes)
{
	this->departureHours = departureHours;
	this->departureMinutes = departureMinutes;
}


std::string Train::getTrainNumber()
{
	return number;
}

std::string Train::getDestination()
{
	return destination;
}

std::pair<unsigned short, unsigned short> Train::getDepartureTime()
{
	return std::pair<unsigned short, unsigned short>(departureHours, departureMinutes);
}


bool operator>(const Train& leftHandSide, const Train& rightHandSide)
{
	return (leftHandSide.destination.compare(rightHandSide.destination)) > 0;
}

bool operator>=(const Train& leftHandSide, const Train& rightHandSide)
{
	return !(leftHandSide < rightHandSide);
}

bool operator<(const Train& leftHandSide, const Train& rightHandSide)
{
	return (leftHandSide.destination.compare(rightHandSide.destination)) < 0;
}

bool operator<=(const Train& leftHandSide, const Train& rightHandSide)
{
	return !(leftHandSide > rightHandSide);
}

std::ostream& operator<<(std::ostream& leftHandSide, const Train& rightHandSide)
{
	leftHandSide
		<< rightHandSide.number << " "
		<< rightHandSide.destination << " "
		<< rightHandSide.departureHours << ":"
		<< rightHandSide.departureMinutes << '\n';

	return leftHandSide;
}

void operator>>(Train& leftHandSide,
	std::tuple<std::string, std::string, unsigned short, unsigned short> rightHandSide)
{
	leftHandSide.number = std::get<0>(rightHandSide);
	leftHandSide.destination = std::get<1>(rightHandSide);
	leftHandSide.departureHours = std::get<2>(rightHandSide);
	leftHandSide.departureMinutes = std::get<3>(rightHandSide);
}

void operator>>(Train& leftHandSide,
	std::tuple<std::string, std::string, std::pair<unsigned short, unsigned short>> rightHandSide)
{
	leftHandSide.number = std::get<0>(rightHandSide);
	leftHandSide.destination = std::get<1>(rightHandSide);
	leftHandSide.departureHours = std::get<2>(rightHandSide).first;
	leftHandSide.departureMinutes = std::get<2>(rightHandSide).second;
}
