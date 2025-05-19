// Question Link :- https://leetcode.com/problems/longest-palindromic-subsequence/
// Longest Palindromic Subsequence

// Brute Force (TLE)
// find all subsequences and then check whether they are palindrome then output the longest
// palindrome subsequence.




// Memoization
// T.C = O(n^2)
// S.C = O(n^2)
class Solution {
public:
    int t[1001][1001];
    int LCS(string& X, string& Y, int n, int m) {
        // base case
        if (n == 0 || m == 0) {
            return 0;
        }
        if (t[n][m] != -1) {
            return t[n][m];
        }
        // choice diagram
        if (X[n - 1] == Y[m - 1]) {    // when last character is same
            t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);    // count the number and decreament the both's string length // store the value in particular block 
        } 
        else {   // when last character is not same -> pick max
            t[n][m] = max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1)); // one take full and another by leaving last char and vice versa // store the value in particular block 
        }
        return t[n][m];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t)); 
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end()); // take reversed string as another string of lcs and apply lcs 
        return LCS(s, rev_s, n, n);
    }
};





// Tabulation
// T.C = O(n^2)
// S.C = O(n^2)
class Solution {
public:
    int LCS(string X, string Y, int n, int m) {
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (X[i - 1] == Y[j - 1]) {    // when last character is same
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {    // when last character is not same -> pick max
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end()); // take reversed string as another string of lcs and apply lcs 
        return LCS(s, rev_s, n, n);
    }
};
