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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout  << i+1 << " ";
        }
        cout << '\n';
    }
    cout << '\n';
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