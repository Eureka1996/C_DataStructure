#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "seqlist.h"

typedef struct _tag_SeqList {		//一个顺序线性表的结构特征
	int length ;
	int capacity;
	unsigned int **node;
}TSeqList;

SeqList* SeqList_Create(int capacity) {
	TSeqList* tSeqList = NULL;
	int ret = 0;
	tSeqList = (TSeqList*)malloc(sizeof(TSeqList));
	if (tSeqList == NULL) {
		ret = -1;
		printf("func SeqList_Create() err:%d\n" , ret );
		return NULL;
	}
	//分配空间来存储顺序线性表的节点
	tSeqList->node = (unsigned int**)malloc(sizeof(unsigned int*)*capacity);
	if (tSeqList -> node == NULL) {
		ret = -2;
		free(tSeqList);
		printf("func SeqList_Create() err:%d\n", ret);
		return NULL;
	}
	tSeqList->capacity = capacity;
	tSeqList->length = 0;
	return tSeqList;
}


//销毁顺序链表
void SeqList_Destroy(SeqList* list) {
	int ret = 0;
	if (list == NULL) {
//		ret = -1;
//		printf("func SeqList_Destroy err:%d\n",ret);
		return ;
	}
	TSeqList *tSeqList = (TSeqList*)list;
	if (tSeqList->node != NULL) {
		free(tSeqList->node);
		tSeqList->node = NULL;
	}
	free(tSeqList);
	tSeqList = NULL;
}

void SeqList_Clear(SeqList* list) {
	
	if (list == NULL) {
		return;
	}
	TSeqList* tList = (TSeqList*)list;
	tList->length = 0;
}

int SeqList_Length(SeqList* list) {
	int ret = 0;
	int length = 0;
	if (list == NULL) {
		ret = -1;

		return ret;
	}
	TSeqList *tList = (TSeqList*)list;
	length = tList->length;
	return length ;
}

int SeqList_Capacity(SeqList* list) {
	int ret = 0;
	if (list == NULL) {
		ret = -1;
		printf("func SeqList_Capacity err:%d\n", ret);
		return ret;
	}
	TSeqList *tList = (TSeqList*)list;
	return tList->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) {
	int ret = 0;
	int i = 0;
	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func SeqList_Insert() err:%d\n", ret);
		return ret;
	}
	TSeqList *tList = (TSeqList*)list;
	if (pos > tList->length) {
		pos = tList->length;
	}
	if (tList->length >= tList->capacity) {
		int **newnode = (unsigned int**)malloc(sizeof(unsigned int*)*tList->capacity*2);
		memset(newnode, 0, sizeof(unsigned int*)*tList->capacity * 2);
		memcpy(newnode, tList->node, sizeof(unsigned int*)*tList->capacity);
		free(tList->node);
		tList->node = newnode;
		tList->capacity = 2 * tList->capacity;
	}

	for (i = tList->length; i > pos; i--) {
		tList->node[i] = tList->node[i - 1];
	}
	tList->node[i] = node;
	tList->length++;
	return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) {
	int ret = 0;
	if (list == NULL || pos < 0) {
		ret = -1;
		printf("func SeqList_Get() err:%d\n", ret);
		return NULL;
	}
	TSeqList* tList = (TSeqList*)list;
	if (pos > tList->length) {
		ret = -2;
		printf("func SeqListGet() err:%d\n", ret);
		return NULL;
	}
	return tList->node[pos];
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) {
	int ret = 0;
	int i = 0;
	if (list == NULL || pos < 0) {
		ret = -1;
		printf("func SeqList_Delete() err:%d\n", ret);
		return NULL;
	}
	TSeqList* tList = (TSeqList*)list;
	if (pos > tList->length) {
		ret = -2;
		printf("func SeqList_Delete() err:%d\n", ret);
		return NULL;
	}
	SeqListNode* node = tList->node[pos];
	for (i = pos; i < tList->length; i++) {
		tList->node[i] = tList->node[i + 1];
	}
	

	tList->length--;
	return node ;
}