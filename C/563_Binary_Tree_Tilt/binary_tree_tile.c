/*
 * Problem Description - 563 binary tree tilt
 * 	Given a binary tree, return the tilt of the whole tree.
 *
 * 	The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values 
 * 	and the sum of all right subtree node values. Null node has tilt 0.
 *
 *
 * Note:
 *	1. The sum of node values in any subtree won't exceed the range of 32-bit integer.
 *	2. All the tilt values won't exceed the range of 32-bit integer.
 *
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


int find_sub_tree_tilt(struct TreeNode *root)
{
	if (root==NULL)
		return (0);

	return (root->val + find_sub_tree_tilt(root->left) + find_sub_tree_tilt(root->right));
}

int findTilt(struct TreeNode* root) 
{
	int left_tilt=0, right_tilt=0;
	
	if (root==NULL)
		return (0);

	left_tilt = find_sub_tree_tilt(root->left);
	right_tilt = find_sub_tree_tilt(root->right);

	return (findTilt(root->left) + findTilt(root->right) + abs(left_tilt - right_tilt));
}

struct TreeNode *insert_node_to_binary_tree(struct TreeNode *root, int num)
{
	struct TreeNode *insert=NULL, *current=NULL, *parent=NULL;

	insert = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	
	insert->val = num;
	insert->left = NULL;
	insert->right = NULL;

	if (root == NULL)
		return (insert);

	current = root;
	while(current!=NULL)
	{
		parent = current;
		if (num > current->val)
			current = current->right;
		else
			current = current->left;
	}

	if (num > parent->val)
		parent->right = insert;
	else 
		parent->left = insert;

	return (root);
}

void print_binary_tree(struct TreeNode *root)
{
	if (root==NULL){
		printf(" 0\n");
		return;
	}

	printf("%2d, ", root->val);
	printf("\nleft : ");
	print_binary_tree(root->left);
	printf("\nright: ");
	print_binary_tree(root->right);
}

int main(void)
{
	struct TreeNode	*root=NULL;
	int num[6] = { 1, 2, 3, 4, 0, 5};
	int i=0, tilt;

	for (i=0; i<6; i++)
	{
		printf("%2d is added to tree.\n", num[i]);
		root = insert_node_to_binary_tree(root, num[i]);
	}

	printf("\n========================================\n");
	print_binary_tree(root);

	printf("\n========================================\n");
	tilt = findTilt(root);
	printf("The binary tree tilt is %d\n", tilt);

	return (0);
}

