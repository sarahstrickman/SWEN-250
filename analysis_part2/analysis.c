// Document Analysis project functions for Part 2

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "linked_list_functions.h"
#include "analysis.h"
#include "unit_tests.h"


// Prints all the values and the word counts for a linked list.
// Returns 0 if a null pointer is passed in
void print_list(struct linked_list *p_list) {
	p_list->p_current = p_list->p_head;
	while (p_list->p_current != NULL) {
		printf("%s : %d\n", p_list->p_current->one_word.unique_word, p_list->p_current->one_word.word_count);
		p_list->p_current = p_list->p_current->p_next;
	}

}

// First checks that p_list is not NULL. Returns 0 if p_list is a NULL pointer.
// Then checks that word pointer is not NULL and word is not any empty string.
// Returns 0 if either of the above tests on the passed word fails.
//
// Creates the list if starting a fresh list.
// Searches existing list for a match on the word. Increments word count
// if found. If not found adds the word in alphabetic order.
// Returns 1 if the word was added successfully.
// Returns 0 on failure.
// NOTE -- this function makes no assumption on upper or lower case. That is handled by read_file.
// For simplicity all words passed from the unit tests are all lower case only.
int process_word ( struct linked_list *p_list, char *word ) {
	int status = 0 ;
	if((p_list == NULL) || (word == NULL)) {
		return status;
	}
	if(*word == '\0') {
		return status;
	}
	else {
		p_list -> p_current = p_list -> p_head;
		status = insert_sorted(p_list, word);
		return status ;
	}
}

// First checks that the passed string with the file name is not a NULL pointer and is not an empty string.
// Also checks that the passed pointer to the linked_list struct is not a NULL pointer.
// Returns 0 if any of the above tests fail.
// returns 0 if the file cannot be read or if the file does not contain any words as defined for this project.
// returns the number of words if the file was found, opened successfully, and it contained at least one valid word.
// NOTE -- this function MUST convert all words read to lower case only! e.g "First" becomes "first"
int read_file( struct linked_list *p_list, char *file_name ) {
	int word_count = 0 ;
	if( file_name == NULL || p_list == NULL) {
		return word_count;
	}

	FILE *fp = fopen(file_name, "r");
	if( fp == NULL ) {
		//fclose(fp);
		return word_count;
	}

	char word_read[MAX_WORD + 1];
	memset(word_read, '\0', sizeof(word_read));
	int index = 0;
	char *word = word_read;

	char c;
	c = fgetc(fp);

	int end_word;
	end_word = 0;

	while (c != EOF) {
		if (isspace(c) == 0) {
			end_word = 1;
			index++;
			if (c >= 65 && c <= 90) {
				word_read[index - 1] = (c + 32);
			}
			else if (c >= 97 && c <= 122){
				word_read[index - 1] = c;
			}
			word_read[index] = '\0';
		}

		if ( end_word == 1 && isspace(c) != 0) {
			//process the word in to the linked list
			process_word(p_list, word);

			word_count++;
			end_word = 0;

			//reinitialize the array for the next word
			memset(word_read, '\0', sizeof(word_read));
			word = word_read;
			index = 0;
		}
		c = fgetc(fp);
	}

	fclose(fp);
	return word_count;

}

// Returns 0 in the word_count field if the p_list pointer is NULL.
// Returns 0 in the word_count field if no first word meaning p_head == NULL (empty list).
// Otherwise, returns a struct with the first unique word and its number of occurrences in the text file.
struct word_entry get_first_word( struct linked_list *p_list )
{
	if(p_list == NULL) {
		struct word_entry entry;
		entry.word_count = 0;
		return entry;
	}
	if(p_list->p_head == NULL) {
		struct word_entry entry;
		entry.word_count = 0;
		return entry;	
	}
	else {
		struct word_entry entry ;
		entry =  p_list->p_head->one_word;
		p_list -> p_current = p_list -> p_head;
		return entry;
	}
}

