#pragma once
#include <stdio.h>

struct tree;

class Data
{
private:
	int year{ 0 };
	int month{ 0 };
	int day{ 0 };
	int hour{ 0 };
	int minute{ 0 };
	int second{ 0 };

public:
	void write_class();
	//static int filtr(tree* a, tree* b);
	void showclass();
	void d_day();
	// int diferent(const Data& d1, const Data& d2); // (tree* ind, tree* index);
	double get_se();
	bool leap_year();

	friend bool operator==(const Data& d1, const Data& d2);
	friend bool operator!=(const Data& d1, const Data& d2);
	friend bool operator<(const Data& d1, const Data& d2);
	
	friend void summ_time(tree* begin, tree*& index);
	friend double diferent(const Data& d1, const Data& d2);
};

inline bool operator==(const Data& d1, const Data& d2)
{
	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day
		&& d1.hour == d2.hour && d1.minute == d2.minute && d1.second == d2.second;
}

inline bool operator!=(const Data& d1, const Data& d2)
{
	return !(operator==(d1, d2));
}

inline bool operator<(const Data& d1, const Data& d2)
{
	return (d1.year < d2.year)
		|| (d1.year == d2.year && d1.month < d2.month)
		|| (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)
		|| (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day && d1.hour < d2.hour)
		|| (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day && d1.hour == d2.hour && d1.minute < d2.minute)
		|| (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day && d1.hour == d2.hour && d1.minute == d2.minute && d1.second < d2.second);

}
