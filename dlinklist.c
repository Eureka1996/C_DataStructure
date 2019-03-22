#include <stdlib.h>
#include <stdio.h>

#include "dlinklist.h"

typedef struct _tag_DLinkList {
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDLinkList;

DLinkList* DLinkList_Create() {

	TDLinkList* list = (TDLinkList*)malloc(sizeof(TDLinkList));
	if (list == NULL) {
		return NULL;
	}
	list->header.next = NULL;
	list->header.pre = NULL;
	list->slider = NULL;
	list->length = 0;
	return list;
}

void DLinkList_Destroy(DLinkList* list) {
	if (list != NULL) {
		free(list);
		list = NULL;
	}

}

void DLinkLst_Clear(DLinkList* list) {
	TDLinkList* tlist = (DLinkList*)list;
	if (tlist == NULL) {
		return;
	}
	
	tlist->header.next = NULL;
	tlist->header.pre = NULL;
	tlist->slider = NULL;
	tlist->length = 0;
}

int DLinkList_Length(DLinkList* list) {
	TDLinkList* tlist = (TDLinkList*)list;
	int ret = 0;
	if (tlist == NULL) {
		ret = -1;
		printf("func DLinkList_Length error:%d\n", ret);
		return ret;
	}
	return tlist->length;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos) {
	int ret = -1;
	int i = 0;
	TDLinkList* tlist = (TDLinkList*)list;
	if (tlist == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func DLinkList_Insert error:%d\n", ret);
		system("pause");
		return ret;
	}

	DLinkListNode* current = (DLinkListNode*)tlist;
	DLinkListNode* next = NULL;
	for (i = 0; (i < pos) && (current->next != NULL);i++) {
		current = current->next;
	}
	next = current->next;

	current->next = node;
	node->next = next;

	if (next != NULL) { //当链表插入第一个元素，需要特殊处理
		next->pre = node;
	}
	
	node->pre = current;

	if (tlist->length == 0) {
		tlist->slider = node;
	}
	if (current == (DLinkListNode*)tlist) {
		node->pre = NULL;
	}
	
	tlist->length++;

	return ret;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos) {
	TDLinkList* tlist = (TDLinkList*)list;
	int i = 0;
	if (tlist == NULL || pos < 0 || pos >= tlist->length) {
		printf("func DLinkList_Get error:%d\n", -1);
		system("pause");
		return NULL;
	}
	DLinkListNode* current = (DLinkListNode*)tlist;
	for (i = 0; i < pos; i++) {
		current = current->next;
	}
	return current->next;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos) {
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	if (tlist == NULL || pos < 0 || pos >= tlist->length) {
		printf("func DLinkList_Delete error:%d\n", -1);
		system("pause");
		return NULL;
	}
	DLinkListNode* current = (DLinkListNode*)tlist;
	DLinkListNode* next = NULL;
	for (i = 0; i < pos; i++) {
		current = current->next;
	}
	ret = current->next;
	next = ret->next;

	current->next = next;

	if (next != NULL) {
		next->pre = current;
		if (current == (DLinkListNode*)tlist) {
			next->pre = NULL;
		}
	}

	if (tlist->slider == ret) {
		tlist->slider = next;
	}

	return ret;
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node) {

	return NULL;
}

DLinkListNode* DLinkList_Reset(DLinkList* list) {

	return NULL;
}

DLinkListNode* DLinkList_Current(DLinkList* list) {

	return NULL;
}

DLinkListNode* DLinkList_Next(DLinkList* list) {

	return NULL;
}

DLinkListNode* DLinkList_Pre(DLinkList* list) {

	return NULL;
}