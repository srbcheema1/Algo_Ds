// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class LNode
{
	public:
	int data;
	LNode* next;
};

/* A Binary Tree node */
class TNode
{
	public:
	int data;
	TNode* left;
	TNode* right;
};

TNode* newNode(int data);
int countLNodes(LNode *head);
TNode* sortedListToBSTRecur(LNode **head_ref, int n);


/* This function counts the number of
nodes in Linked List and then calls
sortedListToBSTRecur() to construct BST */
TNode* sortedListToBST(LNode *head)
{
	/*Count the number of nodes in Linked List */
	int n = countLNodes(head);

	/* Construct BST */
	return sortedListToBSTRecur(&head, n);
}

/* The main function that constructs
balanced BST and returns root of it.
head_ref --> Pointer to pointer to
head node of linked list n --> No.
of nodes in Linked List */
TNode* sortedListToBSTRecur(LNode **head_ref, int n)
{
	/* Base Case */
	if (n <= 0)
		return NULL;

	/* Recursively construct the left subtree */
	TNode *left = sortedListToBSTRecur(head_ref, n/2);

	/* Allocate memory for root, and
	link the above constructed left
	subtree with root */
	TNode *root = newNode((*head_ref)->data);
	root->left = left;

	/* Change head pointer of Linked List
	for parent recursive calls */
	*head_ref = (*head_ref)->next;

	/* Recursively construct the right
		subtree and link it with root
		The number of nodes in right subtree
		is total nodes - nodes in
		left subtree - 1 (for root) which is n-n/2-1*/
	root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1);

	return root;
}



/* UTILITY FUNCTIONS */

/* A utility function that returns
count of nodes in a given Linked List */
int countLNodes(LNode *head)
{
	int count = 0;
	LNode *temp = head;
	while(temp)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

/* Function to insert a node
at the beginning of the linked list */
void push(LNode** head_ref, int new_data)
{
	/* allocate node */
	LNode* new_node = new LNode();
	
	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(LNode *node)
{
	while(node!=NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
TNode* newNode(int data)
{
	TNode* node = new TNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* A utility function to
print preorder traversal of BST */
void preOrder(TNode* node)
{
	if (node == NULL)
		return;
	cout<<node->data<<" ";
	preOrder(node->left);
	preOrder(node->right);
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LNode* head = NULL;

	/* Let us create a sorted linked list to test the functions
	Created linked list will be 1->2->3->4->5->6->7 */
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout<<"Given Linked List ";
	printList(head);

	/* Convert List to BST */
	TNode *root = sortedListToBST(head);
	cout<<"\nPreOrder Traversal of constructed BST ";
	preOrder(root);

	return 0;
}

// This code is contributed by rathbhupendra
