#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *link;
};

class sll{
public:
    Node *tail;
    Node *head;
    sll(){
        head = NULL;
    }
    void create();
    void display();
    void insertfront(int ele);
    void insertback(int ele);
    void deletefront();
    void deleteback();
    void insertafter(int ele,int d);
    void insertbefore(int ele,int d);
    void insertposition(int ele,int pos);
    void deleteposition(int pos);
    void deleteelement(int ele);
    Node* sllsearch(int ele);
};

void sll::create(){
    int x;
    Node *cur,*prev=NULL;
    cout << "Enter data.\nEnter -1 to exit.\n";
    cin >> x;
    while(x != -1){
        Node *cur = new Node;
        cur -> data = x;
        cur -> link = NULL;
        if(prev == NULL)
            head = cur;
        else
            prev -> link = cur;
        prev = cur;
        cin >> x;
    }
    tail = prev;
}

void sll::display(){
    Node *temp;
    temp = head;
    while(temp->link!=NULL){
        cout <<temp -> data;
        temp = temp -> link;
    }
    cout << temp -> data;
    cout << "\n";
}

void sll::insertfront(int ele){
    Node *temp = new Node;
    temp -> data = ele;
    temp -> link = head;
    head = temp;
}

void sll::insertback(int ele){
    Node *temp = new Node;
    temp -> data = ele;
    temp -> link = NULL;
    tail -> link = temp;
    tail = temp;
}

void sll::deletefront(){
    head = head->link;
}

void sll::deleteback(){
    Node *temp = head;
    while(temp-> link != tail){
        temp = temp -> link;
    }
    temp -> link = NULL;
}

void sll::insertafter(int ele,int d){
    Node *temp=head;
    Node *temp2 = new Node;
    while(temp -> data != d){
        temp = temp -> link;
    }
    temp2 -> data = ele;
    temp2 -> link = temp -> link;
    temp -> link = temp2;
}

void sll::insertbefore(int ele,int d){
    Node *temp = head;
    Node *temp2 = new Node;
    Node *temp3 = new Node;
    while(temp -> data != d){
        temp2 = temp;
        temp = temp -> link;
    }
    temp3 -> data = ele;
    temp3 -> link = temp2 -> link;
    temp2 -> link = temp3;
}

void sll::insertposition(int ele,int pos){
    int counter = 1;
    Node *temp = head;
    Node *temp2 = new Node;
    Node *temp3 = new Node;
    while(counter!=pos){
        temp2 = temp;
        temp = temp->link;
        counter ++;
    }
    temp3 -> data = ele;
    temp3 -> link = temp;
    temp2 -> link = temp3;
}

void sll::deleteposition(int pos){
    int counter = 1;
    Node *temp = head;
    Node *temp2 = new Node;
    while(counter != pos){
        temp2 = temp;
        temp = temp ->link;
        counter++;
    }
    temp2 -> link = temp -> link;
}

void sll::deleteelement(int ele){
    Node *temp = head;
    Node *temp2 = new Node;
    while(temp -> data != ele){
        temp2 = temp;
        temp = temp->link;
    }
    temp2 -> link = temp -> link;
}

Node* sll::sllsearch(int ele){
    int counter = 1;
    Node *temp = head;
    while(temp->data != ele){
        temp = temp -> link;
        counter ++;
    }
    cout << "The variable is found at position ";
    cout << counter;
    return temp;
}

int main(){
    sll s;
    s.create();
//  Insert your functions according to need here.
    s.display();
    return 0;
}
