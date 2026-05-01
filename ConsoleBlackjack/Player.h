#pragma once

#include <string>
#include "Hand.h"

class Player {
public:
	Hand hand;
	Player(double startingCash);

private:
	double cash;
};
