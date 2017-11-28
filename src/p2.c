#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// Non recursive version
void compute(void) {
	int sum = 2;
	int four_million = 4000000;

	int* nums = (int *) malloc(sizeof(int) * four_million / 2);
	if (nums == NULL) {
		printf("Malloc failed\n");
		exit(1);
	}
	
	
	nums[0] = 1;
	nums[1] = 2;
	for (int i=2; i < (four_million/2); i++) {
		nums[i] = nums[i-1] + nums[i-2];
		if (nums[i] > four_million) {
			break;
		}
		if ((nums[i] % 2) == 0) {
			sum += nums[i];
		}
	}
	printf("Sum is %d\n", sum);
}

int main(int argc, char* argv[]) {
	time_t start = time(NULL);
	compute();
	time_t end = time(NULL);
	printf("Finished in %ld seconds\n", (end -start));
	return 0;
}
