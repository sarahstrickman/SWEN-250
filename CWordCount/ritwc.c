#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

int main() {
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	/* total words */
	int end_word = 0;       /* Whether or not a word can be ended */
	char c;			/* a character */

	c = getchar();

	while(c != EOF) {
		/*
		 * While the end of the file hasn't been reached:
		*/
		

		if(c == '\n') {
			tot_lines++;
		}

		if(isspace(c) == 0) {
			end_word = 1;
		}
		
		if(end_word == 1 && isspace(c) !=0) {
			tot_words++;
			end_word = 0;
		}

		tot_chars++;
		c = getchar();
	}

	printf("      %d      %d      %d\n", tot_lines, tot_words, tot_chars);
	//prints data


	return 0 ;

	
}
