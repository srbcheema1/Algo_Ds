// https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
// Time Complexity :O(n) Space Complexity : O(n) 

int Solution::adjacent(vector<vector<int> > &A) {
    int incl=max(A[0][0],A[1][0]);
    int excl=0,ex_n;
    for(int i=1;i<A[1].size();i++){
        ex_n=max(incl,excl);
        incl=excl+max(A[0][i],A[1][i]);
        excl=ex_n;
    }
    return max(incl,excl);
    
    
    
}
