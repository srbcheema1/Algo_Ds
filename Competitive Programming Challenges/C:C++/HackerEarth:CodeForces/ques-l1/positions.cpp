//https://www.hackerearth.com/problem/algorithm/attack-on-daleks/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long int sum;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++)
        cin>>arr1[i];
        
    for(int i=0;i<n;i++)
        cin>>arr2[i];

    sort(arr1,arr1+n);
    sort(arr2,arr2+n);
    sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(arr2[i]-arr1[i]);
    }
    cout<<sum<<endl;
}
