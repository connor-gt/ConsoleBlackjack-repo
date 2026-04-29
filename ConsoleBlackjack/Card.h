#pragma once

#include <string>
#include <format>
#include <vector>
#include <iostream>

struct Card {
	int rank;
	std::string suit;
	bool hidden;
	static const int rows = 5; // The number of rows to be rendered (should match toString()'s number of elements)

	/**
	* Create a new card with the specified rank (should be a number 2 through 14) and suit.
	* 
	* @param rank The rank the card should be.
	* @param suit The suit the card should have.
	*/
	Card(int rank, std::string suit) : rank(rank), suit(suit), hidden(false) {}

	/**
	* Create a new card with the specified rank (should be a number 2 through 14), suit, and hidden modifier.
	*
	* @param rank The rank the card should be.
	* @param suit The suit the card should have.
	* @param hidden Whether or not this card is hidden if displayed.
	*/
	Card(int rank, std::string suit, bool hidden) : rank(rank), suit(suit), hidden(hidden) {}

	/**
	* Get the string representation of this card as a vector of 5 rows.
	* 
	* @return A vector of strings that are used to build the card.
	*/
	std::vector<std::string> toString() const {
		return {
			"/---\\",
			hidden ? "|XXX|" : std::format("|{:<2} |", rank < 11 ? std::to_string(rank) : rankToString(rank)),
			hidden ? "|XXX|" : "|   |",
			hidden ? "|XXX|" : std::format("|  {}|", suit),
			"\\---/"
		};
	}

	/**
	* Render a list of cards in place. All of the cards will be rendered on the same line, starting from cards[0].
	* 
	* @param cards A list of cards to render.
	*/
	static void render(const std::vector<Card>& cards) {
		for (int i = 0; i < rows; i++) {
			for (const Card& card : cards) {
				std::cout << card.toString()[i] << " ";
			}
			std::cout << std::endl;
		}
	}

	/**
	* Render a card in place. Only this card will be rendered on a line, any other render() calls will be rendered below.
	*
	* @param card The card to render.
	*/
	static void render(const Card& card) {
		for (int i = 0; i < rows; i++) {
			std::cout << card.toString()[i] << std::endl;
		}
	}

	/**
	* Convert the rank of a card to the string representation. 2 through 10 are converted to strings directly, 11 is converted
	* to "J", 12 to "Q", 13 to "K", and 14 to "A".
	* 
	* @param rank The integer rank of the card (2 - 14).
	* @return The string representation of the rank.
	*/
	std::string rankToString(int rank) const {
		switch (rank) {
			// Handle the face card cases. Otherwise, just turn the int to a string
			case 11:
				return "J";
			case 12:
				return "Q";
			case 13:
				return "K";
			case 14:
				return "A";
			default:
				return std::to_string(rank);
		}
	}
};
