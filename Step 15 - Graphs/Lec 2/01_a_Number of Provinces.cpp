// Question Link :- https://leetcode.com/problems/number-of-provinces/
// Number of Provinces (DFS)


// Approach - 1 (Creating own adjacency list)
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> adj, int u, vector<bool>& visited) {
        visited[u] = true;
        for(int &v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        // create adjacency list
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, i, visited);
            }
        }
        return count;
    }
};





// Approach - 2 (Using given input graph)
class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int n, int u, vector<bool>& visited) { // modification 2
        visited[u] = true;
        //Visit neighbours
        for(int v = 0; v < n; v++) {  // modification 3
            if(!visited[v] && isConnected[u][v] == 1) {  // modification 4
                dfs(isConnected, n, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, n, i, visited); // modification 1
            }
        }
        return count;
    }
};