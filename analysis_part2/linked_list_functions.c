// Document Analysis project linked list functions
// L. Kiser Feb. 20, 2018

#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include "linked_list_functions.h"
#include "unit_tests.h"


// Implement this function first to create an initialized linked list node.
// It must allocate space for the passed string in the one_word structure.
// It must copy the passed string into that structure and sets its word count to 0.
// Assume that the passed word points is not NULL and is not an empty string.
// The calling function is responsible for passing a valid string.
// This function returns a pointer to the allocated node.
struct node* create_node( char *word ) {

	struct node* new;
	new = malloc(sizeof(struct node) + sizeof(struct node) + sizeof(struct word_entry));

	new->one_word.unique_word = malloc((strlen(word) + 1) * sizeof(char));

	char *temp;
	temp = new->one_word.unique_word;

	while(*word != '\0') {
		*new->one_word.unique_word = *word;
		new->one_word.unique_word++;
		word++;
	}
	*new->one_word.unique_word = '\0';
	new->one_word.unique_word = temp;
	
	new->one_word.word_count = 1;

	new->p_previous =  NULL;
	new->p_next =  NULL;
	return new;
}

// Inserts a node at the beginning of the linked list.
// Updates the passed set of pointers as needed based upon the addition that was done.
//
// It checks that p_list is not NULL. Checks that word is not NULL and is not an empty string. 
// Returns 0 for failure if either word test fails.
// Also on failure no change is made to the pointers in p_list.
//
// On success it returns a 1 and updates at least the passed p_head and p_current members of p_list.
// p_head and p_current will always point to the newly added node.
// When adding the first node to an empty list p_tail will also point to this same new node since it is the only node.
//
// Hint: use the create_node function to actually create the node.
// Hint: be sure to maintain both the p_previous and p_next pointers in each node.
int add_node_at_head( struct linked_list *p_list, char *word ) {
	//p_list = malloc(sizeof(struct linked_list));
	if((p_list == NULL) || (word == NULL)) {
		return 0; 
	}
	else {
		if(*word == 0) {
			return 0;
		}

		if(p_list->p_head == NULL) {
			struct node *added = create_node(word);
			added->p_next = p_list->p_head;

			p_list->p_current = added;
			p_list->p_head = added;
			p_list->p_tail = added;
			return 1;
		}

		
		if((p_list->p_head == p_list->p_tail) && (p_list->p_head != NULL)) {
			struct node *added = create_node(word);
			added->p_next = p_list->p_head;
			p_list->p_head->p_previous = added;
			p_list->p_tail->p_previous = added;

			p_list->p_head = added;
			p_list->p_current = added;
			return 1;
		}


		else {
			struct node *added = create_node(word);
			added->p_next = p_list->p_head;
			p_list->p_head->p_previous = added;

			p_list->p_head = added;
			p_list->p_current = added;
			return 1;
		}
	}
}

// For the passed linked_list pointer free all of the nodes in the list.
// Be careful to free the space for the string before freeing the node itself.
// Also be careful to save a copy of the pointer to the next item in the list before
// freeing the node.
// Lastly, return the number of nodes freed (which could be zero if p_list indicates an empty list).
int clear_linked_list( struct linked_list *p_list ) {
	struct node* c = p_list->p_head; //points to the next node

	int count; //counts the number of nodes freed
	count = 0;

	/**
	 * while the head and the tail are not equal, point to the next node
	 * in the sequence and delete whatever was at the head of it
	 */
	while(p_list->p_head != NULL) {
		c = c->p_next;
		free(p_list->p_head->one_word.unique_word);
		p_list->p_head->one_word.unique_word = NULL;
		free(p_list->p_head);
		p_list->p_head = NULL;
		count++;
		p_list->p_head = c;
		p_list->p_current = c;
	}
	p_list->p_tail = p_list->p_head;
	return count;
}


