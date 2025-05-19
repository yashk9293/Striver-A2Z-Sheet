// Question Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Best Time to Buy and Sell Stock III

// (buy/sell at most 2)

// Recursion
// T.C = O(2^n)
// S.C = O(2*3*n) -> idx, buy, cap - states



// Memoization
// T.C = O(2*3*n)
// S.C = O(2*3*n) + O(n)
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};





// Optimal Solution
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice1 = INT_MAX, minPrice2 = INT_MAX;
        int profit1 = 0, profit2 = 0;
        for(int i = 0; i < prices.size(); i++){
            minPrice1 = min(minPrice1, prices[i]);
            profit1 = max(profit1, prices[i] - minPrice1);

            minPrice2 = min(minPrice2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - minPrice2);

        }
        return profit2;
    }
};
