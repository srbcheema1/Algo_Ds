#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
 return (b==0 ? a : gcd(b,a%b));
}
int lcm(int a,int b)
{
  return (a*(b/gcd(a,b)));      //divide before multiply!!
}
int main()
{
  int a,b;
  cin >> a >> b;
  cout << lcm(a,b);
  return 0;
 }
