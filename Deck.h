#pragma once
#include "Card.h"
#include "Enum.h"
#include "Vector.h"
#include <vector>

class Deck
{
private:
	Vector<Card> cards;
	char id[10];
	size_t deck_size;

public:
	Deck();
	Deck(size_t _size);
	Deck(size_t _size, const char* deck_id);

	Vector<Card>& form_deck();
	void shuffle_deck(Vector<Card>&);
	bool inDeck(Card toCheck);

	size_t getDeck_size()const;

	Card& draw();
	void swap(size_t first, size_t second);
	int suit_count(Suit toCount);
	int rank_count(Rank toCount);

	friend std::ostream& operator<< (std::ostream& out, Deck& other)
	{
		out << other.deck_size;

		return out;
	}
	
};

