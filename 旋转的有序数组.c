#define CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int getK(int arr[],int start,int len) {
	int prev = INT_MIN;
	int current = INT_MIN;
	int next = INT_MIN;
	if (arr == NULL) {
		return INT_MIN;
	}
	if (len == 2) {
		return start+1;
	}
	prev = arr[start + len / 2 - 1];
	current = arr[start + len / 2];
	next = arr[start + len / 2 + 1];
	if (current > prev && current > next) {
		return start + len / 2 + 1;
	}
	if (current > arr[start] && current < arr[start + len-1]) {
		return start;
	}
	if (current > arr[start]) {
		int templen = (len%2 == 1) ? len/2+1: len/2;
		return getK(arr, start + len / 2, templen );
	}
	else {
		return getK(arr, start, len / 2 + 1);
	}
	
}


int binary_search(const int arr[], int start, int end, int key) {
	int ret = -1;       // 未搜索到数据返回-1下标

	int mid;
	while (start <= end) {
		mid = start + (end - start) / 2; //直接平均可能會溢位，所以用此算法
		if (arr[mid] < key)
			start = mid + 1;
		else if (arr[mid] > key)
			end = mid - 1;
		else {            // 最後檢測相等是因為多數搜尋狀況不是大於要不就小於
			ret = mid;
			break;
		}
	}

	return ret;     // 单一出口
}

int containX(int arr[], int start, int len,int k, int X) {
	if (arr == NULL) {
		return -1;
	}
	if (arr[start + k - 1] < X || arr[start+k] > X) {
		return -1;
	}
	if (arr[start] <= X) {
		return binary_search(arr, start , k-1,X );
	}
	else if (arr[start + len - 1] >= X) {
		return binary_search(arr,start+k,len-1,X);
	}
	else {
		return -1;
	}

}

//07
int main07() {

	int A[] = {9,13, 16, 18, 19, 23, 28, 31, 37, 42,66,8};
	int k = getK(A,0,sizeof(A)/sizeof(int));
	printf("k=%d\n",k);
	printf("\n----------------\n");
	int X = 17;
	printf("%d \n",containX(A, 0, sizeof(A) / sizeof(int), k, X));
	printf("\n----------------\n");
	system("pause");
	return 0;
}