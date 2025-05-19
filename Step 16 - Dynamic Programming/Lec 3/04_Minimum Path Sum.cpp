// Question Link :- https://leetcode.com/problems/minimum-path-sum
// Minimum Path Sum


// Recursion
// T.C = O(2^(mn))
// S.C - O(mn)
class Solution {
public:
    int func(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if(i >= m || j >= n) {
            return 1e8;
        }
        if(i == m-1 && j == n-1) {
            return grid[i][j];
        }
        return grid[i][j] + min(func(i+1, j, m, n, grid), func(i, j+1, m, n, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return func(0, 0, m, n, grid);
    }
};




// Memoization
// T.C =  O(mn)
// S.C =  O((n-1)+(m-1)) + O(mn) -> recursion stack + dp
class Solution {
public:
    int func(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i >= m || j >= n) {
            return 1e8;
        }
        if(i == m-1 && j == n-1) {
            return grid[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = grid[i][j] + min(func(i+1, j, m, n, grid, dp), func(i, j+1, m, n, grid, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(0, 0, m, n, grid, dp);
    }
};




// Tabulation
// T.C = O(mn)
// S.C = O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j != 0) {
                    grid[i][j] += grid[i][j-1];
                }
                if(i != 0 && j == 0) {
                    grid[i][j] += grid[i-1][j];
                }
                if (i != 0 && j != 0) {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }
        return grid[m-1][n-1];
    }
};