#include<iostream>
#include"../../Header Files/function/action.h"

int deeping(tree* begin, tree*& end, int b, int bb)
{
	if (b == bb)
		end = begin;
	b++;
	if (begin->left != nullptr)
		b = deeping(begin->left, end, b, bb);
	if (begin->right != nullptr)
		b = deeping(begin->right, end, b, bb);
	return b;
}


tree* found(tree *begin)
{
	for (;;)
	{	
		tree* ending = nullptr;


		int in = 1;
		std::cout << std::endl << "write your index: ";
		std::cin >> in;

		if (in < max_number(begin, 1))
		{
			deeping(begin, ending, 1, in);
			return ending;
		}
		else
		{
			std::cout << "Wronge answer, try again.\n\n";
		}
	}
}
