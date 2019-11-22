#include<iostream>
#include "action.h"

void date::write_class()
{
	int bb = 0;
	int check = 0;

	//додаванн€ року
	do{
		std::cout << "write year: ";
		std::cin >> bb;
		year = bb;
		if (year < 0)
		{
			perror("Error: you have write wronge year. Try again.");
			check = 0;
		}
		else
		{
			check = 1;
		}
	} while (check != 1);


	//додаванн€ м≥с€ц€ 
	do {
		std::cout << "write month: ";
		std::cin >> bb;
		month = bb;

		if (month > 12 || month < 1)
		{
			perror("Error: you have write wronge month. Try again.");
			check = 0;
		}
		else
		{
			check = 1;
		}
	} while (check != 1);

	//додаванн€ дн≥в 
	do {
		std::cout << "write day: ";
		std::cin >> bb;
		day = bb;

		if (day < 1)
		{
			perror("Error: you have write wronge day. Try again.");
			check = 0;
		}
		else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		{
			perror("Error: you have write wronge day. Try again.");
			check = 0;
		}
		else if (month == 2)
		{
			bool yr = leap_year(); // true - висок≥сний р≥к.

			if (yr && day > 29)
			{
				perror("Error: you have write wronge day. Try again.");
				check = 0;
			}
			else if (!yr && day > 28)
			{
				perror("Error: you have write wronge day. Try again.");
				check = 0;

			}
			else
			{
				check = 1;
			}
		}
		else if (day > 30)
		{
			perror("Error: you have write wronge day. Try again.");
			check = 0;
		}
		else
		{
			check = 1;
		}
	} while (check != 1);

	//додаванн€ годин
	do
	{
		std::cout << "write hour: ";
		std::cin >> bb;
		hour = bb;

		if (hour > 23 || hour < 0)
		{
			perror("Error: you have write wronge hour. Try again.");
			check = 0;
		}
		else
		{
			check = 1;
		}

	} while (check != 1);

	//додаванн€ хвилин
	do {
		std::cout << "write minute: ";
		std::cin >> bb;
		minute = bb;

		if (minute > 59 || minute < 0)
		{
			perror("Error: you have write wronge minute. Try again.");
			check = 0;
		}
		else
		{
			check = 1;
		}
	} while (check != 1);

	//додаванн€ секунд 
	do{
		std::cout << "write second: ";
		std::cin >> bb;
		second = bb;

		if (second > 59 || second < 0)
		{
			perror("Error: you have write wronge second. Try again.");
			check = 0;
		}
		else
		{
			check = 1;
		}

	} while (check != 1);

	showclass();
}