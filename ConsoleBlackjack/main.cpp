#include <iostream>
#include <vector>
#include <optional>
#include "Blackjack.h"

int main()
{
	std::unique_ptr<Player> player = std::make_unique<Player>(100);
	std::cout << "Cash = $" << player.get()->getCash() << std::endl;
	Blackjack blackjack;
	blackjack.start(*player);

	return 0;
}
