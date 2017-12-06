#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "common.h"

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

/*
- Know all three have to be less than sqrt(1000)
- Triplet has to be all even numbers or two odd + an even
*/

void compute(void) {
	long ans = 0;
	int nums[1000];
	int squares[1000];
	for (int i=1; i <= 1000; i++) {
		nums[i-1] = i;
		squares[i-1] = i*i;
	}

// Super gross, disgusting, revolting solution...but technically functional
	for (int i=0; i < 1000; i++) {
		for (int j=0; j < 1000; j++) {
			for (int k=0; k < 1000; k++) {
				if ((squares[j] + squares[k]) == squares[i]) {
					if ((nums[i] + nums[j] + nums[k]) == 1000) {
						printf("1000 Triplet = %d - %d - %d\n", nums[i], nums[j], nums[k]);
						ans = nums[i] * nums[j] * nums[k];
					}
				}
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
