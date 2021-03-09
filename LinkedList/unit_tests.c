// unit_tests.c
// Larry L. Kiser Oct. 22, 2015
// Copyright 2015 All Rights Reserved

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "linked.h"
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

	struct node *linked; //a new linked list
	linked->next = NULL;
	linked->value = NULL;

	// Test 1 -- check that list length is 0
	assert( length(linked) == 0,
		"Length of list must initially be zero" )
		? passcount++ : failcount++ ;
	
	//Test 2 -- test that an item was pushed to the list
	push(linked, 3);
	assert(length(linked) == 1, "Length after push should be 1. Length is %d", length(linked))
	? passcount++ : failcount++;

	//Test 3 -- test that the correct item was pushed to the list
	int front;
	front = &linked-> value;
	assert(front == 3, "First value should be 3. Your value is %d", front)
		? passcount++ : failcount++;

	


	
	printf( "\nSummary of unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;
	
	return failcount ;
}
