/*
 *  chart1.c makes a chart that converts fahrenheit temperatures to
 *  	celsius
 * 
 * @author: Sarah Strickman
 * 
*/

#include <stdlib.h>
#include <stdio.h>

double i;
double j;

int main() {
	printf("Fahrenheit - Celsius\n");
	for(i = 0.0; i <= 300.0; i += 20.0) {
		j = (5.0 / 9.0) * (i - 32.0);
		printf("  %d           %.1f   \n", (int)i, j);
	}
}
