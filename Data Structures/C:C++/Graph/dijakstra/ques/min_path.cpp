//https://www.codechef.com/SEPT17/problems/QGRID
#include<bits/stdc++.h>
#define ulli long long int
#define dout if(debugg)cout<<" "
using namespace std;
typedef pair<ulli,ulli> mp; 
typedef pair<mp,ulli> mpp;

int debugg=0;

class Node{
    public:
    ulli dist;
    ulli weight;
    ulli parentx,parenty;
    vector<pair<mp,ulli> > next;
    void clear(){
        weight=0;
        dist=LONG_MAX;
        next.clear();
    }
    Node(){
        clear();
    }
    void setparent(ulli px,ulli py){
        parentx=px;
        parenty=py;
    }
} node[5][100009];
 
struct priority_fxn{
    bool operator() (mp a,mp b){
       return node[a.first][a.second].dist > node[b.first][b.second].dist; 
    }
};
void dijakstra(ulli sx,ulli sy,ulli ex,ulli ey,ulli update){
    priority_queue<mp ,vector<mp >,priority_fxn> q;
    queue<mp> dist_sett;//so that i can again set dist as intmax;
    ulli d,n1,n2;
    mp temp;

    node[sx][sy].dist=0;
    node[sx][sy].setparent(sx,sy);
    q.push(mp(sx,sy));
    dist_sett.push(mp(sx,sy));
   
    while(!q.empty()){
        n1=q.top().first;
        n2=q.top().second;
        if(n1==ex && n2==ey)break;//reached the point
        for(ulli i=0;i<node[n1][n2].next.size();i++){
            temp=node[n1][n2].next[i].first;
            d=node[n1][n2].next[i].second;
            if(node[temp.first][temp.second].dist > node[n1][n2].dist + d){
                node[temp.first][temp.second].dist = node[n1][n2].dist + d;
                node[temp.first][temp.second].setparent(n1,n2);
                dist_sett.push(temp);
                q.push(temp);
            }    
        }
        q.pop();
    }//end while loop

    //set dist back to INT_MAX
    while(!dist_sett.empty()){
        mp elem = dist_sett.front();
        node[elem.first][elem.second].dist=LONG_MAX;
        dist_sett.pop();
        
    }

    int n1_;
    while(n1!=sx || n2!=sy){
       node[n1][n2].weight+=update;
       n1_=node[n1][n2].parentx;
       n2=node[n1][n2].parenty;
       n1=n1_;
       dout<<n1<<" "<<n2<<endl;
    }
    node[n1][n2].weight+=update;
}
 
int main(){
    ulli m,n,q,d,type;
    cin>>m>>n>>q;
    for(ulli i=1;i<m;i++){
        for(ulli j=1;j<=n;j++){
            cin>>d;
            node[i][j].next.push_back(mpp(mp(i+1,j),d));
            node[i+1][j].next.push_back(mpp(mp(i,j),d));
        }
    }
    for(ulli i=1;i<=m;i++){
        for(ulli j=1;j<n;j++){
            cin>>d;
            node[i][j].next.push_back(mpp(mp(i,j+1),d));
            node[i][j+1].next.push_back(mpp(mp(i,j),d));
        }
    }

    ulli sx,sy,ex,ey,update;
    while(q--){
        cin>>type;
        if(type==1){
            cin>>sx>>sy>>ex>>ey>>update;
            dijakstra(sx,sy,ex,ey,update);
        }
        else{
            cin>>sx>>sy;
            cout<<node[sx][sy].weight<<endl;
        }
    }
}
