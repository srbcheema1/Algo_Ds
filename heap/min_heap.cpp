#include<iostream>
#include<vector>
using namespace std;

class minHeap{
    vector<int> v;
    
    void heapify(int i){
        int l=2*i;
        int r=2*i+1;
        int minIndex = i;
        if(l < v.size() && v[l]<v[minIndex]){
            minIndex = l;
        }
        if(r< v.size() && v[r]<v[minIndex]){
            minIndex = r;
        }
        if(minIndex!=i){
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }
    }

public:
    minHeap(){
        v.push_back(-1);   
    }
    void push(int data){
        v.push_back(data);
        int index = v.size()-1;
        int parent = index/2;

        while(v[index]<v[parent] && index>1){
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }

    int getmin(){
        return v[1];
    }
    void pop(){
        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }

    bool isEmpty(){
        return v.size()==1;
    }
};

int main(){

    int a[] = {10,45,33,211,16,120,150,132};
    int n = sizeof(a)/sizeof(int);

    minHeap h;
    for(int i=0;i<n;i++) h.push(a[i]);
      
    while(!h.isEmpty()){
        cout<<h.getmin()<<" ";
        h.pop();
    }
    return 0;
}

/* Output : 10 16 33 45 120 132 150 211 */
