#include "Player.h"

void Player::copy(const Player& other)
{
	strcpy_s(name, strlen(other.name) + 1, other.name);
	age = other.age;
	wins = other.wins;
	cWins = other.cWins;
	currentPoints = other.currentPoints;
}

void Player::destroy()
{
	delete[] this->name;
}

Player::Player()
{
	strcpy_s(name, 8, "Default");
	age = 18;
	wins = 0;
	cWins = 0.0;
	currentPoints = 0;
}

Player::Player(const char* _name, int _age, int _wins, double _cWins, int _currentPoints)
{
	if (_name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}
	age = _age;
	wins = _wins;
	cWins = _cWins;
	currentPoints = _currentPoints;
}

Player::Player(const char* _name, int _wins, double _cWins)
{
	if (_name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}
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
		destroy();
		copy(other);
	}

	return *this;
}

Player::~Player()
{
	destroy();
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
	bool Capital = false, two = false;
	int counter = 0, position1 = 0;
	in.getline(other.name, 128);
	do
	{
		Capital = false; two = false;
		counter = 0; position1 = 0;
		for (size_t i = 0; i < strlen(other.name); i++)
		{
			if (other.name[i] == ' ')
			{
				counter++;
				if (position1 == 0)
				{
					position1 = i;
				}
			}
		}
		if (counter != 1)
		{
			std::cout << "Write your name and last name:\n";
			Capital = false; two = false;
			counter = 0; position1 = 0;
			in.getline(other.name, 32);
		}
		else {
			two = true;
			if ((other.name[0] <= 'A' || other.name[0] >= 'Z') || (other.name[position1 + 1] <= 'A' || other.name[position1 + 1] >= 'Z'))
			{
				std::cout << "enter name with capital letters\n";
				Capital = false; two = false;
				counter = 0; position1 = 0;
				in.getline(other.name, 32);
			}
			if ((other.name[0] >= 'A' && other.name[0] <= 'Z') && (other.name[position1 + 1] >= 'A' && other.name[position1 + 1] <= 'Z'))
			{
				Capital = true;
			}
		}
	} while (Capital == false && two == false);

	std::cout << "Age:";
	in >> other.age;
	while (other.age < 18 || other.age > 90)
	{
		std::cout << "You are not allowed to play:" << std::endl;
		in >> other.age;
	}

	std::cout << "Wins: ";
	in >> other.wins;
	std::cout << "Coeficient Wins: ";
	in >> other.cWins;

	return in;
}
