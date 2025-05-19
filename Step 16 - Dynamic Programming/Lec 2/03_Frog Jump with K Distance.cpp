// Question Link :- https://www.geeksforgeeks.org/problems/minimal-cost/1
// Frog Jump with K Distance

// Approach - 1 (Memoization)
// T.C = O(N*K)
// S.C = O(N)
class Solution {
  public:
    int solve(vector<int>& arr, int i, vector<int>& dp, int k) {
        if(i == 0) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int minCost = INT_MAX;
        for(int j=1; j<=k; j++) {
            if (i >= j) {
                int cost = solve(arr, i-j, dp, k) + abs(arr[i] - arr[i - j]);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
    
    int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, n-1, dp, k);
    }
};




// Approach - 2 (Tabulation)
// T.C = O(N*K)
// S.C = O(N)
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i=1; i<n; i++) {  // Loop through the array to fill in the dp array
            int minCost = INT_MAX;
            for (int j=1; j<=k; j++) {   // Loop to try all possible jumps from '1' to 'k'
                if (i >= j) {
                    int cost = dp[i-j] + abs(arr[i] - arr[i-j]);
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[n-1];
    }
};