#include<iostream>
#include "action.h"


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