int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    int sc[m+1][n+1];
    int length = 0;
    for(int i=0;i<=m;i++){
        sc[i][0] = 0;
    }
    for(int j=1;j<=n;j++){
        sc[0][j] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                sc[i][j] = 1+sc[i-1][j-1];
            }
            else{
                sc[i][j] = max(sc[i-1][j],sc[i][j-1]);
            }
        }
    }
    // cout<<sc[m][n]<<"k";
   length = m+n-sc[m][n]; 
   return length;
}
