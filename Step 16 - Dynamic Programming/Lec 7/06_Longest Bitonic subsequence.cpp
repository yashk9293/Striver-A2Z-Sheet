// Question Link :- https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// Same Question :- https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// Longest Bitonic subsequence


// Note in the video, striver did solved the problem on coding ninjas and problem statement is 
// slight different there, there in that ques, the array can be increasing only, can be decreasing
// only or can be both... But in GfG and Leetcode, the array can't be increasing only, can't be 
// decreasing only.


// T.C = O(n^2)
// S.C = O(n)
class Solution {
  public:
    // Compute LIS from left to right and LIS from right to left, then sum and subtract -1 because of overlapping
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1), dp2(n, 1);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
            }
        }
        for(int i = n-1; i>=0; i--) {
            for(int j = n-1; j>i; j--) {
                if(nums[j] < nums[i]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(dp1[i] == 1 || dp2[i] == 1) {     // condition for mountain structure
                continue;
            }
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        return maxi;
    }
};