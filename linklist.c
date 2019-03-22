#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linklist.h"

/*

typedef void LinkList;

typedef struct _tag_LinkListNode {
struct _tag_LinkListNode* next;
}LinkListNode;

LinkList* LinkList_Create();

void LinkList_Destroy(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delete(LinkList* list, int pos);

int LinkList_Reverse(LinkList* list);

*/
typedef struct _tag_LinkList {
	LinkListNode header;
	int length ;
}TLinkList;

LinkList* LinkList_Create() {
	TLinkList *list = NULL;
	list = (TLinkList*)malloc(sizeof(TLinkList));
	memset(list, 0, sizeof(TLinkList));
	list->length = 0;
	list->header.next = NULL;
	return list;
}


void LinkList_Destroy(LinkList* list) {
	if (list != NULL) {
		free(list);
		list == NULL;
	}
	return;
}

void LinkList_Clear(LinkList* list) {
	if (list == NULL) {
		return;
	}
	TLinkList* tlist = (TLinkList*)list;
	tlist->length = 0;
	tlist->header.next = NULL;
	return;
}

int LinkList_Length(LinkList* list) {
	if (list == NULL) {
		return -1;
	}
	TLinkList* tlist = (TLinkList*)list;
	return tlist->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) {
	int i = 0;
	int ret = 0;
	if (list == NULL || node == NULL) {
		ret = -1;
		return ret;
	}
	if (pos < 0) {
		ret = -2;
		return ret;
	}
	
	TLinkList* tlist = (TLinkList*)list;
	if (pos > tlist->length) {
		pos = tlist->length;
	}
	LinkListNode* current = &(tlist->header);
	for (i = 0; i < pos; i++) {
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tlist->length++;
	return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos) {
	int i = 0;
	if (list == NULL) {
		return NULL;
	}
	TLinkList* tlist = (TLinkList*)list;
	if (pos < 0 || pos >= tlist->length) {
		return NULL;
	}
	LinkListNode* node = NULL;
	node = tlist->header.next;
	for (i = 0; i < pos; i++) {
		node = node->next;
	}
	return node;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) {
	int i = 0;
	LinkListNode *current = NULL;
	LinkListNode * ret = NULL;
	TLinkList* tList = NULL;
	if (list == NULL || pos < 0) {
		printf("func LinkList_Delete() err:%d \n", ret);
		return NULL;
	}
	tList = (TLinkList*)list;
	current = &(tList->header);
	for (i = 0; i < pos && (current->next != NULL); i++) {
		current = current->next;
	}
	//缓存被删除的节点
	ret = current->next;
	current->next = ret->next;
	tList->length--;
	return ret;
}

int LinkList_Reverse(LinkList* list) {
	int ret = 0;
	int i = 0;
	if (list == NULL) {
		ret = -1;
		return ret;
	}
	TLinkList* tlist = (TLinkList*)list;

	LinkListNode* current = tlist->header.next;
	TLinkList* ttlist = LinkList_Create();

	for (i = 0; i < tlist->length;i++) {
		LinkListNode* tmp = current->next;
		LinkList_Insert(ttlist ,current, 0);
		current = tmp;
	}

	tlist->header.next = ttlist->header.next;
	LinkList_Destroy(ttlist);
	return ret;
}




