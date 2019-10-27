#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

/*
 * Node Class Declaration
 */
template <class T>
class BSTNode
{
    private:
        T value;
        BSTNode *left, *right;
    public:
        BSTNode(T value) //Constructor
        {
            this->value = value;
            left = NULL;
            right = NULL;
        }
        /*
         * Adding element to a node
         */
        void add(T& value)
        {
            if (value < this->value)
            {
                if (left)
                    left->add(value);
                else
                    left = new BSTNode(value);
            }
            else if (this->value < value)
            {
                if (right)
                    right->add(value);
                else
                    right = new BSTNode(value);
            }
        }
        /*
         * Check if node contains element
         */
        bool contains(T& value)
        {
            if (value < this->value)
    	    {
                if (left)
            	    return left->contains(value);
        	else
           	    return false;
    	    }
    	    else if (this->value < value)
    	    {
                if (right)
            	    return right->contains(value);
        	else
            	    return false;
    	    }
    	    else
    	    {
                return true;
    	    }
        }
        friend class BSTHashtable;
};

/*
 * Table Class Declaration
 */
class BSTHashtable
{
    private:
        int size;
        vector<BSTNode<string>*>* bucket;
        int hash(string& s)
        {
            unsigned int hashVal = 0;
            hashVal = s[s.length()-1];
            return hashVal % size;
        }
    public:
        BSTHashtable(int vectorSize)
        {
            size = vectorSize;
            bucket = new vector<BSTNode<string>*>(size);
        }

        void add(string& s)
        {
            int index = hash(s);
            if (bucket->at(index) == NULL) //Call friend to add string
                bucket->at(index) = new BSTNode<string>(s);
            else
                bucket->at(index)->add(s);
        }

        bool contains(string& s)
        {
            int index = hash(s);
            if (bucket->at(index) == NULL)
                return false;

            if( bucket->at(index)->contains(s)) //Call friend to search the String
            {
                cout<<"String \""<<s<<"\" found at index: "<<index<<endl;
                return true;
            }
            else return false;
        }

        void display()
        {
            for (unsigned int i = 0; i < bucket->size(); i++)
            {
                cout <<"[" << i << "] -> ";
                if (bucket->at(i) != NULL)
                {
                    BSTNode<string> *node = bucket->at(i);
                    display_bst(node);
                }
                cout << "Null" << endl;
            }
        }

        void display_bst(BSTNode<string> *node) // Calling Friend to show List Items using BST LDR Method
        {
	    if (node!=NULL)
            {
            	display_bst(node->left);
            	cout << node->value << " -> ";
            	display_bst(node->right);
            }
        }
};


int main()
{
    BSTHashtable table(10);
    string str;
    int choice;
    while (1)
    {
        cout<<"\t1.Insert element into the table"<<endl;
        cout<<"\t2.Find element in the table"<<endl;
        cout<<"\t3.Display Table Chained with Binary Tree"<<endl;
        cout<<"\t0.Exit"<<endl;
        cout<<"\tEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter String to be inserted: ";
            cin>>str;
            table.add(str);
            break;
        case 2:
            cout<<"Enter String to search: ";
            cin>>str;
            if (table.contains(str) == 0)
                cout<<"String \""<<str<<"\" not found in the table"<<endl;
            break;
        case 3:
            cout<<"Displaying Table Chained with Binary Tree: "<<endl;
            table.display();
            break;
        default:
            cout<<"\nEnter correct option\n";
            exit(0);
        }
    }
    return 0;
}
