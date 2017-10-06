#include<stdio.h>
#include<iostream>
#include<ctime>
#include <fstream>

using namespace std;
//random matrix sizes
int mat[]={10,5,2,8,16,10,5,3,8,9,18,15,3,6,11,5,3,2,8,3,9,7,4,9,3};
//5 15 and 25 as number of matrices
int nn[]={5,10,25};

//funtion for matrix chain multiplication using div and cnquer
int mcmdnc(int a,int b)
{
  int cost;
    //base Case
       if(a==b)
        cost=0;
       else
      {
     for(int i=a;i<b;i++)
      {
            if(i==a)
                cost=mcmdnc(a,i)+mcmdnc(i+1,b)+mat[a-1]*mat[i]*mat[b];
            else
                cost=min(cost,(mcmdnc(a,i)+mcmdnc(i+1,b)+mat[a-1]*mat[i]*mat[b]));
      }
    }
    return  cost;
}
   

//function for matrix chain multiplication using dp
int mcmdp(int p[], int n){
    int m[n][n];
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (L=2; L<n; L++)   {
        for (i=1; i<=n-L+1; i++){
            j = i+L-1;
            m[i][j] = 100000;
            for (k=i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}
int main(){
    int val;
    
    for (int i=0;i<3; i++){

int t=clock();
	val= mcmdp(mat,nn[i]);
    cout<<"Optimised cost for "<<nn[i]<<" matrices is "<<val<<"(DP)"<<endl<<" time taken :"<< ((float)(clock()-t))/CLOCKS_PER_SEC<<endl;

         t=clock();
  

	val=mcmdnc(1,nn[i]-1);
    cout<<"Optimised cost for "<<nn[i]<<" matrices is "<<val<<"(DivAndConq)"<<endl<<" time taken :"<< ((float)(clock()-t))/CLOCKS_PER_SEC<<endl;

	}
    return 0;
}
