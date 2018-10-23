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

    void del()
    { int ele;
    t=h;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    node * p,*ptr,*temp;
        //p=h;
        cout<<"enter no. to delete its seniors...:)"<<endl;
        cin>>ele;
        p=h;
        while(p!=NULL)
        {
            ptr=p;
            if(ptr->info>ele)
            {
                if(h->info>ele)
                    {
                        h=h->next;
                    }
                else if(t->info>ele)
                    {
                        temp=t->pre;
                        temp->next=NULL;
                        t=temp;
                        p=p->pre;
                    }
                else
                    {
                        temp=ptr->pre;
                        temp->next=ptr->next;
                        ptr->next->pre=temp;
                    }
                   p=p->next;
            }
           else
           {
               p=p->next;
           }
        }
        cout<<"\nAfter deletion the linked list is:\n";

    }
    void occur()
    { int a,f=0;
        cout<<"enter no. to find its occurance.....:)"<<endl;
        cin>>a;
        t=h;
        while(t!=NULL)
        { if(t->info!=a)
        {   t=t->next;
        }
            else
                { f=f+1;
                t=t->next;
        }
        }
        cout<<"occurance is...... "<<f<<endl;
    }
        };
    int main()
    {int c;
    link l;
    int n=0;
    cout<<"please enter your choice"<<endl;
    cin>>c;
    while(c!=0)
    {if(c==1)
    {cout<<"hi rishi! please enter your element"<<endl;
        l.ins_beg();
    n=n+1;
    }
    else if(c==2)
    {l.disp();
    }
    else if(c==3)
    {cout<<"printing size of linked list"<<endl;
    cout<<n<<endl;
    }
    else if(c==4)
    { cout<<"get ready for...... reversing list :)"<<endl;
        l.disp_rev();
    }
    else if(c==5)
    { cout<<"now numbers are going to delete...,get ready...for it"<<endl;
        l.del();

    }
    else if(c==6)
    {
        cout<<"finding occurance... for you sir...... :)"<<endl;
        l.occur();

    }
    cout<<"enter choice again"<<endl;
    cin>>c;
    }

    }
