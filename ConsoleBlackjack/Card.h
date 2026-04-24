#pragma once

#include <string>
#include <format>

struct Card {
	int rank;
	char suit;

	Card(int rank, char suit) : rank(rank), suit(suit) {}

	std::string toString() const {
		return std::format("{}{}", rankToString(rank), suit);
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