// Inserts a node after the current pointer in the linked list.
// Updates the passed set of pointers as needed based upon the addition that was done.
//
// It checks that p_list is not NULL. Checks that word is not NULL and is not an empty string. 
// Returns 0 for failure if either word test fails.
// Also on failure no change is made to the pointers in p_list.
//
// On success it returns a 1 and updates at least the p_current member of p_list. p_current points to the newly added node.
// p_head is updated only if p_current is NULL (an empty list).
// p_tail is updated only if the new node is at the end of the list.
// When adding the first node to an empty list p_tail will also point to this same new node since it is the only node.
//
// Hint: use the create_node function to actually create the node.
// Hint: be sure to maintain both the p_previous and p_next pointers in each node.
// Hint: if this function is called with a p_current that is NULL (meaning the list is empty)
//       use the add_node_at_head function to create the new node.
int add_node_after_current( struct linked_list *p_list, char *word ) {
	//p_list = malloc(sizeof(struct linked_list));
	if((p_list == NULL) || (word == NULL)) {
		return 0;
	}
	else {
		if(*word == 0) {
			return 0;
		}

		if(p_list->p_head == NULL) {
			struct node *added = create_node(word);
			added->p_next = p_list->p_head;

			p_list->p_current = added;
			p_list->p_head = added;
			p_list->p_tail = added;
			return 1;
		}

		
		if((p_list->p_head == p_list->p_tail) && (p_list->p_head != NULL)) {
			struct node *added = create_node(word);
			added->p_previous = p_list->p_head;
			p_list->p_head->p_next = added;
			p_list->p_tail = added;
			p_list->p_current = added;
			return 1;
		}

		if(p_list->p_current == p_list->p_tail) {
			struct node *added = create_node(word);
			added->p_previous = p_list->p_current;
			p_list->p_current->p_next = added;
			p_list->p_tail = added;
			return 1;
		}

		else {
			struct node *added = create_node(word);
			added->p_next = p_list->p_current->p_next;
			added->p_previous = p_list->p_current;
			p_list->p_current->p_next->p_previous = added;
			p_list->p_current->p_next = added;

			p_list->p_current = added;
			return 1;
		}
	}
	return 0;
}


// Inserts a node before the current pointer in the linked list.
// Updates the passed set of pointers as needed based upon the addition that was done.
//
// It checks that p_list is not NULL. Checks that word is not NULL and is not an empty string. 
// Returns 0 for failure if either word test fails.
// Also on failure no change is made to the pointers in p_list.
//
// On success it returns a 1 and updates at least the p_current member of p_list. p_current points to the newly added node.
// p_tail is updated only if p_current is NULL (an empty list).
// p_head is updated only if the new node is at the beginning of the list.
// When adding the first node to an empty list p_tail will also point to this same new node since it is the only node.
//
// Hint: use the create_node function to actually create the node.
// Hint: be sure to maintain both the p_previous and p_next pointers in each node.
// Hint: if this function is called with a p_current that is NULL (meaning the list is empty)
//       use the add_node_at_head function to create the new node.
int add_node_before_current( struct linked_list *p_list, char *word ) {
	//p_list = malloc(sizeof(struct linked_list));
	if((p_list == NULL) || (word == NULL)) {
		return 0;
	}
	else {
		if(*word == 0) {
			return 0;
		}

		if(p_list->p_head == NULL) {
			struct node *added = create_node(word);
			added->p_next = p_list->p_head;

			p_list->p_current = added;
			p_list->p_head = added;
			p_list->p_tail = added;
			return 1;
		}

		
		if((p_list->p_head == p_list->p_tail) && (p_list->p_head != NULL)) {
			struct node *added = create_node(word);
			added->p_next = p_list->p_tail;
			p_list->p_tail->p_previous = added;
			p_list->p_head = added;
			p_list->p_current = added;
			return 1;
		}

		if(p_list->p_current == p_list->p_head) {
			struct node *added = create_node(word);
			added->p_next = p_list->p_current;
			p_list->p_current->p_previous = added;
			p_list->p_head = added;
			return 1;
		}

		else {
			struct node *added = create_node(word);
			added->p_previous = p_list->p_current->p_previous;
			added->p_next = p_list->p_current;
			p_list->p_current->p_previous->p_next = added;
			p_list->p_current->p_previous = added;

			p_list->p_current = added;
			return 1;
		}
	}
	return 0;
}


