

#include <stdlib.h>
#include <stdio.h>

typedef struct BiTNode {
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

void preOrder(BiTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%d  ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void inOrder(BiTNode* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->lchild);
	printf("%d ", root->data);
	inOrder(root->rchild);
}

void postOrder(BiTNode* root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d ", root->data);
}


//12
int main12() {

	BiTNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(t1));
	memset(&t2, 0, sizeof(t1));
	memset(&t3, 0, sizeof(t1));
	memset(&t4, 0, sizeof(t1));
	memset(&t5, 0, sizeof(t1));
	t1.data = 1001;
	t2.data = 1002;
	t3.data = 1003;
	t4.data = 1004;
	t5.data = 1005;
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4 ;
	t2.rchild = &t5;
	preOrder(&t1);

	printf("\n----------------------\n");
	system("pause");
	return 0;
}