/*
An effective CPP program to reverse a Queue.In this program,
a Queue is populated with values and then it is reversed using the use of Stack.
Time Complexity:O(n)
Space Complexity:Extra Space for Stack
#include <bits/stdc++.h>
*/
using namespace std; 
void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
 
// Function to reverse the queue
void reverseQueue(queue<int>& Queue)
{
    stack<int> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}
 
// Main Function
int main()
{
    queue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);
    Queue.push(6);
    Queue.push(7);
    Queue.push(8);
    Queue.push(9);
    Queue.push(10);
 
    reverseQueue(Queue);
    Print(Queue);
}