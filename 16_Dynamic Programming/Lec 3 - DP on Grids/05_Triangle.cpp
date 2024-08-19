// Question Link :- https://leetcode.com/problems/triangle/
// Triangle

// Recursion
// T.C = O(2^m)
// S.C = O(m) -> recursion stack
class Solution {
public:
    int func(int i, int j, int m, vector<vector<int>>& triangle) {
        if(i >= m) {
            return 1e8;
        }
        if(i == m-1) {
            return triangle[i][j];
        }
        return triangle[i][j] + min(func(i+1, j, m, triangle), func(i+1, j+1, m, triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        return func(0, 0, m, triangle);
    }
};


// Memoization
// T.C = O(m*m)
// S.C = O(m*m)
class Solution {
public:
    int func(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i >= m) {
            return 1e8;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i == m-1) {
            return triangle[i][j];
        }
        return dp[i][j] = triangle[i][j] + min(func(i+1, j, m, triangle, dp), func(i+1, j+1, m, triangle, dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return func(0, 0, m, triangle, dp);
    }
};