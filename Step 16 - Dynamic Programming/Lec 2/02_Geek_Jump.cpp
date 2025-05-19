// Question Link :- https://www.geeksforgeeks.org/problems/geek-jump/1
// Geek Jump


// Approach - 1 (Memoization)
// T.C = O(N)
// S.C = O(N) + O(N) [for recursion stack and array]
class Solution {
  public:
    int solve(int ind, vector<int>& height, vector<int>& dp) {
        if(ind == 0) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        int jumpOne = solve(ind-1, height, dp) + abs(height[ind] - height[ind-1]);

        int jumpTwo = INT_MAX;
        
        if(ind > 1) {
            jumpTwo = solve(ind-2, height, dp)+ abs(height[ind] - height[ind-2]);
        }
        return dp[ind] = min(jumpOne, jumpTwo);
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, -1);
        return solve(n-1, height, dp);
    }
};



// Approach - 2 (Tabulation)
// T.C = O(N)
// S.C = O(N)
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i = 1; i<=n; i++) {
            int jumpOne = dp[i-1] + abs(height[i] - height[i-1]);
            
            int jumpTwo = INT_MAX;
            if(i > 1) {
                jumpTwo = dp[i-2] + abs(height[i] - height [i-2]);
            }
            dp[i] = min(jumpOne, jumpTwo);
        }
        return dp[n-1];
    }
};



// Approach - 3 (Space Optimisation)
// T.C = O(N)
// S.C = O(1)
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int prev1 = 0;
        int prev2 = 0;
        for(int i=1; i<n; i++) {
            int jumpTwo = INT_MAX;
            int jumpOne= prev1 + abs(height[i] - height[i-1]);
            if(i>1) {
               jumpTwo = prev2 + abs(height[i] - height[i-2]);
            }
            int curr_i = min(jumpOne, jumpTwo);
            prev2 = prev1;
            prev1 = curr_i;
            
        }
        return prev1;
    }
};