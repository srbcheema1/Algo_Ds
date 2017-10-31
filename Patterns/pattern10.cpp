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
   23
  456
78910

*/

