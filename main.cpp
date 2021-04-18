#pragma once
#include <iostream>
#include "Deck.h"
#include "Enum.h"
#include "Card.h"
#include "Vector.h"
#include"Player.h"

void game(Player& current)
{
	int choice = 0;
	int pPoints = 0, dPoints = 0;
	char* word;
	do
	{
		std::cout << "Enter the deck size (more than 52): ";
		std::cin >> choice;

	} while (choice < 52);
	Deck player_deck(choice);
	Card player_card;

	std::cout << "Start!";
	player_card = player_deck.draw();
	std::cout << player_card;
	pPoints += player_card.currPoints();

	while (pPoints < 21 || dPoints < 17)
	{
		std::cout << "Hit/Stand/Probability\n $" << std::endl;
		std::cin >> word;

		if (word == "Hit")
		{
			player_card = player_deck.draw();
			std::cout << player_card;
			pPoints += player_card.currPoints();
		}
		else if (word == "Stand")
		{

		}
		else if (word == "Probability")
		{

		}
	}

	if (dPoints >= 17 && dPoints < 21)
	{
		if (dPoints > pPoints)
		{
			std::cout << "You loose!" << std::endl;
			current.change_points(-1);
		}
		else
		{
			std::cout << "You win!" << std::endl;
			current.change_points(1);
		}
	}
}

int main()
{
	char playerName[64];
	bool indexForName = true;
	Player demi("Ivan Ivanov", 19, 0.8);
	Player cveti("Petar Popov", 4, 1.5);
	Player kayo("Kiril Petkov", 5, 12.4);
	Deck newDeck;

	Player current;

	std::cout << demi;
	std::cout << cveti;
	std::cout << kayo;

	std::cout << "Chose a player or enter a new player:  " << std::endl;

	std::cin.sync();
	std::cin.getline(playerName, 64);

	if (strcmp(playerName, "Ivan Ivanov") == 0)
	{
		bool indexForName = false;
		std::cout << "You will play as Ivan Ivanov.";
		current = demi;
	}
	if (strcmp(playerName, "Petar Popov") == 0)
	{
		bool indexForName = false;
		std::cout << "You will play as Petar Popov.";
		current = cveti;
	}
	if (strcmp(playerName, "Kiril Petkov") == 0)
	{
		bool indexForName = false;
		std::cout << "You will play as Kiril Petkov.";
		current = kayo;
	}
	if (indexForName == true)
	{
		Player newplayer;
		std::cin >> newplayer;
		std::cout << "You will play as " << newplayer.getName();
		current = newplayer;
	}

	game(current);




	//std::cout << demi;
	//Player demi = Player(alo);

	Deck random = Deck();
	std::cout << random << std::endl;

	/*for (size_t i = 0; i < logged.size(); i++)
	{
		std::cout << logged[i] << std::endl;
	}*/

	/*std::cout << "Chose a player or enter a new player:  " << std::endl;

	std::cin.sync();
	std::cin.getline(playerName, 64);

	for (size_t i = 0; i < logged.size(); i++)
	{
		if (strcmp(playerName, logged[i].getName()) == 0)
		{
			bool indexForName = false;
			std::cout << "You will play as " << logged[i].getName() << std::endl;
			break;
		}
	}

	if (indexForName == true)
	{
		Player newplayer;
		std::cin >> newplayer;
		std::cout << "You will play as " << newplayer.getName() << std::endl;
	}*/
}