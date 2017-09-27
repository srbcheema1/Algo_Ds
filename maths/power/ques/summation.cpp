//http://www.spoj.com/problems/SUMMATION/
#include<bits/stdc++.h>
#define ui unsigned long long int
#define mod 100000007

using namespace std;

ui two_pow(int n){
    ui ans = 1,fact = 2;
    while(n){
        if(n & 1)
            ans = (ans * fact)%mod;
        fact = (fact * fact)%mod;
        n = n>>1;
    }
    return ans%mod;
}

//return b^p
ui modular_expo(ui b,ui p){
    if(p==1) return b;
    if(p & 1)
        return ((modular_expo(b,p/2)*modular_expo(b,p/2))%mod * b)%mod;
    else return (modular_expo(b,p/2)*modular_expo(b,p/2))%mod;
}

int main(){
    int t,n;
    ui ans=0,pow,sum,a;
    cin>>t;
    for (int i=1;i<=t;i++){
        sum=0;
        cin>>n;
        pow = modular_expo(2,n-1);
        while(n--){
            cin>>a;
            sum+=a;
        }
        sum=sum%mod;
        ans = (sum*pow)%mod;
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
}
