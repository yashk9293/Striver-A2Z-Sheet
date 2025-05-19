// Question Link :- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Detect cycle in an undirected graph using BFS

// T.C = O(V+E)
// S.C = O(V)
class Solution {
  public:
    bool isCyclicBFS(vector<int> adj[], int u, vector<bool>& visited) {
        queue<pair<int, int>> que;
        que.push({u, -1});
        visited[u] = true;
        while(!que.empty()) {
            pair<int, int> P = que.front();
            que.pop();
            int source = P.first;
            int parent = P.second;
            for(int &v : adj[source]) {
                if(visited[v] == false) {
                    visited[v] = true;
                    que.push({v, source});  // {node, parent}
                } else if(v != parent) {  // visited hai aur parent nhi hai
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) {
            if(!visited[i] && isCyclicBFS(adj, i, visited)) {
                return true;
            }
        }
        return false;
    }
};



/*
The condition if (!visited[i] && isCyclicBFS(adj, i, visited)) inside the isCycle function ensures 
that we only start a BFS traversal from an unvisited node. This is important because:

Handling Disconnected Graphs:-
A graph may have multiple connected components. If we don’t check !visited[i], we might not explore 
all components, and a cycle in an unvisited component could go undetected.

Preventing Redundant BFS Calls:-
If we have already visited a node in a previous BFS traversal, there's no need to check it again. The
visited array ensures that we do not restart a BFS from the same node unnecessarily, improving efficiency.

*/