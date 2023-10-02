#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int const MOD  = 1000000007;
int const HALF = 500000004;
int const ONE_SIXTH = 166666668;

ll _ceil(ll a, ll b) {
    return 1 + (a - 1) / b;
}

ll _floor(ll a, ll b) {
    return a / b - ((a%b != 0) && (a*b < 0));
}

// O(log(min(a, b)))
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int bin_log(int x) {
    return 31 - __builtin_clz(x);
}

ll sum_of_natural_numbers(ll a, ll b) {
	return ((((b - a + 1) % MOD) * ((a + b) % MOD) % MOD) * HALF % MOD);
}

ll sum_of_AP(int a, int b, int d = 1) {
    ll n = b - a + 1;
    return n * (2 * a + (n - 1) * d) / 2;
}

ll sum_of_squares(ll a, ll b) {
    // sum 1 to b^2
    ll sum1 = b * (b + 1) * (2 * b + 1) / 6;
    // sum 1 to (a - 1)^2
    ll sum2 = a * (a - 1) * (2 * a - 1) / 6;
    return sum1 - sum2;
}

ll pwr(ll n, ll a = 2){
    // returns a^n
    ll res = 1;
    while(n) {
        if(n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

// Used when mod is included in power
ll modpwr(ll a, ll n, ll M) {
    // returns a^n
    int res = 1;
    while (n) {
        if(n & 1) res = (res * a) % M;
        a = (a * a) % M;
        n >>= 1;
    }
    return res;
}

// Multiplicative Inverse
ll mod_inverse(ll a, ll M) {
    return modpwr(a, M - 2, M);
}

// nth root of x
ll nth_root(ll x, ll n = 2) {
    ll res = 1;
    ll hi = x + 1;
    while(res + 1 < hi) {
        ll mid = (res + hi) / 2;
        if(pwr(n, mid) <= x) res = mid;
        else hi = mid;
    } 
    return res;
}

ll factorial(ll n) {
    ll res = 1;
    for(int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll nCr(ll n, ll r) {
    ll res = 1;
    r = min(r, n - r);
    for(int i = 1; i <= r; i++) 
        res = res * (n - r + i) / i;
    return res;
}

ll quad_bs(ll a, ll b, ll c) {
    // solve ax^2 + bx = c in logn time
    // used to avoid overflow
    ll g = gcd(a, gcd(b, c));
    a /= g; b /= g; c /= g;
    assert(a > 0 && c >= 0);
    ll ng = sqrt(c / a) + 1;
    ll ok = 0;
    while(ok + 1 < ng) {
        ll mid = (ok + ng) / 2;
        // value can overflow!!!!!
        if(a * mid * mid + b * mid <= c) 
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {

    return 0;
}