#include <bits/stdc++.h> 
using namespace std; 
  
struct Queue { 
    stack<int> st; 
  
    // Enqueue an item to the queue 
    void enQueue(int x) 
    { 
        st.push(x); 
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        if (st.empty()) { 
            cout << "Q is empty"; 
            exit(0); 
        } 
  
        // pop an item from the stack 
        int x = st.top(); 
        st.pop(); 
  
        // if stack becomes empty, return 
        // the popped item 
        if (st.empty()) 
            return x; 
  
        // recursive call 
        int item = deQueue(); 
  
        // push popped item back to the stack 
        st.push(x); 
  
        // return the result of deQueue() call 
        return item; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    Queue q; 
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
  
    return 0; 
} 
