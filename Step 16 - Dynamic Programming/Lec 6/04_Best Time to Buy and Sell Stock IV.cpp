// Question Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
// Best Time to Buy and Sell Stock IV

// (buy/sell at most k times)

// Recursion
// T.C = O(2^(nk))
// S.C = O(2*n*k) -> idx, buy, cap - states



// Memoization
// T.C = O(2*n*k)
// S.C = O(2*n*k) + O(n)
class Solution {
public:
    int solve(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
        if (idx == prices.size() || cap == 0) {
            return 0;
        }
        if (dp[idx][buy][cap] != -1) {
            return dp[idx][buy][cap];
        }
        int profit;
        if (buy == 1) {
            profit = max(-prices[idx] + solve(idx+1, 0, cap, prices, dp), 0 + solve(idx+1, 1, cap, prices, dp));
        }
        else { // sell
            profit = max(prices[idx] + solve(idx+1, 1, cap-1, prices, dp), 0 + solve(idx+1, 0, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};





class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(k+1, 0)));
        for (int i = n-1; i >= 0; i--) {
            for (int buy=0; buy<=1; buy++) {
                for(int cap=1; cap <= k; cap++) {
                    if(buy == 1) {
                        dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
                    } else {  // sell
                        dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap-1], dp[i + 1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};