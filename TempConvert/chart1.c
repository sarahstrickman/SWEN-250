/*
 *  chart1.c makes a chart that converts fahrenheit temperatures to
 *  	celsiudd
 * 
 * @author: Sarah Strickman
 * 
*/

#include <stdlib.h>
#include <stdio.h>

int i;
int j;

int main() {
	printf("Fahrenheit -  Celsius\n");
	for(i = 0; i <= 300; i += 20) {
		j = (5.0 / 9.0) * (i - 32);
		printf("  %d            %d   \n", i, j);
	}
}
