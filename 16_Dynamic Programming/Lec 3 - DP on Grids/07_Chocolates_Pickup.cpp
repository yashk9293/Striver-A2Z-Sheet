// Question Link :- https://www.geeksforgeeks.org/problems/chocolates-pickup/1
// Chocolates Pickup

// Recursion
// T.C = O(9^N * M*M)
// S.C = O(1)
class Solution {
  public:
    int func(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid) {
        if(j1<0 || j1>= m || j2<0 || j2>= m || i >= n) {
            return 0;
        }
        if(j1 == j2) {
            return grid[i][j1];
        }
        int maxi = INT_MIN;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int ans = grid[i][j1] + grid[i][j2] + func(i+1, j1+dj1, j2+dj2, n, m, grid);
                maxi = max(maxi, ans);
            }
        }
        return maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        return func(0, 0, m-1, n, m, grid);  // (i, j1, j2, n, m, grid, dp)
    }
};


// T.C = O(N*M*M) * 9
// S.C = O(N) + O(N*M*M) -> recursion stack + dp
class Solution {
  public:
    int func(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(j1<0 || j1>= m || j2<0 || j2>= m || i >= n) {
            return 0;
        }
        if(j1 == j2) {
            return grid[i][j1];
        }
        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        int maxi = INT_MIN;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int ans = grid[i][j1] + grid[i][j2] + func(i+1, j1+dj1, j2+dj2, n, m, grid, dp);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return func(0, 0, m-1, n, m, grid, dp);  // (i, j1, j2, n, m, grid, dp)
    }
};