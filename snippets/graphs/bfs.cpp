#include<bits/stdc++.h>
using namespace std;

// shortest path (unweighted graph)
vector<int> shortest_path(int source, vector<vector<int>>& adj) {
    int N = (int)adj.size();
    vector<int> dist(N, INT_MAX);
    queue<int> q;
    dist[source] = 0;
    q.push(source);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto neigh : adj[curr]) {
            if(dist[curr] == INT_MAX) {
                dist[neigh] = 1 + dist[curr];
                q.push(neigh);
            }
        }
    }
    return dist;
}
