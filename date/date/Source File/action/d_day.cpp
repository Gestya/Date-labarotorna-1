#include<iostream>
#include "action.h"

//Знаходження додаткового кофіциєнта для року.
int ind(int a)
{
	a /= 100;
	int re = 6;

	for (int b = 0; b != a; b++, re - 2)
	{
		if (re == -2)
			re = 6;
	}

	return re;
}

//Знаходження дня тижня.
void date::d_day()
{
	int f1;

	if (month == 1 || month == 10)
		f1 = 1;
	else if (month == 5)
		f1 = 2;
	else if (month == 8)
		f1 = 3;
	else if (month == 2 || month == 3 || month == 1)
		f1 = 4;
	else if (month == 6)
		f1 = 5;
	else if (month == 12 || month == 9)
		f1 = 6;
	else if (month = 4 || month == 7)
		f1 = 0;

	int inde;

	inde = ind(year);

	int f2 = (inde + year % 100 + (year % 100) / 4) % 7;

	int result = (day + f1 + f2) % 7;


	if (result == 0)
		std::cout  << "Is are saturday" << std::endl;
	else if (result == 1)
		std::cout  <<  "Is are sunday" << std::endl;
	else if (result == 2)
		std::cout  << "Is are monday" << std::endl;
	else if (result == 3)
		std::cout << std::endl << "Is are tuesday" << std::endl;
	else if (result == 4)
		std::cout << std::endl << "Is are wednesday" << std::endl;
	else if (result == 5)
		std::cout << std::endl << "Is are friday" << std::endl;
}
