#include<iostream>
#include "../../Tree/function/action.h"


/*Function needed when adding an element to trees to check all class values.
If the program returns 3, then turn left. If 2 - right.
And in case 1, do not add an element because it is already in the tree.*/
/*int Data::filtr(tree* a, tree*b)
{
	if (a->d.year < b->d.year)
		return 3;
	else if (a->d.year > b->d.year)
		return 2;

	if (a->d.month < b->d.month)
		return 3;
	else if (a->d.month > b->d.month)
		return 2;

	if (a->d.day < b->d.day)
		return 3;
	else if (a->d.day > b->d.day)
		return 2;

	if (a->d.hour < b->d.hour)
		return 3;
	else if (a->d.hour > b->d.hour)
		return 2;

	if (a->d.minute < b->d.minute)
		return 3;
	else if (a->d.minute > b->d.minute)
		return 2;

	if (a->d.second < b->d.second)
		return 3;
	else if (a->d.second > b->d.second)
		return 2;

	return 1;
}*/