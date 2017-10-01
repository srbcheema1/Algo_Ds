#include <iostream>
#include <vector>
using namespace std;
void sieve_of_eratosthenes(std::vector<int>& primes, const int max) {
	vector<bool> isPrime;
	// Initially, all the numbers are considered to be prime
	for (int i = 0; i <= max; i++) {
		isPrime.push_back(true);
	}
	// 0 and 1 are obviously not prime, so we set it in the isPrime vector
	isPrime[0] = isPrime[1] = false;

	// Iterate from 2 up to the square root of max
	for (int i = 2; i*i <= max; i++) {
		if (isPrime[i]) {
			// If the current number is prime, then set i^2, i^2+i, i^2+2i, ... as not prime
			for (int j = i * i; j <= max; j += i) {
				isPrime[j] = false;
			}
		}
	}

	// Iterate from 2 to max again. All the numbers, that are still set to true, are prime
	for (int i = 2; i <= max; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}
}

int main() {
	int n = 100;
	vector<int> primes;
	// Find primes up to n
	sieve_of_eratosthenes(primes, n);
	cout << "Primes up to "<<n<<" are:"<<endl;
	for (auto prime : primes) {
		cout << prime << " ";
	}
	return 0;
}
