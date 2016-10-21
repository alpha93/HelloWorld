#include <stdio.h>
#include <time.h>

void delay(int mili) {
	clock_t target = mili + clock();
	while(target > clock());
}

int main() {
	int i = 0;
	for(; i<50; i++) {
		int j;
		for(j=0; j<i; j++)
			printf("=");

		printf(">");

		for(j=0; j<80-i; j++)
			printf(" ");

		printf("\b");

		printf("%d%%", (i+1)*2);
		printf("\r");
		delay(100);		
	}

	printf("\n");
	for(i=0; i<31; i++) 
		printf(" ");
	printf("---Task Complete---");
}