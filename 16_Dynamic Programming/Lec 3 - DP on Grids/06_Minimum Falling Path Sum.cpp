// Question Link :- https://leetcode.com/problems/minimum-falling-path-sum
// Minimum Falling Path Sum (Striver Sheet, own)

// Memoization
// T.C = O(n*n)
// S.C = O(n*n)
class Solution {
public:
    int func(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i >= n || j<0 || j >= n) {
            return 1e8;
        }
        if(i == n-1) {
            return matrix[i][j];
        }
        if(dp[i][j] != INT_MIN) {    // why INT_MIN; because -1 can conflict if matrix can contain -1 as valid values, because it contains negative values.
            return dp[i][j];
        }
        return dp[i][j] = matrix[i][j] + min({func(i+1, j-1, n, matrix, dp), func(i+1, j, n, matrix, dp), func(i+1, j+1, n, matrix, dp)});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));   // //WHY INT_MIN;because -1 can conflict if matrix can contain -1 as valid values.because it contains negative values.

        int minPathSum = INT_MAX;
        for (int j = 0; j < n; j++) {     // we can start from any column
            minPathSum = min(minPathSum, func(0, j, n, matrix, dp));
        }
        return minPathSum;
    }
};