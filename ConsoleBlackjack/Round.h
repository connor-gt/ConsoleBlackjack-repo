#pragma once

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

class Round {
public:
	/**
	* Play a single round of Blackjack.
	*
	* @param player The player reference.
	* @param dealer The dealer reference.
	* @param deck A reference to the deck that should be used.
	* @param bet The player's starting bet for this round.
	*/
	Round(Player& player, Dealer& dealer, Deck& deck, double bet);

private:
	/**
	* Initialize the round by dealing 2 cards to the player and dealer, rendering their hands, and hiding the dealer's 2nd card.
	*/
	void initialize();

	/**
	* Give the player the options to hit, stand, or double down. This phase lasts until the player stands or busts.
	*/
	std::string bettingPhase();

	Player& player;
	Dealer& dealer;
	Deck& deck;
	double bet;
};
