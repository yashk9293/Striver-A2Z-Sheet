// Question Link :- https://leetcode.com/problems/max-consecutive-ones/
// Max Consecutive Ones


// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                cnt++;
            } else {
                cnt = 0;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};