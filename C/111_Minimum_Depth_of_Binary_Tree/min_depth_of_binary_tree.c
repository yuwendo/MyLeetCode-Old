/*	
 * Problem Description - 111 minimum depth of binary tree
 *		Given a binary tree, find its minimum depth.
 *		The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
	struct TreeNode *left;
	struct TreeNode *right;
	int val;
};

int depth(struct TreeNode* root)
{
    return (1 + depth(root->left) + depth(root->right));
}

int minDepth(struct TreeNode* root) {

    int left=0, right=0;

    if (root == NULL)
        return (0);

    if (root->left==NULL && root->right==NULL)
        return (1);

    left = minDepth(root->left);
    right = minDepth(root->right);

    if (left == 0)
        return (right+1);

    else if (right ==0)
        return (left+1);

    return (left < right ? left+1 : right+1);
}


struct TreeNode *insert_binary_tree_node(struct TreeNode *root, int num)
{
	struct TreeNode *insert;
	struct TreeNode *current;
	struct TreeNode *parent;

	insert = (struct TreeNode *)malloc(sizeof(struct TreeNode));
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


int main(void)
{
	struct TreeNode *root=NULL;
	int num[8] = {4, 2, 1, 3, 7, 6, 9, 11};
	int i=0;

	for (i=0; i<8; i++)
	{
		printf("num[%d] - %d added to tree\n", i+1, num[i]);
		root = insert_binary_tree_node(root, num[i]);
	}

	printf("\n==========================================\n");
	printf("The minimum depth of binary tree is %d\n", minDepth(root));

	return (0);
}
