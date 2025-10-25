#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;
TreeNode* node_create(int key) {
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

TreeNode* insert(TreeNode* root,int key) {
	if (root == NULL) {
		return node_create(key);
	}
	if (key < root->key) {
		root->left = insert(root->left, key);
	} else if (key > root->key) {
		root->right = insert(root->right, key);
	}
	return root;
}
TreeNode* minnode(TreeNode* root) {
	while (root != NULL && root->left != NULL) {
		root = root->left;
	}
	return root;
}
TreeNode* delete(TreeNode* root, int key) {
	if (root == NULL) {
		return NULL;
	}

	if (key < root->key) {
		root->left = delete(root->left, key);
	} else if (key > root->key) {
		root->right = delete(root->right, key);
	} else{
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		} else if(root->right == NULL) {
			TreeNode* temp = minnode(root->right);
			root->key = temp->key;
			root->right = delete(root->right,temp->key);
		}
		return root;
	}
}
int search(TreeNode* root, int key) {
	if (root == NULL) {
		return 0;
		printf("net\n");
	}
	if (key == root->key) {
		return 1;
		printf("da\n");
	} else if (key < root->key) {
		return search(root->left,key);
	} else {
		return search(root->right, key);
	}
}
void free_tree(TreeNode* root) {
	if (root != NULL) {
		free_tree(root->left);
		free_tree(root->right);
		free(root);
	}
}
int main() {
	TreeNode* root = NULL;
	char operation;
	int number;
	while(scanf("%c%d", &operation,&number) == 2) {
		switch (operation) {
			case '+':
				root = insert(root,number);
				break;
			case '-':
				root = delete(root,number);
				break;
			case '?':
				printf("%d%s\n", number, search(root,number) ? "yes" : "no");
				break;
			default:
				break;
		}
	}
	free_tree(root);
	return 0;
}
