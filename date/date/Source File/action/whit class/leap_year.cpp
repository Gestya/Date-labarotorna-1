#include<iostream>
#include "action.h"


//перевірка високосного року.
bool date::leap_year()
{

	if (year % 400 == 0)
		return true;
	else if (year % 4 == 0 && year % 100 != 0)
		return true;
	else
		return false;
}