// Question Link :- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// Number of Ways to Arrive at Destination

// T.C = O(E logV)
// S.C = O(V + E)
#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<ll> dist(n, LONG_MAX);
        dist[0] = 0;
        vector<int> way(n, 0);
        way[0] = 1;

        priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0, 0});   // {dist, node}
        while(!pq.empty()) {
            ll d = pq.top().first;   // current time
            int node = pq.top().second;   // current node
            pq.pop();
            for(auto it: adj[node]) {
                int v = it.first;
                int wt = it.second;
                if(d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({d+wt, v});
                    way[v] = way[node] % mod;
                }
                else if(d + wt == dist[v]) {
                    way[v] = (way[v] + way[node]) % mod;
                }
            }
        }
        return way[n-1];
    }
};