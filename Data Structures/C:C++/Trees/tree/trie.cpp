#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int ii,i,at;
struct no{
	no* nxt[26];
	no *root;
	ll fim,qtdNo;
	
	inline no(char k){
		for(ii=0;ii<26;ii++) nxt[ii] = NULL;
		root = this;
		fim = qtdNo = 0;
	}
	inline bool insert(const string s, ll i){
		if(i == s.size()){
			fim = 1;
			return false;
		}
		at = s[i] - 'a';
		if(!nxt[at]){
			nxt[at] = new no(s[i]);
			nxt[at] -> root = root;
			root -> qtdNo++;
		}
		else if(nxt[at] -> fim) return true;
		return nxt[at] -> insert(s,i+1);
	}
};
 main(){}
