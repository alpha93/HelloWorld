#include <stdio.h>

int binary_search(int x[], int start, int end, int num);

int main() {
	int x[] = {2, 3, 5, 9, 12, 13, 24, 31, 72, 85, 99, 105};
	int len = sizeof(x)/sizeof(int), i = 6; //printf("%i\n", len);

	for(int j=0; j<106; j++) {
		printf("%i exists in the array at index %i\n", j, binary_search(x, 0, len-1, j));
	}
}

int binary_search(int x[], int start, int end, int num) {
	if(start == end) {
		if(num == x[start])
			return start;
		else
			return -1;
	}

	int mid_index = start+((end-start)/2), index;

	if(num == x[mid_index])
		return mid_index;
	else if(num < x[mid_index]  &&  mid_index != start) 
		index = binary_search(x, start, mid_index-1, num);
	else if(num > x[mid_index]  &&  mid_index != end)
		index = binary_search(x, mid_index+1, end, num);
	else
		return -11;

	return index;
}