#define CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int getLocalMax(int arr[],int start , int len) {
	int prev = INT_MIN;
	int current = INT_MIN;
	int next = INT_MIN;
	if (arr == NULL) {
		printf("数组为NULL\n");
		system("pause");
		return INT_MIN;
	}
	if (len < 3) {
		printf("数组长度不够\n");
		system("pause");
		return INT_MIN;
	}

	prev = arr[start + len / 2 -1];
	current = arr[start + len / 2];
	next = arr[start + len / 2 + 1];

	if (current > prev && current > next) {
		return current;
	}
	if (current < prev) {
		return getLocalMax(arr, start, len / 2 + 1);
	}
	else {
		return getLocalMax(arr, start + len/2, len/2 + 1);
	}
}

//06
int main06() {

	int arr[7] = {2,3,4,5,7,10,1};

	int localmax = getLocalMax(arr, 0, sizeof(arr)/sizeof(int));
	printf("localmax:%d\n", localmax);
	printf("\n--------------------\n");
	system("pause");
	return 0;
}
