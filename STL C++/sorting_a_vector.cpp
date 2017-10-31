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

    int d;
    cin>>d;

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
