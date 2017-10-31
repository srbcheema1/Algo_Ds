#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int count = 1;
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j <= i; j++ ){
			if ( n < count){
				return 0;
			}
			cout << count << " ";
			count++;
		}
		cout << endl;
	}
	cout << endl;
    return 0;

}

/*
10 

1
23
456
78910

*/
