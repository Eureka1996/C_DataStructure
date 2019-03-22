#include <stdlib.h>
#include <stdio.h>

int hailstone(int n) {
	int length = 1;
	while (1 < n) {
		n % 2 ? (n = 3*n +1)  : (n=n/2) ;
		length++;
	}
	return length;
}

int mainhailstone() {
	int length = hailstone(27);
	printf("hailstone length :%d\n",length);
	system("pause");
	return 0;
}