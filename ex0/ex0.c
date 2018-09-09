// Name: Chenyang Fang



#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define BAD_INPUT 1

// this funciton prototype is a declaration of printPi
void printPi(int64_t n);

int main(int argc, char* argv[]) {
	
	if (argc != 2) {
		// checking if the user passes only one integer
		printf("Please enter only one non-negative integer\n");
        	return BAD_INPUT;
	}else {
		int64_t n;
		char *endptr;
		n = (int64_t) strtol(argv[1], &endptr, 10);
		if (*endptr != '\0') {
			// checking if the the input is a valid integer
			printf("Please enter a valid integer\n");
			return BAD_INPUT;
		}else if (n < 0) {
			// checking if the input integer is not negative
			printf("Please enter a non-negative integer within proper range");
			printf(" between 0 and LONG_MAX\n");
			return BAD_INPUT;
		}else {
			// print the result of the estimation of pi by 
			// NIlakantha's Series
			if (n == LONG_MAX) {
				// handle overflow case
				printf("note that your input is possibly larger than our limit");
				printf(" LONG_MAX, in which case ");
				printf(" we will calculate up to LONG_MAX terms\n");
			}
			printPi(n);
		}	
	}
}


// print the result of the estimation of pi to 20 decimal places by Nilakantha's Series
// with the given n
// n : the number of terms that the series should develop to estimate pi
void printPi(int64_t n) {
	double sum = 3.0;
	double term;
	for (int64_t i = 1; i <= n; i ++) {
		// determine if this term in the series is negative or not
		if (i % 2 == 0) {
			term = -1.0; 
		}else {
			term = 1.0;
		}
		sum += term * (4.0/(2.0 * i * (2 * i + 1) * (2 * i + 2)));
	}
	printf("Our estimate of Pi is %.20f\n", sum);
}
