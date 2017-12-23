#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Tree Node Structure
typedef struct node {
	struct node *left;
	struct node *right;
	int data;
}Node;


// Function Prototypes
Node* createBinaryTree(int *values, int size);
Node* createNode(int data);
bool searchBinaryTree(int data, Node *root);
Node* insertIntoBinaryTree(int data, Node *root);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
void createVine(Node **root);
void printVine(Node *root);
Node* deleteInorderPredecessor(Node *root);

// Function definitions 
Node* createNode(int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}
Node* createBinaryTree(int *values, int size) {
	if (size <= 0) {
		printf("No values in the input!\n");
	}

	Node *root = createNode(values[0]);
	printf("Inserting %d \n", values[0]);
	for (int i = 1; i < size; ++i) {
		printf("Inserting %d ", values[i]);
		insertIntoBinaryTree(values[i],root);
		printf("Done!!\n");
	}

	printf("Done Creating Tree!\n");
	printf("\n");
	return root;
}

Node* insertIntoBinaryTree(int data, Node *root) {
	if (root == NULL) {
		return createNode(data);
	}
	if (data < root->data) {
		root->left = insertIntoBinaryTree(data, root->left);
	}
	else {
		root->right = insertIntoBinaryTree(data, root->right);	
	}

	return root;
}

void preorder(Node *root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(Node *root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);	
}

bool searchBinaryTree(int data, Node *root) {
	if (root == NULL ) {
		return false;
	}

	if (data < root->data) {
		return searchBinaryTree(data, root->left);
	}
	else if (data > root->data) {
		return searchBinaryTree(data, root->right);
	}
	return true;
}

Node* deleteInorderPredecessor(Node *root) {
	if (!root) {return NULL;}
	
	Node *temp = root;	
	root = root->left;

	if (root->right) {
		temp = root;
		root = root->right;
	}
	else {
		temp->left = root->left;
		return root;
	}

	while(root->right) {
		root = root->right;
		temp = temp->right;
	}
	temp->right = root->left;
	return root;

}

void createVine(Node **root) {
	if ((*root) == NULL || (*root)->left == NULL) {
		return;
	}
	while ((*root)->left) {
		printf("Next one on the left of %d is %d \n", (*root)->data,(*root)->left->data);
		Node *pre = deleteInorderPredecessor((*root));
		printf("Preorder predecessor is %d\n", pre->data);
		pre->right = *root;
		pre->left = (*root)->left;
		*root = pre;
	}
	createVine(&((*root)->right));
}

void printVine(Node *root) {
	while(root) {
		printf("%d ", root->data);
		root = root->right;
	}

	printf("\n");
}

// Main 
int main(void) {
	int data[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
	int size = sizeof(data)/sizeof(data[0]);
	printf("Hi there! i have %d elements\n", size);
	Node *root = createBinaryTree(data, size);
	inorder(root);
	printf("\n");

	// Morris Traversal
	createVine(&root);
	printf("Printing vine!\n");
	printVine(root);


	return 0;
}