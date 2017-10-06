//http://codeforces.com/problemset/problem/834/B
#include<bits/stdc++.h>

using namespace std;

int main(){
    int g,k;
    int start[27];
    int last[27];
    
    cin>>g>>k;
    string str;
    cin>>str;

    int alot=0,free=0,gate=0;
    memset(start,-1,sizeof(start));
    memset(last,-1,sizeof(last));
    for(int i=0;i<g;i++){
        gate=str[i]-'A'+1;

        if(start[gate]==-1)start[gate]=i;

        last[gate]=i;
    }

    for(int i=0;i<g;i++){
        gate=str[i]-'A'+1;

        if(start[gate]==i){
            if(free==0){
                alot++;
            }
            else{
                free--;
                alot++;
            }
        }
        if(last[gate]==i){
            alot--;
            free++;
        }
    }
    if(free>k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
