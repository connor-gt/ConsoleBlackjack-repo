#pragma once

#include <string>
#include "Hand.h"

class Player {
public:
	Hand hand;
	Player(double startingCash);
	double getCash();
	void setCash(double cash);

private:
	double cash;
};
