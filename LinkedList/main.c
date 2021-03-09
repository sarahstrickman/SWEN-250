// Updated linked list activity
// L. Kiser Nov. 18, 2015

#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "unit_tests.h"
	
extern char *malloc_options ;

int main( int argc, char *argv[] )
{
	malloc_options = "CFGSU" ;		// DO NOT TOUCH THIS LINE

	return test() ;		// execute unit tests
}

