/*
 * Problem Description - 226 invert binary tree
 * 	Example:
 *
 * 		  4							4
 * 		/   \					  /   \
 *     2     7			to 		 7	   2
 * 	  / \   / \					/ \   / \
 * 	 1   3 6   9			   9   6 3   1
 *
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

TreeNode *insert_binary_tree_node(TreeNode *root, int num)
{
	TreeNode *insert;
	TreeNode *current;
	TreeNode *parent;

	insert = (TreeNode *)malloc(sizeof(TreeNode));
	insert->val = num;
	insert->left = NULL;
	insert->right = NULL;

	if (root==NULL)
		return (insert);

	current = root;
	while (current!=NULL)
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

void print_binary_tree(TreeNode *root)
{
	if (root==NULL){
		printf("END");
		return;
	}
	printf("%2d, ", root->val);
	printf("\nleft tree: ");	
	print_binary_tree(root->left);
	printf("\nright tree: ");
	print_binary_tree(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) 
{
	TreeNode *tmp = NULL;

	if (root==NULL)
		return (root);	
    
	tmp = root->left;			/* swap tree */
	root->left = root->right;
	root->right = tmp;

	invertTree(root->left);		/* invert left tree*/	
	invertTree(root->right);	/* invert right tree */

	return (root);
}

int main(void)
{
	TreeNode *root=NULL;
	int num[7] = {4, 2, 1, 3, 7, 6, 9};
	int i=0;

	for (i=0; i<7; i++)
	{
		printf("num[%d] - %d added to tree\n", i+1, num[i]);
		root = insert_binary_tree_node(root, num[i]);
	}

	printf("\n==========================================\n");
	print_binary_tree(root);

	printf("\n==========================================\n");
	printf("Invert the binary tree\n");
	invertTree(root);

	printf("\n==========================================\n");
	print_binary_tree(root);

	free(root);	
	return (0);
}
