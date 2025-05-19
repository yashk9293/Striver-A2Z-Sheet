// Question Link :- https://leetcode.com/problems/largest-divisible-subset/
// Largest Divisible Subset


// Recursion (giving TLE - 47/49)
// T.C = O(2^n)
// S.C = O(n)
class Solution {
public:
    void generate(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {
        if(idx >= nums.size()) {
            if(temp.size() > result.size()) {
                result = temp;
            }
            return;
        }
        if(prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            generate(idx+1, nums, result, temp, nums[idx]);   // prev changes to nums[idx]
            temp.pop_back();
        }
        generate(idx+1, nums, result, temp, prev);   // prev remains same
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> result;
        vector<int> temp;  // for populating current elements
        generate(0, nums, result, temp, -1);
        
        return result;
    }
};




// Memoization is bit complex here
// which is also giving TLE




// Tabulation
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int lastIdx = 0;
        int maxL = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j] + 1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        lastIdx = i;
                    }
                }
            }
        }
        vector<int> result;
        while(lastIdx >= 0) {
            result.push_back(nums[lastIdx]);
            lastIdx = prev_idx[lastIdx];
        }
        return result;
    }
};
