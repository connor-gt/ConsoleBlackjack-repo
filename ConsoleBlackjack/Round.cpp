#include "Round.h"

Round::Round(Player& player, Dealer& dealer, Deck& deck, double bet) : player(player), dealer(dealer), deck(deck), bet(bet) {
	initialize();

	std::string input;
	int handValue = 0;
	do {
		input = bettingPhase();
		handValue = this->player.hand.evaluate();

		std::cout << "\nDealer:\n\n";
		this->dealer.hand.render();

		std::cout << "\n\nPlayer:\n\n";
		this->player.hand.render();
		std::cout << "\nValue: " << handValue << "\n\n";
	} while (input != "S" && handValue <= 21);

	if (handValue > 21) {
		std::cout << "Bust!\n";
		return;
	}

	// Handle displaying the dealer's hidden card and draw cards for the dealer if needed
	dealer.hand.hideCard(1, false);
	std::cout << "\nDealer:\n\n";
	dealer.hand.render();
	std::cout << "\nValue: " << dealer.hand.evaluate() << "\n\n";

	std::cout << "\n\nPlayer:\n\n";
	player.hand.render();
	std::cout << "\nValue: " << player.hand.evaluate() << "\n\n";

	while (dealer.hand.evaluate() < dealer.minHandValue) {
		std::cout << "Dealer drawing card...\n";

		std::optional<Card> card = deck.deal();
		if (card) {
			dealer.hand.addCard(card.value());
		}

		std::cout << "\nDealer:\n\n";
		dealer.hand.render();
		std::cout << "\nValue: " << dealer.hand.evaluate() << "\n\n";

		std::cout << "\n\nPlayer:\n\n";
		player.hand.render();
		std::cout << "\nValue: " << player.hand.evaluate() << "\n\n";
	}
	
	int playerHand = player.hand.evaluate();
	int dealerHand = dealer.hand.evaluate();
	if (dealerHand > 21 || playerHand > dealerHand) {
		// Add winning funds to the player
		this->bet *= 2;
		this->player.setCash(this->player.getCash() + this->bet);

		std::cout << "Player wins! $" << this->bet << " has been credited to the balance.\n";
	}
	else if (playerHand < dealerHand) {
		std::cout << "Dealer wins!\n";
	}
	else {
		this->player.setCash(this->player.getCash() + this->bet);

		std::cout << "Tie! The initial bet of $" << this->bet << " has been credited to the balance.\n";
	}
}

void Round::initialize() {
	player.setCash(player.getCash() - bet);

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
		std::cout << "(H) Hit  (S) Stand  (D) Double ($" << bet << " bet, $" << player.getCash() << " remaining balance) => ";
		std::cin >> input;

		if (input.size() > 1) {
			continue;
		}

		input[0] = std::toupper(input[0]);

		if (input == "D" && bet > player.getCash()) {
			std::cout << "Not enough cash to double down.\n";
			input = "d"; // Change to lowercase to run the loop again
			continue;
		}

	} while (input != "H" && input != "S" && input != "D");

	if (input == "S") {
		return input;
	}
	else if (input == "D") {
		player.setCash(player.getCash() - bet);
		bet *= 2;
	}

	std::optional<Card> card = deck.deal();
	if (card) {
		player.hand.addCard(card.value());
	}

	return input;
}
