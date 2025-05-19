// Question Link - https://leetcode.com/problems/majority-element-ii/description/
// Majority Element II


// Brute Force
// T.C = O(n^3)
// S.C = O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (ans.size() == 0 || ans[0] != nums[i]) {  // to avoid duplicates, for eg. nums=[1,1,1,2,2,3,3,3]
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (nums[j] == nums[i]) {
                        count++;
                    }
                }
                if (count > n / 3) {
                    ans.push_back(nums[i]);
                }
            }
            if (ans.size() == 2) {
                break;
            }
        }
        return ans;
    }
};




// Better Approach
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        for(auto &it : mpp) {
            if(it.second > n/3) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};






// Optimal Solution (Boyer Moore Voting Algorithm)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int maj1 = NULL, maj2 = NULL;

        for(int i = 0; i<n; i++) {
            if(nums[i] == maj1) {
                cnt1++;
            } else if(nums[i] == maj2) {
                cnt2++;
            } else if(cnt1 == 0) {
                cnt1 = 1;
                maj1 = nums[i];
            } else if(cnt2 == 0) {
                cnt2 = 1;
                maj2 = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> result;   // because atmost two elements can occur more than ⌊ n/3 ⌋ in an array of length n
        int maj1_cnt = 0, maj2_cnt = 0;
        for(int num : nums) {
            if(num == maj1) {
                maj1_cnt++;
            } else if(num == maj2) {
                maj2_cnt++;
            }
        }

        if(maj1_cnt > n/3) {
            result.push_back(maj1);
        }
        if(maj2_cnt > n/3) {
            result.push_back(maj2);
        }

        return result;
    }
};
