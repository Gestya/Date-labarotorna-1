#include<iostream>
#include "../function/action.h"


/*Removing the initial element of a tree
in: the beginning of the tree, and the element.
out: Tree without that element change begin.*/
void spec_del(tree* dell, tree*& begin)
{
	tree* down = dell->left;

	while (down->right)
		down = down->right;
	down->right = dell->right;
	dell->right->parent = down; 

	if (!dell->parent)
		begin = down;
	else
	{
		if (dell->parent->right == dell)
			dell->parent->right = down;
		else
			dell->parent->left = down;

		down->parent = dell->parent;
	}
}

/*deletes the specified tree element.
in: the beginning of the tree, and the element.
out: Tree without that element, can be change begin.*/
void delet(tree* dell, tree*& begin)
{
	if (!dell->left && !dell->right)
	{
		if (!dell->parent)
			begin = nullptr;
		else if (dell->parent->left == dell)
			dell->parent->left = nullptr;
		else if (dell->parent->right == dell)
			dell->parent->right = nullptr;	
	}
	else if (!dell->parent)
	{
		if (dell->left && !dell->right)
			begin = dell->left;

		else if (dell->right && !dell->left)
			begin = dell->right;

		else
			spec_del(dell, begin);

	}
	else
	{

		if (dell->parent->left && !dell->parent->right)
		{
			if (dell->left && !dell->right)
			{
				dell->left->parent = dell->parent;
				dell->parent->left = dell->left;
			}
			else if (dell->right && !dell->left)
			{
				dell->right->parent = dell->parent;
				dell->parent->left = dell->right;
			} 
		}

		else  if (dell->parent->right && !dell->parent->left)
		{
			if (dell->left && !dell->right)
			{
				dell->left->parent = dell->parent;
				dell->parent->right = dell->left;
			}
			else if (dell->right && !dell->left)
			{
				dell->right->parent = dell->parent;
				dell->parent->right = dell->right;
			}
			
		}



		if (dell->right && dell->left)
			spec_del(dell, begin);
	}

	delete dell;
	

}