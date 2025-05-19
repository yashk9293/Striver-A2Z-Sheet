// Question Link - https://leetcode.com/problems/subarray-sum-equals-k/
// Leetcode 560 - Total number of subarrays whose sum equals to k

// Leetcode 930. Binary Subarrays With Sum (same code used in this question)


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



// Optimal Solution
// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;  // {sum, frequency}
        int sum=0, cnt=0;

        mp[0] = 1;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            int remain = sum - k;
            if(mp.find(remain) != mp.end()){
                cnt += mp[remain];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
