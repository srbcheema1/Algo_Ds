#include<iostream>
using namespace std;
int BIT[1000], arr[1000],l,r,n,s;
void update(int x, int delta)
{
      for( ;x<=n;x+=x&-x)
        BIT[x]+=delta;
}
int query(int x)
{
     int sum=0;
     for(;x>0;x-=x&-x)
        sum+=BIT[x];
     return sum;
}

int main()
{
     cin>>n;
     cout<<"Enter "<<n<<" elemets and more than 8 elemets\n";
     for(int i = 1; i <= n; i++)
     {
       cin>>arr[i];
           update(i,arr[i]);
     }
     cout<<"Give the number of elemets you want sum for\n";
     cin>>s;
     cout<<"Sum of first "<<s<<" elements is "<<query(s)<<endl;
     cout<<"Sum of all elements in range [2,8] is "<<query(8)-query(2-1)<<endl;
     return 0;
}
