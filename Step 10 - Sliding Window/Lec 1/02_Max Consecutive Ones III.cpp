// Question Link :- https://leetcode.com/problems/max-consecutive-ones-iii/
// Max Consecutive Ones III
// The question becomes longest subarray with at most K zeros..


// Brute Force
// T.C = O(N^2)
// S.C = O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size() ;
        int ans=0 ;
        int zeroCnt=0 ;
        for(int i=0; i<n; i++) {   
            zeroCnt=0 ;
            for(int j=i; j<n; j++) {
                if(nums[j]==0) {
                    zeroCnt++ ;
                }
                if(zeroCnt <= k) {
                    ans = max(ans, j-i+1) ;
                } else {
                    break ;
                }
            }
        }
        return ans;
    }
};





// Optimal Solution
// T.C = O(N) + O(N) = O(2N)
// S.C = O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeroCount = 0;
        int ans = 0;
        while(r < nums.size()) {
            if(nums[r] == 0) {
                zeroCount++;
            }
            while(zeroCount > k) {   // here while loop traverse n in small parts throughout the whole loop
                if(nums[l] == 0) {
                    zeroCount--;
                }
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};








// Little bit optimised
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeroCount = 0;
        int ans = 0;
        while(r < nums.size()) {
            if(nums[r] == 0) {
                zeroCount++;
            }
            if(zeroCount > k) {    // modification 1 - if in place of while
                if(nums[l] == 0) {
                    zeroCount--;
                }
                l++;
            }
            if(zeroCount <= k) {   // modification 2
                ans = max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};