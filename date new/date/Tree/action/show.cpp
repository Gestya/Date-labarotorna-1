#include <iostream>
#include "../function/action.h"

/*walks through all the elements of the tree, include a feature for writing the class.*/
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


/*determines the maximum number of elements in a tree
in: pointer to the beginning of the tree and B returning (B in the process indicates which item we stopped at).
return: maximum number of elements*/
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
