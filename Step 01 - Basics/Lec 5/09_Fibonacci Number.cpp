// Question Link :- https://leetcode.com/problems/fibonacci-number/
// Fibonacci Number

// Recursion
// T.C = O(2^n)
// S.C = O(n)
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) {
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};



// Memoization
// T.C = O(n) Each Fibonacci number is computed once
// S.C = O(n)
class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n<=1) {
            return n;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int fib(int n) {
        if(n <= 1) {
            return n;
        }
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};




// Tabulation
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }
        int dp[n+1];   // dp[i] = ith Fibonacci Number
        
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};



// Space Optimized Tabulation
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int fib(int n) {
        if( n<=1) {
            return n;
        }
        int c;
        int a = 0, b = 1;
        for(int i = 2; i<=n; i++) {
            c = a+b;
            a = b;
            b = c;    
        }
        return c;
    }
};