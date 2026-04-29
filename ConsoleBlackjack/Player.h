#pragma once

#include "Hand.h"
#include "PlayerAction.h"

class Player {
public:
	Hand hand;
	Player(double startingCash);
	PlayerAction getInput();

private:
	double cash;
};
