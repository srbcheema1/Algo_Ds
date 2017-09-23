//https://www.codechef.com/problems/BUG2K17B
#include<bits/stdc++.h>
#define mp pair<int,int>
using namespace std;

int debugg=0;
class Node{
    public:
    int dist;
    vector<pair<int,int> > next;//first contains city index .. second contains distance
    
    void clear(){
        dist=INT_MAX;
        next.clear();
    }
} node[100002];

struct priority_fxn{
    bool operator() (int a,int b){
       return node[a].dist > node[b].dist; 
    }
};
void dijakstra(int source){
    int n,d,temp;
    priority_queue<int,vector<int>,priority_fxn> q;
    
    //init queue
    node[source].dist=0;
    q.push(source);
    
    while(!q.empty()){
        temp=q.top();
        for(auto elem : node[temp].next){
            n=elem.first;
            d=elem.second;
            if(node[n].dist > node[temp].dist + d){
                node[n].dist = node[temp].dist + d;
                q.push(n);
            }    
        }
        q.pop();
    }
}

int main(){
    int t,a,b,c,n,p;
    cin>>t;
    while(t--){
        cin>>n>>p;
        for(int i=1;i<=n;i++)
            node[i].clear();
        while(p--){
            cin>>a>>b>>c;
            node[a].next.push_back(mp(b,c));
            node[b].next.push_back(mp(a,c));
        }
        dijakstra(1);
        if(node[n].dist==INT_MAX)cout<<"NONE"<<endl;
        else
            cout<<node[n].dist<<endl;
    }
}
