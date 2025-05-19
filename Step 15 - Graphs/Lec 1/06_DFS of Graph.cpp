// Question Link :- https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// DFS of Graph

// T.C = O(V+E)
// S.C = O(V)
class Solution {
  public:
    void dfs(vector<int> adj[], int u, vector<bool>& visited, vector<int>& result) {
        if(visited[u] == true) {
            return;
        }
        visited[u] = true;
        result.push_back(u);
        for(auto &v: adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited, result);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {  // V is the no. of nodes
        vector<int> result;
        vector<bool> visited(V, false);
        dfs(adj, 0, visited, result);
        return result;
    }
};