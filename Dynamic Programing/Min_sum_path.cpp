// Problem : Given a matrix with non-negative numbers find the minimum 
// sum path from top left to bottom right.

// Helper function: 



int minPathSum(vector<vector<int> > &A) {
    if(A.size()==1 && A[0].size()==1 ) return A[0][0];
    int tc[A.size()][A[0].size()];
    tc[0][0]=A[0][0];
    for(int i=1;i<A[0].size();i++){
        tc[0][i]=tc[0][i-1]+A[0][i];
    }
    for(int i=1;i<A.size();i++){
        tc[i][0]=tc[i-1][0]+A[i][0];
    }
    for(int i=1;i<A.size();i++){
        for(int j=1;j<A[0].size();j++){
            tc[i][j] = min(tc[i-1][j],tc[i][j-1]) + A[i][j];
        }
    }
    
    return tc[A.size()-1][A[0].size()-1];
}

