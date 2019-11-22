#include<iostream>
#include"../../Header Files/function/action.h"

void date::summ_time(tree* begin, tree*& index)
{
	int type;
	int volume;

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

	if (type >= 6 && volume)
	{
		newnode->d.second = (volume + second) % 60;
		volume = ((volume + second) - newnode->d.second) / 60;
	}
	else
	{
		newnode->d.second = second;
	}
	if (type >= 5 && volume)
	{
		newnode->d.minute = (volume + minute) % 60 ;
		volume = ((volume + minute) - newnode->d.minute) / 60;
	}
	else
	{
		newnode->d.minute = minute;
	}
	if (type >= 4 && volume)
	{
		newnode->d.hour = (volume + hour) % 24 ;
		volume = ((volume + hour) - newnode->d.hour) / 24;
	}
	else
	{
		newnode->d.hour = hour;
	}
	if (type >= 3 && volume)
	{
		if (newnode->d.month == 1 || newnode->d.month == 3 || newnode->d.month == 5 || newnode->d.month == 7 || newnode->d.month == 8 || newnode->d.month == 10 || newnode->d.month == 12)
		{
			newnode->d.day = volume % 31 + day;
			volume = (volume - newnode->d.day) / 31;
		}
		else if (newnode->d.month == 2) 
		{
			bool yr = false; // true - високісний рік.

			if (newnode->d.year % 400 == 0)
				yr = true;
			else if (newnode->d.year % 4 == 0 && newnode->d.year % 100 != 0)
				yr = true;

			if (yr && newnode->d.day > 29)
			{
				newnode->d.day = (volume + day) % 29;
				volume = ((volume + day) - newnode->d.day) / 29;
			}
			else if (!yr && newnode->d.day > 28)
			{
				newnode->d.day = (volume + day) % 28;
				volume = ((volume + day) - newnode->d.day) / 28;
			}
		}
		else
		{
			newnode->d.day = (volume + day) % 30;
			volume = ((volume + day) - newnode->d.day) / 30;
		}
	
	}
	else
	{
		newnode->d.day = day;
	}
	if (type >= 2 && volume)
	{
		newnode->d.month = (volume + month) % 12;
		volume = ((volume + month) - newnode->d.hour) / 12;
	}
	else
	{
		newnode->d.month = month;
	}
	if (type >= 1 && volume)
	{
		newnode->d.year = volume + year;
	}


	tree* endtree = begin;
	tree* end1 = begin;

	int check = 0; //1 - такий елемент існує, 2 - рух праворуч, 3 - рух ліворуч.

	while (end1)
	{
		endtree = end1;
		check = date::filtr(newnode, end1);

		if (check == 1)
		{
			std::cout << std::endl << "Wrong! This element already here." << std::endl;
			break;
		}
		else if (check == 2)
			end1 = end1->right;
		else if (check = 3)
			end1 = end1->left;
	}


	if (check != 1)
		newnode->parent = endtree;
	if (check == 2)
		endtree->right = newnode;
	else if (check == 3)
		endtree->left = newnode;

	index = newnode;

}