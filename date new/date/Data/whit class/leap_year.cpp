#include<iostream>
#include "../../Tree/function/action.h"


//leap year check.
bool Data::leap_year()
{

	if (year % 400 == 0)
		return true;
	else if (year % 4 == 0 && year % 100 != 0)
		return true;
	else
		return false;
}