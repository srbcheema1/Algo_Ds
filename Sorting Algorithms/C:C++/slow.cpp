#include <bits/stdc++.h>
using namespace std;

void _slow_sort(int v[], int i, int j) {
  if (i >= j) return;
  int m = i + (j-i)/2;
  _slow_sort(v, i, m);
  _slow_sort(v, m+1, j);
  if (v[j] < v[m])
    swap(v[j], v[m]);
  _slow_sort(v, i, j-1);
}

void slow_sort(int length, int v[]) {
  _slow_sort(v, 0, length-1);
}

