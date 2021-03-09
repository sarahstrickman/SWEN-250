/* prime-number finding program
Originally by Norman Matloff, UC Davis
http://wwwcsif.cs.ucdavis.edu/~davis/40/gdb_Tutorial.htm
Modified by Mark Ardis, RIT, 11/1/2006

Will report a list of all primes which are less than
or equal to the user-supplied upper bound.
WARNING: There are bugs in this program! */

#include <stdio.h>

int primes[15];  /* Prime[i] will be 1 if i is prime, 0 otherwise */
int upper_bound; /* check all numbers up through this one for primeness */


/**
 * Given an upperbound, make an array of all prime numbers
 * that are less than the upper bound
 *
 * param u_bound: the upper bound
 * param Prime[]: the array of prime numbers
 * 
*/
void CheckPrime(int k, int primes[]) {
  int j; // counter that checks numbers up to u_bound
 
  j = 2;

  /**
   * for each number inwhile the counter is less than the 
   * upper bound, divide each number by numbers below it.
   * If it's divisible by anything, set its value to 0 (not prime).
   *
  */
  while (j * j  <= k) {
    if (primes[j] == 1){
      if (k % j == 0)  {
        primes[k] = 0;
        return;
      } 
    }
    j++;
  } /* while (1) */

  /* if we get here, then there were no divisors of K, so it is prime */
  primes[k] = 1;

}  


/**
 * Prompts user for an upper bound, and prints all prime numbers
 * up to the upper bound
 *
*/
int main() {
  int i; // the number whose primality is being checked

  printf("Enter upper bound:\n");
  scanf("%d", &upper_bound);
  upper_bound = 50 ;
  primes[1] = 1;
  primes[2] = 1;

 /**
  * for each entry up to upper bound, check if the number is prime
  * if the number is prime, print the number
 */
  for (i = 3; i <= upper_bound; i += 2) {
    CheckPrime(i, primes);
    if (primes[i]) {
      printf("%d is a prime\n", i);
    } 
} 

  return 0;
} 
