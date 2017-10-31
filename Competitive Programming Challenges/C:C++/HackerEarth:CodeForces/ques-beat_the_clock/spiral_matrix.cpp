#include<bits/stdc++.h>

#define F0(i,t) for(int i=0; i<t; i++)
#define F1(i,t) for(int i=1; i<=t; i++)
#define Si(x) scanf("%d",&x)
#define Si2(x,y) scanf("%d %d",&x,&y)
#define Sl(x) scanf("%lld",&x)
#define Sl2(x,y) scanf("%lld %lld",&x,&y)
#define dout if(debugg)cout<<" "

   /* * * * * * * * * * * * * * * * * * * * * * * *
    *                                             *
    *            _/_/_/            _/             *
    *         _/        _/  _/_/  _/_/_/          *
    *          _/_/    _/_/      _/    _/         *
    *             _/  _/        _/    _/          *
    *      _/_/_/    _/        _/_/_/             * 
    *                                             *
    * * * * * * * * * * * * * * * * * * * * * * * */

using namespace std;

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;

int debugg = 0;

/*
 * func to return matrix in a vector such that it is unfolded 
 * vec is vector of vectors containing the matrix
 * m and n are dimentions
 */
vector<int> func(vector<vector<int> > vec,int m,int n){
    vector<int> ans;
    int l=0,r=n-1,u=0,d=m-1;
    int row=0;int col=0;

    while(true){
        if(l>r || u>d) break;
        for(int i=l;i<=r;i++){//     >>>
            dout<<"> ";
            ans.push_back(vec[row][i]);
        }
        col = r;
        u = u+1;
        if(l>r || u>d) break;
        for(int i=u;i<=d;i++){//     V
            dout<<"V ";
            ans.push_back(vec[i][col]);
        }
        row = d;
        r = r-1;
        if(l>r || u>d) break;
        for(int i=r;i>=l;i--){//   <<<
            dout<<"< ";
            ans.push_back(vec[row][i]);
        }
        col=l;
        d = d-1;
        if(l>r || u>d) break;
        for(int i=d;i>=u;i--){//  ^
            dout<<"^ ";
            ans.push_back(vec[i][col]);
        }
        row = u;
        l = l+1;
        if(l>r || u>d) break;
    }
    return ans;
}

int main(){
	int t=1,n,m,temp;
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
        cin>>m>>n;
        vector<vector<int> > vec(m);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                cin>>temp;
                vec[i].push_back(temp); 
            }

        vector<int> ans = func(vec,m,n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
	}
}
// a code by srbcheema1
