// unit_tests.c
// Larry L. Kiser Oct. 22, 2015
// Copyright 2015 All Rights Reserved

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "bubble_sort.h"
#include "unit_tests.h"


// Simple boolean assert function for unit testing
int assert( int test_result, char error_format[], ... ) {
	va_list arguments ;
	static int test_number = 1 ;
	int result = 1 ;	// return 1 for test passed or 0 if failed
	
	if ( ! test_result ) {
		va_start( arguments, error_format ) ;
		printf( "Test # %d failed: ", test_number ) ;
		vprintf( error_format, arguments ) ;
		printf( "\n" ) ;
		result = 0 ;
	}
	test_number++ ;
	return result ;
}

//////////////////////////////////////////////////////////////////////////
// Begin unit tests //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// do the unit tests
int test()
{
	int passcount = 0 ;
	int failcount = 0 ;
	char empty_string[] = "" ;
	char string2[] = "ab" ;
	char string3[] = "testCAB" ;
	char string4[] = "bac1zt" ;
	char string5[] = "test" ;
	char bogus_string[] = { '\0', '\0', 'a', 'b' } ;	// NOT a valid string
	char bogus_string_copy[] = { '\0', '\0', 'a', 'b' } ;	// NOT a valid string
	int positions_swapped ;
	
	// Test 1 -- confirms that the swap_characters_in_array function is testing for end of string conditions.
	swap_characters_in_array( bogus_string, 0 ) ;	// This must do nothing since we have an End of String in the 0 position
	assert( memcmp( bogus_string, bogus_string_copy, sizeof(bogus_string) ) == 0,
		"swap_characters_in_array failed -- it incorrectly swapped characters" )
		? passcount++ : failcount++ ;
	
	// Test 2 -- confirms that the swap_characters_in_array function is testing for end of string conditions.
	swap_characters_in_array( bogus_string, 1 ) ;	// This must do nothing since we have an End of String in the 0 position
	assert( memcmp( bogus_string, bogus_string_copy, sizeof(bogus_string) ) == 0,
		"swap_characters_in_array failed -- it incorrectly swapped characters" )
		? passcount++ : failcount++ ;

	// Test 3 -- confirms that a simple two character string will be swapped correctly.
	swap_characters_in_array( string2, 0 ) ;
	assert( strcmp( string2, "ba" ) == 0,
		"swap_characters_in_array failed -- it incorrectly swapped characters. Got %s: ", string2 )
		? passcount++ : failcount++ ;
	
	// Test 4 -- confirms that a longer string will have its first two characters swapped correctly.
	swap_characters_in_array( string4, 0 ) ;
	assert( strcmp( string4, "abc1zt" ) == 0,
		"swap_characters_in_array failed -- it failed to swap characters. Got %s: ", string4 )
		? passcount++ : failcount++ ;
	
	// Test 5 -- confirms that the last two characters in a longer string will be swapped correctly.
	swap_characters_in_array( string4, 4 ) ;
	assert( strcmp( string4, "abc1tz" ) == 0,
		"swap_characters_in_array failed -- it failed to swap characters. Got %s: ", string4 )
		? passcount++ : failcount++ ;
	
	// Test 6 -- see that sort_two_positions stops at end of the string
	positions_swapped = sort_two_positions( empty_string, 0 ) ;
	assert( positions_swapped == 0,
		"sort_two_positions failed on empty string. Instead swapped %d positions", positions_swapped )
		? passcount++ : failcount++ ;
	
	// Test 7 -- now see if sort test correctly in one pass.
	positions_swapped = sort_two_positions( string5, 0 ) ;
	assert( strcmp( string5, "estt" ) == 0,
		"swap_characters_in_array failed -- it failed to swap characters. Got %s: ", string5 )
		? passcount++ : failcount++ ;
	
	// Test 8 -- now see if we can do a more complex string that requires multiple passes
	sort( empty_string, 0 ) ;
	assert( strcmp( empty_string, "" ) == 0,
		"swap_characters_in_array failed -- it failed to swap characters. Got %s: ", empty_string )
		? passcount++ : failcount++ ;
	
	// Test 9 -- now see if we can do a more complex string that requires multiple passes
	sort( string3, 0 ) ;
	assert( strcmp( string3, "ABCestt" ) == 0,
		"Top level sort failed. Expected ABCestt but got %s: ", string3 )
		? passcount++ : failcount++ ;
	
	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	
	return failcount ;
}
