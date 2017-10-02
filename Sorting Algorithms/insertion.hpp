#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int length, int v[]){
	for(int i=0;i<length;i++){
		int j = i;
		while(j>0 && v[j] < v[j-1]){
			swap(v[j], v[j-1]);
			j--;
		}
	}
}
