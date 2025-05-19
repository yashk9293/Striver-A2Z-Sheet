// Question Link :- https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Shortest path in Undirected Graph


// Approach 1 : Dijkstra's Algorithm
// T.C = O(n+m)
// Each node is pushed into the queue at most once → O(N)
// Each edge is traversed once when checking neighbors → O(M)

// S.C = O(n)
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int N = adj.size();
        vector<int> distance(N, 1e9);
        distance[src] = 0;

        queue<pair<int,int>> que;
        que.push({0, src});    // {dist, node}

        while(!que.empty()) {
            int d = que.front().first;
            int node = que.front().second;
            que.pop();
            for(int &v : adj[node]) {
                if(d + 1 < distance[v]) {   // since, wt = 1 (unit weight)
                    distance[v] = d + 1;
                    que.push({d+1, v});
                }
            }
        }
        for (int i=0; i<N; i++) {
            if (distance[i] == 1e9) {
                distance[i] = -1;
            }
        }
        return distance;
    }
};




// Approach - 2 : BFS
// T.C = O(n+m)
// S.C = O(n)
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        
        queue<int> q;
        q.push(src);
        
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
    
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (distance[v] == INT_MAX) {
                    distance[v] = distance[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i=0; i<n; i++) {
            if (distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }
        return distance;
    }
};