#pragma once
#include <iostream>
#include "Enum.h"

class Card
{
private:
	Suit suit;
	Rank rank;
	char id[15];

public:
	Card();
	Card(Suit _suit, Rank _rank, const char* _id, int _points);
	bool operator== (const Card&);
	void change_id(const char*);

	void set_id(const char*);

	Suit getSuit() const;
	Rank getRank() const;
	int currPoints() const;

	friend std::ostream& operator << (std::ostream& out, Card& other)
	{
		out << other.getSuit()
			<< other.getRank()
			<< other.currPoints();

		return out;
	}
};