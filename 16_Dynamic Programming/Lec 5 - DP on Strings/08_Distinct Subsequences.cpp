// Question Link :- https://leetcode.com/problems/distinct-subsequences/
// Distinct Subsequences


// Recursion
// T.C = O(2^m * 2^n) ~ O(2^(m+n))
// S.C = O(m + n)
class Solution {
public:
    int solve(int i, int j, string& s, string& t) {
        if(j == t.size()) {
            return 1;
        }
        if(i == s.size()) {
            return 0;
        }
        int take = 0, skip = 0;
        if(s[i] == t[j]) {
            take = solve(i+1, j+1, s, t);
            skip = solve(i+1, j, s, t);
            return take + skip;
        } else {
            return solve(i+1, j, s, t);
        }
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        return solve(0, 0, s, t);
    }
};



// Memoization
// T.C = O(n*m)
// S.C = O(n*m) + O(n+m) -> 2d array + recursion stack
class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(j == t.size()) {
            return 1;
        }
        if(i == s.size()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = 0, skip = 0;
        if(s[i] == t[j]) {
            take = solve(i+1, j+1, s, t, dp);
            skip = solve(i+1, j, s, t, dp);
            return dp[i][j] = take + skip;
        } else {
            return dp[i][j] = solve(i+1, j, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, s, t, dp);
    }
};




// Memoization (top down)
// T.C = O(n*m)
// S.C = O(n*m) + O(n+m) -> 2d array + recursion stack
class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(j < 0) {
            return 1;
        }
        if(i < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int take = 0, skip = 0;
        if(s[i] == t[j]) {
            take = solve(i-1, j-1, s, t, dp);
            skip = solve(i-1, j, s, t, dp);
            return dp[i][j] = take + skip;
        } else {
            return dp[i][j] = solve(i-1, j, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, s, t, dp);
    }
};





// Tabulation
// T.C = O(m*n)
// S.C = O(m*n)
class Solution {
public:
    int MOD = 1e9+7;
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        // dp[i][j] stores no. of unique subsequences of t[0, ...j-1] from s[0, ...i-1]
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<=m; i++) {
            dp[i][0] = 1;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
                } else {
                    dp[i][j] = dp[i-1][j];
                }   
            }
        }
        return dp[m][n]%MOD;
    }
};




// Because dp[i][0] represents no. of unique subsequences of t = "" from s[0,..i-1]
// EXP: dp[1][0] represents no. of unique subsequences of t = "" from s[0]
// Since t = "" can be generated in 1 way from s[0], s[0,1], s[0,..2], s[0,..3]...

