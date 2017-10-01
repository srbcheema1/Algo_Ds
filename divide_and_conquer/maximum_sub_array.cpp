/**
*	Implementation of finding maximum subarray which consists of finding range and sum of the subarray
*   Using divide and conquer 
*/

#include<bits/stdc++.h>
using namespace std;

// vector array 
vector<int> a;

int resM[3];
int resR[3];
int resL[3];
int res[3];

// find maximum subarray
int * findMaxSubArray(int, int);

// find subarray in the middle of two halves
int * findMiddleSubArray(int, int, int);

int main(){
	
	// size of array
	int n;
	cin>>n;
	
	
	int foo;
	for (int i = 0; i < n; i++){
		cin>>foo;
		// add elements to vector a
		a.push_back(foo);
	}
	

	
	int *x = findMaxSubArray(0, n - 1);
	
	// left position
	cout<<"("<<x[0]<<",";
	// right position
	cout<<x[1]<<")"<<endl;
	// max sum
	cout<<x[2]<<endl;
		
}

int * findMaxSubArray(int low, int high){
	
	if (high == low){
	// base case
		
		// return if only one element id present 

		res[0] = low;
		res[1] = high;
		res[2] = a[low];
		return res;
		
	}
	else{
	
		// find middle of vector
		int mid = (low + high)/2;
		
		int *res1L, *res1R, *res1M;
		
		// find maximum subarray in the left half
		res1L = findMaxSubArray(low, mid);
		
		// find maximum sub array in the right half
		res1R = findMaxSubArray(mid + 1, high);
		
		// find maximum subarray in the middle of the partition
		res1M = findMiddleSubArray(low, mid, high);
		
		// return maximum of 3 results comparing their sums
		if ((res1L[2] >= res1R[2]) && (res1L[2] >= res1M[2])){
		
			resL[0] = res1L[0];
			resL[1] = res1L[1];
			resL[2] = res1L[2];
			return resL;
		}
		else if ((res1R[2] >= res1L[2]) && (res1R[2] >= res1M[2])){
			
			resM[0] = res1R[0];
			resM[1] = res1R[1];
			resM[2] = res1R[2];
			return resR;
		}
		else{
		
			return res1M;
		}
		
		
	}
}

int * findMiddleSubArray(int low, int mid, int high){
	
	int lSum = INT_MIN, rSum = INT_MIN;
	int sum = 0;
	

	
	// move through the left sub array starting from the middle to find the longest sub array
	for (int i = mid; i >= low; i--){
		sum += a[i];
		if (sum > lSum){
			lSum = sum;
			resM[0] = i;
		}
	}
	
	sum = 0;
	// move through the right sub array starting from middle to find the longest sub array
	for (int i = mid + 1; i <= high; i++){
		sum += a[i];
		if (sum > rSum){
			rSum = sum;
			resM[1] = i;
		}
	}
	
	// find sum of the combined middle sub array
	resM[2] = lSum + rSum;
	
	return resM;
}

