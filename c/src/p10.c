#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "common.h"

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#define two_million 2000000
/*
Brute force solution, walk through up to two million checking primality.
Checking all, it took 2s on i5-6600k.
After cutting out even numbers, took 1s.
Took 36s to compute the sum for 20,000,000.
*/
void compute(void) {
	// Allow ourselves to start on odd numbers
	long ans = 2;

	for (int i=3; i < two_million; i+=2) {
		if (is_prime(i) == 1) {
			ans += i;
		}
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
