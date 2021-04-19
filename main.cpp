#pragma once
#include <iostream>
#include "Deck.h"
#include "Enum.h"
#include "Card.h"
#include "Vector.h"
#include"Player.h"


void toLower(char txt[])
{
	for (int i = 0; i < strlen(txt); i++)
	{
		if (txt[i] >= 'A' && txt[i] <= 'Z')
		{
			txt[i] = txt[i] + 32;
		}
	}
}

void game(Player& current)
{
	int choice = 0, pPoints = 0, dPoints = 0;
	int counter = 0; //counts how many cards we draw
	char word[16];
	do
	{
		std::cout << "Enter the deck size (number >= 52): ";
		std::cin >> choice;

	} while (choice < 52);
	Deck player_deck(choice);
	Card player_card, dealer_card;

	std::cout << "Start!" << std::endl;
	player_card = player_deck.draw();
	pPoints += player_card.currPoints();
	std::cout << player_card;
	
	std::cout << pPoints << std::endl;

	while (pPoints < 21 || dPoints < 17 || counter != choice)
	{
		std::cout << "\nHit/Stand/Probability" << std::endl;
		std::cout << "$ ";
		std::cin >> word;
		toLower(word);

		if (strcmp(word, "hit") == 0)
		{
			player_card = player_deck.draw();
			std::cout << player_card << std::endl;
			pPoints += player_card.currPoints();
			player_card = player_deck.draw();
			std::cout << player_card << std::endl;
			pPoints += player_card.currPoints();
			counter += 2;
		}
		else if (strcmp(word, "stand") == 0)
		{
			dealer_card = player_deck.draw();
			std::cout << dealer_card;
			dPoints += dealer_card.currPoints();
			dealer_card = player_deck.draw();
			std::cout << dealer_card;
			dPoints += dealer_card.currPoints();
			counter += 2;
		}
		else if (strcmp(word, "probability") == 0)
		{

		}
		else
			std::cout << "Wrong!";
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
	char playerName[128];
	bool isPlayer = false;
	Player demi("Ivan Kirkov", 37, 5, 0.8, 5);
	Player cveti("Niki Bankov", 4, 1.5);
	Player kayo("Ico Radoev", 5, 12.4);

	Vector<Player> logged;
	logged.push_back(demi);
	logged.push_back(cveti);
	logged.push_back(kayo);
	
	Player current;

	for (size_t i = 0; i < logged.getSize(); i++)
	{
		std::cout << logged[i] << std::endl;
	}

	std::cout << "Chose a player or enter a new player:  " << std::endl;

	std::cin.sync();
	std::cin.getline(playerName, 64);

	for (size_t i = 0; i < logged.getSize(); i++)
	{
		if (strcmp(playerName, logged[i].getName()) == 0)
		{
			isPlayer = true;
			current = logged[i];
			std::cout << "You will play as " << logged[i].getName() << std::endl;
			break;
		}
	}
	
	if (isPlayer == false)
	{
		std::cin >> current;
		std::cout << "You will play as " << current.getName();
	}
	game(current);




	//std::cout << demi;
	//Player demi = Player(alo);

	//Deck random = Deck();
	//std::cout << random << std::endl;

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
	return 0;
}