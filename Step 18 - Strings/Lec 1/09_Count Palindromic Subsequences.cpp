// Question Link :- https://www.geeksforgeeks.org/problems/count-palindromic-subsequences/1
// Count Palindromic Subsequences
// Video Link :- https://youtu.be/YHSjvswCXC8

// T.C = O(n^2)
// S.C = O(n^2)
class Solution {
    public:
    long long int const MOD = 1000000007;

    int solve(int i, int j, string &s, vector<vector<long long int>>&dp){
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i==j) {    // single character strings
            return dp[i][j] = 1;
        }
        if(s[i] == s[j]) {
            return dp[i][j]= (1 + solve(i+1, j, s, dp) + solve(i, j-1, s, dp)) % MOD;
        }
        else {
            return dp[i][j] = (solve(i+1, j, s, dp) + solve(i, j-1, s, dp) - solve(i+1, j-1, s, dp) + MOD) % MOD;
        }
    }
    
    long long int countPS(string str) {
       int n = str.length();
       vector<vector<long long int>>dp(n, vector<long long int>(n, -1));
       return solve(0, n-1, str, dp);
    }
};


/* In modular arithmetic, we need all numbers to be non-negative before applying the modulo operation. By 
adding MOD, you ensure that the result is non-negative.

After adding MOD, taking % MOD brings the number back within the desired range of 0 to MOD-1.   
*/