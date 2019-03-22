
#include <stdlib.h>
#include <stdio.h>


void sortByColor(int* arr , int len) {
	int index1 = 0 ;
	int index2 = 0 ;
	int index3 = len-1 ;
	while (index1 < len && arr[index1] == 1) {
		index1++;
	}
	while (index3 >= 0 && arr[index3] == 3) {
		index3--;
	}
	index2 = index1;
	while (index2<=index3) {
		if (arr[index2] == 2) {
			index2++;
			continue;
		}
		if (arr[index2] == 1) {
			int temp = arr[index2];
			arr[index2] = arr[index1];
			arr[index1] = temp;
			index1++;
			index2++;
			continue;
		}
		if (arr[index2] == 3) {
			int temp = arr[index2];
			arr[index2] = arr[index3];
			arr[index3] = temp;
			index3--;
		}

	}

}


//16
int main16() {

//	int arr[] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3 };
//	int arr[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1 };
//	int arr[] = { 2,2,2,2,2,2,2,2,2,2,2,2,2 };
//	int arr[] = { 3,3,3,3,3,3,3,3,3,3,3,3 };
	int arr[] = {1,2,3,2,1,3,1,3,2,1,3,1,3,1,3,1,2,3,2,3,2,2,3,1,3,1,3,2,3,1,3,2,3,1,3,1,2,3,1,2,3,1,3,1,2,1,2,3,1,2,3,3,2};
	int len = sizeof(arr) / sizeof(int);
	sortByColor(arr,len);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nwufuqiang\n");
	system("pause");
	return 0;
}

