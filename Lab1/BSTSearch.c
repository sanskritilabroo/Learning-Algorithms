// Write a program to construct a binary tree to support the following operations.
// Assume no duplicate elements while constructing the tree.
// i. Given a key, perform a search in the binary search tree. If the key is found
// then display “key found” else insert the key in the binary search tree.
// ii. Display the tree using inorder, preorder and post order traversal methods

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *l, *r; //node children
}Node;

Node* getNode(int val)
{
	Node *temp = malloc(sizeof(int));
	temp->data = val;
	temp->l = temp->r = NULL;
	return temp;
}

Node* create(Node *root, int val)
{
	if (root == NULL)
	{
		root = getNode(val);
	}
	else
	{
		if (root->data > val)
			root->l = create(root->l,val);
		else
			root->r = create(root->r,val);
	}
	return root;
}
Node* search(Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->r, key);
    else
    	return search(root->l, key);
}

void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		printf("%d ", root->data);
		inorder(root->r);
	}
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->data);
		preorder(root->l);
		preorder(root->r);
	}
}

void postorder(Node *root)
{
	if(root!=NULL) //important to check this condition to prevent segmentation fault
	{
		postorder(root->l);
		postorder(root->r);	
		printf("%d ", root->data);
	}
}

int main()
{
	int choice, val, key;
	Node *root = NULL;
	do {
		printf("1. Create Tree\n");
		printf("2. Search List\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
		case 1: 
			printf("Please enter the node value: ");
			scanf("%d", &val);
			root = create(root, val); //important to store in root variable to prevent segmentation fault
			break;
		case 2: 
			printf("Enter the node value to be searched: ");
			scanf("%d", &key);
			if(search(root,key) != NULL)
				printf("Key Found \n");
			else
				root = create(root,key);
			break;
		case 3:
			printf("Inorder: \n");
			inorder(root);
			printf("\n Preorder: \n");
			preorder(root);
			printf("\n Postorder: \n");
			postorder(root);
			printf("\n");
			break;
		case 4:
			break;
		default:
			printf("Invalid choice ");
			break;
		}
	}while(choice!=4);
	return 0;
}