#pragma once

#include <string>
#include <format>
#include <vector>
#include <iostream>

struct Card {
	int rank;
	std::string suit;
	bool hidden;
	static const int rowsToRender = 5;

	Card(int rank, std::string suit) : rank(rank), suit(suit), hidden(false) {}
	Card(int rank, std::string suit, bool hidden) : rank(rank), suit(suit), hidden(hidden) {}

	std::vector<std::string> render() const {
		return {
			"/---\\",
			hidden ? "|XXX|" : std::format("|{:<2} |", rank < 11 ? std::to_string(rank) : rankToString(rank)),
			hidden ? "|XXX|" : "|   |",
			hidden ? "|XXX|" : std::format("|  {}|", suit),
			"\\---/"
		};
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
