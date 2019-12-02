#include <iostream>
#include <cstdlib>
#include "../function/action.h"

// Converts seconds to the canonical data view
double get_num(double sec, int p)
{
	if (p == 1)
		return sec / 31536000;
	if (p == 2)
		return sec / 2592000;
	if (p == 3)
		return sec / 86400;
	if (p == 4)
		return sec / 3600;
	if (p == 5)
		return sec / 60;
	return 0;
}

double diferent(const Data& d1, const Data& d2)
{
	Data diferent;

	//translating values ​​to positive integers if a subtracted number is positive.
	diferent.year = std::abs(d1.year - d2.year);
	diferent.month = std::abs(d1.month - d2.month);
	diferent.day = std::abs(d1.day - d2.day);
	diferent.hour = std::abs(d1.hour - d2.hour);
	diferent.minute = std::abs(d1.minute - d2.minute);
	diferent.second = std::abs(d1.second - d2.second);

	std::cout << std::endl << "in diferent we get: ";
	diferent.showclass();
	double seco = diferent.get_se();

	int put = 0;
	
	do {
		std::cout << std::endl << "What type of time do you want get:";
		std::cout << "\n  1 - years\n  2- month\n  3 - days\n  4 - hors\n  5 - minutes\n  6 - seconds\nanswer: ";

		std::cin >> put;
		if (put < 1 || put > 6)
			std::cout << std::endl << "Wrong anser, try again." << std::endl;
	} while (put < 1 || put > 6);
	
	if (put != 6)
		return get_num(seco, put);
	else	
		return 0;
}
