
/* linked - linked list functions
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
	
static *node head = NULL;


/************************************************************
 length - return length of a list
 ************************************************************/
int length() {
	int i = 0;
	while(head != NULL) {
		i++;
		head = head->next;
	}
	return i;
}


/************************************************************
 push - add new node at beginning of list
 ************************************************************/
void push(int data) {
	node *new = malloc(sizeof(node));
	new->value = data;
	new->next = head;
	head->value = new;
}

/************************************************************
 pop - delete node at beginning of non-empty list and return its data
 ************************************************************/
int pop(node *head) {
	int num; //the value at of the first node
	num = &head->value;
	head = &head->next;
	free(head);
	return num;
}

/************************************************************
 appendNode - add new node at end of list
 ************************************************************/
void appendNode(node *head, int data) {
	node *new = malloc(sizeof(data));
	node *iter;
	iter = head;
	while(iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = new;
	new->next = NULL;
	new->value = data;
	return head;
}

/************************************************************
 copyList - return new copy of list
 ************************************************************/
struct node* copyList(node *head) {
	node *new = malloc(sizeof(&head->value));

}

/************************************************************
 freeList - release all memory you allocated for the linked list.
 NOTE -- add a unit test that calls this function and observes
 that you returned 1 for success on freeing all memory.
 The instructor will verify that you correctly freed all
 allocated memory.
 ************************************************************/
int freeList() {
 
 // YOUR CODE HERE

  return 0 ;
}

