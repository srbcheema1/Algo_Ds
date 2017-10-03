// This a program to demonstrate insert in a binary tree through recursion it also keeps count of all child of a node and also deletes nodes by recursion. It is basically a spoj question orderset. 

#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "

int debug = 0;

struct tree{
    int data;
    int childcnt;
    tree *left;
    tree *right;
};

tree *root = NULL;

//This is the 
void insert(tree *curr, tree *node){
    int sum = 0;
    if(node->data < curr->data){

        if(curr -> left == NULL){
            curr -> left = node;
            sum++;
            
        }
        
        else{
            insert(curr -> left, node);
            sum += curr -> left -> childcnt + 1;   
        }
                
        if(curr -> right != NULL){
            sum += curr -> right -> childcnt + 1;
        }
        
        curr -> childcnt = sum;
        return;
    }

    else if(node->data > curr->data){

        if(curr -> right == NULL){
            curr -> right = node;
            sum++;
        }
        
        else{
           insert(curr -> right, node);
           sum += curr -> right -> childcnt + 1;
        }
                
        if(curr -> left != NULL){
            sum += curr -> left -> childcnt + 1;
        }
        
        curr -> childcnt = sum;
        return ;
    }
    
}

tree * minValueNode( tree *curr){
    tree *current= curr;

    while(current -> left != NULL)
        current = current -> left;

    return current;
}

tree* deleteNode(tree *root, int key){
    root -> childcnt--;

    if (root == NULL)
        return root;

    if (key  < root -> data){
        root -> left = deleteNode(root -> left, key);
    }

    else if (key > root -> data){
        root -> right = deleteNode( root -> right, key);
    }

    else{ 

        if (root -> left == NULL){
            tree *temp = root -> right;
            free(root);
            return temp;
        }
        
        else if (root -> right == NULL){
            tree *temp = root -> left;
            free(root);
            return temp;
        }
         
        tree *temp = minValueNode(root -> right);

        root -> data =temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }
    return root;
}

int Kpify(tree *curr, int pos, int target){
    int count = pos + 1;

    if( curr -> left != NULL){
        count += curr -> left -> childcnt + 1;

        if (target < count){
            return Kpify(curr -> left, pos, target); 
        }
    }
    
    if ( target == count )
    {
        return curr -> data;
    }

    else if (target > count )
    {
        return Kpify(curr -> right, count, target);
    }
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int Q;
    cin >> Q;

    set<int> myset;

    while (Q--){
        char type;
        cin >> type;
        int num;
        set<int> :: iterator its;

        if (type == 'I'){
            cin >> num;

            if (myset.find(num) == myset.end())
                myset.insert(num);

            tree *n =new tree;
            n->left = NULL;
            n->right = NULL;
            n->data = num;
            n->childcnt = 0;    

            if ( root == NULL){
                root = n;
            }
            
            else{
                insert(root, n);
            }
        }
        
        if (type == 'D'){
            cin >> num;
            its = myset.find(num);

            if (its != myset.end()){
                myset.erase(num);
                root = deleteNode(root, num);
            }
        }
        
        if (type == 'C'){
            cin >> num;
            its = myset.lower_bound(num);
            cout << distance(myset.begin(), its) << endl;
        }

        if (type == 'K'){
            cin >> num;

            if (num <= myset.size() ){
                cout << Kpify(root, 0, num) << endl; 
            }

            else
                cout << "invalid" << endl;
        }
    }
	return 0;
}
