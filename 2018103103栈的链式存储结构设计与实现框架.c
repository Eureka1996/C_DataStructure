#include <stdlib.h>
#include <stdio.h>

#include "LinkStack.h"


//14
int main14() {
	int i = 0;;
	int a[10] = { 0 };
	LinkStack* stack = LinkStack_Create();
	if (stack == NULL) {
		return -1;
	}

	for (i = 0; i < 5;i++) {
		a[i] = i + 1;
		LinkStack_Push(stack,&a[i]);
	}

	printf("len:%d\n", LinkStack_Size(stack));
	printf("top:%d\n", *((int *)LinkStack_Top(stack)));
	while (LinkStack_Size(stack) > 0) {
		int tmp = *((int *)LinkStack_Pop(stack));
		printf("%d  ", tmp);
	}
	LinkStack_Destroy(stack);
	printf("\n---------------------------\n");
	system("pause");
	return 0;
}