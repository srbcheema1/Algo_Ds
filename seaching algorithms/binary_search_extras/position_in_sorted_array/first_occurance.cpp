
#include<bits/stdc++.h>
using namespace std;

/*
 * return position of last elem less than or equal to num
 * best is best position till now
 */
int binary_search(vector<int> &vec,int l,int r,int num,int best){
    if(r<l) return best;//search ends

    int m = (l+r)/2;

    if(vec[m]<num){//num is small.. go forward
        return binary_search(vec,m+1,r,num,best);//search for bigger
    }
    if(vec[m]==num){//got the number 
        best=m;//this is best ans till now 
        return binary_search(vec,l,m-1,num,best);//go for even better
    }
    if(vec[m]>num){//out of reach ... go back
        return binary_search(vec,l,m-1,num,best);
    }
}

/*
 * program to find first occurance of num in sorted array
 * if not there print -1
 */
int main(){
    int n;
    cin>>n;
    vector<int> vec(n+1);
    vec[0]=-1;
    for(int i=1;i<=n;i++){
        cin>>vec[i]; 
    }
    sort(vec.begin()+1,vec.end());

    int q;//querries
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<binary_search(vec,1,n,num,-1)<<endl;
    }
}
