// Question Link :- https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
// M-Coloring Problem

// Approach is:
// for every node try all possible color
// suppose if you reach last it means you successfully colored all the nodes, then return true

// T.C = O(N^m)
// S.C = O(N) + O(N)
class Solution {
  public:
    bool isSafe(int node, unordered_map<int, list<int>>& adj, vector<int>&color, int i){
        for(auto it : adj[node]) {
            if(color[it] == i) {   // adjacent node already have this color
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int v, int m, unordered_map<int, list<int>>& adj, vector<int>& color) {
        if(node == v) {  // if all nodes are colored successfully
            return true;
        }
        for(int i=1; i<=m; i++) {
            if(isSafe(node, adj, color, i)) {
                color[node] = i;
                // at any moment you successfully colored all node, then return true
                if(solve(node+1, v, m, adj, color)) {
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        unordered_map<int, list<int>> adj;
        // vector<vector<int>> adj(v);
        for(auto &edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color (v, 0);  // color of nodes
        
        return solve(0, v, m, adj, color);
    }
};