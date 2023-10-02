#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;  // limit for array size
vector<int> t(2 * N);

class SegmentTree {
public:
    int n;  // array size

    SegmentTree(vector<int>& a) {
        n = (int) a.size();
        for(int i = 0; i < n; i++)
            t[n + i] = a[i];
        build();
    }

    void build() {  // build the tree
        for(int i = n - 1; i > 0; i--) 
            t[i] = t[2 * i] + t[2 * i + 1];
    }

    void modify(int p, int value) {  // set value at position p
        for(t[p += n] = value; p > 1; p >>= 1) 
            t[p>>1] = t[p] + t[p^1];
    }

    int query(int l, int r) {  // sum on interval [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    SegmentTree ST(a);

    while(true) {
        int q;
        cin >> q;
        if(q == 0)
            break;
        else if(q == 1) {
            int p, val;
            cin >> p >> val;
            ST.modify(p, val);
        } else if(q == 2) {
            int l, r;
            cin >> l >> r;
            cout << ST.query(l, r + 1) << '\n';
        } else {
            for(int i = 1; i < 2 * n; i++)
                cout << t[i] << " \n"[i == 2 * n - 1];
        }
    }
    
}


int main() {
    solve();
}

