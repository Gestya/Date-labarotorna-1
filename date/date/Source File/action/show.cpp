#include <iostream>
#include "../../Header Files/function/action.h"


int show(tree *begin, int b)
{
	tree* showtree = begin;
	
	if(b != 0)
		std::cout << std::endl << b << ": ";
	else
		std::cout << std::endl << "Work with: ";

	showtree->d.showclass();
	

	if (b != 0)
	{
		b++;
		if (showtree->left)
			b = show(showtree->left, b);	
		if (showtree->right)
			b = show(showtree->right, b);
	}
	
	return b;
}

int max_number(tree *begin, int b)
{
	tree* showtree = begin;

	b++;

	if (showtree->left)
		b = max_number(showtree->left, b);
	if (showtree->right)
		b = max_number(showtree->right, b);
	return b;
}
