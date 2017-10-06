#include <bits/stdc++.h>
using namespace std;

int _partition(int v[], int left, int right){
	int pivot = v[right];
	int i = left-1;
	for(int j=left;j<right-1;j++){
		if(v[j] <= pivot){
			i++;
			swap(v[i], v[j]);
		}
	}
	i++;
	swap(v[i], v[right]);
	return i;
}

void _quick(int v[], int left, int right){
	if(left < right){
		int partition_index = _partition(v, left, right);
		_quick(v, left, partition_index - 1);
		_quick(v, partition_index + 1, right);
	}
}

void quick_sort(int length, int v[]){
	_quick(v, 0, length - 1);
}