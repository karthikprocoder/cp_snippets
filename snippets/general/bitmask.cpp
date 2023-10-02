#include<bits/stdc++.h>
using namespace std;

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