#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*

The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

long sum_squares(int n) {
	long sum = 0;
	for (int i=1; i < (n+1); i++) {
		sum += i * i;
	}

	return sum;
}

long square_sums(int n) {
	long sum = 0;
	for (int i=1; i < (n+1); i++) {
		sum += i;
	}
	sum *= sum;

	return sum;

}
// Naive approach, just implement as stated with no improvements to the math
void compute(void) {
	long squares = sum_squares(100);
	long summed = square_sums(100);
	long ans = summed - squares;
	printf("Answer is %ld\n", ans);
}

int main(int argc, char* argv[]) {
	time_t start = time(NULL);
	compute();
	time_t end = time(NULL);
	printf("Finished in %ld seconds\n", (end -start));
	return 0;
}
