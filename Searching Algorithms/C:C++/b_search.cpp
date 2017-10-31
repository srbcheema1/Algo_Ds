#include<iostream>
using namespace std;
int b_search(int a[],int l,int u,int s)
{
    int m=(l+u)/2;
      if(l>=u)
       return -1;
       
      if(a[m]>s)
        return b_search(a,l,m-1,s);
      else if(a[m]<s)
        return b_search(a,m+1,u,s);
      else
        return m;
 }
 int main()
 {
   int arr[100],n,s,i;           // n is the size of the array , s is the element to search in the array, i is the index of the element found  
          .
          .
          .
          .
          .
          .
    i=b_search(arr,0,n,s);       // assuming every variable has value assigned 
     if ( i==-1)
      cout<<"\n The Element was not found ");
     else
      cout<<"\n The Element was found at index "<<i;
    
    return 0;
    }
