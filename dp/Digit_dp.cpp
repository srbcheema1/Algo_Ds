#include <bits/stdc++.h>
using namespace std;

long long int dp[20][180][2];

long long int getDigits(long long int x, vector <int> &digits) {
	while(x) {
		digits.push_back(x%10);
		x = x/10;
	}
}

long long int digitSum(int idx, int sum, int tight, vector <int> &digit) {

	if(idx == -1) {
		return sum;
	}

	if(dp[idx][sum][tight] != -1 && tight != 1) {
		return dp[idx][sum][tight];
	}

	long long int ret = 0;


	int k = (tight)?digit[idx]:9;

	int i;

	for(i=0;i<=k;i++) {

		int newTight = (digit[idx] == i)?tight:0;

		ret += digitSum(idx - 1, sum + i, newTight, digit);
	}

	return ret;
}

long long int rangeDigitSum(int a, int b) {

	memset(dp, -1, sizeof(dp));

	vector <int> digitA;
	getDigits(a-1, digitA);

	long long int ans1 = digitSum(digitA.size() - 1, 0, 1, digitA);

	vector <int> digitB;
	getDigits(b, digitB);


	long long int ans2 = digitSum(digitB.size() - 1, 0, 1, digitB);

	return (ans2 - ans1);
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<(rangeDigitSum(a,b));
	return 0;
}