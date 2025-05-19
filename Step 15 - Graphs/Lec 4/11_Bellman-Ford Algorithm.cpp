// Question Link :- https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// Distance from the Source (Bellman-Ford Algorithm)

// T.C = O(V*E)
// S.C = O(V)
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for(int c = 1; c<=V-1; c++) {
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        //Now detect negative cycle
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }
        return dist;
    }
};
