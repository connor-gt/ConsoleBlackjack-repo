#include <iostream>
#include <optional>
#include "Blackjack.h"
#include "Card.h"

void Blackjack::start(Player& player) {
	std::cout << "------------------------------------------------\n";
	std::cout << "|                 Weclome to:                  |\n";
	std::cout << "|                  Blackjack                   |\n";
	std::cout << "------------------------------------------------\n";

	int count = 0;
	int max = 3000000;
	//bool playAgain = true;
	do {
		Deck deck;
		deck.shuffle();
		
		for (int i = 0; i < 3; i++) {
			std::optional<Card> card = deck.deal();

			if (card) {
				player.hand.addCard(card.value());
			}
		}

		if (count % 300000 == 0) {
			player.hand.render();
			std::cout << "\n";
		}

		/*
		player->hand.render();

		std::string response;
		std::cout << "Run again?: ";
		std::cin >> response;
		if (response == "N" || response == "n") {
			playAgain = false;
		}
		*/
		player.hand.clear();
		count++;
	} while (count <= max);
}

void Blackjack::playRound(Player& player, Deck deck) {

}
