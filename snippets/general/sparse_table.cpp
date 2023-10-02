#include<bits/stdc++.h>
using namespace std;

// can be used to calculate static range min, max, gcd in O(NlogN) time
vector<vector<int>>sparse_table;

int bin_log(int x) {
    return 31 - __builtin_clz(x);
}

void pre_compute(vector<int>& a) { // O(NlogN)
    int n = a.size();
    sparse_table.resize(n);

    for(int i = 0; i < n; i++) {
        sparse_table[i].resize(20);
        sparse_table[i][0] = a[i];
    }

    for(int pwr = 1; pwr <= bin_log(n); pwr++) {
        for(int i = 0; i + (1 << pwr) - 1 < n; i++) {
            sparse_table[i][pwr] = min(sparse_table[i][pwr - 1], 
                    sparse_table[i + (1 << (pwr - 1))][pwr - 1]);
        }
    }
}

int query(int l, int r) { // O(1)
    int len = r - l + 1;
    int p = bin_log(len);
    return min(sparse_table[l][p], sparse_table[r - (1 << p) + 1][p]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    pre_compute(a);

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r) << "\n";
    }    
}
