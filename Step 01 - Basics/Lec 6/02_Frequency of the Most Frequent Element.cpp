// Question Link :- https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Frequency of the Most Frequent Element


// Brute Force (giving TLE)
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());  // descending order
        int ans = 0;
        for(int i=0; i<n-1; i++) {
            int operations = k;
            int cnt = 1;
            for(int j=i+1; j<n; j++) {
                if(nums[i] - nums[j] <= operations) {
                    cnt++;
                    operations -= nums[i] - nums[j];
                } else {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};



// Optimal Solution
// T.C = O(nlogn)
// S.C = O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int result = 0;
        int i = 0;
        long currSum = 0;
        for(int j=0; j<nums.size(); j++) {
            currSum += nums[j];
            if((long)(j-i+1)*nums[j] - currSum > k) { // (j-i+1)*nums[j] = window sum
                currSum -= nums[i];                   // long is necessary as it big no. was multiplied
                i++;
            }
            result = max(result, j-i+1);
        }
        return result;
    }
};