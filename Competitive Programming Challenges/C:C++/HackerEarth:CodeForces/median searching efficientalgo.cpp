#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
int median(int *a,int s,int r,int k);
int pivot(int *a,int s,int r);
int main()
{
int *a;
int n;
cin>>n;
a=new int[n];
for(int i=0;i<n;i++)
{
cin>>a[i];

}
int k;
cin>>k;
int x=median(a,0,n-1,k);
cout<<"kth smallest element is\n"<<x;
return 0;

}
int median(int *a,int s,int r,int k)
{
int p=pivot(a,s,r);
int v1[r+1],v2[r+1],v3[r+1];
int s1=0,s2=0,s3=0;
int r=0,v=0,t=0;
for(int i=0;i<r+1;i++)
{
if(a[i]<p)
{
v1[r]=a[i];
cout<<v1[i]<<" ";
s1++;
r++;
cout<<s1;
}
else if(a[i]==p)
{
v2[v]=a[i];
s2++;v++;
}
else{
v3[t]=a[i];
s3++;t++;
}
}



if(s1>k)
{
median(v1,s,s1-1,k);

}
else if(s1+s2>k)
{
return p;
}
else{
median(v3,s1+s2-1,r,k-s1-s2);
}
}

int pivot(int *a,int s,int r)
{
    int t;
    if((r+1)%5==0)
    {
        t=(r+1)/5;
    }
   else{
       t=((r+1)/5)+1;
   }
int b[t][5];

int p;
int k=0;
for(int i=0;i<t;i++)
{
for(int j=0;j<5;j++)
{
b[i][j]=a[k];
k++;
}
}

for(int i=0;i<t;i++)
{
  int *q=*(b+i);
  int *w=(*(b+i)+5);
sort(q,w);
}
p=b[t/2-1][2];
cout<<p<<endl;
return p;

}
