#include <stdio.h>
#include "euler.h"

void compute(void) {
	int max = 1000;
	int sum = 0;
	for (int i=0; i < max; i++) {
		if ( i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	printf("Sum: %d\n", sum);
}

int main(int argc, char* argv[]) {
	compute();
	return 0;
}
