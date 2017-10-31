#include<bits/stdc++.h>
using namespace std;

/*
 * return position of num in sorted array
 * if not there then return -1
 */
int binary_search(vector<int> &vec, int l, int r, int num){
    if(r<l) return -1;    

    int m = (l+r)/2;
    if(vec[m]<num){
        return binary_search(vec,m+1,r,num);
    }
    else if(vec[m]>num){
        return binary_search(vec,l,m-1,num);
    }
    else{
        return m;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++){
        cin>>vec[i]; 
    }
    sort(vec.begin()+1,vec.end());

    int q;//num of querries
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<binary_search(vec,1,n,num)<<endl;
    }
}
