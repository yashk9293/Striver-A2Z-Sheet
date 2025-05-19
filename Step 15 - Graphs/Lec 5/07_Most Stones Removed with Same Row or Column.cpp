// Question Link :- https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Most Stones Removed with Same Row or Column


// Approach - 1 (using DFS) [Preferred]
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    int n ;
    void dfs(vector<vector<int>>& stones, int u, vector<bool>& visited) {
        visited[u] = true;
        for(int i = 0; i<n; i++) {
            if(!visited[i] && ((stones[i][0] == stones[u][0]) || (stones[i][1] == stones[u][1]))) {
                dfs(stones, i, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> visited(n, false);

        int cntGroups = 0;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                dfs(stones, i, visited);
                cntGroups++;
            }
        }
        return n - cntGroups;
    }
};





// Approach - 2 (using DSU)
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent != y_parent) {
            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }
            }
        }
        int groups = 0;
        for(int i = 0; i<n; i++) {
            if(parent[i] == i) {
                groups++;
            }
        }
        return n-groups;
    }
};