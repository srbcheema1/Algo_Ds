/*Given a binary tree, return the inorder traversal of its nodes’ values.
Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].
*/
# include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*Algorithm:
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/

vector<int> inOrderTraversal(TreeNode *A)
{
	if(A==NULL)
		return A;
	stack<TreeNode*> my_stack;
	vector<int> ans;
	TreeNode* current=A;

	while(current!=NULL)
	{
		my_stack.push(current);
		current=current->left;
	}
	while(!my_stack.empty())
	{
		TreeNode* node=my_stack.top();
		my_stack.pop();
		ans.push_back(node->val);
		current=node->right;
		while(current!=NULL)
		{
			my_stack.push(current);
			current=current->left;
		}
	}
	return ans;
}

int main()
{
	TreeNode *A=new TreeNode(1);
	A->left=new TreeNode(2);
	A->right=new TreeNode(3);
	A->left->left=new TreeNode(4);
	A->left->right=new TreeNode(5);
	A->right->left=new TreeNode(6);
	A->left->right=new TreeNode(7);
	vector<int> ans=inOrderTraversal(A);
	cout << "Inorder Traversal is : "
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
} 