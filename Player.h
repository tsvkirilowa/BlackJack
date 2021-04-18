#pragma once
#include<iostream>
class Player
{
private:
	char* name;
	int age;
	int wins;
	double cWins;
	int currentPoints;

	void copy(const Player&);
	void destroy();

public:
	Player();
	Player(const char* _name, int _age, int _wins, double _cWins, int _currentPoints);
	Player(const char* _name, int _wins, double _cWins);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();

	const char* getName()const;

	void change_points(int _currPoints);

	friend std::ostream& operator<<(std::ostream& out, const Player& other);
	friend std::istream& operator>>(std::istream& in, Player& other);
};

