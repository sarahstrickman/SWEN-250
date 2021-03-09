/*
 * Implementation of the read_data module.
 *
 * See read_data.h for a description of the read_data function's
 * specification.
 *
 * Note that the parameter declarations in this module must be
 * compatible with those in the read_data.h header file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read_data.h"

// Reads the three fields from lines such as W$1349$1.414$ into
// local variables using getchar().
// Converts the two numeric fields to numbers using atoi for the
// integer fields and atof for the double.
// Using a correctly defined set of parameters (use pointers) pass
// those values back to the program that called this function.
void read_data(char *C, int *I, double *D) {
	
	char ch;
	ch = fgetc(stdin);

	char chars[LINE_MAX + 1]; //the string that holds the character
	chars[0] = "\0";
	int charidx; //the index of chars
	charidx = 0;

	char ints[LINE_MAX + 1]; //the string that holds the integer
	ints[0] = "\0";
	int intidx; //the index for the integer array
	intidx = 0;

	char dubs[LINE_MAX + 1]; //the string that holds the double
	dubs[0] = "\0";
	int dubidx; //the index of the double array
	dubidx = 0;


	int fields = 0;

	
	/*
	While the end of the line hasn't been reached, put the
	different data into the different structs.
	*/
	while(ch != EOF && fields <= 2 && ch != "\n") {
		if(ch == "$") {
			field++;
		}

		if(field == 0) {
			charidx++;
			chars[charidx] = "\0";
			chars[charidx] = ch;
			*C = &chars[charidx];
		}

		if(field == 1) {
			intidx++;
			ints[intidx] = "\0";
			ints[intidx - 1] = ch;
			*I = &atoi(ints);
		}

		if(field == 2) {
			dubidx++;
			dubs[dubidx] = "\0";
			dubs[dubidx] = ch;
			*D = &atof(dubs);
		}
		
		ch = getchar();
	}


	return ;
}
