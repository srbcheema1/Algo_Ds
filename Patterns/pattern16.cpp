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
	count--;
	for( int i = 1; i <= n-1; i++ ){
		for( int j = 1; j <= i; j++ ){
			cout << spaces;
		}
		for( int j = n-1; j >= i; j-- ){
			count--;
			cout << count << " ";
		}
		cout << endl;
	}

    return 0;

}
