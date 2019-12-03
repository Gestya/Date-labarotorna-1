#include <iostream>
#include "../../Tree/function/action.h"


//Promotes all class values
void Data::showclass()
{
	std::cout << year << "y. " << month << "mo. " << day << "d. " << hour << "h. " << minute << "mi. " << second << "s. ";
}