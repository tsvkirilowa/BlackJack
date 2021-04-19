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
	Card(Suit _suit, Rank _rank, const char* _id);
	bool operator== (const Card&);
	void change_id(const char*);

	void set_id(const char*);

	Suit getSuit() const;
	Rank getRank() const;
	int currPoints() const;

	friend std::ostream& operator << (std::ostream& out, Card& other)
	{
		int s = (int)other.getSuit();
		int r = (int)other.getRank();

		//Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Q, K
		switch (r)
		{
		case 1:
			out << "Ace "; break;
		case 2:
			out << "Two "; break;
		case 3:
			out << "Three "; break;
		case 4:
			out << "Four "; break;
		case 5:
			out << "Five "; break;
		case 6:
			out << "Six "; break;
		case 7:
			out << "Seven "; break;
		case 8:
			out << "Eight "; break;
		case 9:
			out << "Nine "; break;
		case 10:
			out << "Ten "; break;
		case 11:
			out << "J "; break;
		case 12:
			out << "Q "; break;
		case 13:
			out << "K "; break;
		}

		//Clubs, Diamonds, Hearts, Spades
		switch (s)
		{
		case 0:
			out << "(clubs)"; break;
		case 1:
			out << "(diamonds)"; break;
		case 2:
			out << "(hearts)"; break;
		case 3:
			out << "(spades)"; break;
		}

		return out;
	}
};