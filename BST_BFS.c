#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;
Node* insertInTree(Node *root,int data);


Node* createNode(int data) {
	Node *root = (Node *)malloc(sizeof(Node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

Node* createTree(int data) {
	Node *root = createNode(data);
	// srand(time(NULL));
	// for (int i = 0; i < 10; ++i) {
	// 	int r = rand()%100;
	// 	insertInTree(root, r);
	// }

	insertInTree(root, 10);
	insertInTree(root, 5);
	insertInTree(root, 17);
	insertInTree(root, 1);
	insertInTree(root, 8);

	insertInTree(root, 30);
	insertInTree(root, 25);
	insertInTree(root, 40);
	insertInTree(root, 22);
	insertInTree(root, 27);
	insertInTree(root, 35);
	insertInTree(root, 50);

	return root;
}

Node* insertInTree(Node *root,int data) {
	if (!root) {
		return createNode(data);
	}

	if (data < root->data) {
		root->left = insertInTree(root->left, data);
	}
	else {
		root->right = insertInTree(root->right, data);
	}

	return root;

}

void inorderTraversal(Node *root) {
	if (root) {
		// printf("%d -> ", root->data);
		inorderTraversal(root->left);
		printf("%d -> ", root->data);
		inorderTraversal(root->right);
	}
}

// Queue implementation

typedef struct queue {
	Node *array[400];
	int capacity;
	int end;
	int front;

}Queue;

Queue* createQueue(int capacity) {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->capacity = capacity;
	// q->array = (Node *)malloc(sizeof(Node)*2*capacity);
	q->end = -1;
	q->front = 0;
	return q;
}

void enqueue(Node *data, Queue *q) {
	// printf("Queuing - %d\n", data->data);
	q->end++;
	q->array[q->end] = data;
}

void dequeue(Queue *q) {


	if (q->front <= q->end) {
		printf("Dequeued %d\n", q->array[q->front]->data);
		q->front++;
	}


}

void printQueue(Queue *q) {
	printf("Front %d End %d\n",q->front, q->end);
	for (int i = q->front; i <= q->end; i++) {
		printf("%d - ", q->array[i]->data);
	}
	printf("\n");
}

Queue *globalQueue;

void BFS(Node *root) {
	if (!root) {
		return;
	}
	if (root->left == NULL && root->right == NULL) {
		// dequeue(globalQueue);
		// return;
	}

	if (root->left) {
		enqueue(root->left, globalQueue);
	}

	if (root->right) {
		enqueue(root->right, globalQueue);
	}
	// printQueue(globalQueue);
	dequeue(globalQueue);
	// printQueue(globalQueue);
	BFS(globalQueue->array[globalQueue->front]);
	

}

int main(void) {
	Node *root = createTree(20);
	inorderTraversal(root);
	printf("\n");
	globalQueue = createQueue(20);
	// printQueue(globalQueue);
	enqueue(root, globalQueue);
	BFS(root);
	// Queue *q = createQueue(20);
	// enqueue(201,q);
	// enqueue(202,q);
	// enqueue(203,q);
	// enqueue(204,q);
	// enqueue(205,q);
	// printQueue(q);

}