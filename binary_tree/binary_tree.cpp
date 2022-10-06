#include<iostream>
#include<queue>
using namespace std;
class node{
 public: 
 /*here are 3 members in class which are data(value of that node), left(pointer for storing address of left node of root node),
 right(pointer for stroring address of right node of root node)*/
 int data;
 node* left;
 node* right;
 node(int d)
 {
   this->data=d;
   this->right=NULL;
   this->left=NULL;
 }
};

node* makeTree(node* root)
{
	//take data input from user
    int data;
    cout<<"enter data: "<<endl;
    cin>>data;
    root = new node(data);
	
	//if input is -1 than that means we have to put NULL there and end that branch of the tree
    if(data==-1)
      return NULL;
  
    //make a left subtree of root node
    cout<<"insertion at left: "<<endl;
    root->left=makeTree(root->left);
	
	//make a right subtree of root node
    cout<<"insertion at right: "<<endl;
    root->right=makeTree(root->right);
    return root;
}
int main(){
    // ex- 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  node* root=NULL;
  root=makeTree(root);
  return 0;
}