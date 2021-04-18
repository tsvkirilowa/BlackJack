#include "Deck.h"
#include <cstring>
#include <stdlib.h>
#include <time.h> 

Deck::Deck()
{
	cards = form_deck();
	shuffle_deck(cards);
	this->deck_size = 52;
	strcpy_s(id, 8, "Default");
}

Deck::Deck(size_t _size)
{
	strcpy_s(id, 7, "Custom");

	size_t full_deck = _size / 52; //shows how many times we have to fill a standart deck
	size_t cards_left = _size % 52; //swohs how many cards should we add more
	Vector<Card> helperDeck = form_deck();
	shuffle_deck(helperDeck);
	Card helperCard;

	if (_size > 52)
	{
		//cards.clear();
		while (full_deck != 0)
		{
			for (size_t r = 0; r < 13; r++)
			{
				//r for card rank
				for (size_t s = 0; s < 4; s++)
				{
					//s for card suit
					Card temp((Suit)s, (Rank)r, "custom");
					temp.change_id(this->id);
					cards.push_back(temp);
				}
			}
			full_deck -= 1;
		}

		for (size_t i = 0; i < cards_left; i++)
		{
			helperCard = helperDeck.pop();
			cards.push_back(helperCard);
		}
	}

	shuffle_deck(cards);
}

Deck::Deck(size_t _size, const char* deck_id)
{
	strcpy_s(id, strlen(deck_id) + 1, deck_id);

	size_t full_deck = _size / 52; //shows how many times we have to fill a standart deck
	size_t cards_left = _size % 52; //swohs how many cards should we add more
	Vector<Card> helperDeck = form_deck();
	shuffle_deck(helperDeck);
	Card helperCard;

	if (_size > 52)
	{
		//cards.clear();
		while (full_deck != 0)
		{
			for (size_t r = 0; r < 13; r++)
			{
				//r for card rank
				for (size_t s = 0; s < 4; s++)
				{
					//s for card suit
					Card temp((Suit)s, (Rank)r, "custom");
					cards.push_back(temp);
				}
			}
			full_deck -= 1;
		}

		for (size_t i = 0; i < cards_left; i++)
		{
			helperCard = helperDeck.pop();
			cards.push_back(helperCard);
		}
	}

	shuffle_deck(cards);
}

Vector<Card>& Deck::form_deck()
{
	this->deck_size = 52;
	//cards.clear();
	for (size_t r = 0; r < 13; r++)
	{
		//r for card rank
		for (size_t s = 0; s < 4; s++)
		{
			//s for card suit
			Card temp((Suit)s, (Rank)r, "default");
			cards.push_back(temp);
		}
	}

	return cards;
}

void Deck::shuffle_deck(Vector<Card>& toShuffle)
{
	srand(time(NULL));
	for (int i = 0; i < toShuffle.getSize(); i++)
	{
		int r = i + (rand() % (toShuffle.getSize() - i));
		Deck::swap(i, r);
	}
}

bool Deck::inDeck(Card toCheck)
{
	for (size_t i = 0; i < deck_size; i++)
	{
		if (cards[i] == toCheck)
		{
			return true;
		}
	}

	return false;
}

size_t Deck::getDeck_size() const
{
	return this->deck_size;
}

Card& Deck::draw()
{
	Card drawn = cards.pop();
	cards.push_back(drawn);

	return cards[cards.getSize() - 1];
}

void Deck::swap(size_t first, size_t second)
{
	Card temp;

	cards[first] = temp;
	cards[first] = cards[second];
	cards[second] = temp;
}

int Deck::suit_count(Suit toCount)
{
	int counter = 0;
	int suit_count = (int)toCount;

	for (size_t i = 0; i < deck_size; i++)
	{
		if (cards[i].getSuit() == suit_count)
		{
			counter++;
		}
	}

	return counter;
}

int Deck::rank_count(Rank toCount)
{
	int counter = 0;
	int rank_count = (int)toCount;
	
	//Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Q, K
	for (size_t i = 0; i < deck_size; i++)
	{
		if (cards[i].getRank() == rank_count)
		{
			counter++;
		}
	}

	return counter;
}


