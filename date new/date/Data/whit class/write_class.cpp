#include<iostream>
#include "../../Tree/function/action.h"


// Function with all validity checks of the recorded data value.
void Data::write_class()
{
	int bb = 0;
	int check = 0;

	//Check and record year
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


	//Check and record the month 
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

	//Checking and recording days
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
			bool yr = leap_year(); // true - a leap year.

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

	//додавання Checking and recording hours
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

	//Check and record minutes
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

	//додавання Check and record seconds
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