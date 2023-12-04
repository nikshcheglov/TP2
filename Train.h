#pragma once
#include <string>
#include <iostream>
#include <tuple>

class Train
{
private:
	std::string number, destination;
	unsigned short departureHours, departureMinutes;
public:
	Train();
	Train(std::string number, std::string destination,
		unsigned short departureHours, unsigned short departureMinutes);
	Train(Train* copyFrom); //конструктор копирования

	~Train();

	void setTrainNumber(std::string number);
	void setDestination(std::string destination);
	void setDepartureHours(unsigned short departureHours);
	void setDepartureMinutes(unsigned short departureMinutes);
	void setDepartureTime(unsigned short departureHours, unsigned short departureMinutes);

	std::string getTrainNumber();
	std::string getDestination();
	std::pair<unsigned short, unsigned short> getDepartureTime();

	friend bool operator>(const Train& leftHandSide, const Train& rightHandSide);
	friend bool operator>=(const Train& leftHandSide, const Train& rightHandSide);
	friend bool operator<(const Train& leftHandSide, const Train& rightHandSide);
	friend bool operator<=(const Train& leftHandSide, const Train& rightHandSide);

	friend std::ostream& operator<<(std::ostream& leftHandSide, const Train& rightHandSide);
	friend void operator>>(Train& leftHandSide,
		std::tuple<std::string, std::string, unsigned short, unsigned short> rightHandSide);
	friend void operator>>(Train& leftHandSide,
		std::tuple<std::string, std::string, std::pair<unsigned short, unsigned short>> rightHandSide);
};

bool operator>(const Train& leftHandSide, const Train& rightHandSide);
bool operator>=(const Train& leftHandSide, const Train& rightHandSide);
bool operator<(const Train& leftHandSide, const Train& rightHandSide);
bool operator<=(const Train& leftHandSide, const Train& rightHandSide);

std::ostream& operator<<(std::ostream& leftHandSide, const Train& rightHandSide);
void operator>>(Train& leftHandSide,
	std::tuple<std::string, std::string, unsigned short, unsigned short> rightHandSide);
void operator>>(Train& leftHandSide,
	std::tuple<std::string, std::string, std::pair<unsigned short, unsigned short>> rightHandSide);