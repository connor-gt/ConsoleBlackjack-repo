#include <iostream>
#include <vector>
#include <optional>
#include "Blackjack.h"

int main()
{
	Player player(100);
	Blackjack blackjack;
	blackjack.start(&player);

	return 0;
}
