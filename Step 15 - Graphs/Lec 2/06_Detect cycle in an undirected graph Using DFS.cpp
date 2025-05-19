// Question Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Detect cycle in an undirected graph

// T.C = O(V+E)
// S.C = O(V)
class Solution {
public:
    bool isCyclicDFS(vector<vector<int>>& adj, int u, int parent, vector<bool>& visited) {
        visited[u] = true;
        for(int &v : adj[u]) {
            if(!visited[v]) {
                if (isCyclicDFS(adj, v, u, visited)) {
                    return true;
                }
            } else if(v != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(!visited[i] && isCyclicDFS(adj, i, -1, visited)) {
                return true;
            }
        }
        return false;
    }
};