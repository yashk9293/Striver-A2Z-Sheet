// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Best Time to Buy and Sell Stock

// Brute Force
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] > prices[i]) {
                maxProfit = max(prices[j] - prices[i], maxProfit);
                }
            }
        }
        return maxProfit;
    }
};




// Optimal Solution
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = i+1;
        int maxProfit = 0;
        while(j < prices.size()) {
            if(prices[i] < prices[j]) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            } else {
                i = j;
            }
            j++;
        }
        return maxProfit;
    }
};