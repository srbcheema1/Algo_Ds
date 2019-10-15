// Problem : Given a 2 x N grid of integer, A, 
//choose numbers such that the sum of the numbers is maximum and 
//no two chosen numbers are adjacent horizontally, vertically or diagonally, 
//and return it.

// Function : 
int adjacent(vector<vector<int> > &A) {
    int incl=max(A[0][0],A[1][0]);
    int excl=0,ex_n;
    for(int i=1;i<A[1].size();i++){
        ex_n=max(incl,excl);
        incl=excl+max(A[0][i],A[1][i]);
        excl=ex_n;
    }
    return max(incl,excl);
    
    
    
}

