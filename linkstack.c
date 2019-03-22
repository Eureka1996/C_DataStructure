#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linklist.h"
#include "linkstack.h"

typedef struct _tag_LinkStackNode {
	LinkListNode node;    //第一个域（第一个元素）
	void* item;			//栈的业务节点
}TLinkStackNode;

LinkStack* LinkStack_Create() {

	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack) {
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

//清空一个栈相当于清空一个线性表
//清空栈的时候，涉及到栈元素生命周期的管理
//所有入栈的节点都是malloc的
//若要清空栈，需要把栈中元素弹出，并且释放结点内存
void LinkStack_Clear(LinkStack* stack) {
	if (stack == NULL) {
		return;
	}
	while (LinkList_Length(stack) > 0) {
		LinkStack_Pop(stack);
	}
}

//向栈中添加元素，相当于向线性表的头部插入元素
//void* item栈的业务节点-------->转化成链表的业务节点
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
	//因为LinkStack_Push的时候，分配了内存，所以LinkStack_Pop时需要释放内存
	free(tmp);
	tmp = NULL;
	
	return item;
}

//获取栈顶元素
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