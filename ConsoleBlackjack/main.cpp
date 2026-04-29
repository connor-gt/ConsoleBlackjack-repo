#include <iostream>
#include <vector>
#include <optional>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

int main()
{
	Card ace(14, "C");
	Card ten(10, "D");
	Card three(3, "S");
	Card jack(11, "H");
	Card queen(12, "D");
	Card six(6, "S");

	Hand h1;
	h1.hit(ace);
	h1.hit(jack);

	Hand h2;
	h2.hit(ten);
	h2.hit(three);
	h2.hit(six);
	h2.hit(ace);

	Hand h3;
	h3.hit(queen);
	h3.hit(ace);
	h3.hit(ace);

	Hand h4;
	h4.hit(jack);
	h4.hit(six);
	h4.hit(ace);

	Hand h5;
	h5.hit(ace);
	h5.hit(six);

	Hand h6;
	h6.hit(ace);
	h6.hit(ace);

	h1.render();
	std::cout << "h1 value: " << h1.evaluate() << "\n\n";

	h2.render();
	std::cout << "h2 value: " << h2.evaluate() << "\n\n";

	h3.render();
	std::cout << "h3 value: " << h3.evaluate() << "\n\n";

	h4.render();
	std::cout << "h4 value: " << h4.evaluate() << "\n\n";

	h5.render();
	std::cout << "h5 value: " << h5.evaluate() << "\n\n";

	h6.render();
	std::cout << "h6 value: " << h6.evaluate() << "\n\n";

	return 0;
}
