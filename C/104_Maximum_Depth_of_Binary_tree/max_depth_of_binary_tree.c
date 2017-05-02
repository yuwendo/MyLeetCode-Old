/*
 * Problem Description - 104 Maximun Depth of Binary Tree
 * 		Given a binary tree, find its maximum depth.
 *		The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * 
 * Reference:
 * 	1. Tree consruction is refered to http://120.101.70.10/ds/doku.php?id=%E6%A8%B9%E7%9A%84%E7%A8%8B%E5%BC%8F
 *
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	struct TreeNode *left;
	struct TreeNode *right;
	int val;
}TreeNode;

int maxDepth(struct TreeNode* root) 
{
	int left=1, right=1;

	if (root == NULL)
		return (0);	

	left = left + maxDepth(root->left);
	right = right + maxDepth(root->right);

	return ((left>right) ? left : right);
}

void print_binary_tree(TreeNode *root)
{
	if (root != NULL)
	{
		printf("%2d, ", root->val);	/* root */

		printf("\nleft: ");
		print_binary_tree(root->left); /* left */

		printf("\nright: ");	
		print_binary_tree(root->right); /* right */
	}
}

TreeNode * insert_node_to_binary_tree(TreeNode *root, int num)
{
	TreeNode *insert;	
	TreeNode *now;
	TreeNode *parent;

	insert = (TreeNode *)malloc(sizeof(TreeNode));
	insert->val = num;
	insert->left = NULL;
	insert->right = NULL;

	if (root==NULL)
		return (insert);

	now = root;
	while(now!=NULL)
	{
		parent = now;
		if (num > now->val)
			now = now->right;
		else
			now = now->left;
	}

	if (num>parent->val)
		parent->right = insert;
	else
		parent->left = insert;
	
	return (root);
}

TreeNode *create_binary_tree(int num[], int size)
{
	TreeNode *root=NULL;
	int i=0;

	for (i=0; i<size; i++){
		root = insert_node_to_binary_tree(root, num[i]);
		printf("\nnum[%d] %d is added", i, num[i]);
	}

	return (root);
}

int main(void)
{
	int numbers[10]={5, 2, 3, 4, 7, 8, 1, 9, 6, 11};
	TreeNode *root;
	
	printf("\nStart to create binary tree\n");
	root = create_binary_tree(numbers, 10);
	printf("\n========================================\n");

	printf("\nPrint the tree information\n");
	print_binary_tree(root);
	printf("\n========================================\n");

	printf("\nThe depth is %d\n", maxDepth(root));

	free(root);
	return (0);
}
