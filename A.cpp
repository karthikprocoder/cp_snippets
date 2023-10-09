#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(...) 1
#endif

/*
notice that b is a symmetric matrix
find the farthest a number can be from the diagonal

if ai 's farthes pos is j then ans = (j-i+1)*2
a0 _ _ _ _   _
a1
a2
a3
    3   2   4 5
3   3   2   3 3
2   2   2   2 2
4   3   2   4 4
5             5
*/

void solve(int test_no) {
    int n, K;
    cin >> n >> K;
    vector<int> a(n), p(K+1, n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(p[a[i]] == n)
            p[a[i]] = i;
    }
    vector<int> right_max(n);
    right_max[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) 
        right_max[i] = max(right_max[i+1], a[i]);
    

    vector<int> left_max(n);
    left_max[0] = a[0];
    for(int i = 1; i < n; i++) 
        left_max[i] = max(left_max[i-1], a[i]);


    auto farthest_pos = [&](int i) -> int {
        int x = a[i];
        int ok = i;
        int ng = n;
        while(ok + 1 < ng) {
            int mid = (ok + ng) / 2;
            if(x <= right_max[mid]) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    auto nearest_pos = [&](int i) -> int {
        int x = a[i];
        int ok = i;
        int ng = -1;
        while(ok - 1 > ng) {
            int mid = (ok + ng) / 2;
            if(x <= left_max[mid]) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    // dbg(p);

    for(int k = 1; k <= K; k++) {
        if(p[k] != n) {
            int j = farthest_pos(p[k]);
            int i = nearest_pos(p[k]);
            cout << 2 * (j-i+1) << " \n"[k == K];
        }
        else {
            cout << 0 << " \n"[k == K];
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        solve(t);
    }
}