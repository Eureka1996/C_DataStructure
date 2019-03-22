#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linklist.h"
#include "linkstack.h"

typedef struct _tag_LinkStackNode {
	LinkListNode node;    //��һ���򣨵�һ��Ԫ�أ�
	void* item;			//ջ��ҵ��ڵ�
}TLinkStackNode;

LinkStack* LinkStack_Create() {

	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack) {
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

//���һ��ջ�൱�����һ�����Ա�
//���ջ��ʱ���漰��ջԪ���������ڵĹ���
//������ջ�Ľڵ㶼��malloc��
//��Ҫ���ջ����Ҫ��ջ��Ԫ�ص����������ͷŽ���ڴ�
void LinkStack_Clear(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	while (LinkList_Length(stack) > 0) {
		LinkStack_Pop(stack);
	}
}

//��ջ�����Ԫ�أ��൱�������Ա��ͷ������Ԫ��
//void* itemջ��ҵ��ڵ�-------->ת���������ҵ��ڵ�
int LinkStack_Push(LinkStack* stack, void * item) {
	TLinkStackNode* tmp = NULL;
	int ret = 0;
	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (tmp == NULL) {
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;
	ret = LinkList_Insert(stack,(LinkListNode*)tmp,0);
	if (ret != 0) {
		printf("func LinkList_Insert() err:%d\n", ret);
		if (tmp != NULL) {
			free(tmp);
			tmp = NULL;
		}
		return ret;
	}
	return ret;
	
}

void* LinkStack_Pop(LinkStack* stack) {
	
	TLinkStackNode* tmp = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if (tmp == NULL) {
		return NULL;
	}
	void* item = tmp->item;
	//��ΪLinkStack_Push��ʱ�򣬷������ڴ棬����LinkStack_Popʱ��Ҫ�ͷ��ڴ�
	free(tmp);
	tmp = NULL;
	
	return item;
}

//��ȡջ��Ԫ��
void* LinkStack_Top(LinkStack* stack) {
	TLinkStackNode* node = (TLinkStackNode*)LinkList_Get(stack,0);
	if (node == NULL) {
		return NULL;
	}
	return node->item;
}

int LinkStack_Size(LinkStack* stack) {

	return LinkList_Length(stack) ;
}