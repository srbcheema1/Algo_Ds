// C++ program to convert a decimal  number to hexadecimal number 
#include<bits/stdc++.h> 
using namespace std; 

void decitohexa(int n) 
{ 
	
	char num[100]; 
	
	
	int i = 0; 
	while(n!=0) 
	{ 
		// temporary variable 
		int tempe = 0; 
		//  remainder stored in temp 
		tempe = n % 16; 
	
		if(tempe < 10) 
		{ 
			num[i] = tempe + 48; 
			i++; 
		} 
		else
		{ 
			num[i] = tempe + 55; 
			i++; 
		} 
		
		n = n/16; 
	} 
	
	
	for(int g=i-1; g>=0; g--) 
		cout << num[g]; 
} 


int main() 
{ 
	int n = 4534; 
	
	decitohexa(n); 
	
	return 0; 
} 
