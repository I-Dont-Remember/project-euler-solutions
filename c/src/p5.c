#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#define SMALLEST_WITH_10 2520
/*
Div rules: 
- Any even is divisible by 2
- divisible by 3 if sum of digits is divisible by 3
- 4 if last two digts are divisible by 4
- 5, last digit must be 0 or 5
- 6, if 2 and 3 are both possible
- 7, double last digit and subtract it from number made of the other digits, if divisible by 7
   it works, can do multiple times
- 8, last 3 form number divisible by 8
- 9, if sum of digits are evenly divisible by 9
- divisible by 10 if final digit is 0
- 11 if difference of the sums of the alternating digits is divisible by 11
*/
int divisible_one_to_twenty(int number) {
	for (int i=1; i <= 20; i++) {
		if (number % i != 0) {
			return 0;
		}
	}
	return 1;
}

// Brute force mostly naive-solution, though we only do 10% of the work of a true brute force
void compute(void) {
	long ans = 0;
	// Use the rules that are most restrictive first e.g. has to end in 0 for 10
	for (long i=SMALLEST_WITH_10; i < 500000000; i+=10) {
		if (divisible_one_to_twenty(i) == 1) {
			ans = i;
			break;
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
