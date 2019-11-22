#include <iostream>

#include "menu.h"

//6.9



int main()
{

	bool check = true;


	for (;;)
	{
		if (check)
			std::cout << "Strat program?\n  y - yes\n  n - no\nanswer: ";

		char answer = 0;
		std::cin >> answer;

		if (answer == 'y' || answer == 'n')
		{
			check = true;

			if (answer == 'y')
				start_menu();
			else if (answer == 'n')
				break;
		}
		else
		{
			std::cout << "  wronge answer, try again!\nanswer:";
			check = false;
		}
	}

	std::cout << std::endl << "End of wroking program." << std::endl;
	return 0;
}
