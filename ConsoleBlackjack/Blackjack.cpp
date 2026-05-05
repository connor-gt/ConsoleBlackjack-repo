#include <iostream>
#include <optional>
#include <string>
#include "Blackjack.h"
#include "Card.h"

void Blackjack::start(Player& player) {
	std::cout << "------------------------------------------------\n";
	std::cout << "|                 Weclome to:                  |\n";
	std::cout << "|                  Blackjack                   |\n";
	std::cout << "------------------------------------------------\n";

	std::unique_ptr<Dealer> dealer = std::make_unique<Dealer>();

	do {
		std::unique_ptr<Deck> deck = std::make_unique<Deck>();
		deck->shuffle();
		playRound(player, *dealer, *deck);

	} while (askPlayAgain());
}

void Blackjack::playRound(Player& player, Dealer& dealer, Deck& deck) {
	player.hand.clear();
	dealer.hand.clear();

	for (int i = 0; i < 2; i++) {
		std::optional<Card> card = deck.deal();
		if (card) {
			player.hand.addCard(card.value());
		}

		card = deck.deal();
		if (card) {
			dealer.hand.addCard(card.value());
		}
	}

	std::cout << "\nDealer:\n";
	dealer.hand.render();

	std::cout << "\nPlayer:\n";
	player.hand.render();
}

bool Blackjack::askPlayAgain() {
	char c = '?';

	do {
		std::string input;
		std::cout << "Play another round? (Y/N): ";
		std::cin >> input;

		if (input.size() != 1) {
			continue;
		}

		c = std::toupper(input[0]);
	} while (c != 'Y' && c != 'N');

	return c == 'Y';
}
