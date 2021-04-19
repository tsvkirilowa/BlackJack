#include "Player.h"
#include <iostream>

void Player::copy(const Player& other)
{
	strcpy_s(name, 128, other.name);
	age = other.age;
	wins = other.wins;
	cWins = other.cWins;
	currentPoints = other.currentPoints;
}

Player::Player()
{
	setName("Default Default");
	age = 18;
	wins = 0;
	cWins = 0.0;
	currentPoints = 0;
}

Player::Player(const char* _name, int _age, int _wins, double _cWins, int _currentPoints)
{
	setName(_name);
	age = _age;
	wins = _wins;
	cWins = _cWins;
	currentPoints = _currentPoints;
}

Player::Player(const char* _name, int _wins, double _cWins)
{
	strcpy_s(name, 128, _name);
	wins = _wins;
	cWins = _cWins;
}


Player::Player(const Player& other)
{
	copy(other);
}

Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

bool Player::isCorrect(const char* _name)
{
	int count = 0, space_index = 0;
	bool capitals = false;
	
	for (int i = 0; i < strlen(_name) + 1; i++)
	{
		if (_name[i] == ' ')
		{
			count++;
			space_index = i;
		}
	}
	if (count != 1)
	{
		return false;
	}

	if (_name[0] >= 'A' && _name[0] <= 'Z' &&
		_name[space_index + 1] >= 'A' && _name[space_index + 1] <= 'Z')
	{
		capitals = true;
	}

	return capitals;
}


void Player::setName(const char* _name)
{
	strcpy_s(this->name, 64, _name);
}

const char* Player::getName() const
{
	return this->name;
}

void Player::change_points(int _currPoints)
{
	currentPoints += _currPoints;
}

std::ostream& operator<<(std::ostream& out, const Player& other)
{
	out << "Name: " << other.name << std::endl
		<< "Age: " << other.age << std::endl
		<< "Wins: " << other.wins << std::endl
		<< "Coeficient Wins: " << other.cWins << std::endl
		<< "Current Points: " << other.currentPoints << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Player& other)
{
	std::cout << "Enter Player Name (First Last) : ";
	char _name[64];
	in.getline(_name, 128);
	while (other.isCorrect(_name) == false)
	{
		std::cout << "Wrong input! Example: (Default Default). Try again: ";
		in.getline(_name, 128);
	}
	strcpy_s(other.name, strlen(_name) + 1, _name);

	bool ageCheck = false; // flag is false

	while (ageCheck == false)
	{
		std::cout << "Age:(must be between 18 and 90 years) ";
		in >> other.age;

		if (other.age >= 18 && other.age <= 90)
		{
			ageCheck = true; // if the condition is satisfied, flag is true and loop stops
		}
	}

	std::cout << "Wins: ";
	in >> other.wins;

	std::cout << "Win Rate: ";
	in >> other.cWins;

	std::cout << "Current Points: ";
	in >> other.currentPoints;

	return in;
}