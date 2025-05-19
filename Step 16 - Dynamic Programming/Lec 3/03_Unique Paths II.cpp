// Question Link :- https://leetcode.com/problems/unique-paths-ii
// Unique Paths II


// Recursion
// T.C = O(2^(mn))
// S.C - O(n)
class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid) {
        if(i >= m || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }
        if(i == m-1 && j == n-1) {
            return 1;
        }
        return countPaths(i+1, j, m, n, obstacleGrid) + countPaths(i, j+1, m, n, obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return countPaths(0, 0, m, n, obstacleGrid);
    }
};




// Memoization
// T.C =  O(M*N)
// S.C =  O((N-1)+(M-1)) + O(M*N)
class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp) {
        if(i >= m || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = countPaths(i+1, j, m, n, obstacleGrid, dp) + countPaths(i, j+1, m, n, obstacleGrid, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return countPaths(0, 0, m, n, obstacleGrid, dp);
    }
};




// Tabulation
// T.C = O(M*N)
// S.C = O(M*N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));      // dp[i][j] = total ways to reach at [i][j]
        
        // dp[i][j] = 0 means we can't reach at [i][j]
        // dp[i][j] = 1 means we can reach at [i][j]

        // if we found an obstacle at [0][i], then we can't reach at the cells after that cell
        for(int i=0; i<n; i++) {
            if(obstacleGrid[0][i] == 0) {
                dp[0][i] = 1;
            } else {
                break;
            }
        }

        // if we found an obstacle at [j][0], then we can't reach at the cells after that cell
        for(int j=0; j<m; j++) {
            if(obstacleGrid[j][0] == 0) {
                dp[j][0] = 1;
            } else {
                break;
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};