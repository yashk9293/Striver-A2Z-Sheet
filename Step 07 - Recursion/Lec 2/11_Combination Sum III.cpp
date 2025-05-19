// Question Link :- https://leetcode.com/problems/combination-sum-iii/
// Combination Sum III


// T.C = O(2^9)
// S.C = O(k) + O(C(9, k))
class Solution {
public:
    void solve(int i, int k, int n, vector<int>& temp, vector<vector<int>>& ans) {
        if(i > 10) {
            return ;
        }

        if(k == 0 && n == 0){
            ans.push_back(temp);
            return ;
        }

        // exclude
        solve(i+1, k, n, temp, ans);

        // include
        temp.push_back(i);
        solve(i+1, k-1, n-i, temp, ans);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(1, k, n, temp, ans);
        return ans;
    }
};




// T.C = O(2^9)
// S.C = O(k) + O(C(9, k)) + extra nums vector
class Solution {
public:
    void solve(int i, int k, int n, vector<int>& temp, vector<vector<int>>& ans, vector<int>&nums) {
        if(k == 0 && n == 0){
            ans.push_back(temp);
            return ;
        }
        if(k < 0 || n < 0 || i >= nums.size()) {
            return;
        }

        // exclude
        solve(i+1, k, n, temp, ans, nums);

        // include
        temp.push_back(nums[i]);
        solve(i+1, k-1, n-nums[i], temp, ans, nums);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, k, n, temp, ans, nums);
        return ans;
    }
};