#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	struct ListNode* newhead = head;
	struct ListNode* next = head->next;
	newhead->next = NULL;
	while (next) {
		struct ListNode* next_next = next->next;
		next->next = newhead;
		newhead = next;
		next = next_next;
	}
	return newhead;
}

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		return head;
	}
	struct ListNode* newhead = head->next;
	struct ListNode* current;
	struct ListNode* prev = NULL ;
	current = head;
	while (head) {
		head = head->next;
		if (head == NULL) {
			break;
		}
		if (prev != NULL) {
			prev->next = head;
		}
		current->next = head->next;
		head->next = current;

		head = current->next;
		prev = current;
		current = head;
	}
	return newhead;

}

int hasCycle(struct ListNode *head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	int count = 0;
	while (fast != NULL && fast->next != NULL) {
		count++;
		printf("%d\n",count);
		slow = slow->next;
		
		fast = fast->next->next;
		if (slow == fast) {
			return 1;
		}
	}
	return 0;
}

struct ListNode* findLoopPort(struct ListNode* head) {
	struct ListNode* loopPort = NULL;

	struct ListNode* slow = head;
	struct ListNode* fast = head;
	int count = 0;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;

		fast = fast->next->next;
		if (slow == fast) {
			fast = head;
			while (fast != slow) {
				fast = fast->next;
				slow = slow->next;
			}
			loopPort = fast;
			break;
		}
	}

	return loopPort;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode* newhead = head;
	struct ListNode* prev = head;
	struct ListNode* next = head;
	struct ListNode* end = head;
	struct ListNode* temp = head;
	struct ListNode* first = head;
	struct ListNode* next_next = NULL;
	int i = 0;
	int flag = 1;
	int flag2 = 1;

	if (head == NULL) {
		return NULL;
	}
	if (k == 1) {
		return head;
	}

	while (temp != NULL) {
		for (i = 0; i < k-1; i++) {
			temp = temp->next;
			if (temp == NULL) {
				flag = 0;
				break;
			}
		}
		
		if (flag == 0) {
			break;
		}

		next = next->next;
		int tk = k - 1;
		while (tk) {
			next_next = next->next;
			next->next = prev;
			prev = next;
			next = next_next;
			tk--;
			
		}
		prev = next;
		first->next = next_next;
		
		if (flag2 == 0) {
			end->next = temp;
			end = first;
		}
		first = next_next;
		if (flag2 == 1) {
			head = temp;
			flag2 = 0;
		}
		temp = next_next;
	}

	return head;
}


//04
int main04() {

	//	Definition for singly-linked list.

	struct ListNode* head, *ln1, *ln2, *ln3, *ln4, *ln5;
	ln1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(ln1, 0, sizeof(struct ListNode));
	ln2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(ln2, 0, sizeof(struct ListNode));
	ln3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(ln3, 0, sizeof(struct ListNode));
	ln4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(ln4, 0, sizeof(struct ListNode));
	ln5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	memset(ln5, 0, sizeof(struct ListNode));
	head = ln1;
	ln1->val = 1;
	ln1->next = ln2;
	ln2->val = 2;
	ln2->next = ln3;
	ln3->val = 3;
	ln3->next = ln4;
	ln4->val = 4;
	ln4->next = ln5;
	ln5->val = 5;
	ln5->next = NULL;

	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	head = ln1;
	printf("\nwufuqiang\n");
//	head = swapPairs(head);
	head = reverseKGroup(head, 2);
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}

//	printf("%d",hasCycle(head));
//	struct ListNode* loopPort = findLoopPort(head);
//	printf("%d\n",loopPort->val);
	printf("\nwufuqiang\n");
	system("pause");
	return 0;
}