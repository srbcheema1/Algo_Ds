#include<iostream>
#include<malloc.h>
using namespace std;
//structure of node
struct node
{
    int data;
    struct node *next;
}*start=NULL;
//function to create linked list
struct node* create(struct node*current)
{
  struct node *new_node;//pointer to node
  new_node=(struct node *)malloc(sizeof(struct node));

  cout<<"\nEnter the data : ";
  cin>>new_node->data;
  new_node->next=NULL;

  if(start==NULL)//to check if the root node is null or not
  {
    start=new_node;
    current=new_node;
  }
  else
  {
    current->next=new_node;
    current=new_node;
  }
  return current;

}
//function to display linked list
void display()
{
    struct node *new_node;
    cout<<"\nThe Linked List : "<<endl;
    new_node=start;
    while(new_node!=NULL)//condition to point to the last node
    {
        cout<<new_node->data<<"--->";
        new_node=new_node->next;
    }
    cout<<"NULL"<<endl;
}
//function to reverse linked list
void reverse()
{
    struct node *prev,*curr,*nextt;//prev for pointing to previous node,curr for pointing to current node,nextt for pointing to next node
    curr=start;//pointing to the root node
    prev=NULL;
    while(curr!=NULL)
    {
        nextt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextt;


    }
    start=prev;
    display();
}
int main()
{
    int n;
    struct node*current;
    current=NULL;
    while(1)
    {
        cout<<"1.to insert\n2.display\n3.reverse\n4.exit\nenter choice"<<endl;
        cin>>n;

        switch(n)
        {
            case 1: current=create(current);//passing current pointer to create function
                    break;
            case 2: display();
                    break;
            case 3:reverse();
                    break;
            case 4: return 0;
        }
    }
    return 0;
}
