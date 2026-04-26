#include <iostream>
#include "Card.h"

int main()
{
	Card cards[3] = { Card(13, "H"), Card(4, "D", true), Card(10, "C") };

	for (int i = 0; i < 5; i++) {
		// Using Card& instead of just Card prevents copying the card and uses a reference, const makes sure the reference isn't modified
		for (const Card& card : cards) {
			std::cout << card.render()[i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	cards[1].hidden = false;
	cards[0].hidden = true;

	for (int i = 0; i < 5; i++) {
		for (const Card& card : cards) {
			std::cout << card.render()[i] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

/*
#include <format>
#include <iostream>
#include <string>

enum class Suit { Clubs, Diamonds, Hearts, Spades };
std::string suitToString(Suit suit)
{
	switch (suit) {
		case Suit::Clubs:
			return "Clubs";
		case Suit::Diamonds:
			return "Diamonds";
		case Suit::Hearts:
			return "Hearts";
		case Suit::Spades:
			return "Spades";
	}

	return "Unknown";
}

enum class Rank
{
	Ten,
	Jack,
	Queen,
	King,
	Ace
};
std::string rankToString(Rank rank)
{
	switch (rank) {
		case Rank::Ten:
			return "Ten";
		case Rank::Jack:
			return "Jack";
		case Rank::Queen:
			return "Queen";
		case Rank::King:
			return "King";
		case Rank::Ace:
			return "Ace";
	}

	return "Unknown";
}
*/