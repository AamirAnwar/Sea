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

int addWithCarry(Node *head) {
	if (!head) {return 1;}
	head->value = head->value + addWithCarry(head->next);
	int total = head->value;


	head->value = head->value%10;
	return total/10;
}

Node* addOne(Node* head) {
	int carry = addWithCarry(head);
	if (carry) {
		Node* newNode = createNode(carry, NULL);
		newNode->next = head;
		head = newNode;
	}
	return head;
}

int main(void) {
	Node* head= createNode(9, NULL);
	int i=1;

	createNode(9, head);
	createNode(9, head);
	createNode(9, head);
	createNode(9, head);

	printList(head);
	head = addOne(head);
	printList(head);


	return 0;
}
