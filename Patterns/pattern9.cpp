#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	char spaces = ' ';
	for( int i = 1; i <= 5; i++ ){
		for( int j = n - i; j > 0; j-- ){
			cout << spaces;
		}
		for( int j = 1; j <= i; j++ ){
			cout << i;
		}
		cout << endl;
	}

    return 0;

}

/*
5

    1
   22
  333
 4444
55555

*/
