#include "Round.h"

Round::Round(Player& player, Dealer& dealer, Deck& deck) : player(player), dealer(dealer), deck(deck) {
	initialize();

	std::string input;
	do {
		input = bettingPhase();
	} while (input != "S");
}

void Round::initialize() {
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

	// Hide the 2nd card in the dealer's hand
	dealer.hand.hideCard(1, true);
	std::cout << "\nDealer:\n\n";
	dealer.hand.render();

	std::cout << "\n\nPlayer:\n\n";
	player.hand.render();
	std::cout << "\nValue: " << player.hand.evaluate() << "\n\n";
}

std::string Round::bettingPhase() {
	std::string input;

	do {
		std::cout << "(H) Hit  (S) Stand  (D) Double => ";
		std::cin >> input;

		if (input.size() > 1) {
			continue;
		}

		input[0] = std::toupper(input[0]);
	} while (input != "H" && input != "S" && input != "D");

	if (input == "H") {
		
	}
	else if (input == "D") {

	}

	return input;
}
