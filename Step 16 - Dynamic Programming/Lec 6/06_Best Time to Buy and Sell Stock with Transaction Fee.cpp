// Question Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
// Best Time to Buy and Sell Stock with Transaction Fee


// Recursion
// T.C = O(2^n)
// S.C = O(n) -> recursion stack


// Memoization
// T.C = O(2n)  ->  There are N*2 states
// S.C = O(2n) + O(n)
class Solution {
public:
    int solve(int idx, bool buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        int profit;
        if(buy == 1) {
            // profit = max(take, skip);
            profit = max(-prices[idx] - fee + solve(idx+1, 0, prices, fee, dp), solve(idx+1, 1, prices, fee, dp));
        } else {  // sell
            profit = max(prices[idx] + solve(idx+1, 1, prices, fee, dp), solve(idx+1, 0, prices, fee, dp));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};





// Tabulation (not required)
// T.C = O(2n)
// S.C = O(2n)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for (int idx = n-1; idx >= 0; idx--) {
            for (int buy = 0; buy <=1; buy++) {
                if(buy == 1) {
                    dp[idx][buy] = max(-prices[idx] - fee + dp[idx+1][0], dp[idx+1][1]);
                } else {  // sell
                    dp[idx][buy] = max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};




// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0, hold = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            profit = max(profit, hold + prices[i] - fee);
            hold = max(hold, profit - prices[i]);
        }
        return profit;
    }
};
