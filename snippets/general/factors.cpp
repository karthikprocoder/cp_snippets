#include<bits/stdc++.h>
using namespace std;

/* https://cp-algorithms.com/algebra/prime-sieve-linear.html */

/* Do not use if N > 1e7                                     */

/* run time O(n)                                             */

constexpr int N = int(1e7);
constexpr int mxN = int(1e5);

// stores lowest prime factor of all number from 2 to N
int lpf[N + 1]; 
vector<int>primes;

// list of factors of all numbers in a range
vector<vector<int>>f(mxN+1);

int main() {
    
    for(int i = 2; i <= N; i++) {
        if(!lpf[i]) {
            lpf[i] = i;
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(i * p > N) break;
            lpf[i * p] = p;
            if(i % p == 0) break;
        }
    }

    for(int i = 1; i <= mxN; i++) {
        for(int j = i; j <= mxN; j += i) {
            f[j].push_back(i);
        }
    }
}