#include<bits/stdc++.h>
using namespace std;
#define ll long long
/* https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html    */

/* finds prime numbers in [1, n] in O(n * log(logn)) (approx O(n)) */

vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    vector<int>primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.emplace_back(i);
            for (ll j = 1LL * i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}
