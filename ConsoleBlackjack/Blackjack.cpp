#include <iostream>
#include <optional>
#include <string>
#include "Blackjack.h"
#include "Deck.h"
#include "Dealer.h"
#include "Round.h"

void Blackjack::start(Player& player) {
	std::cout << "------------------------------------------------\n";
	std::cout << "|                 Weclome to:                  |\n";
	std::cout << "|                  Blackjack                   |\n";
	std::cout << "------------------------------------------------\n";

	std::unique_ptr<Dealer> dealer = std::make_unique<Dealer>();

	do {
		std::cout << "\n------------------------------------------------\n";

		double bet = getBet();

		std::unique_ptr<Deck> deck = std::make_unique<Deck>();
		deck->shuffle();
		Round round(player, *dealer, *deck, bet);

	} while (askPlayAgain());
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

double Blackjack::getBet() {
	std::string input;
	bool isValid;
	double bet;

	do {
		try {
			std::string input;
			std::cout << "Enter bet amount: ";
			std::cin >> input;

			bet = std::stod(input);
			isValid = true;
		} catch (...) {}
	} while (!isValid);

	return bet;
}
