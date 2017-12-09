#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *left;
	struct node *right;
	int data;
} Node;


Node *createNode(int data) {
	Node *root = (Node *)malloc(sizeof(Node));
	root->left = NULL;
	root->right = NULL;
	root->data = data;
	return root;
}

Node* createTree(int rootValue) {
	return createNode(rootValue);
}

Node* insert(Node *root ,int value) {
	if (!root) {
		return createNode(value);
	}
	if (root->data > value) {
		root->left = insert(root->left, value);
	}
	else {
		root->right = insert(root->right, value);
	}
	return root;
}


void inorderTraversal(Node *root) {
	if (!root) {
		return;
	}
	inorderTraversal(root->left);
	printf("%d->", root->data);
	inorderTraversal(root->right);

}

void search(Node *root, int data) {	
	if (!root) {
		return;
	}

	if (root->data == data) {
		printf("Found it! \n");
		return;
	}

	if (root->data > data) {
		printf("Going left!\n");
		search(root->left, data);
	}
	else {
		printf("Going right!\n");
		search(root->right, data);
	}

}


int main(void) {
	Node *root = createTree(50);
	insert(root, 20);
	insert(root, 40);
	insert(root, 21);
	insert(root, 22);
	insert(root, 42);
	insert(root, 44);

	inorderTraversal(root);
	printf("\n");
	search(root, 44);
	return 0;
}