// Returns 0 in the word_count field if p_list is NULL.
// Returns 0 in the word_count field if no next word (previously reached end of list or it is an empty list).
// Otherwise, returns a struct with the next unique word and its number of occurrences in the text file.
struct word_entry get_next_word( struct linked_list *p_list )
{
	if(p_list == NULL) {
		struct word_entry entry ;	
		entry.word_count = 0 ;
		return entry;
	}
	if(p_list->p_current == NULL) {
		struct word_entry entry ;	
		entry.word_count = 0 ;
		return entry;
	}
	if(p_list->p_current == p_list->p_tail) {
		struct word_entry entry ;	
		entry.word_count = 0 ;
		return entry;
	}
	else {
		struct word_entry entry ;	
		p_list->p_current = p_list->p_current->p_next;
		entry = p_list->p_current->one_word;
		return entry;
	}
}

// Returns 0 in the word_count field if no previous word (was already at beginning of the list or it is an empty list).
// Otherwise, returns a struct with the previous unique word and its number of occurrences in the text file.
struct word_entry get_prev_word( struct linked_list *p_list )
{
	if(p_list == NULL) {
		struct word_entry entry ;
		entry.word_count = 0 ;
		return entry;
	}
	if(p_list->p_current == NULL) {
		struct word_entry entry;
		entry.word_count = 0 ;
		return entry;
	}
	if(p_list->p_current == p_list->p_head) {
		struct word_entry entry ;	
		entry.word_count = 0 ;
		return entry;
	}
	else {
		struct word_entry entry ;	
		p_list->p_current = p_list->p_current->p_previous;
		entry = p_list->p_current->one_word;
		return entry;
	}
}

// Returns 0 in the word_count field if the p_list pointer is NULL.
// Returns 0 in the word_count field if no last word meaning p_tail == NULL (empty list).
// Otherwise, returns a struct with the last unique word and its number of occurrences in the text file.
struct word_entry get_last_word( struct linked_list *p_list )
{
	if(p_list == NULL) {
		struct word_entry entry;
		entry.word_count = 0;
		return entry;
	}
	if(p_list->p_head == NULL) {
		struct word_entry entry;
		entry.word_count = 0;
		return entry;	
	}
	else {
		struct word_entry entry ;
		entry =  p_list->p_tail->one_word;
		p_list->p_current = p_list->p_tail;
		return entry;
	}
}


// First check the p_list is not NULL. Return 0 if it is NULL.
// Return 0 if the list is empty (e.g. p_head is NULL).
// Writes the sorted unique word list to a csv file.
// Receives the linked list pointer and the name of the file to be created.
// Returns 1 on a successful write of the file.
// Returns 0 on any failure.
// Test for a NULL or empty string in the file_name. Return 0 for failure if NULL or empty.
// Be sure to test for failure to open the file, failure to write to the file, and failure to close.
// You must have a header row exactly like this (without the quotes): "word,count"
// You must have one row for each unique word and its count (e.g. without quotes "student,5").
// It must be in sorted order and must be the complete list.
int write_unique_word_list_to_csv_file(  struct linked_list *p_list, char *file_name )
{
	int status;
	status = 0;
	
	if(p_list == NULL) {
		return status;
	}
	if(p_list->p_head == NULL) {
		return status;
	}
	if(file_name == NULL) {
		return status;
	}
	if(*file_name == '\0') {
		return status;
	}
	else {
		FILE *fp = fopen(file_name, "w");
		if(fp == NULL) {
			fclose(fp);
			return status;
		}
		else {
			fprintf(fp, "word,count");
			p_list->p_current = p_list->p_head;
			while(p_list->p_current != NULL) {
			fprintf(fp, "%s,%d", p_list->p_current->one_word.unique_word, p_list->p_current->one_word.word_count);
			p_list->p_current = p_list->p_current->p_next;
			}
			fclose(fp);
			status = 1;
			return status;
		}
	}

	return status ;
}
