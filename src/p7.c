#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "common.h"

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#define GOAL_PRIME 1000000//10001
/* Naive, compute until you have the number (Don't make array since that would be wasted space, we only 
need to know the final, don't care about the preceding primes). Computes in under 1s on i5-6600k.

To find the 100,000th prime, took 1 second.
To find the 1,000,000th prime number, it took 25 seconds.
--> After the improvement of eliminating even numbers, took 25 seconds still.
    Loop is based on number of primes found, so it makes some sense in hindsight (kinda, still unexpected)

*/

void compute(void) {
	long ans = 0;
	// All primes are odd numbers except for the lone even, 2, set initial values to 
	// keep rest of code simple
	int prime_count = 1;
	long num_count = 1;

	while (prime_count < GOAL_PRIME) {
		if (is_prime(num_count) == 1) {
			prime_count++;
			ans = num_count;
		}
		num_count += 2;
	}
	printf("Answer is %ld\n", ans);
}

int main(int argc, char* argv[]) {
	time_t start = time(NULL);
	compute();
	time_t end = time(NULL);
	printf("Finished in %ld seconds\n", (end -start));
	return 0;
}
