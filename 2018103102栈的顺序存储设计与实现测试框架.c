#include <stdlib.h>
#include <stdio.h>

#include "seqstack.h"


//13
int main13() {
	int i = 0;
	int a[10];
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if (stack == NULL) {
		return -1;
	}
	for (i = 0; i < 5; i++){
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
		
	}

	printf("Capacity:%d\n", SeqStack_Capacity(stack));
	printf("Length:%d\n", SeqStack_Size(stack));
	printf("top:%d\n", *(int *)SeqStack_Top(stack));

	while (SeqStack_Size(stack) > 0) {
		printf("top:%d  ",*(int *)SeqStack_Pop(stack));
	}

	printf("\n------------------------\n");
	system("pause");
	return 0;
}