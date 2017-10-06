#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	int count = 1;

	char spaces = ' ';
	for( int i = 1; i <= n; i++ ){
		for( int j = n - i; j > 0; j-- ){
			cout << spaces;
		}
		for( int j = 1; j <= i; j++ ){
			cout << count << " ";
			count++;
		}
		cout << endl;
	}
	for( int i = 1; i <= n; i++ ){
		for( int j = 1; j < i; j++ ){
			cout << spaces;
		}
		for( int j = n; j >= i; j-- ){
			cout << count;
			count++;
		}
		cout << endl;
	}

    return 0;

}

/*
4

    1
   2 3
  4 5 6
 7 8 9 10
 11 12 13
   14 15
    16

*/
