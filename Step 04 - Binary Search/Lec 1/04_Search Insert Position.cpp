// Question Link :- https://leetcode.com/problems/search-insert-position
// Search Insert Position

// T.C = O(log n)
// S.C = O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        
        // find lower bound
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};