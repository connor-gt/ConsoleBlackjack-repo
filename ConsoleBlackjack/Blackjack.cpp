#include <iostream>
#include "Blackjack.h"

void Blackjack::play() {
	displayTitle();
}

void Blackjack::playRound(Player player, Deck deck) {

}

void Blackjack::displayTitle() {
	std::cout << "------------------------------------------------\n";
	std::cout << "|                 Weclome to:                  |\n";
	std::cout << "|                  Blackjack                   |\n";
	std::cout << "------------------------------------------------\n";
}
