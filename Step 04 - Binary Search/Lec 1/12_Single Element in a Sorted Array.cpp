// Question Link :- https://leetcode.com/problems/single-element-in-a-sorted-array/
// Single Element in a Sorted Array 

// Approach - 1
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorr = 0;
        for(int num : nums) {
            xorr = xorr ^ num;
        }
        return xorr;
    }
};




// Approach - 2 (binary search)
// T.C = O(logN)
// S.C = O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right)/2;
            // single element is not present till mid
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                left = mid + 1;
            } else {     // single element is passed as pattern is not matching
                right = mid;
            }
        }
        return nums[left];
    }
};