// Question Link :- https://www.geeksforgeeks.org/problems/geeks-training/1
// Ninjas's Training

// T.C = O(3n)
// S.C = O(3n)
class Solution {
  public:
    int func(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
        if (dp[day][last] != -1) {
            return dp[day][last];
        }
        
        if (day == 0) {
            int maxPoints_dayZero = 0;
            // Calculate the maximum points for the first day by choosing an activity different from the last one
            for (int i = 0; i <= 2; i++) {
                if (i != last)
                maxPoints_dayZero = max(maxPoints_dayZero, points[0][i]);
            }
            return dp[day][last] = maxPoints_dayZero;
        }
    
        int maxi = 0;

        for (int i = 0; i <= 2; i++) {      // Iterate through the activities for the current day
            if (i != last) {
                int activity = points[day][i] + func(day - 1, i, points, dp);
                maxi = max(maxi, activity);
            }
        }
        return dp[day][last] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Create a dp array of size [n][4]. There are total ‘n’ days and for every day, there can be 4 choices (0,1,2 and 3). Therefore we take the dp array as dp[n][4].
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        // Start the recursive calculation from the last day with no previous activity
        return func(n - 1, 3, points, dp);
    }
};





// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    int dp[100001][3];
    int solve(int day, vector<vector<int>>& points, int choice) {
        if(day == points.size()) {
            return 0;
        }
        if(dp[day][choice] != -1) {
            return dp[day][choice];
        }
        if(choice == 0){
            return dp[day][choice] = points[day][choice] + max(solve(day + 1, points, 1), solve(day + 1, points, 2));
        }
        else if(choice == 1){
            return dp[day][choice] = points[day][choice] + max(solve(day + 1, points, 0), solve(day + 1, points, 2));
        }
        else if(choice == 2){
            return dp[day][choice] = points[day][choice] + max(solve(day + 1, points, 0), solve(day + 1, points, 1));
        }
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        memset(dp, -1, sizeof(dp));
        int x = solve(0, points, 0);
        int y = solve(0, points, 1);
        int z = solve(0, points, 2);
        return max({x, y, z});
    }
};
