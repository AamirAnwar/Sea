#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
int numberOfNodes(Node *root);
Node* DSW(Node **root);
Node* rotateLeft(Node *root);
Node* rotateRight(Node *root);

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
	// printf("Inserting %d \n", values[0]);
	for (int i = 1; i < size; ++i) {
		// printf("Inserting %d ", values[i]);
		insertIntoBinaryTree(values[i],root);
		// printf("Done!!\n");
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
	if (!root) {return temp;}

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
	if ((*root) == NULL) {
		return;
	}
	while ((*root)->left) {
		// printf("Next one on the left of %d is %d \n", (*root)->data,(*root)->left->data);
		Node *temp = *root;
		Node *pre = deleteInorderPredecessor(temp);
		// printf("Preorder predecessor is %d\n", pre->data);
		pre->right = *root;
		pre->left = (*root)->left;
		(*root)->left = NULL;
		*root = pre;
	}
	if ((*root)->right == NULL) {return;} 	
	// printf("Next one to be stripped of left children is %d \n",(*root)->right->data);
	createVine(&((*root)->right));
}

void printVine(Node *root) {
	while(root) {
		printf("%d ", root->data);
		root = root->right;
	}

	printf("\n");
}

int numberOfNodes(Node *root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}

Node* rotateLeft(Node *root) {
	if (root == NULL || root->right == NULL) {
		return root;
	}
	Node *nodeToRotate = root->right;
	root->right = nodeToRotate->left;
	nodeToRotate->left = root;
	return nodeToRotate;
}

Node* rotateRight(Node *root) {
	if (root == NULL) {
		return root;
	}
	exit(0);
}


Node* DSW(Node **root) {
	// Create backbone tree
	if (*root == NULL) {
		return *root;
	}

	createVine(root);
	printVine(*root);

	int n = numberOfNodes(*root);
	int m = pow(2, floor(log2(n+1))) - 1;
	
	printf("There are %d in the closest perfect tree form but we have %d nodes here!\n", m,n);

	if (n > m) {
		// Perform n-m rotations from the top (Pre-processing)
		for (int i=0;i<(n-m);i++) {
			*root = rotateLeft(*root);
		}
	}

	// Perform a rotation for every alternate node

	while (m > 1) {
		Node *temp = *root;
		Node *parent = NULL;
		*root = temp->right;
		printf("Root is now %d\n",(*root)->data );
		m = m/2;
		printf("M is now %d\n", m);
		printVine(temp);
		while (temp && temp->right && (temp->right->right || temp->right->left)) {
			printf("Rotating about node %d \n", temp->data);
			printVine(*root);
			printf("--------------\n");
			if (parent) {
				parent->right = temp->right;
			}
			temp = rotateLeft(temp);
			parent = temp;
			temp = temp->right;

		}

	}
	return *root;

}

// Main 
int main(void) {
	int data[] = {50,30,100,10,40, 110,75};
	int size = sizeof(data)/sizeof(data[0]);
	printf("Hi there! i have %d elements\n", size);
	Node *root = createBinaryTree(data, size);
	// inorder(root);
	postorder(root);
	printf("\n");

	// printf("Rotating root\n");
	// root = rotateLeft(root);
	// postorder(root);
	// printf("\n");
	// printf("Total number of nodes is %d\n", numberOfNodes(root));

	// Morris Traversal
	// createVine(&root);
	// printf("Printing vine!\n");
	// printVine(root);

	root = DSW(&root);
	postorder(root);



	return 0;
}