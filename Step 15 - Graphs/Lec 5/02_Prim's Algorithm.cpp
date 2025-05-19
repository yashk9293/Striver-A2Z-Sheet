// Question Link :- https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Minimum Spanning Tree

// T.C = O(E logv)
// S.C = O(V+E)
class Solution {
  public:
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});  // {dist, node}
        
        vector<bool> inMST(V, false);
        int sum = 0;
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(inMST[node] == true) {
                continue;
            }
            inMST[node] = true; // added to mst
            sum += d;
            for(auto &vec : adj[node]) {
                int v = vec[0];
                int wt = vec[1];
                if(inMST[v] == false) {
                    pq.push({wt, v});
                }
            }
        }
        return sum;
    }
};