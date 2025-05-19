// Question Link :- https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Search in Rotated Sorted Array II

// Test Case Dry run -> {3 3 1 3 3 3 3} or {1 1 1 2 1 1}

// T.C = O(logN) - average
//     = O(N) - worst (for skipping duplicate element)
// S.C = O(1)
class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            if(l < r && nums[l] == nums[l+1]) {    // modification 1
                l++;
                continue;
            }
            if(l < r && nums[r] == nums[r-1]) {    // modification 2
                r--;
                continue;
            }
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    bool binary_search(vector<int>& nums, int l, int r, int target) {
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = find_pivot(nums, 0, n-1);
        if(nums[pivot] == target) {
            return true;
        }
        if( target >= nums[pivot] && target <= nums[n-1]) {
            return binary_search(nums, pivot, n-1, target);   //BS on second line
        } else { 
            return binary_search(nums, 0, pivot - 1, target);  //BS on first line
        }
    }
};