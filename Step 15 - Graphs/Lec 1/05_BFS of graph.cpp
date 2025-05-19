// Question Link :- https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// BFS of graph

// T.C = O(V+E)
// S.C = O(V)
class Solution {
  public:
    void bfs(vector<int> adj[], int u, vector<bool>& visited, vector<int>& result) {
        queue<int>q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(int &v: adj[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> visited(V, false);
        bfs(adj, 0, visited, result);
        return result;
    }
};