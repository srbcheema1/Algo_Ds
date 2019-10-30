#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node Node;

void Display(struct Node* root)
{
	struct Node *temp = root;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


struct Node* getNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}


struct Node *insertNodeAtEnd(struct Node *root, int data)
{
	struct Node *newNode = getNode(data), *temp;
	if (root == NULL)
		root = newNode;
	else
	{
		temp = root;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	return root;
}

int length(struct Node *root)
{
	int i = 0;
	struct Node *temp = root;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

int add_two_sll_carry(struct Node *temp, struct Node *temp1)
{
	if (temp->next == NULL && temp1->next == NULL)
	{
		int sum = temp->data + temp1->data;
		temp->data = (sum) % 10;
		return (sum / 10);
	}
	int sum = temp1->data + temp->data + add_two_sll_carry(temp1->next, temp->next);
	temp->data = (sum)%10;
	return (sum / 10);
}

struct Node *add_two_sll(struct Node *root1,struct Node *root2,int l1,int l2)
{
	int carry=0;
	int d = l2 > l1 ? l2 - l1 : l1 - l2;
	int i = 1;
	struct Node *temp = root1,*prev=root1;
	struct Node *temp1 = root2, *prev1 = root2;
	if (l1 > l2)
	{
		while (i <= d)
		{
			prev = temp;
			temp = temp->next;
			i++;
		}
		carry = add_two_sll_carry(temp, temp1);
		if (carry != 0)
			prev->data = prev->data + carry;
		return root1;
	}
	else if (l2>=l1)
	{
		while (i <= d)
		{
			prev1 = temp1;
			temp1 = temp1->next;
			i++;
		}
		carry = add_two_sll_carry(temp1, temp);
		if (l1 == l2 && carry != 0)
		{
			struct Node *root = getNode(carry);
			root->next = root2;
			return root;
		}
		if (carry != 0)
		{
			prev1->data = prev1->data + carry;
			return root2;
		}
	}
}

