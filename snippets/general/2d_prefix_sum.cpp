#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> prefSumMatrix(vector<vector<int>>& A) {
    int N = A.size(), M = A[0].size();
    vector<vector<ll>>pref(N+1, vector<ll>(M+1));
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= M; j++)
            pref[i][j] = A[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    return pref;
}

/*

FOR 0-indexed matrix
top left coordinate of the rectangle -> r1, c1
bottom right coordinate of the rectangle -> r2, c2
sum of the rectangle -> 
pref[r2+1][c2+1] - pref[r2+1][c1] - pref[r1][c2+1] + pref[r1][c1]

solve problem 3
https://practice.geeksforgeeks.org/contest/megajob-a-thon-hiring-challenge-freshers/problems
*/