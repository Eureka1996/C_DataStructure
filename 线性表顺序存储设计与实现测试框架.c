#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "seqlist.h"

typedef struct Teacher {
	char name[64];
	int age;
}Teacher;



//01
int main01() {
	int ret = 0;
	SeqList* list = NULL;
	Teacher t1, t2, t3;
	int i = 0;

	list = SeqList_Create(1);
	if (list == NULL) {
		ret = -1;
		printf("func SeqList_Create() ret = %d\n" , ret);
		system("pause");
		return -1;
	}

	t1.age = 25;
	strcpy(t1.name, "wufuqiang");
	t2.age = 26;
	strcpy(t2.name, "liyuqing");
	t3.age = 27;
	strcpy(t3.name, "wu");

	ret = SeqList_Insert(list , (SeqListNode*)&t1,0);
	ret = SeqList_Insert(list, (SeqListNode*)&t2, 0);
	ret = SeqList_Insert(list, (SeqListNode*)&t3, 0);

	for (i = 0; i < SeqList_Length(list); i++) {
		Teacher* temp = (Teacher*)SeqList_Get(list, i);
		if (temp == NULL) {
			ret = -2;
			return ret;
		}
		printf("name=%s\tage=%d\n",temp->name , temp->age );
	}
/*
	while (SeqList_Length(list) > 0) {
		SeqList_Delete(list, 0);
	}*/
	SeqList_Delete(list, 0);
	printf("--------------------------\n");
	for (i = 0; i < SeqList_Length(list); i++) {
		Teacher* temp = (Teacher*)SeqList_Get(list, i);
		if (temp == NULL) {
			ret = -2;
			return ret;
		}
		printf("name=%s\tage=%d\n", temp->name, temp->age);
	}
	SeqList_Destroy(list);
	printf("wufuqiang\n");
	system("pause");
	return 0;
}