//Performs the recursive part of alphabetize().
//Inserts a node with a specified word into a sorted linked list.
//Returns 1 if the operation has been performed successfully
//Returns 0 if the operation failed
//(p_list is NULL, word is NULL, or word is an empty string).
//
//Prerequisites:
//	The linked list must already be sorted
//	The current pointer must be pointing to the same node as the head
int insert_sorted(struct linked_list *p_list, char* word) {
	if(p_list->p_head == NULL) {
		int i = add_node_at_head(p_list, word);
		return i;
	}
	else {
		int c;
		c = strcmp(word, p_list->p_current->one_word.unique_word);
		if(c < 0) {
			int i = add_node_before_current(p_list, word);
			return i;
		}
	
		if(c == 0) {
			p_list->p_current->one_word.word_count++;
			return 1;
		}
		else {
			if(p_list->p_current == p_list->p_tail) {
				int i = add_node_after_current(p_list, word);
				return i;
			}
			else {
				p_list->p_current = p_list->p_current->p_next;
				return insert_sorted(p_list, word);
			}
		}
	}
}	

//helper function to find_word.  Alphabetizes the linked list by their word.
void alphabetize(struct linked_list *p_list) {
	
	//create and initialize a new linked list
	struct linked_list *sorted;
	sorted = malloc(sizeof(struct linked_list));
	sorted->p_head = NULL;
	sorted->p_tail = NULL;
	sorted->p_current = NULL;

	int i;
	i = 0;
	char* word;

	//initialize p_current so that it points to p_head
	p_list->p_current = p_list->p_head;
	//printf("ohead %s", p_list->p_head->one_word.unique_word);

	while(p_list->p_current != NULL) {
		
		//initialize variables each for each node in the p_list
		sorted->p_current = sorted->p_head;
		word = p_list->p_current->one_word.unique_word;
		
		int k;
		k = insert_sorted(sorted, word);

		i += k;
		p_list->p_current = p_list->p_current->p_next;
	}

	int j;
	j = clear_linked_list(p_list);
	
	int k;
	k = 0;

	sorted->p_current = sorted->p_head;
	char* val;

	while(sorted->p_current != NULL) {
		val = sorted->p_current->one_word.unique_word;
		k += add_node_after_current(p_list, val);
		sorted->p_current = sorted->p_current->p_next;
	}

	j = clear_linked_list(sorted);
	free(sorted);


}
	

// Searches the linked list for the passed word.
// NOTE -- this function REQUIRES that the linked list has been maintained in English language alphabetical order.
// Definition of match: every letter must match exactly including by case.
// e.g. "A" does NOT match "a". "a " does NOT match "a"
//
// If found it sets the current pointer to the matching node.
// If not found it returns a failure and sets the current pointer to the node just before the
// insertion point (by alphabetic order). Note the special case for a new word that goes at the
// beginning of the list. See the examples below.
//
// Hint: use strcmp to determine sorting order.
//
// If it is found the current pointer is set to the node containing the matching word.
// If it is found this function returns a 1 to indicate success.
//
// If it is not found the current pointer is set to the node just before the insertion point.
// If it is not found the function returns a 0 to indicate failure.
// e.g. the list contains the words "apple", "buy", "cat".
//      Searching for "baby" would set current to the node containing "apple".
//      Searching for "acid" would set current to NULL to indicate that "acid" belongs at the head.
//      searching for "zebra" would set current to the node containing "cat".
//
// Tests on p_list and word: p_list, p_list->head, and word must all not be NULL.
// In addition, word must not be an empty string.
// We must have a valid list with at least one node and we must a valid word to match.
// If any of these conditions are violated this function returns a -1 to indicate invalid input.
int find_word( struct linked_list *p_list, char *word ) {
	
	if((p_list == NULL) || (word == NULL)) {
		return -1;

	}

	else {
		if(strlen(word) == 0) {
			return -1;
		}

		if(p_list->p_head == NULL) {
			return -1;
		}

		else {
			//alphabetize(p_list);
			p_list->p_current = p_list->p_head; //initialized the sorted list

			p_list->p_current = p_list->p_head;
			
			//points to the value of the current node
			char* val;
			while(p_list->p_current != NULL) {
				val = p_list->p_current->one_word.unique_word;
				if(strcmp(val, word) == 0) {
					p_list->p_current = p_list->p_current;
					return 1;
				}
				if(strcmp(val, word) > 0) {
					p_list->p_current = p_list->p_current->p_previous;
					return 0;
				}
				else {
					p_list->p_current = p_list->p_current->p_next;
				}
			}
			p_list->p_current = p_list->p_tail;
			return 0;
		}
	}
}

