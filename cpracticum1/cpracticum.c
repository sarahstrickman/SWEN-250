// C (no pointers) Practicum
// SWEN-250
// Larry Kiser Feb. 13, 2018
//             New no pointers practicum without structs

#include <stdlib.h>
#include <stdio.h>
#include "cpracticum.h"
#include "unit_tests.h"

// Create a loop that goes to the end of the passed string that
// counts the number of numeric characters in that string.
// Return that count from this function.
// Numeric characters are all of the characters from 0 through 9.
//
// Return 0 if there are no numeric characters in the string.
// Return 0 if the passed string is an empty string.
// Otherwise, return the number of numeric characters in the string.
//
// You are NOT allowed to use any library functions. You must write
// C code that determines whether or not each character is a numeric character.
// If you wish you can create your own function that determines whether
// or not a character is a numeric character. You could then call that function
// in your loop that searches the string.
int count_number_of_numeric_characters( char mystring[] )
{	
	int count; //the number of numeric characters in the string
	count = 0;
	
	int i;//the index of the string
	i = 0;

	//While the end of the string hasn't been reached, check each 
	//character and check if it's a number. if yes, increment count.
	while(mystring[i] != '\0') {
		if(mystring[i] >= 48 && mystring[i] <= 57) {
			count++;
		}
		
		i++;
	}

	return count ;	
}

// For the passed string you must convert all lower case letters to upper case letters.
// Do no change make any other changes to the array.
// For example a string "ab132 CD==" would become "AB123 CD==".
// The string may be an empty string. If it is empty do nothing.
// Note that this means you are directly changing the characters in the passed string.
// Hint -- per the ASCII code chart an 'a' is 97 decimal and an 'A' is 65 decimal.
//         You can use that difference to convert from lower case to upper case.
void convert_to_upper_case( char mystring[] )
{

	int i; //the index that is being read from the string
	i = 0;


	//while the end of the string hasn't been reached, check to 
	//see if the character being read is a lowercase letter.
	//if yes, replace it with its uppercase letter.
	while(mystring[i] != '\0') {
		
		char ch;
		ch = mystring[i];

		if(ch >= 97 && ch <= 122) {
			char lower;
			lower = ch;

			char upper; //the uppercase of the letter
			upper = lower - 32;
			mystring[i] = upper;
			i++;
		}
		
		//this else statement isnt needed, but im too fed up to take it out
		else {
			i++;

		}
	}
}

// This function returns the letter 'L' if the value is < the lower_limit.
// It returns the letter 'M' if the value is >= the lower limit and <= the upper_limit.
// It returns 'H' if the value is > the upper limit.
// You can assume that upper_limit is always > lower_limit.
char range_test( int value, int lower_limit, int upper_limit )
{
	if(value >= lower_limit && value <=upper_limit) {
		return 'M';
	}

	if(value < lower_limit) {
		return 'L';
	}
	
	else {
		return 'H';
	}
}

// This function is implemented incorrectly. You need to correct it.
// It is supposed to total up the integers in the array.
// The number of entries to add up is the second parameter.
// It returns that sum.
// NOTE -- you are required to correct this code. You are not allowed to completely rewrite it.
//         There are 5 errors in this routine. You must fix all errors. It is possible that the
//         unit tests may pass without all errors being corrected. Be sure that your corrected
//         code does not produce any warnings.
int fix_bad_code( int numbers[], int number_to_add )
{
	int i ;
	i = 0;

	int total ;
	total = 0; //total not initialized

	int result ;
	result = 0;
	
	//arrays start at [0], not at [1]
	//you would also need to subtract 1 from the number_to_add, because of the 
	//index at 0 thing
	for ( i = 0 ; i < number_to_add ; i++ ) {
	//there were semicolons????????
		total += numbers[ i ] ;
	}
	result = total ;
	//returning result == total would return 0
	return result;
}


// Only runs the unit tests.
int main( int argc, char *argv[] ) {

	// Execute unit tests
	return test() ;
}
