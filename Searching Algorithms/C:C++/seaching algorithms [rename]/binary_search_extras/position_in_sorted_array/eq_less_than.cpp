#include<bits/stdc++.h>
using namespace std;

/*
 * return position of last elem less than or equal to num
 * best is best position till now
 * every elem is atleast greater than 0th elem (-1) so initially best is 0
 */
int binary_search(vector<int> &vec,int l,int r,int num,int best){
    if(r<l) return best;//search ends

    int m = (l+r)/2;

    if(vec[m]<=num){//got one good ans but still hungary .. go forward
        best=m;//atleast it is good
        return binary_search(vec,m+1,r,num,best);//search for better
    }
    else{//out of reach ... go back
        return binary_search(vec,l,m-1,num,best);
    }
}

/*
 * program to print number of elems less or equal to num
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
        cout<<binary_search(vec,1,n,num,0)<<endl;
    }
}
