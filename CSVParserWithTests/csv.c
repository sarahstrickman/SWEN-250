/*
 * Skeleton implementation for the activity to parse and print
 * CSV formatted files read from standard input.
 *
 * @EditedBy Sarah Strickman sxs4599
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csv.h"
#include "unit_tests.h"


/*
 * Returns true iff the character 'ch' ends a field. That is, ch is end of file,
 * a comma, or a newline.
 */
bool is_end_of_field(int ch) {
	return (ch == ',') || (ch == '\n') || (ch == EOF) ;
}


/*
 * Return the minimum of two integers.
 */
int min(int x, int y) {
	return (x < y ? x : y) ;
}


/*
 * Read the next field from standard input. Returns the value of getchar() that
 * stopped (terminated) the field.
 */
int get_field(f_string field) {

	int i;
	i = 0;

	int letter;
	letter = fgetc(stdin);
	
	bool is_end;
	is_end = is_end_of_field(letter);


	field[i] = '\0';
	i++;


	/**
	 * While the end of the field hasn't been reached (while 
	 * letter is not a comma, '\n', or EOF), add characters
	 * to the field
	 */ 
	while(!(is_end)) {
		field[i] = '\0';
		field[i - 1] = letter;

		letter = getchar();
		i++;
		is_end =  is_end_of_field(letter);
	}

	return (letter);

}


/*
 * Read in a CSV line. No error checking is done on the number of fields or
 * the size of any one field.
 * On return, the fields have been filled in (and properly NUL-terminated), and
 * nfields is the count of the number of valid fields.
 * nfields == 0 means end of file was encountered.
 */
csv_line get_line() {

	csv_line line;

	f_string field;

	int endchar;
	endchar = get_field(field);

	int i;
	i = 0;

	/**
	 * While the end of the line or end of file hasn't been reached,
	 * fill the csv_line with content that is in the fields.
	 */
	while(endchar != '\n' && endchar != EOF) {
		strlcpy(line.field[i], field, MAX_CHARS + 1);
		endchar = get_field(field);

		i++;
		
	}

	if(i == 0) {
		line.nfields = i;
	}
	else {
		strlcpy(line.field[i], field, MAX_CHARS + 1);
		line.nfields = (i + 1);
	}

	return(line);
}


/*
 * Print a CSV line, associating the header fields with the
 * data line fields.
 * The minimum of the number of fields in the header and the data
 * determines how many fields are printed.
 */
void print_csv(csv_line header, csv_line data) {

	int i;
	i = 0;

	int max = min(header.nfields, data.nfields);
	//printf("%d %d \n", header.nfields, data.nfields);

	/**
	 * While there are still entries in the array to read,
	 * print them accordingly
	 */
	while (i < max ) {
		printf("%s = %s\n", header.field[i], data.field[i]);
		i++;
	}
}


/*
 * Driver - read a CSV line for the header then read and print data lines
 * until end of file.
 */
int main( int argc, char *argv[] ) {

	csv_line header ;
	csv_line current ;

	// LLK additional if statement to execute unit tests if program
	// name contains "test".
	if ( strstr( argv[0], "test" ) )
		return test() ;

	header = get_line() ;
	current = get_line() ;

	while ( current.nfields > 0 ) {
		print_csv(header, current) ;
		current = get_line() ;
	}

	return 0 ;
}
