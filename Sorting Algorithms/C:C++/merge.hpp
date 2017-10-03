#include <bits/stdc++.h>
using namespace std;

void _merge(int v[], int left, int mid, int right){
	int i, j, k;
	int n1 = mid - left + 1; // size of first subarray
    int n2 =  right - mid; // size of second subarray
 
    // create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (j = 0; j < n2; j++)
        R[j] = v[mid + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }else{
            v[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1){
        v[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void _merge_sort(int v[], int left, int right){
	if(left < right){
		// same as (left + right) / 2, but avoids overflow due to large values of left and right
		int mid = left + (right - left) / 2;
		_merge_sort(v, left, mid);
		_merge_sort(v, mid + 1, right);

		_merge(v, left, mid, right);
	}
}

void merge_sort(int length, int v[]){
	_merge_sort(v, 0, length-1);
}