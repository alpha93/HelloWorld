#include <stdio.h>

int main() {
	/* Maximum Sum Sub-Array - Kadane's Algorithm */
	/*
	 * 1. sum stores the sum of certain number of consecutive elements according to the algorithm. max takes the maximum
	 *    from sum.
	 * 2. take the 0th element as both sum and max and iterate from the 1th element.
	 * 3. if the total of the sum and the current element is greater than the current element, add current element to sum.
	 * 4. else set sum equal to the current element.
	 * 5. the sum can increase only if a positive element is encountered. so set max equal to sum whenever a positive number
	 *    is encountered
	 */ 

	int x[] = {-1, 2, -5, 6, 1, 4, -2, 3}, start_index = -1, end_index = -1, i, sum, max;
	sum = max = x[0];

	for(i=1; i<sizeof(x)/sizeof(int); i++) {
		if(sum+x[i] > x[i]) {
			sum += x[i];
		} else {
			sum = x[i];
			start_index = i;
		}

		if(x[i] > 0) {
			max = sum;
			end_index = i;
		}
	}

	printf("maximum sum: %i  start_index: %i  end_index: %i", sum, start_index, end_index);
}