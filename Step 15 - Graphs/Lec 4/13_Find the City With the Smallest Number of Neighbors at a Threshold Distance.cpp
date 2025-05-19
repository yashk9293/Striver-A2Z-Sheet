// Question Link :- https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Find the City With the Smallest Number of Neighbors at a Threshold Distance

// Approach - 1 (Using Floyd Warshall Algorithm)
// T.C = O(V^3)
// S.C = O(V^2)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n, 10001));  // O(n^2) Initializing dist matrix
        for(int i=0; i<n; i++) {
            dist[i][i]=0;
        }
        for(int i=0; i<edges.size();i++) {  // O(E)
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], (dist[i][via] + dist[via][j]));
                }
            }
        }
         
        int min_city = -1, mincnt = n;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= mincnt){
                min_city = i;
                mincnt = count;
            }
        }
        return min_city;
    }
};








// Approach - 2 (Using Dijkstra Algorithm)
// T.C = O( V*[(V + E)*log(V)] )
// S.C = O(V + E)

class Solution {
public:
    int dijkstra(int source, int limit, int n, vector<vector<pair<int, int>>> &adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        pq.push({0, source});  // {dist, node}

        vector<int> dis(n, INT_MAX);
        dis[source] = 0;
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &vec : adj[node]){
                int v = vec.first;
                int wt = vec.second;
                if(d + wt < dis[v]){
                    dis[v] = d + wt;
                    pq.push({d + wt, v});
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i != source && dis[i] <= limit){
                cnt++;
            }
        }
        return cnt;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges) {   // S.C = O(V+E)
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int mincnt = n;
        int min_city = -1;

        for(int i=0; i<n; i++){
            int cnt = dijkstra(i, distanceThreshold, n, adj);  // O((V + E) log V)
            if(cnt <= mincnt){
                min_city = i;
                mincnt = cnt;
            }
        }
        return min_city;
    }
};