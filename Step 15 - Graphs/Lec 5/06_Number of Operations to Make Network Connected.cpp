// Question Link :- https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Number of Operations to Make Network Connected

// Approach - 1 (DSU)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if(i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent) {
            return;
        }
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) {
            return -1;
        }
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        int components = n;
        for(auto &vec : connections) {
            if(find(vec[0]) != find(vec[1])) {
                Union(vec[0], vec[1]);
                components--;
            }
        }
        return components -1;
    }
};







// Approach - 1 (DFS)
class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u) {
        visited[u] = true;
        for(int v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, visited, v);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) {
            return -1;
        }
        vector<vector<int>> adj(n);
        for(auto &vec : connections) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(adj, visited, i);
                components++;   // inc no. of components
            }
        }
        return components - 1;
    }
};