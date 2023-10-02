#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "inc/debug.h"
#else
#define dbg(...) 1
#endif

/*

*/

void solve(int test_no) {
    int N;
    cin >> N;
    dbg(N);
    cout << N * N << '\n';
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for(int t = 1; t <= T; t++) {
        solve(t);
    }
}
