#pragma once

#include "Player.h"

class Blackjack {
public:
	/**
	* Start a game of Blackjack.
	* 
	* @param player A reference to the player.
	*/ 
	void start(Player& player);

private:
	/**
	* Ask the player if they would like to play another round and validate the input.
	* 
	* @param player The player reference.
	*/
	bool askPlayAgain(Player& player);

	/**
	* Get the player's bet for this round and validate it.
	*
	* @param player The player reference.
	*/
	double getBet(Player& player);
};
