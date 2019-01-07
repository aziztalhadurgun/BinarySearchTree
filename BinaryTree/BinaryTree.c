#include <stdio.h>
#include <stdlib.h>

struct n
{
	int data;
	struct n *left;
	struct n *right;
};
typedef struct n node;

node* insert(node *tree, int x) {
	if (tree == NULL)
	{
		node *root = (node*)malloc(sizeof(node));
		root->right = NULL;
		root->left = NULL;
		root->data = x;
		return root;
	}
	if (tree->data < x)
	{
		tree->right = insert(tree->right, x);
		return tree;
	}
	tree->left = insert(tree->left, x);
	return tree;
}

void InOrder(node *tree) {
 #pragma region LNR
 	/*if (tree == NULL)
 		return;
 	InOrder(tree->left);
 	printf("%d ", tree->data);
 	InOrder(tree->right);*/
 #pragma endregion

#pragma region RNL
	if (tree == NULL)
		return;
	//printf("%d ", tree->data);//root degerini basa yazar
	InOrder(tree->right);
	printf("%d ", tree->data);
	InOrder(tree->left);
#pragma endregion
}

int find(node *tree, int wanted) {
	//eger wanted deger bulunursa 1 bulunmazsa -1 basar;
	if (tree == NULL)
		return -1;
	if (tree->data == wanted)
		return 1;
	if (find(tree->left, wanted) == 1)
		return 1;
	if (find(tree->right, wanted) == 1)
		return 1;
	return -1;
}

int MAX(node *tree) {
	while (tree->right != NULL)
		tree = tree->right;
	return tree->data;
}

int MIN(node *tree) {
	while (tree->left != NULL)
		tree = tree->left;
	return tree->data;
}

node *del(node *tree, int x) {
	if (tree == NULL)
		return NULL;
	if (tree->data == x)
	{
		if (tree->right == NULL && tree->left == NULL)
			return NULL;
		if (tree->right != NULL)
		{
			tree->data = MIN(tree->right);
			tree->right = del(tree->right, MIN(tree->right));
			return tree;
		}
		tree->data = MAX(tree->left);
		tree->left = del(tree->left, MAX(tree->left));
		return tree;
	}
	if (tree->data <x)
	{
		tree->right = del(tree->right,x);
		return tree;
	}
	tree->left = del(tree->left, x);
	return tree;
}

int main() {
	node *tree = NULL;
	tree = insert(tree, 12);
	tree = insert(tree, 15);
	tree = insert(tree, 7);
	tree = insert(tree, 23);
	tree = insert(tree, 1);
	tree = insert(tree, 21);
	tree = insert(tree, 4);
	tree = insert(tree, 24);

	InOrder(tree);
	printf("\nsearch result: %d", find(tree, 21));
	printf("\nMax value: %d", MAX(tree));
	printf("\nMin value: %d", MIN(tree));
	printf("\n");
	tree = del(tree, 12);
	InOrder(tree);
	return 0;
}