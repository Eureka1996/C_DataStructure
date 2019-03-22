#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "stack"
/*
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild ;
    struct BiTNode *rchild ;
	struct BiTNode *parent;
}BiTNode,*BiTree;

void preOrder(BiTNode *root) {
	if (root == NULL) {
		return;
	}
	printf("%c\t",root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void preOrderWhile(BiTNode *root) {
	BiTNode * S[10] = { 0 };
	int position = 0;
	S[position] = root;
	position++;
	while (position != 0) {
		root = S[position - 1];
		position--;
		printf("%c\t", root->data);
		if (root->rchild != NULL) {
			S[position] = root->rchild;
			position++;
		}
		if (root->lchild != NULL) {
			S[position] = root->lchild;
			position++;
		}
	}
}


void inOrder(BiTNode *root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->lchild);
	printf("%c\t", root->data);
	inOrder(root->rchild);
}

void inOrderWhile(BiTNode *root) {
	BiTNode* s[10] = { 0 };
	int position = 0;
	while (1) {
		if (root->lchild != NULL) {
			s[position] = root;
			position++;
			root = root->lchild;
			continue;
		}
		printf("%c\t", root->data);
		if (root->rchild != NULL) {
			root = root->rchild;
			continue;
		}
		while (1) {

			if (position != 0) {
				root = s[position-1];
				position--;
				printf("%c\t", root->data);
				if (root->rchild != NULL) {
					root = root->rchild;
					break;
				}
			}
			else {
				position--;
				break;
			}
		}
		if (position == -1)
			break;
	}
}

void postOrder(BiTNode *root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%c\t", root->data);
}

//03
int main03() {
	BiTNode* p1, *p2, *p3 , *p4 ,*p5, *p6, *p7, *p8, *p9;
	p1 = (BiTNode*)malloc(sizeof(BiTNode));
	p2 = (BiTNode*)malloc(sizeof(BiTNode));
	p3 = (BiTNode*)malloc(sizeof(BiTNode));
	p4 = (BiTNode*)malloc(sizeof(BiTNode));
	p5 = (BiTNode*)malloc(sizeof(BiTNode));
	p6 = (BiTNode*)malloc(sizeof(BiTNode));
	p7 = (BiTNode*)malloc(sizeof(BiTNode));
	p8 = (BiTNode*)malloc(sizeof(BiTNode));
	p9 = (BiTNode*)malloc(sizeof(BiTNode));
	
	memset(p1, 0, sizeof(BiTNode));
	memset(p2, 0, sizeof(BiTNode));
	memset(p3, 0, sizeof(BiTNode));
	memset(p4, 0, sizeof(BiTNode));
	memset(p5, 0, sizeof(BiTNode));
	memset(p6, 0, sizeof(BiTNode));
	memset(p7, 0, sizeof(BiTNode));
	memset(p8, 0, sizeof(BiTNode));
	memset(p9, 0, sizeof(BiTNode));

	p1->data = 65;
	p2->data = 66;
	p3->data = 67;
	p4->data = 68;
	p5->data = 69;
	p6->data = 70;
	p7->data = 71;
	p8->data = 72;
	p9->data = 73;
	
	p1->lchild = p2;
	p1->rchild = p5;
	p2->rchild = p3;
	p3->lchild = p4;
	p5->rchild = p6;
	p6->lchild = p7;
	p7->lchild = p8;
	p7->rchild = p9;
	
	preOrder(p1);
	printf("\n---------------------------\n");
	preOrderWhile(p1);
	printf("\n---------------------------\n");
	inOrder(p1);
	printf("\n---------------------------\n");
	inOrderWhile(p1);
	printf("\n---------------------------\n");
//	postOrder(p1);

	printf("wufuqiang\n");
	
	system("pause");
	return 0;
}

*/