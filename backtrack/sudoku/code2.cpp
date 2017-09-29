//http://www.spoj.com/problems/EASUDOKU/
#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > matrix;

bool check_possibility(matrix& vec,int num,int row,int col){
    //check in row && col
    for(int i=0;i<9;i++){
        if(i!=col && vec[row][i]==num) return false;
        if(i!=row && vec[i][col]==num) return false;
    }

    //check in 3*3 matrix
    int row_ = row - row%3;
    int col_ = col - col%3;
    
    for(int i=row_;i<row_+3;i++)
        for(int j=col_;j<col_+3;j++)
            if(i!=row && j!=col)
                if(vec[i][j]==num) return false;

    return true;
}

bool isGood(matrix& vec,int num,int row,int col){
    int temp = vec[row][col];
    if(temp){//fix
        if(num==temp)//if num is same then check for its possibility
            return check_possibility(vec,num,row,col); 
        else// no ther number can replace a fixed number
            return false; 
    }
    else 
        return check_possibility(vec,num,row,col); 
}

bool back_track(matrix& vec,int row,int col){
    vector<int> poss;
    int temp = vec[row][col];

    for(int i=1;i<=9;i++)//collect all possibilities
        if(isGood(vec,i,row,col))
            poss.push_back(i);
    
    if(row==9-1 && col==9-1 )//last elem
        if(poss.size()==1){//last elem with single possibility
            vec[row][col]=poss[0];return true;
        }
        else return false;
     
    for(int i : poss){
            vec[row][col]=i;
            if(col==9-1){//move to next row
                if(back_track(vec,row+1,0))
                    return true;
            }
            else{
                if(back_track(vec,row,col+1))
                    return true;
            }
    }
    
    //backtrack
    vec[row][col]=temp;
    
    return false;
}


int main(){
	int t=1;
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
        matrix vec(9,vector<int>(9,0));             
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                cin>>vec[i][j];
            }

        if( back_track(vec,0,0) ){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<vec[i][j]<<" ";
                } 
                cout<<endl;
            }
        } else {
            cout<<"No solution\n";
        }
	}
}
// a code by srbcheema1
