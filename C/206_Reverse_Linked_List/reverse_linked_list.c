/*
 * Problem Description - 206. Reverse Linked List 
 *		Reverse a singly linked list. 
 *
 * Reference - 
 *	1. https://algorithm.yuanbin.me/zh-tw/linked_list/reverse_linked_list.html
 *
 * Notification - 
 *
 */
#include <stdio.h>
#include <stdlib.h>


/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) 
{
	struct ListNode *reHead=NULL, *current=NULL, *tmp=NULL;

	if (head == NULL)
		return (NULL);
	if (head->next == NULL)
		return (head);

	current = head;
	while ( current != NULL)
	{
		tmp = current->next;
		current->next = reHead;
		reHead = current;
		current = tmp;
	}

	head = reHead;
	return (head);
}

struct ListNode *create_list_node(struct ListNode *root, int val)
{
	struct ListNode *addNode, *ptr;

	addNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	addNode->val = val;
	addNode->next = NULL;

	if (root==NULL)
		return (addNode);

	ptr = root;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = addNode;

	return (root);
}

int main(void)
{
	int nums[5]={10, 5, 20, 22, 33};
	int i=0;
	struct ListNode *root=NULL, *ptr=NULL;

	for(i=0; i<5; i++)
	{
		root = create_list_node(root, nums[i]);
	}

	printf("\n======================================\n");
	printf("The first lists :\n");
	ptr = root;
	while(ptr!=NULL)
	{
		printf("%2d, ", ptr->val);
		ptr = ptr->next;
	}

	printf("\nThe reverse lists :\n");
	root = reverseList(root);
	ptr = root;
	while(ptr!=NULL)
	{
		printf("%2d, ", ptr->val);
		ptr = ptr->next;
	}

	printf("\n\n");
	return (0);
}
