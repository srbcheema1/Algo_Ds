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
    {node *ptr=h;
    if(h==NULL)
        cout<<"Linked List is empty";
    while(ptr!=NULL)
    {
        cout<<ptr->info<<"<->";
        ptr=ptr->next;
    }

    }
    void disp_rev()
    { node * p,*ptr,*temp;
    if(t==NULL)
        cout<<"Linked List is empty";
        ptr=h;
        p=NULL;

    while(ptr!=NULL)
    {
      temp=ptr->next;
      ptr->next=p;
      ptr->pre=temp;
      p=ptr;
      ptr=temp;

    }
    h=t;
    //cout<<endl;

    }

    void del_beg()
    {
node * t;
t=h;
h=t->next;
t->pre=NULL;

    }
void del_end()
{
node * te;
te=h;
while(te->next!=NULL)
{t=te;
    te=t->next;
}
t->next=NULL;
}
 void del_after()
 { int x;
     cout<<"enter node to delete after ... "<<endl;
 cin>>x;
     node * te,*temp;
     te=h;
     while(te->info!=x)
     {
         te=te->next;
     }
     temp=te->next->next;
     te->next=temp;
     temp->pre->pre=te;
 }
 void del_before()
 { int x;
     cout<<"enter node to delete before ... "<<endl;
 cin>>x;
     node * te,*temp;
     te=h;
     while(te->next->info!=x)
     {
         te=te->next;
     }
     te->next->pre=te->next;
     te->pre->next=te->next;
 }

   };
   int main()
    {
    link l;
    l.ins_beg();
    l.disp();
    l.disp_rev();
    cout<<"now get ready to delete element from begining......!!!!!"<<endl;
    l.del_beg();
    l.disp();
    //l.disp_rev();
    cout<<"now get ready to delete element from ending......!!!!!"<<endl;
    l.del_end();
    l.disp();
    l.del_after();
    l.disp();
    l.del_before();
    l.disp();
    }
