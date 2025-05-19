// Question Link :- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Dijkstra Algorithm (Using Priority Queue)

// Shortest Path in a weighted graph Using Dijkstras Algorithm
// It can work with both directed as well as undirected graph.

// T.C - O(V^2 log(v) or O(E log(V)) (worst case) // V = vertices, E = edges
// S.C - O(|E| + |V|) 

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int source) {
        // pair {dist,node} where dist is the distance from source to the node. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX);
        result[source] = 0;    // Source initialised with dist = 0
        pq.push({0, source});
        while (!pq.empty()) {                  // O(v)
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();                          // O(log v)
            for (auto &vec : adj[node]) {      // O(v)
                int v = vec[0];
                int wt = vec[1];
                if (d + wt < result[v]) {
                    result[v] = d + wt;
                    pq.push({d + wt, v});      // O(log v)
                }
            }
        }
        return result;
    }
};