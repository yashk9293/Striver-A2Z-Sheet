// Question Link :- https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0
// Number of Distinct Islands


// T.C = O(4*n*m) ~ O(n*m)
// S.C = O(n*m)
class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int, int>>& vec, int start_idx_i, int start_idx_j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;

        vec.push_back({i - start_idx_i, j - start_idx_j});   // fir waha se jaha jaha index pe jayega usko base index se minus karwa ke set me daalte jaana
        
        dfs(i + 1, j, grid, vec, start_idx_i, start_idx_j, n, m);
        dfs(i, j + 1, grid, vec, start_idx_i, start_idx_j, n, m);
        dfs(i - 1, j, grid, vec, start_idx_i, start_idx_j, n, m);
        dfs(i, j - 1, grid, vec, start_idx_i, start_idx_j, n, m);
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> st;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {    // base index (i,j) (i.e., first index where grid[i][j] == 1)
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vec, i, j, n, m);
                    st.insert(vec);      // used set to avoid duplicate islands
                }
            }
        }
        return st.size();   // no. of distinct islands
    }
};

