// Question Link :- https://www.geeksforgeeks.org/problems/geeks-training/1
// Ninjas's Training

// T.C = O(3n)
// S.C = O(3n)
class Solution {
  public:
    int solve(vector<vector<int>>& arr, vector<vector<int>>& dp, int day, int last) {
        if(dp[day][last] != -1) {
            return dp[day][last];
        }
        
        if(day == 0) {
            int dayZero_maxi = INT_MIN;
            // Calculate the maximum points for the first day by choosing an activity different from the last one
            for(int i=0; i<=2; i++) {
                if(i != last) {
                    dayZero_maxi = max(dayZero_maxi, arr[day][i]);
                }
            }
            return dp[day][last] = dayZero_maxi;
        }
        
        int maxi = INT_MIN;
        for(int i=0; i<=2; i++) {     // Iterate through the activities for the current day
            if(i != last) {
                int points = arr[day][i] + solve(arr, dp, day-1, i);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Create a dp array of size [n][4]. There are total ‘n’ days and for every day, there can be 4 choices (0,1,2 and 3). Therefore we take the dp array as dp[n][4].
        vector<vector<int>> dp(n+1, vector<int>(4, -1));
        
        // Start the recursive calculation from the last day with no previous activity
        return solve(arr, dp, n-1, 3);
    }
};





// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    int dp[100001][3];
    int solve(int day, vector<vector<int>>& arr, int choice) {
        if(day == arr.size()) {
            return 0;
        }
        if(dp[day][choice] != -1) {
            return dp[day][choice];
        }
        if(choice == 0){
            return dp[day][choice] = arr[day][choice] + max(solve(day + 1, arr, 1), solve(day + 1, arr, 2));
        }
        else if(choice == 1){
            return dp[day][choice] = arr[day][choice] + max(solve(day + 1, arr, 0), solve(day + 1, arr, 2));
        }
        else if(choice == 2){
            return dp[day][choice] = arr[day][choice] + max(solve(day + 1, arr, 0), solve(day + 1, arr, 1));
        }
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
        memset(dp, -1, sizeof(dp));
        int x = solve(0, arr, 0);
        int y = solve(0, arr, 1);
        int z = solve(0, arr, 2);
        return max({x, y, z});
    }
};