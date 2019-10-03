
#include<iostream>
using namespace std;

//using quicksort to simultaneously sort the array of profit and weight
int partition(int a[],int b[],int l,int r)
{
    int pivot=a[r];
    //P-index indicates the pivot value index

    int pidx=l;
    int i,t,t1;

    for(i=l;i<r;i++)
    {
    	if(a[i]<=pivot)
        {
            t=a[i]; t1=b[i];
            a[i]=a[pidx]; b[i]=b[pidx];
            a[pidx]=t; b[pidx]=t1;
            pidx++;
        }
     }
     //Now exchanging value of
     //pivot and P-index
      t=a[r]; t1=b[r];
      a[r]=a[pidx]; b[r]=b[pidx];
      a[pidx]=t; b[pidx]=t1;

     //at last returning the pivot value index
     return pidx;
 }

 void quick_sort(int p[],int w[], int l,int r)
 {
    if(l<r)
    {
         int pidx=partition(p,w,l,r);
             quick_sort(p,w,l,pidx-1);
             quick_sort(p,w,pidx+1,r);

    }
}


int main()
{
    int n, wa=0,pa=0,W=100;
    n=5;
    //w[]:array of weights of items
    //p[]:array of profit of items
    int w[5] = {10,20,30,40,50};int p[5]={20,30,66,40,60};
    int ans[5]; int j=0;
    quick_sort(p,w,0,n-1);
    /*for(int i=0;i<n;i++)
        cout<<w[i]<<"\t"<<p[i]<<"\n";*/

    int i = n-1;
    while(wa + w[i] <=W)
    {
        ans[j++]=i;
        wa+=w[i];
        pa+=p[i];
        i--;

    }
    if(wa != W)
    {
        int x=W-wa;
        float f = (float)x/w[i];
        float pf = (float)p[i]*f;
        pa+=pf;
    }

    cout<<"weight: "<<W<<" and profit: "<<pa;
    return 0;

}





