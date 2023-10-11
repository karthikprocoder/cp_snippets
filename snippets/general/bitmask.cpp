#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
** commutative propertiy holds true for xor, and, or *****
*** useful in hashing + bitmask problems **********
XOR
0 ^ a = a
111..11 ^ a = ~a
a ^ a = 0
xor is similar to sum of numbers in terms of parity

AND
0 & a = 0
111..11 & a = a
a & a = a
If a & b = c, then c <= min(a, b)

OR
0 | a = a
111..11 | a = 111..11
a | a = a
If a | b = c then c >= max(a, b)
*/

/*
masking is generally used when n is under 30
imp note -> number of alphabets is 26, so can use bitmasking in such problems
solve problem 2
https://practice.geeksforgeeks.org/contest/megajob-a-thon-hiring-challenge-freshers/problems
*/
void iterate_every_subset_of_n_items(int n) {
    for(int m = 0; m < (1 << n); m++) {
        for(int i = 0; i < 31; i++) {
            if(m >> i & 1) {
                // do something
            }
        }
    }
}

void print_binary(int x) {
    for(int i = 31; i >= 0; i--) {
        cerr << (x >> i & 1 ? 1 : 0);
    }
    cerr << "\n";
}

/* useful inbuilt functions */
// https://codeforces.com/blog/entry/72437
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt_mod_2(int x) { return __builtin_parity(x); }
int popcnt_mod_2(ll x) { return __builtin_parityll(x); }
// (0, 1, 2, 3, 4, 6) -> (-1, 0, 1, 1, 2, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4, 6) -> (-1, 0, 1, 0, 2, 1)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }


int main() {
    int n;
    cin >> n;
    cout << __lg(n) << '\n';
    cout << __builtin_ffs(n) << '\n';
}