
#include <stdlib.h>
#include <stdio.h>
#include "circlelist.h"


typedef struct _tag_CircleList {
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;



CircleList* CircleList_Create() {
	TCircleList* tlist = (TCircleList*)malloc(sizeof(TCircleList));
	if (tlist == NULL) {
		return NULL;
	}
	tlist->length = 0;
	tlist->header.next = NULL;
	tlist->slider = NULL;
	return tlist ;
}

void CircleList_Destroy(CircleList* list) {
	if (list == NULL) {
		return;
	}
	free(list);
	list = NULL;
}

void CircleList_Clear(CircleList* list) {
	if (list == NULL) {
		return;
	}
	TCircleList* tlist = (TCircleList*)list;
	tlist->length = 0;
	tlist->header.next = NULL;
	tlist->slider = NULL;
}

int CircleList_Length(CircleList* list) {
	if (list == NULL) {
		return -1;
	}
	TCircleList* tlist = (TCircleList*)list;
	
	return tlist->length;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) {
	int ret = 0;
	int i = 0;
	if (list == NULL || node == NULL) {
		ret = -1;
		printf("func CircleList_Insert err:%d\n", ret);
		system("pause");
		return ret;
	}
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* current = (CircleListNode*)(tlist);   //需不需要将tlist取地址？此处不需要取地址

	for (i = 0; (i < pos) && (current->next != NULL); i++) {
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	if (tlist->length == 0) {
		tlist->slider = node;
	}
	tlist->length++;
	//循环链表头插法的特别处理
	if (current == (CircleListNode*)tlist) {
		CircleListNode* last = CircleList_Get(tlist, tlist->length - 1);
		last->next = node;
	}
	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos) {
	int i = 0;
	if (list == NULL) {
		printf("func CircleList_Get error:%d\n", -1);
		system("pause");
		return NULL;
	}
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* current = (CircleListNode*)(tlist);
	for (i = 0; (i < pos)&&(current->next != NULL);i++) {
		current = current->next;
	}
	return current->next ;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos) {
	int i = 0;
	CircleListNode* ret = NULL;
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* last = NULL;
	if (tlist == NULL || pos < 0 || tlist->length <= 0) {
		printf("func CircleList_Delete error:%d\n", -1);
		system("pause");
		return NULL;
	}

	CircleListNode* current = (CircleListNode*)tlist;
	for (i = 0; (i < pos)&&(current->next != NULL); i++) {
		current = current->next;
	}

	if (current == (CircleListNode*)tlist) {
		last = CircleList_Get(list, tlist->length - 1);
	}

	ret = current->next;
	current->next = current->next->next;
	tlist->length--;

	//判断是否有取得最后一个元素
	if (last != NULL) {
		tlist->header.next = ret->next;
		last->next = ret->next;
	}

	//若删除的元素为游标所指的元素
	if (tlist->slider == ret) {
		tlist->slider == ret->next;
	}

	//若删除元素后，链表长度为0
	if (tlist->length == 0) {
		tlist->slider == NULL;
		tlist->header.next = NULL;
	}
	
	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) {
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;
	if (tlist == NULL || node == NULL) {
		printf("func CircleList_DeleteNode error:%d\n", -1);
		system("pause");
		return NULL;
	}
	CircleListNode* current = (CircleListNode*)tlist;
	for (i = 0; i < tlist->length; i++) {
		if (current->next == node) {
			ret = current->next;
			break;
		}
		current = current->next;
	}

	if (ret != NULL) {
		CircleList_Delete(list,i);
	}
	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list) {
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (tlist != NULL) {
		tlist->slider = tlist->header.next;
		ret = tlist->slider;
	}
	return ret;
}

CircleListNode* CircleList_Current(CircleList* list) {
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (tlist != NULL) {
		ret = tlist->slider;
	}

	return ret;
}

CircleListNode* CircleList_Next(CircleList* list) {
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if ((tlist != NULL) && (tlist->slider != NULL)) {
		ret = tlist->slider;
		tlist->slider = ret->next;
	}
	return ret;
}