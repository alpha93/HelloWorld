#include <stdio.h>

/////////////////////////////////// Weird Function Syntax ////////////////////////////////////////
void f(n, m) int n; float m;{printf("%i %f\n", n, m);}

int main() {
	f(5, 34.23);
}
