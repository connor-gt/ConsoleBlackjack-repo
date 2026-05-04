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

	do {
		std::unique_ptr<Deck> deck = std::make_unique<Deck>();
		deck->shuffle();
		playRound(player, *deck);

	} while (askPlayAgain());
}

void Blackjack::playRound(Player& player, Deck& deck) {
	std::cout << "Another round playing.\n";
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
