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

Node *createLL(int headValue) {
	Node* head= createNode(headValue, NULL);
	createNode(2, head);
	createNode(3, head);
	createNode(4, head);
	createNode(5, head);	
	return head;
}

Node *reverseLinkedList(Node *head) {

	if (head == NULL) {
		return head;
	}
	
	Node *prev = NULL, *next = head;
	
	while(head != NULL) {
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;	
}

void recursiveReverse(Node **head) {
	Node *first;
	Node *rest;

	if (*head == NULL) {return;}
	first = *head;
	rest = first->next;


	if (rest == NULL) {return;}

	recursiveReverse(&rest);
	printList(rest);

	first->next->next = first;
	first->next = NULL;

	*head = rest;



}


int main(void) {
	Node* head= createLL(1);
	printf("%s\n", "Printing Original List");
	printList(head);
	printf("\n");
	recursiveReverse(&head);
	// printList(head);


	

	return 0;
}
