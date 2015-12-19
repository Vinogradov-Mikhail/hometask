#include <iostream>
#include "workWithTr.h"

struct Trees
{
	int number;
	Trees *left;
	Trees *right;
	Trees *parent;
};

using namespace std;



void show(int symbol, Trees *Tree)
{
	if (Tree != NULL)
	{
		if (symbol == 1)
		{
			show(1, Tree->left);
			cout << Tree->number << " ";
			show(1, Tree->right);
		}
		else
		{
			show(2, Tree->right);
			cout << Tree->number << " ";
			show(2, Tree->left);
		}
	}
}



void add(int symbol, Trees *&Tree)
{
	if (NULL == Tree)
	{
		Tree = new Trees;
		Tree->number = symbol;
		Tree->left = Tree->right = NULL;
	}
	if (symbol < Tree->number)
	{
		if (Tree->left != NULL)
		{
			add(symbol, Tree->left);
		}
		else
		{
			Tree->left = new Trees;
			Tree->left->left = Tree->left->right = NULL;
			Tree->left->number = symbol;
		}
	}

	if (symbol > Tree->number)
	{
		if (Tree->right != NULL)
		{
			add(symbol, Tree->right);
		}
		else
		{
			Tree->right = new Trees;
			Tree->right->left = NULL;
			Tree->right->right = NULL;
			Tree->right->number = symbol;
		}
	}
}

bool search(int symbol, Trees *Tree)
{
	if (Tree != NULL)
	{

		if (symbol < Tree->number)
		{
			search(symbol, Tree->left);
		}

		if (symbol > Tree->number)
		{
			search(symbol, Tree->right);
		}
		if (symbol == Tree->number)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

Trees *&findMin(Trees *&Tree)
{
	while (Tree->left)
	{
		Tree->left;
	}
	return Tree;
}

void delElem(int symbol, Trees *&Tree)
{
	if (symbol < Tree->number)
	{
		delElem(symbol, Tree->left);
	}
	if (symbol > Tree->number)
	{
		delElem(symbol, Tree->right);
	}
	if (symbol == Tree->number)
	{
		if ((Tree->right == NULL) && (Tree->left != NULL))
		{
			Trees *old = Tree;
			Tree = old->left;
			delete old;
		}
		else
		{
			if ((Tree->right != NULL) && (Tree->left == NULL))
			{
				Trees *old = findMin(Tree->right);
				delete Tree;
				Tree = old;
			}
			else 
			{	   
				if ((Tree->right == NULL) && (Tree->left == NULL))
				{
					delete Tree;
					Tree = NULL;
				}
				else if ((Tree->right != NULL) && (Tree->left != NULL))
				{
					Trees *old2 = Tree->right;
					while (old2->left != nullptr)
					{
						old2 = old2->left;
					} 
					Tree->number = old2->number;
					delElem(old2->number, Tree->right);
				}
			}
		}
	}
}

void delTree(Trees *&Tree)
{
	if (Tree->right)
	{
		delTree(Tree->right);
	}
	if (Tree->left)
	{
		delTree(Tree->left);
	}
	delete Tree;
	Tree = NULL;
}