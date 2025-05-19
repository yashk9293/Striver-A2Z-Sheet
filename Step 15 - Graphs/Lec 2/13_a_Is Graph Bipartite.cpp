// Question Link :- https://leetcode.com/problems/is-graph-bipartite/
// Is Graph Bipartite?

// odd cycle are only non-bipartite graph

// DFS
class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph, int u, vector<int>& color, int currColor) {
        color[u] = currColor;
        for(int &v : graph[u]) {
            if(color[v] == color[u]) {
                return false;
            }
            if(color[v] == -1) {  // never coloured
                if(checkBipartiteDFS(graph, v, color, 1-currColor) == false) {  // 1-currColor is the color to node v
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // visited ka kaam kar rha 'color' vector
        // Let green = 1 and red = 0
        for(int i=0; i<n; i++) {
            if(color[i] == -1 && checkBipartiteDFS(graph, i, color, 1) == false) {
                return false;
            }
        }
        return true;
    }
};