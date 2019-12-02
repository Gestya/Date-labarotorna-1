#include "../function/action.h"
#include <iostream>

/*The first addition that passes a pointer to the first element.
out: begin and first element of tree*/
tree* first_add()
{

	tree* tnode = new tree;

	tnode->d.write_class();

	return tnode;
}


/*adding an element to an existing tree.
in: Pointer to the first element of the tree.
out: new element*/
void add_node(tree* begin)
{
	tree* newtree = new tree;
	newtree->d.write_class();

	add_node_adres(begin, newtree);
	
}

void add_node_adres(tree* begin, tree* newtree)
{
	tree* endtree = begin;
	tree* end1 = begin;

	//int check = 0; //1 - such element exists, 2 - movement on the right, 3 - movement on the left.


	//cycle to find free place in tree
	while (end1)
	{
		endtree = end1;

		if (newtree->d == end1->d)
		{
			std::cout << std::endl << "Wrong! This element is already here." << std::endl;
			break;
		}
		else if (newtree->d < end1->d)
			end1 = end1->left;
		else
			end1 = end1->right;
	}


	if (newtree->d != endtree->d)
	{
		newtree->parent = endtree;
		if (newtree->d < endtree->d)
			endtree->left = newtree;
		else
			endtree->right = newtree;
	}
}
	