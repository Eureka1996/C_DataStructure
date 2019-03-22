#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linklist.h"


typedef struct Teacher {
	LinkListNode* node;
	int age;
	char name[64];
} Teacher;

int main02() {
	int len = 0, ret;
	int i = 0;
	Teacher t1 , t2, t3, t4, t5;

	t1.age = 25;
	strcpy(t1.name, "wufuqiang");
	t2.age = 26;
	strcpy(t2.name, "liyuqing");
	t3.age = 27;
	strcpy(t3.name, "wu");
	t4.age = 30;
	strcpy(t4.name, "lyq");


	LinkList* list = NULL;
	list = LinkList_Create();
	if (list == NULL) {
		return;
	}
	len = LinkList_Length(list);
	ret = LinkList_Insert(list, (LinkListNode*)(&t1), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&t2), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&t3), 0);
	ret = LinkList_Insert(list, (LinkListNode*)(&t4), 0);
	
	for (i = 0; i < LinkList_Length(list); i++) {
		Teacher* temp = (Teacher*)LinkList_Get(list, i);
		if (temp == NULL) {
			return;
		}
		printf("tmp->age:%d,tmp->name:%s;\n", temp->age, temp->name);
	}

	printf("--------------------------------------------------\n");
	LinkList_Reverse(list);
	for (i = 0; i < LinkList_Length(list); i++) {
		Teacher* temp = (Teacher*)LinkList_Get(list, i);
		if (temp == NULL) {
			return;
		}
		printf("tmp->age:%d,tmp->name:%s;\n", temp->age, temp->name);
	}
	printf("--------------------------------------------------\n");
	while (LinkList_Length(list) > 0) {
		Teacher* tmp = (Teacher*)LinkList_Delete(list, 0);
		if (tmp == NULL) {
			return;
		}
		printf("tmp->age:%d,tmp->name:%s;\n", tmp->age, tmp->name);
		
	}

	LinkList_Destroy(list);
	
	printf("\n");
	system("pause");
	return 0;
}