// C++ program to demonstrate insert operation
// in binary search tree with parent pointer
#include<bits/stdc++.h>

struct Node
{
	int key;
	struct Node *left, *right, *parent;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->parent = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("Node : %d, ", root->key);
		if (root->parent == NULL)
		printf("Parent : NULL \n");
		else
		printf("Parent : %d \n", root->parent->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new Node with
given key in BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
	{
		Node *lchild = insert(node->left, key);
		node->left = lchild;

		// Set parent of root of left subtree
		lchild->parent = node;
	}
	else if (key > node->key)
	{
		Node *rchild = insert(node->right, key);
		node->right = rchild;

		// Set parent of root of right subtree
		rchild->parent = node;
	}

	/* return the (unchanged) Node pointer */
	return node;
}

// Driver Program to test above functions
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// print inorder traversal of the BST
	inorder(root);

	return 0;
}
