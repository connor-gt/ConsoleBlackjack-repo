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

	Card(int rank, std::string suit) : rank(rank), suit(suit), hidden(false) {}
	Card(int rank, std::string suit, bool hidden) : rank(rank), suit(suit), hidden(hidden) {}

	std::vector<std::string> toString() const {
		return {
			"/---\\",
			hidden ? "|XXX|" : std::format("|{:<2} |", rank < 11 ? std::to_string(rank) : rankToString(rank)),
			hidden ? "|XXX|" : "|   |",
			hidden ? "|XXX|" : std::format("|  {}|", suit),
			"\\---/"
		};
	}

	static void render(const std::vector<Card>& cards) {
		for (int i = 0; i < rows; i++) {
			for (const Card& card : cards) {
				std::cout << card.toString()[i] << " ";
			}
			std::cout << std::endl;
		}
	}

	static void render(const Card& card) {
		for (int i = 0; i < rows; i++) {
			std::cout << card.toString()[i] << std::endl;
		}
	}

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
