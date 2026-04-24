#include <iostream>
#include "Card.h"

int main()
{
	Card card1(13, 'H');
	std::cout << card1.toString() << std::endl;

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