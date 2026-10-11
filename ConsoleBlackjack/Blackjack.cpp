#include <iostream>
#include <optional>
#include <string>
#include <memory>
#include "Blackjack.h"
#include "Deck.h"
#include "Dealer.h"
#include "Round.h"

void Blackjack::start(Player& player) {
	std::cout << "------------------------------------------------\n";
	std::cout << "|                 Weclome to:                  |\n";
	std::cout << "|                  Blackjack                   |\n";
	std::cout << "------------------------------------------------\n";

	double startingBalance = player.getCash();
	std::unique_ptr<Dealer> dealer = std::make_unique<Dealer>();

	do {
		std::cout << "\n------------------------------------------------\n";
		std::cout << "Cash = $" << player.getCash() << std::endl;

		double bet = getBet(player);

		std::unique_ptr<Deck> deck = std::make_unique<Deck>();
		deck->shuffle();
		Round round(player, *dealer, *deck, bet);

		if (player.getCash() < 0.01) {
			std::cout << "No more cash in balance!\n";
			break;
		}

	} while (askPlayAgain(player));

	std::cout << "Thanks for playing! You started with $" << startingBalance << " and ended with $" << player.getCash() << ".\n";
}

bool Blackjack::askPlayAgain(Player& player) {
	char c = '?';

	do {
		std::string input;
		std::cout << "Play another round? Current balance: $" << player.getCash() << ". (Y/N): ";
		std::cin >> input;

		if (input.size() != 1) {
			continue;
		}

		c = std::toupper(input[0]);
	} while (c != 'Y' && c != 'N');

	return c == 'Y';
}

double Blackjack::getBet(Player& player) {
	std::string input;
	bool isValid;
	double bet;

	do {
		try {
			std::string input;
			std::cout << "Enter bet amount: $";
			std::cin >> input;

			bet = std::stod(input);

			// Make sure bet is valid by not being negative and that the player can afford it
			isValid = bet <= player.getCash() && bet > 0;
		} catch (...) {}
	} while (!isValid);

	return bet;
}
