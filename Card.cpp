#include "Card.h"
#include <iostream>
#include <cstring>

Card::Card()
{
	suit = Spades;
	rank = Ace;
	strcpy_s(id, 8, "Default");
}

Card::Card(Suit _suit, Rank _rank, const char* _id, int _points)
{
	suit = _suit;
	rank = _rank;
	strcpy_s(id, strlen(_id) + 1, _id);
}

bool Card::operator==(const Card& other)
{
	return suit == other.suit && rank == other.rank;
}

void Card::change_id(const char* newID)
{
	if (newID != nullptr) {
		strcat_s(id, (strlen(id) + strlen(newID) + 1), newID);
	}
}

void Card::set_id(const char* _id)
{
	if (_id != nullptr)
	{
		strcpy_s(id, strlen(_id) + 1, _id);
	}
}

void Card::setPoints(int _points)
{
	this->points = _points;
}

Suit Card::getSuit() const
{
	return this->suit;
}

Rank Card::getRank() const
{
	return this->rank;
}

int Card::currPoints() const
{
	int p = (int)this->rank;
	int choice = 0;
	if (this->rank == J || this->rank == Q || this->rank == K)
	{
		return 10;
	}
	else if (this->rank == Ace)
	{
		std::cout << "Choose how many points you want to receive (1 or 11): ";
		std::cin >> choice;
		if (choice == 11)
		{
			return 11;
		}
		else return 1;
	}
	else return p;
}
