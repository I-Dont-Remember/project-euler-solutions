#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
int is_palindrome(char* string) {
	int len = strlen(string);
	if (len == 0 || len == 1) {
		return 1;
	}
	
	// Dividing with int does floor() for us, even if str is odd
	// the extra char is in both and doesn't disrupt the palindrome
	int midline = len / 2;
	for (int i=0; i < midline; i++) {
		if (string[i] != string[(len-1) - i]) {
			return 0;
		}
	}
	return 1;

}


/* Naive approach: try em all and time it :)
 Computers are only getting faster, so though this is a gross solution,
O(N^2) where N is the number of permutations of our 3-digit number aka 900
*/
void compute(void) {
	int ans = 0;
	int max = 1000;
	int start_3_digit = 100;
	int temp;
	char buf[7];

	for (int i=start_3_digit; i < max; i++) {
		for (int j=start_3_digit; j < max; j++) {
			temp = i * j;
			sprintf(buf, "%d", temp);
			if (is_palindrome(buf) == 1) {
				if (temp > ans) {
					ans = temp;
				}
			}
		}
	}
	printf("Answer is %d\n", ans);
}

int main(int argc, char* argv[]) {
	time_t start = time(NULL);
	compute();
	time_t end = time(NULL);
	printf("Finished in %ld seconds\n", (end -start));
	return 0;
}
