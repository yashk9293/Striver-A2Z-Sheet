// Question Link :- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Dijkstra Algorithm (Using Set)

// T.C - O(V^2 log(v) or O(E log(V)) (worst case) // V = vertices, E = edges
// S.C - O(|E| + |V|) 

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int source) {
        // pair {dist,node} where dist is the distance from source to the node. 
        set<pair<int, int>> st;
        vector<int> result(V, INT_MAX);
        result[source] = 0;    // Source initialised with dist = 0
        st.insert({0, source});
        while (!st.empty()) {
            auto &it = *(st.begin());     // Fetching top pair
            int d = it.first;
            int node = it.second;
            st.erase(it);
            for (auto &vec : adj[node]) {
                int v = vec[0];
                int wt = vec[1];
                if (d + wt < result[v]) {
                    if(result[v] != INT_MAX) {
                        st.erase({result[v], v});
                    }
                    result[v] = d + wt;
                    st.insert({d + wt, v});
                }
            }
        }
        return result;
    }
};