// Question Link :- https://leetcode.com/problems/wildcard-matching/description/
// Wildcard Matching


// T.C = O(n*m)
// S.C = O(n*m) + O(n+m) -> 2d dp array + recursion stack
class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) {     // both string exhausted
            return true;
        }
        else if(j < 0 && i >= 0) {    // string p is exhausted
            return false;
        }
        // imp base case now
        else if(i < 0 && j >= 0) {    // string s is exhausted
        // dekho yaha pe hoskta hai p = "***" ye ho ya fir p = "**b" aisa kuch ho sakta hai..to yaha pe loop chalana hoga
            for(int k = 0; k <= j; k++){
                if(p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        else if(p[j] == '*'){
            bool takeone = solve(i - 1, j, s, p, dp);
            bool takenull = solve(i, j - 1, s, p, dp);

            return dp[i][j] = takeone || takenull;
        }
        else {     // agar koi character s aur p me match nhi kiya to
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, s, p, dp);
    }
};
