#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
    // topo_sort is a DAG(directly acylic graph)
	vector<int> topo_sort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool>vis(V);
	    vector<int>topoOrder(V);
	    int curr = V - 1;
	    function<void(int)> dfs = [&](int node) -> void {
	        vis[node] = true;
	        for(auto neigh : adj[node]) {
	            if(!vis[neigh]) {
	                dfs(neigh);
	            }
	        }
	        topoOrder[curr--] = node;
	    };  
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) dfs(i);
	    }
	    return topoOrder;
	}
};