#include<iostream>
using namespace std;
struct node
{ struct node * pre;
int info;
 struct node * next;
};

struct link
{node * h;
node* t;
link()
{h=NULL;
t=NULL;
}
node * create(int x)
{  node* temp=new node;
   temp->pre=NULL;
   temp->info=x;
   temp->next=NULL;
   return temp;
   }
   void ins_beg()
{int ele,n,i,a;
    node *p;
    cout<<"Enter the no. of nodes you want to enter: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        p=create(ele);
        if(h==NULL)
        {
            h=p;
            t=p;
        }
        else
        {
            p->next=h;
            h->pre=p;
            h=p;
        }

    }
    }
    void disp()
    {t=h;
    if(h==NULL)
        cout<<"Linked List is empty";
    while(t!=NULL)
    {
        cout<<"->"<<t->info;
        t=t->next;
    }
    cout<<endl;

    }
    void swap1()
{
    struct node *temp = h;
    while (temp != NULL && temp->next != NULL)
    {  swap(&temp->info, &temp->next->info);
        temp = temp->next->next;
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
node * ins_sort()
{ int info;
node * current;
cout<<"enter node to add in sorted linked list"<<endl;
cin>>info;
    node * n = new node;
    n->info = info;
    current = h;
        while (current->next != NULL && current->next->info < n->info)
            current = current->next;
        n->next = current->next;
        if (current->next != NULL)
            n->next->pre = n;

        current->next = n;
        n->pre = current;
}

node* rem_dup()
 {     node *after = NULL;
    node *dup = NULL;

node * curr = h;

    while(curr->next != NULL)
    {
       after = curr->next;
       while(after != NULL)
       {
          if(curr->info == after->info)
          {
             dup = after;
             curr->next = after->next;
             delete dup;
          }
          else
          {
             after = after->next;
          }
       }
          curr = curr->next;
    }

 }

 void del_3()
 {int ele,n,i;
    node *p,*ptr,*p1;
    cout<<"Enter the no. of nodes you want to enter: ";
    cin>>n;
    if(n<=0)
    {
        cout<<"sorry cant create list"<<endl;

    }
    else
{
    for(i=0;i<n;i++)
    {
        cin>>ele;
        p=create(ele);
        if(h==NULL)
        {
            h=p;
        }
        else
        {
            ptr=h;
            h=p;
            p->next=ptr;
        }

    }
t=h;
if(h==NULL)
cout<<"Cannot delete from an empty list\n";
else
{
        while(t->next!=NULL)
        {
           // ele=t->info;
            if(h->info%3==0)
            {
                h=h->next;
            }
            else if(t->next->info%3==0)
            {
                t->next=t->next->next;
            }
            else
            {
                t=t->next;
            }
        }
        }
}

disp();
 }
 void triplets()
 {
     int ele,n,i,x;
    node *p;
    cout<<"Enter the no. of nodes you want to enter: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        p=create(ele);
        if(h==NULL)
        {
            h=p;
            t=p;
        }
        else
        {
            p->next=h;
            h->pre=p;
            h=p;
        }

    }
     cout<<"sir/mam please enter no.X"<<endl;
     cin>>x;

    struct node* ptr1, *ptr2, *ptr3;
    int count = 0;
    for (ptr1 = h; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
        if ((ptr1->info + ptr2->info + ptr3->info) == x)
                    count++;
                    cout<<count<<endl;

 }


    };
    int main()
    {link l;
    /*l.ins_beg();
    l.disp();
    l.ins_sort();
    l.disp();
    cout<<"deleteing duplicates ,just for you sir!!!"<<endl;
    l.rem_dup();
    l.disp();
    cout<<"get ready to get swapped list"<<endl;
    l.swap1();
    l.disp();*/
   // l.del_3();
    l.triplets();




    }
