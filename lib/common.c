#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_prime(long number) {
	long sqrt_num = (long) ceil(sqrtl((long double) number));
	for (long i=2; i<= sqrt_num; i++) {
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}

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

