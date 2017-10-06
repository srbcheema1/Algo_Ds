//Following  is the code where in you can update the value in the array and Query for the sum in l to r
#include <bits/stdc++.h>
using namespace std;

int getSum(int *st, int n, int ss, int se, int qs, int qe, int si) {

	if(qs < 0 || qs > qe || qe >= n) {
		return -1;
	}	

		if(ss >= qs && se <= qe) { //segment range fully within query range
			return st[si];
		}
		if(se < qs || ss > qe) {//segment range has not intersection
			return 0;
		}

		int mid = (ss + se)/2;
		return getSum(st, n, ss ,mid, qs, qe, 2*si+1) + getSum(st, n, mid+1 ,se, qs, qe, 2*si+2);
	}

	void UpdateUtil(int *st, int ss, int se, int i, int diff, int si) {

		if(i < ss || i > se) {
			return;
		}

		st[si] += diff;

		if(ss != se) {
			int mid = (ss + se)/2;
			UpdateUtil(st, ss, mid, i, diff, 2*si+1);
			UpdateUtil(st, mid+1, se, i, diff, 2*si+2);
		} 
	}

	void UpdateValue(int a[], int *st, int n, int i, int new_value) {

		if(i < 0 || i > n -1) {
			return;
		}

		int diff = new_value - a[i];

		a[i] = new_value;

		UpdateUtil(st, 0, n-1, i, diff, 0);

	}

	int buildTree(int a[], int n, int ss, int se, int *st, int si) {

		if(ss == se) {
			st[si] = a[ss];
			return a[ss];
		}

		int mid = (ss + se)/2;
		st[si] = buildTree(a, n, ss, mid,st, 2*si + 1) + buildTree(a, n, mid+1, se,st,2*si+2);

		return st[si];
	}

	int *constructTree(int a[], int n) {

		int x = (int)(ceil(log2(n)));

		int max_size = 2*(int)pow(2,x) - 1;

		int *st = new int[max_size];

		buildTree(a, n, 0, n-1, st, 0);

		return st;
	}

	int main()
	{
		int n;
		cin>>n;
		int a[n], i;
		for(i=0;i<n;i++) {
			cin>>a[i];
		}
		int *st = constructTree(a, n);
		int qs, qe;
		cin>>qs>>qe;
		cout<<getSum(st, n, 0, n-1, qs, qe, 0)<<endl;
		UpdateValue(a, st, n, 2, 10);
		cin>>qs>>qe;
		cout<<getSum(st, n, 0, n-1, qs, qe, 0)<<endl;
		return 0;
	}