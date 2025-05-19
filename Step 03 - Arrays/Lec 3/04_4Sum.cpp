// Question Link - https://leetcode.com/problems/4sum/
// 4Sum


// Brute Force
// T.C = O(N^4 * log k)  (where k is the number of unique quadruplets)
// k can be at max(N^4) so overall T.C = O(N^4 logN)
// S.C = O(2 * no. of quad)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        // taking bigger data type to avoid integer overflow:
                        long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};




// Better Approach
// T.C = O(N^3 logN)
// S.C =O(2 * no. of quad)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> mpp;  // important to write long long here, otherwise it will give wrong answer.
                for (int k = j + 1; k < n; k++) {
                    long long fourth = target - (1LL* nums[i] + nums[j] + nums[k]);
                    if (mpp.find(fourth) != mpp.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    // put the kth element into the mpp:
                    mpp.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};







// Optimal Solution
// T.C = O(N^3)
// S.C =O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            // avoid the duplicates while moving i:
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                // avoid the duplicates while moving j:
                if (j-1 > i && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        //skip the duplicates:
                        while (k < l && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};