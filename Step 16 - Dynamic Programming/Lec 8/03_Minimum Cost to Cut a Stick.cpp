// Question Link :- https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// Minimum Cost to Cut a Stick

// Recursion [TLE]
// T.C = O(2^n)
// S.C = O(n)
class Solution {
public:
    int solve(int i, int j, vector<int>& cuts) {
        if (i > j) {
            return 0;
        }
        int cost = INT_MAX;
        for (int k = i; k <= j; k++) {
            int temp = (cuts[j + 1] - cuts[i - 1]) + solve(i, k - 1, cuts) + solve(k + 1, j, cuts);
            cost = min(cost, temp);
        }
        return cost;
    }

    int minCost(int n, vector<int>& cuts) {
        // Add boundaries to cuts
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        return solve(1, cuts.size() - 2, cuts);
    }
};




// Memoization
// T.C = O(mlogm + m^3)
// There are O(m^2) unique subproblems (because i and j can range from 0 to m-1). For each subproblem, the
// function tries all possible k values between i and j (inclusive), making O(m) recursive calls for each subproblem.

// S.C = O(m^2)
class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& t) {
        if (i > j) {
            return 0;
        }
        if(t[i][j] != -1) {
            return t[i][j];
        }
        int cost = INT_MAX;
        for (int k = i; k <= j; k++) {
            int temp = (cuts[j + 1] - cuts[i - 1]) + solve(i, k - 1, cuts, t) + solve(k + 1, j, cuts, t);
            cost = min(cost, temp);
        }
        return t[i][j] = cost;
    }

    int minCost(int n, vector<int>& cuts) {
        // Add boundaries to cuts
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> t(m, vector<int>(m, -1));
        
        return solve(1, cuts.size() - 2, cuts, t);
    }
};