#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node *next;
	int value;
} Node;

void printList(struct Node *head) {
	while(head != NULL) {
		printf("%d->", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

Node* createNode(int value, struct Node *head) {
	struct Node *newNode = (Node*)malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->next = NULL;
	if (head != NULL) {
		while(head->next){head = head->next;}
		head->next = newNode;
	}
	return newNode;
}


void swapNode(int i, int j, Node* head) {
	if (head == NULL || (i >= j) || (i<0 || j<0)) {
		return;
	}

	Node *p = NULL,*q = NULL;
	Node *temp = head;
	int z = 0;
	while(temp) {
		if (z == i - 1) {
			p = temp;
		}
		else if (z == j - 1) {
			q = temp;
		}
		temp = temp->next;
		z++;
	}
	if (q==NULL){
		printf("Arguments are not valid\n");
		return;
	}

	Node *x = p->next;
	Node *y = q->next;

	if (i==0) {
		x = head;
		printf("Swapping around %d with %d\n", x->value, y->value);

		if (j-i == 1) {
			x->next = y->next;
			y->next = x;
			head = y;
		}
		else {
			q->next = x;
			temp = x->next;
			x->next = y->next;
			y->next = temp;
			head = y;

		}

	}
	else if (p && q) {
		if (j-i == 1) {
			x->next = y->next;
			y->next = x;
			p->next = y;
		}
		else {
			temp = y->next;
			y->next = x->next;
			x->next = temp;

			temp = q->next;
			q->next = p->next;
			p->next = temp;
		}
	}
	printList(head);

}

Node* sortList(Node *head) {
	if (head->next == NULL) {return head;}
	printList(head);
	Node *node = sortList(head->next);
	return node;
}

int main(void) {
	Node* head= createNode(17, NULL);
	int i,j;
	// scanf("%d\n%d", &i, &j);

	createNode(16, head);
	createNode(15, head);
	createNode(14, head);
	createNode(13, head);
	createNode(12, head);
	createNode(11, head);
	sortList(head);

	// printList(head);
	// swapNode(i,j, head);
	// printList(head);

	return 0;
}
