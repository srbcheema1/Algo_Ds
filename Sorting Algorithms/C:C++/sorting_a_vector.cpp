#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
    return a>b;
}

int main(){

    vector<int> v;

    for(int i=1;i<5;i++){
        v.push_back(i);
    }
    int p;
    cin>>p;
    // the position at which we wanna insert in vector.

    int d;
    cin>>d;
    // the element we wanna insert at v.begin()+p

    v.insert(v.begin() + p,d);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    ///Sort a vector
    sort(v.begin(),v.end(),compare);

     for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }



return 0;
}
