// A program to search for an element in a 2D matrix in which each row and coloumn is sorted in ascending order
#include <iostream>
using namespace std;

int main(){
  // Number of test cases
  int test;
  cin >> test;
  while(test--){
    // Number of rows and coloumns in the matrix
    int a, b;
    cin >> a >> b;
    int ar[a][b];
    // Array of arrays to store the values of 2D-Matrix
    for (int i = 0; i < a * b; ++i) {
      cin >> ar[i % a][i % b];
    }
    // Number to be searched for
    int x;
    cin >> x;
    // Start from top right
    int i = 0, j = b - 1;
    while(1){
      // Problem solved if element is found
      if(ar[i][j] == x){
	cout << 1;
	break;
      }
      // Move down if element is less than key
      else if(ar[i][j]<x){
	i++;
      }
      // Move left if element is greater than key
      else if(ar[i][j]>x){
	j--;
      }
      // If element is not found return 0
      // as we reach the bottom-left of the matrix
      // The element was not present
      if(i >= a || j <0){
	cout << 0 << endl;
	break;
      }
    }
  }
  return 0;
}

// Sample test case:
// 1
// 3 3
// 2 6 8
// 3 9 12
// 4 10 13
// 9
