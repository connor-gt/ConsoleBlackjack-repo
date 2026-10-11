#include <iostream>
#include <vector>
#include <optional>
#include <memory>
#include "Blackjack.h"

int main()
{
	std::unique_ptr<Player> player = std::make_unique<Player>(100);
	Blackjack blackjack;
	blackjack.start(*player);

	return 0;
}
