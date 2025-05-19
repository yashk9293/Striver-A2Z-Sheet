// Question Link :- https://leetcode.com/problems/binary-subarrays-with-sum/
// 930. Binary Subarrays With Sum


// Brute Force
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0 ; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


// same code of Leetcode 560.
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int, int> mpp;
        int sum = 0, cnt = 0;

        mpp[0] = 1; // it has a important significance
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remove = sum - goal;
            cnt += mpp[remove];
            // Update the count of prefix sum in the map.
            mpp[sum]++;
        }
        return cnt;
    }
};




// Optimal Solution (Using Sliding Window)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0, int count = 0, window_sum = 0;
        int prefix_zeros = 0;
        while(j < nums.size()) {
            window_sum += nums[j];
            while (i < j && (nums[i] == 0 || window_sum > goal)) {
                if (nums[i] == 1) {
                    prefix_zeros = 0;
                } 
                else {
                    prefix_zeros += 1;
                }
                window_sum -= nums[i];
                i++;
            }
            if (window_sum == goal) {
                count += 1 + prefix_zeros;
            }
            j++;
        }
        return count;
    }
};