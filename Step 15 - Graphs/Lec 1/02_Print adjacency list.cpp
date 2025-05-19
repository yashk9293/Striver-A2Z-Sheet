// Question Link :- https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
// Print adjacency list

// T.C = O(V)
// S.C = O(V+E)
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // for(int &p : edges) {
        //     int u = p.first;
        //     int v = p.second;
            
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        return adj;
    }
};