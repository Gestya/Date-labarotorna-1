#include<iostream>
#include "../../Header Files/function/action.h"


// Перевод секунд у звичайний запис дати.
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

int date::diferent(tree *ind, tree *index)
{


	year = ind->d.year - index->d.year;
	if (year < 0)
		year *= (-1);

	month = ind->d.month - index->d.month;
	if (month < 0)
		month *= (-1);

	day = ind->d.day - index->d.day;
	if (day < 0)
		day *= (-1);

	hour = ind->d.hour - index->d.hour;
	if (hour < 0)
		hour *= (-1);

	minute = ind->d.minute - index->d.minute;
	if (minute < 0)
		minute *= (-1);

	second = ind->d.second - index->d.second;
	if (second < 0)
		second *= (-1);

	std::cout << std::endl << "in diferent we get: ";
	showclass();
	double seco = get_se();

	int put = 0;

	
	do {
		std::cout << std::endl << "What type of time do you want get:";
		std::cout << "\n  1 - years\n  2- month\n  3 - days\n  4 - hors\n  5 - minutes\n  6 - seconds\nanswer: ";

		std::cin >> put;
		if (put < 1 || put > 6)
			std::cout << std::endl << "Wrong anser, try again." << std::endl;
	}while (put < 1 || put > 6);
	
	if(put != 6)
		seco = get_num(seco, put);
	
	std::cout << "result: " << seco << std::endl;

	return 0;
}
