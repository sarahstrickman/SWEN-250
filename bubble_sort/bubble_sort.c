/*
 * bubble sort
 * Assignment completed by: Sarah Strickman sxs4599
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bubble_sort.h"
#include "unit_tests.h"

// Swaps the characters at myarray[position] and myarray[position + 1].
// It is up to the calling program to ensure that position + 1 is a valid array location.
// If myarray[position] or myarray[position + 1] is an end of string ('\0') do not swap.
// This is an example of defensive programming.
// You are NOT allowed to use any library functions like swap().
void swap_characters_in_array( char myarray[], int position ) {
	char i;
	char j;

	i = myarray[position];
	j = myarray[position + 1];

	if(i != '\0' && j != '\0') {
		myarray[position] = j;
		myarray[position + 1] = i;
	}
}

// Recursively sorts two characters in an array by their numeric value
// not a very good sort for alphabetic ordering).
// Returns the number of times a pair of characters were actually swapped.
int sort_two_positions(char myarray[], int position) {
	int swap_was_done = 0 ;
	
	char i;
	char j;

	i = myarray[position];
	j = myarray[position + 1];

	if(i == '\0' || j == '\0') {
		return 0;
	}

	else {
		if(i > j) {
			swap_characters_in_array(myarray, position);
			swap_was_done = 1;
		}
	}

	return (swap_was_done + sort_two_positions(myarray, position + 1));
}

// Implement this function that repeatedly calls sort_two_positions until the entire string is sorted.
// This is the top level function that is called by the unit tests.
void sort( char myarray[], int position ) {
	
	int start;
	start = 0;

	int positions_sorted;
	positions_sorted = sort_two_positions(myarray, start);

	while(positions_sorted > 0){
		start = 0;

		positions_sorted = sort_two_positions(myarray, start);
	}
}


// Run the unit tests or as a "normal program".
// You can run this as a "normal program" if you want for a simple test of the sort_two_positions function.
int main( int argc, char *argv[] ) {
	char one_string[] = "test" ;
	int positions_swapped = 0 ;

	// Execute unit tests if program name contains "test".
	if ( strstr( argv[0], "test" ) )
		return test() ;

	// Simple test for the mid-level function.
	positions_swapped = sort_two_positions( one_string, 0 ) ;
	printf( "%d positions swapped. New string is: %s\n", positions_swapped, one_string ) ;
	
	return 0 ;
}
