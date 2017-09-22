//http://www.spoj.com/problems/TDBFS/
#include<bits/stdc++.h>
#define dout if(debugg) cout<<" "
using namespace std;

int debugg = 1;
class Node{
    public:
    vector<int> adj;
    int visited; 

    Node(){
        clear();
    }
    void clear(){
        visited = 0;
        adj.clear();
    }
};

void dfs_rec(vector<Node> &node,int a){
    cout<<a<<" ";
    for(auto i : node[a].adj){
        if(node[i].visited==0){
            node[i].visited=1;
            dfs_rec(node,i);
        }
    }
}
void dfs(vector<Node> &node,int a){
    for(auto &i : node){
        i.visited=0;
    }

    node[a].visited=1;
    dfs_rec(node,a);

    cout<<endl;
}

void bfs(vector<Node> &node,int a){
    for(auto &i : node)
        i.visited=0;

    queue<int> q;
    q.push(a);
    node[a].visited=1;

    while(!q.empty()){
        int temp = q.front();
        for(auto i : node[temp].adj){
            if(node[i].visited==0){
                node[i].visited=1;
                q.push(i);
            }
        }
        q.pop();
        cout<<temp<<" ";
    }
    cout<<endl;
}

int main(){
    int t,temp;
    cin>>t;
    for(int x=1; x<=t; x++){
        int n;
        cin>>n;
        vector<Node> node(n+1);

        for(int i=1; i<=n; i++){//insert adj nodes
            int m,faltu;
            cin>>faltu>>m;
            while(m--){
                cin>>temp;
                node[i].adj.push_back(temp); 
            }
        }

        cout<<"graph "<<x<<endl;
        while(true){
            int a,type;
            cin>>a>>type;
            if(a==0)break;

            if(type)
                bfs(node,a);
            else
                dfs(node,a);
        }
    }
}
