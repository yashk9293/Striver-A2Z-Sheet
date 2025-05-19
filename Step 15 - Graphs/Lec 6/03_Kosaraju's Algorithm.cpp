// Question Link :- https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// Strongly Connected Components (Kosaraju's Algo) MIK

// T.C = O(V+E) + O(V+E) + O(V+E) ~ O(V+E) 
// S.C = O(V) + O(V) + O(V+E)
class Solution {
	public:
	void topoSort(int u, vector<vector<int>>& adj, vector<bool> &visited, stack<int>& st) {
	    visited[u] = true;
	    for(int &v : adj[u]) {
	        if(!visited[v]) {
	            topoSort(v, adj, visited, st);
	        }
	    }
	    st.push(u);
	}
	
	void dfsTraverse(int u, vector<vector<int>>& adjReversed, vector<bool> &visited) {
	    visited[u] = true;
	    for(int &v : adjReversed[u]) {
	        if(!visited[v]) {
	            dfsTraverse(v, adjReversed, visited);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        // Step 1 : Store order of dfs in the stack (Topo Sort)
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                topoSort(i, adj, visited, st);
            }
        }
            
        // Step 2 : Make a reversed graph
        vector<vector<int>> adjReversed(V);
        for(int u = 0; u<V; u++) {
            for(int &v : adj[u]) {
                adjReversed[v].push_back(u);
            }   
        }
        
        // Step 3 : Call dfs based on stack order
        int count = 0;
        visited = vector<bool>(V, false);
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!visited[node]) {
                dfsTraverse(node, adjReversed, visited);
                count++;
            }
        }
        return count;
    }
};