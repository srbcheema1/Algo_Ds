#include<bits/stdc++.h>
#define ui unsigned long long int
#define mod 1000000007
using namespace std;

//faster wayy to calc (b^p)%mod in log(p) 
//it is fast as it dont use recursion
ui modular_expo_no_rec(int base,int p){
    ui ans = 1,fact = base;
    while(p){
        if(p & 1)
            ans = (ans * fact)%mod;
        fact = (fact * fact)%mod;
        p = p>>1;
    }
    return ans%mod;
}

//return (b^p)%mod in log(p)
ui modular_expo_rec(ui b,ui p){
    if(p==1) return b;
    
    ui temp = modular_expo_rec(b,p/2);
    temp = (temp*temp)%mod;
    
    if(p & 1)//odd
        return (temp * b)%mod;
    else return temp;
}

int main(){
    int t,base,pow;
    ui ans;
    cin>>t;
    while(t--){
        cin>>base>>pow;
        cout<<modular_expo_no_rec(base,pow)<<endl;
    }
}
