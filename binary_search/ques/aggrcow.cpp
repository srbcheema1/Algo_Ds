#include<bits/stdc++.h>
using namespace std;
int arr[100002];
int np,nc;
int ans;
int find(int l,int r){ 
    int m=(l+r)/2;
    int cnt=1,last=1;
    for(int i=2;i<=np;i++){
        if(arr[i]-arr[last]>=m){
            cnt++;
            last=i;
        }    
    }
    if(l==r){
        if(m>ans && cnt>=nc)ans=m;
        return ans;
    }
    if(cnt<nc){
        return find(l,m-1);//both ways are correct find(l,m);
    }
    else{
        if(m>ans)ans=m;
        return find(m+1,r);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ans=1;
        cin>>np>>nc;
        for(int i=1;i<=np;i++)
            cin>>arr[i];
        sort(arr+1,arr+np+1);

        cout<<find(1,arr[np])<<endl;
    }
}
