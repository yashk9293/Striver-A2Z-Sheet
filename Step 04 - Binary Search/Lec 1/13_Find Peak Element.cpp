// Question Link :- https://leetcode.com/problems/find-peak-element/description/
// Find Peak Element


// T.C = O(logn)
// S.C = O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;

        while(s<e){
            if(nums[mid] < nums[mid+1]) {
                s = mid+1;
            } else {
                e = mid;
            }
            mid = s+(e-s)/2;
        }
        return mid;
    }
};



// OR [preferred]
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(mid + 1 < n && nums[mid] < nums[mid+1]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return l;
    }
};