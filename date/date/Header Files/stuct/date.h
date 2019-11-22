#pragma once
#include <stdio.h>

struct tree;

class date
{
private:
	int year, month, day, hour, minute, second;

public:
	
	void write_class();
	static int filtr(tree* a, tree* b);
	void showclass();
	void d_day();
	int diferent(tree * ind, tree * index);
	double get_se();
	void summ_time(tree* begin, tree*& index);
	bool leap_year();
};