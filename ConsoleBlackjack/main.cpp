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

struct Card
{
	Rank rank;
	Suit suit;

	Card(Rank r, Suit s) : rank(r), suit(s) {}

	std::string toString() const {
		return std::format("{} of {}", rankToString(rank), suitToString(suit));
	}
};

int main()
{
	Card card = { Rank::Jack, Suit::Hearts };
	std::cout << card.toString();
}