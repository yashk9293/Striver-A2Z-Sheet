// Question Link :- https://leetcode.com/problems/count-square-submatrices-with-all-ones
// Count Square Submatrices with All Ones


// Brute Force :
// In order to solve this question, we will first try the brute force approach. In the brute force approach,
// we will just check for every cell(i, j)(if the cell contains 1) that if there exists a k-sized square 
// where k can range from 1 to min(n-i, m-j)(considering 0-based indexing).



// Memoization
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& t) {
        if (i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        if (grid[i][j] == 0) {
            return 0;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        // Right
        int right = solve(i, j + 1, grid, t);
        // Diagonal
        int diagonal = solve(i + 1, j + 1, grid, t);
        // Below
        int below = solve(i + 1, j, grid, t);

        return t[i][j] = 1 + min({right, diagonal, below});
    }

    int countSquares(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                result += solve(i, j, grid, t);
            }
        }
        return result;
    }
};





// Optimised Approach DP
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }
};