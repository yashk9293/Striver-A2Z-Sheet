// Question Link :- https://leetcode.com/problems/wildcard-matching/description/
// Wildcard Matching


// T.C = O(n*m)
// S.C = O(n*m) + O(n+m) -> 2d dp array + recursion stack
class Solution {
public:
    bool solve(int m, int n, string& s, string& p, vector<vector<int>>& dp){
        if(m <= 0 && n <= 0) {     // both string exhausted
            return true;
        } 
        else if(m > 0 && n <= 0) {    // string p is exhausted
            return false;
        } 
        else if(m <= 0 && n > 0) {    // string s is exhausted
            // dekho yaha pe hoskta hai p = "***" ye ho ya fir p = "**b" aisa kuch ho sakta hai..to yaha pe loop chalana hoga
            for(int i=0; i<n; i++) {
                if(p[i] != '*') {
                    return false;
                }
            }
            return true;
        }
        
        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        if(s[m-1] == p[n-1] || p[n-1] == '?') {
            return dp[m][n] = solve(m - 1, n - 1, s, p, dp);
        }
        else if(p[n-1] == '*') {
            bool takeone = solve(m - 1, n, s, p, dp);
            bool takenull = solve(m, n - 1, s, p, dp);

            return dp[m][n] = takeone || takenull;
        }
        else {     // agar koi character s aur p me match nhi kiya to
            return dp[m][n] = false;
        }
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return solve(m, n, s, p, dp);
    }
};