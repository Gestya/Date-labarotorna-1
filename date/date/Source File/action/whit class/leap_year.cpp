#include<iostream>
#include "action.h"


//�������� ����������� ����.
bool date::leap_year()
{

	if (year % 400 == 0)
		return true;
	else if (year % 4 == 0 && year % 100 != 0)
		return true;
	else
		return false;
}