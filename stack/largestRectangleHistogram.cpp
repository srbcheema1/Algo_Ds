#include<iostream>
#include<stack>
#include<climits>
using namespace std;
int main() {
    int n;
    int a[]={6,2,5,4,5,1,6};  //input array
    n = sizeof(a)/sizeof(a[0]);
    int i,q;
    stack <int> s;  // stack to calculate max area
    i=0;
    int area,maxarea=INT_MIN;
    while(i<n){
        if(s.empty()||a[s.top()]<=a[i])
        s.push(i++);
        else{
            q=s.top();
            s.pop();
            area=a[q]*(s.empty()?i:i-s.top()-1);
            if(maxarea<area)
                maxarea=area;
        }
    }
    while(!s.empty()){
        q=s.top();
        s.pop();
        area=a[q]*(s.empty()?i:i-s.top()-1);
        if(maxarea<area)
            maxarea=area;
    }
    cout<<maxarea;
	return 0;
}
