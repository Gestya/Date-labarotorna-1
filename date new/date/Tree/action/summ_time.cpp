#include<iostream>
#include"../function/action.h"


/*Adds some time to the selected item
in: Start pointer and index
out: Changes the index value and adds a new element*/
void summ_time(tree* begin, tree*& index)
{
	int type;
	int volume;
	Data summ;

	do{
			std::cout << std::endl << "What type of time do you want write:";
			std::cout << "\n  1 - years\n  2- month\n  3 - days\n  4 - hors\n  5 - minutes\n  6 - seconds\nanswer: ";

			std::cin >> type;
			if (type < 1 || type > 6)
				std::cout << std::endl << "Wrong anser, try again." << std::endl;
		}while (type < 1 || type > 6);

	std::cout << std::endl << "How much: ";
	std::cin >> volume;

	tree* newnode = new tree;
	
	//checks to record all values correctly
	if (type >= 6 && volume)
	{
		newnode->d.second = (volume + summ.second) % 60;
		volume = ((volume + summ.second) - newnode->d.second) / 60;
	}
	else
	{
		newnode->d.second = summ.second;
	}
	if (type >= 5 && volume)
	{
		newnode->d.minute = (volume + summ.minute) % 60 ;
		volume = ((volume + summ.minute) - newnode->d.minute) / 60;
	}
	else
	{
		newnode->d.minute = summ.minute;
	}
	if (type >= 4 && volume)
	{
		newnode->d.hour = (volume + summ.hour) % 24 ;
		volume = ((volume + summ.hour) - newnode->d.hour) / 24;
	}
	else
	{
		newnode->d.hour = summ.hour;
	}
	if (type >= 3 && volume)
	{
		if (newnode->d.month == 1 || newnode->d.month == 3 || newnode->d.month == 5 || newnode->d.month == 7 || newnode->d.month == 8 || newnode->d.month == 10 || newnode->d.month == 12)
		{
			newnode->d.day = volume % 31 + summ.day;
			volume = (volume - newnode->d.day) / 31;
		}
		else if (newnode->d.month == 2) 
		{
			bool yr = false; // true - leap year.

			if (newnode->d.year % 400 == 0)
				yr = true;
			else if (newnode->d.year % 4 == 0 && newnode->d.year % 100 != 0)
				yr = true;

			if (yr && newnode->d.day > 29)
			{
				newnode->d.day = (volume + summ.day) % 29;
				volume = ((volume + summ.day) - newnode->d.day) / 29;
			}
			else if (!yr && newnode->d.day > 28)
			{
				newnode->d.day = (volume + summ.day) % 28;
				volume = ((volume + summ.day) - newnode->d.day) / 28;
			}
		}
		else
		{
			newnode->d.day = (volume + summ.day) % 30;
			volume = ((volume + summ.day) - newnode->d.day) / 30;
		}
	
	}
	else
	{
		newnode->d.day = summ.day;
	}
	if (type >= 2 && volume)
	{
		newnode->d.month = (volume + summ.month) % 12;
		volume = ((volume + summ.month) - newnode->d.hour) / 12;
	}
	else
	{
		newnode->d.month = summ.month;
	}
	if (type >= 1 && volume)
	{
		newnode->d.year = volume + summ.year;
	}

	//Write a new item to a tree
	add_node_adres(begin, newnode);

	index = newnode;

}