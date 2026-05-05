#include "Round.h"

void Round::play(Player& player, Dealer& dealer, Deck& deck) {
	initialize(player, dealer, deck);
	bettingPhase(player, deck);
}

void Round::initialize(Player& player, Dealer& dealer, Deck& deck) {
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

void Round::bettingPhase(Player& player, Deck& deck) {
	std::string input;

	do {
		std::cout << "(H) Hit  (S) Stand  (D) Double => ";
		std::cin >> input;

		if (input.size() > 1) {
			continue;
		}

		input[0] = std::toupper(input[0]);
	} while (input != "H" && input != "S" && input != "D");

	std::cout << "You selected " << input << "\n";
}
