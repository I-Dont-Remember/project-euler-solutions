#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

//http://www.puzzles9.com/how-to-find-prime-numbers-how-to-check-if-a-number-is-prime/

int is_prime(long number) {
	long sqrt_num = (long) ceil(sqrtl((long double) number));
	for (long i=2; i<= sqrt_num; i++) {
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}

// This ends up searching double, since it finds the answer value in 'i' first, but it's
// only checking the output value.  Naive solution needs much improvement, look into sqrt method
void compute(void) {
	long ans = 0;
	long large_num = 600851475143;
	printf("Starting at %ld\n", large_num);
	for (double i=2.0; i < large_num/2; i++) {
		double output = large_num / i;
		if (output == (long) output) {
			printf("Factors at %f and %f\n", output, i);
			if (is_prime((long) output)) {
				printf("Found prime\n");
				ans = (long) output;
				break;
			}
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
