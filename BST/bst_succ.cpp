#include<iostream>
#include<stack>
using namespace std;

struct BST{ //Creating BST data srtucture
    int data;
    struct BST* parent = NULL;
    struct BST* left = NULL;
    struct BST* right = NULL;
};

struct BST* root = NULL;


struct BST* search(int k){   //searching for an element in BST
    struct BST* node = (struct BST*) malloc(sizeof(struct BST));
    node = root;
    while(node!=NULL){
        if(k == node->data) return node;
        else if(k < node->data) node = node->left;
        else node = node->right;
    }
    return NULL;
}

struct BST* min(struct BST* x){ //finding min element in BST
    while(x->left!=NULL){
        x = x->left;
    }
    return x;
}

struct BST* max(struct BST* x){ //finding max element in BST
    while(x->right!=NULL){
        x = x->right;
    }
    return x;
}

int succ(struct BST* x){  //finding successor if an element in BST
    if(x == max(root)) return x->data; //if x is the maximum element then it has no successor

    if(x->right!=NULL)
        return min(x->right)->data; //if right subtree exist for the element than its successor is minimum element in right subtree
    else{ //else we find successor when current node is node right child of its parent
        struct BST* y = x->parent;
        while(y!=NULL && y->right==x){
            x = y;
            y = y->parent;
        }
        return y->data;
    }
}

void insert(struct BST* x, int data){ //inserting node in BST
    struct BST *node  = (struct BST*) malloc(sizeof(struct BST)), *newi = (struct BST*) malloc(sizeof(struct BST));;
    x = root;
    node = NULL;
    while(x != NULL){
        node = x;
        if(data > x->data) x = x->right;
        else x = x->left;
    }
    newi->data = data;
    newi->parent = node;
    if(node==NULL) root = newi;
    else{
        if(data>node->data) node->right = newi;
        else node->left = newi;
    }
}



int main(){
    struct BST* x = NULL;
    insert(x, 2);
    insert(x, 1);
    insert(x, 999);
    insert(x, 3);
    insert(x, 24);
    cout<<succ(root);   //calling succ on root, it return 3

}