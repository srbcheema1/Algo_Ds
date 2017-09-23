//https://www.codechef.com/APRIL17/problems/CLIQUED
//  only dijastra ques not complete
#include<bits/stdc++.h>
#define ulli long long int
#define ui unsigned int

using namespace std;

class Road{
    public:
    int dist;
    int left;
    int right;
    
    Road(int l,int r,int d){
        left=l;
        right=r;
        dist=d;
    }
};

class Node{
    public:
    ulli dist;
    vector<Road> linked;
    
    Node(){
        dist=LLONG_MAX;
    }
};

typedef pair<int,vector<Node>&> node_info;//stores node index and vector reference

struct priority_fxn{
    bool operator() (node_info a,node_info b){
        return a.second[a.first].dist > b.second[b.first].dist;
    }
};

/*
 * set value of dist in each node relative to root
 * ct ==> vector of Nodes 
 * root ==> source node
 */
void dijakstra(vector<Node> &ct,int root){
    priority_queue<node_info,vector<node_info>,priority_fxn> pq;//priority queue
    int ind;//contains index
    ulli temp_dist;
    
    ct[root].dist=0;
    pq.push(node_info(root,ct));
    
    while(!pq.empty()){
        root = pq.top().first;
        pq.pop();
        
        for(auto elem : ct[root].linked){
            ind = elem.left==root ? elem.right : elem.left;//select other than root
            temp_dist = ct[root].dist + (ulli)elem.dist;//calculate temp_dist 
            
            if(temp_dist < ct[ind].dist){
                ct[ind].dist=temp_dist;
                pq.push(node_info(ind,ct));
            }
        }
    }
}

int main()
{
	int t=1,n,r,s,a,b;
	ulli d;
	cin>>t;
	while(t--)
	{    
	    cin>>n>>r>>s;//num of cities  , roads , source
	    vector<Node> city(n+1,Node());
	    for(int i=1;i<=r;i++){
	        cin>>a>>b>>d;
		    city[a].linked.push_back(Road(a,b,d));
		    city[b].linked.push_back(Road(a,b,d));
	    }
	    
	    dijakstra(city,s);
	    
	    for(int i=1;i<=n;i++){
	        cout<<city[i].dist<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
