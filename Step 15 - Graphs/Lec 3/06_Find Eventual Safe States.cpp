// Question Link :- https://leetcode.com/problems/find-eventual-safe-states/
// Find Eventual Safe States

// Approach - 1 (Check cycle - topo sort BFS) [Preferred]
// T.C = O(VlogV + E)
// S.C = O(V + E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);  // reversed graph
        for(int u = 0; u<V; u++) {
	        for(int &v : graph[u]) {
	            adj[v].push_back(u); // push in reverse direction
	        }
	    }

        // Now perform cycle detection (topo sort BFS)
        queue<int> que;
	    vector<int> indegree(V, 0);
	    //1. finding indegree of each node
	    for(int u = 0; u<V; u++) {
	        for(int &v : adj[u]) {
	            indegree[v]++;
	        }
	    }
	    //2. Fill que, indegree with 0
	    for(int i = 0; i<V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	        }
	    }
	    //3. Simple BFS
	    vector<int> result;
	    while(!que.empty()) {
	        int u = que.front();
	        result.push_back(u);
	        que.pop();
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            if(indegree[v] == 0) {
	                que.push(v);
	            }
	        }
	    }
        sort(begin(result), end(result));
        return result;
    }
};




// Approach - 2 (Cycle detection DFS)
// T.C = O(V + E)
// S.C = O(V)
class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion)) {
                return true;
            }
            else if(inRecursion[v] == true) {  // visited[v] == true
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                isCycleDFS(graph, i, visited, inRecursion);
            }
        }
        vector<int> safeNodes;
        for(int i = 0; i<V; i++) {
            if(inRecursion[i] == false) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};