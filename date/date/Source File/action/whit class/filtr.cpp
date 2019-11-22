#include<iostream>
#include "action.h"


/*Функція що потрібна при додавання елемента у дерева, що б перевірити усі значення класу. 
Якщо програма повертає 3, то повернути ліворуч. Якщо  2 - праворуч. 
І у випадку 1, не додавати елемент, бо він вже є у дереві.*/
int date::filtr(tree* a, tree*b)
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
}