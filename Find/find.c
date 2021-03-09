/*
 * Implementation of functions that find values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h>
 *****
 */

#include <stdlib.h>
#include <stdbool.h>

#include "find.h"

#define NOT_FOUND (-1)	// integer indicator for not found.

/*
 * Return the index of the first occurrence of <ch> in <string>,
 * or (-1) if the <ch> is not in <string>.
 */
int find_ch_index(char string[], char ch) {
	int i; //counts the index of the string
	i = 0;

	/**
	 * while the end of the string hasn't been reached,
	 * check each character to check if it's the character
	 * that you're looking for.
	 */
	while(string[i] != '\0') {
		if(string[i] == ch) {
			return i;
		}

		i++;
	}

	return NOT_FOUND;
}

/*
 * Return a pointer to the first occurrence of <ch> in <string>,
 * or NULL if the <ch> is not in <string>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_ch_ptr(char *string, char ch) {
	
	char *first; //points to the first occurance of ch within a string
	first = string;

	while(*first != '\0') {
		if(*first == ch) {
			return first;
		}
		first++;
	}

	return NULL;
}

/*
 * Return the index of the first occurrence of any character in <stop>
 * in the given <string>, or (-1) if the <string> contains no character
 * in <stop>.
 */
int find_any_index(char string[], char stop[]) {
	
	int i; //the index of the string
	i = 0;

	int j; //the index of the stop

	while(string[i] != '\0') {
		j = 0;
		while(stop[j] != '\0') {
			if(string[i] == stop[j]) {
				return i;
			}
			j++;
		}
		i++;
	}
	return NOT_FOUND ;
}

/*
 * Return a pointer to the first occurrence of any character in <stop>
 * in the given <string> or NULL if the <string> contains no characters
 * in <stop>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_any_ptr(char *string, char *stop) {

	char *first; //points to a character in string
	first = string;

	char *second; //points to a character in stop
	
	while(*first != '\0') {
		second = stop;
		while(*second != '\0') {
			if(*first == *second) {
				return first;
			}
			second++;
		}
		first++;
	}
	return NULL ;	// placeholder
}

/*
 * Return a pointer to the first character of the first occurrence of
 * <substr> in the given <string> or NULL if <substr> is not a substring
 * of <string>.
 * Note: An empty <substr> ("") matches *any* <string> at the <string>'s
 * start.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_substr(char *string, char *substr) {

	char *sub; //points to a character in the substring
	sub = substr;

	char *whole; //points to a character in string

	char *start; //points to the first matching character
			//between substr and string

	if(*sub == '\0') {
		whole = string;
		return whole;
	}

	else {

		whole = string;//whole points to string[0]
		start = whole;
		while(*whole != '\0') {
			sub = substr;//sub points to substr[0]
			whole = start;//"resets" the index of whole

				while(*whole == *sub) {
					sub++;
					whole++;
					if(*sub == '\0') {
						return start;
					}
				}
			start++;
		}
		return NULL;
	}
}
