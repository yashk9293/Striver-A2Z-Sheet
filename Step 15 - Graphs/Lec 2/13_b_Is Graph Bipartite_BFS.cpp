// Question Link :- https://leetcode.com/problems/is-graph-bipartite/
// Is Graph Bipartite?

// odd cycle are only non bipartite graph

// BFS
class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& graph, int u, vector<int>& color, int currColor) {
        color[u] = currColor;
        queue<int> q;
        q.push(u);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int &v : graph[u]) {
                if(color[v] == color[u]) {
                    return false;
                }
                else if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        // Let green = 1 and red = 0
        for(int i =0; i<n; i++) {
            if(color[i] == -1 && checkBipartiteBFS(graph, i, color, 1) == false) {
                return false;
            }
        }
        return true;
    }
};