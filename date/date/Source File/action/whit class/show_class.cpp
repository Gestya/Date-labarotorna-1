#include <iostream>
#include "action.h"


//Пише класс
void date::showclass()
{
	std::cout << year << "y. " << month << "mo. " << day << "d. " << hour << "h. " << minute << "mi. " << second << "s. ";
}