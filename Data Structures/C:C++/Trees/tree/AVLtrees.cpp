#include<iostream>
using namespace std;
int c=7;
struct node
{
    int data;
    node* prev;
    node* next;
    int height;
};
node* root;
class AVL
{
  public:
    void makeEmpty(node* t)
    {
        if(t == NULL)
            return;
        makeEmpty(t->prev);
        makeEmpty(t->next);
        delete t;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->prev = t->next = NULL;
        }
        else if(x < t->data)
        {
            t->prev = insert(x, t->prev);
            if(height(t->prev) - height(t->next) == 2)
            {
                if(x < t->prev->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->next = insert(x, t->next);
            if(height(t->next) - height(t->prev) == 2)
            {
                if(x > t->next->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->prev), height(t->next))+1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->prev;
        t->prev = u->next;
        u->next = t;
        t->height = max(height(t->prev), height(t->next))+1;
        u->height = max(height(u->prev), t->height)+1;
        return u;
    }

    node* singleLeftRotate(node* &t)
    {
        node* u = t->next;
        t->next = u->prev;
        u->prev = t;
        t->height = max(height(t->prev), height(t->next))+1;
        u->height = max(height(t->next), t->height)+1 ;
        return u;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->next = singleRightRotate(t->next);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->prev = singleLeftRotate(t->prev);
        return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->prev == NULL)
            return t;
        else
            return findMin(t->prev);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->next == NULL)
            return t;
        else
            return findMax(t->next);
    }

    node* remove(int x, node* t)
    {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->prev = remove(x, t->prev);
        else if(x > t->data)
            t->next = remove(x, t->next);
        else if(t->prev && t->next)
        {
            temp = findMin(t->next);
            t->data = temp->data;
            t->next = remove(t->data, t->next);
        }
        else
        {
            temp = t;
            if(t->prev == NULL)
                t = t->next;
            else if(t->next == NULL)
                t = t->prev;
            delete temp;
        }
        if(t == NULL)
            return t;
        t->height = max(height(t->prev), height(t->next))+1;
        if(height(t->prev) - height(t->next) == 2)
        {
            if(height(t->prev->prev) - height(t->prev->next) == 1)
                return singleLeftRotate(t);
            else
                return doubleLeftRotate(t);
        }
        else if(height(t->next) - height(t->prev) == 2)
        {
            if(height(t->next->next) - height(t->next->prev) == 1)
                return singleRightRotate(t);
            else
                return doubleRightRotate(t);
        }
        return t;
    }
    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->prev) - height(t->next);
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->prev);
        cout << t->data << " ";
        inorder(t->next);
    }

public:
    AVL()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }
     void printtree(node *root,int gap)
    {
        if(root==NULL)
           {
              return;
           }
        gap+=c;
        printtree(root->next,gap);
        cout<<endl;
        for(int i=c;i<gap;i++)
        {
            cout<<"  ";
        }
        cout<<root->data;
        printtree(root->prev,gap);
    }
};
int main()
{
    AVL t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.insert(43);
    t.insert(21);
    t.insert(10);
    t.insert(89);
    t.insert(38);
    t.insert(69);
    t.printtree(root,0);
    t.remove(5);
    t.remove(35);
    t.remove(65);
    t.remove(89);
    t.remove(43);
    t.remove(88);
    t.remove(20);
    t.remove(38);
    t.printtree(root,0);
}
