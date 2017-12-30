// TODO - Change to .h file
#include "binarytree_DSW_Morris.c"
#include <limits.h>
int *counter;


Node* createTreeFromInorder(int *traversal, int size, int min, int max, Node *root) {

	if ((*counter) >= size) {
		return NULL;
	}

	int data = traversal[*counter];

	printf("Data is %d\n", data);
	printf("Min is %d and Max is %d\n", min, max);
	if (data >= min && data <= max && root == NULL) {
		printf("Found the place for this bugger! %d\n", data);
		*counter = (*counter) + 1;
		root = createNode(data);
	}

	if (root) {
		root->left = createTreeFromInorder(traversal, size, min,data, root->left);
		root->right = createTreeFromInorder(traversal, size, data, max,root->right);
	}
	return root;

}

int main(void) {
	int data[] = {50,20,10,30,70,60,100};
	int size = sizeof(data)/sizeof(data[0]);
	int initialValue = 0;
	counter = &initialValue;
	// Node *root = insertIntoBinaryTree(data[0], NULL);
	Node *root = NULL;
	root = createTreeFromInorder(data, size,-INT_MAX, INT_MAX, root);
	inorder(root);

	return 0;
}