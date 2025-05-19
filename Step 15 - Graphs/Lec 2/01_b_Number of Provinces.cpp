// Question Link :- https://leetcode.com/problems/number-of-provinces/
// Number of Provinces (BFS)


// Approach - 1 (Creating own adjacency list)
class Solution {
public:
    void bfs(unordered_map<int, vector<int>> adj, int u, vector<bool>& visited) {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int &v : adj[curr]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        // create adjacency list
        unordered_map<int, vector<int>> adj;  // vector<vector<int>> adj(n);
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
                bfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};





// Approach - 2 (Using given input graph)
class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, int n, int u, vector<bool>& visited) {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            //Visit neighbours
            for(int v = 0; v<n; v++) {
                if(!visited[v] && isConnected[u][v] == 1) {
                    visited[v] = true;
                    q.push(v);
                }
            } 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                bfs(isConnected, n, i, visited);
                count++;
            }
        }
        return count;
    }
};