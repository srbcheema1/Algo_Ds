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

