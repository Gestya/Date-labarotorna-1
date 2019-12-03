#include<iostream>
#include "../../Tree/function/action.h"


//translate all values in seconds for future reference. 
double Data::get_se()
{
	double result = 0;

	result += 31536000 * year;
	result += 2592000 * month;
	result += 86400 * day;
	result += 3600 * hour;
	result += 60 * minute;
	result += second;

	return result;
}