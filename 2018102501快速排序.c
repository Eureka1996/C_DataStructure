#include <stdlib.h>
#include <stdio.h>

int randomnum(int start, int end) {
	if (start == end) {
		return start;
	}
	
	srand(time(NULL));
	int num = (rand() % (end - start+1))+start;
	return num;
}

int Partition(int arr[], int start, int end) {
	int index = randomnum(start, end);
	int x = arr[index];
	int i = start - 1;
	int j = 0;
	arr[index] = arr[end];
	arr[end] = x;
	for (j = start; j < end; j++) {
		if (arr[j] <= x) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
	return i+1;
}

void QuickSort(int arr[], int start, int end ) {
	
	if (start < end) {
		int q = Partition(arr, start, end);
		QuickSort(arr, start, q - 1);
		QuickSort(arr, q + 1, end);
	}
}


//08
int main08() {
	int arr[] = {2,8,7,1,3,5,6,4};
	for (int i = 0; i < 8; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	QuickSort(arr, 0, 7);

	for (int i = 0; i < 8; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");

	printf("\n-----------------------------\n");
	system("pause");
	return 0;
}

