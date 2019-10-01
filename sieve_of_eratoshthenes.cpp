//isPrime denotes the array which will be used to mark prime numbers.
//N is the limit, upto which we need to find prime numbers.

bool isPrime[N+1];

void sieve() {
    int i, j;

    memset(isPrime, true, sizeof(isPrime))

    for(i = 2; i*i <= N; i++) {
        if(isPrime[i] == true) {
            for(j = i*i; j <= N; j = j+i)
                isPrime[j] = false;
        }
    }
}

//For instance, to return the number of primes until 'n' we could do the following:

#include<bits/stdc++.h>
using namespace std;

int erasthostenesSieve(int n) {
    vector<bool> primes(n+1,true);
    int numberOfPrimes = 0;
    for (int i = 2; i*i <= n; i++) {
        if(primes[i]) {
            for (int j = i*i; j <= n; j+=i)
                primes[j] = false;
        }
    }
    for (int p=2; p<=n; p++) {
        if (primes[p]) {
            numberOfPrimes++;
        }
    }
    return numberOfPrimes;
}

int main() {
    int n;
    cin >> n;
    cout << erasthostenesSieve(n) << endl;
}
