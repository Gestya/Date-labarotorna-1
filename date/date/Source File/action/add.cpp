#include "action.h"
#include <iostream>

//����� ���������, �� ������ �������� �� ������ �������.
tree* first_add()
{

	tree* tnode = new tree;

	tnode->d.write_class();

	return tnode;
}

//������ ��������� ��������, ��� � ������ ������.
void add_node(tree* begin)
{
	tree* newtree = new tree;
	newtree->d.write_class();

	tree* endtree = begin;
	tree* end1 = begin;
	
	int check = 0; //1 - ����� ������� ����, 2 - ��� ��������, 3 - ��� ������.

	while (end1)
	{	
		endtree = end1;
		check = date::filtr(newtree, end1);

		if (check == 1)
		{
			std::cout << std::endl << "Wrong! This element already here." << std::endl;
			break;
		}
		else if (check == 2)
			end1 = end1->right;
		else if (check = 3)
			end1 = end1->left;
	}


	if(check != 1)
		newtree->parent = endtree;
	if (check == 2)
		endtree->right = newtree;
	else if (check == 3)
		endtree->left = newtree;

}
