#include<iostream>
using namespace std;
struct node
{ struct node * pre;
char info;
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
{char ele;
int n,i,a=0;
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
void check()
{int a=0,n=0;
    t=h;
    while(t->next!=NULL)
    {n=n+1;
        t=t->next;

    }
    cout<<n/2<<endl;
    while(n/2)
    {
        if(h->info==t->info){
        a=a+1;
        h=h->next;
        t=t->pre;
        n=n-1;

    }
    else
    {
    cout<<endl<<"not palindrome"<<endl;;
    break;

    }
}
    if(a>=n/2)
        cout<<endl<<"palindrome hai ji!!!"<<endl;
}
void disp()
    {node *ptr=h;
    if(h==NULL)
        cout<<"Linked List is empty";
    while(ptr!=NULL)
    {
        cout<<ptr->info<<"<->";
        ptr=ptr->next;
    }

    }
    };
    int main()
    {link l;
    l.ins_beg();
    l.disp();
    l.check();
   // l.disp();
    }
