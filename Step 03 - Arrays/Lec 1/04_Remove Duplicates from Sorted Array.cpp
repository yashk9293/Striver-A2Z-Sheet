// Question Link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Remove Duplicates from Sorted Array

// Brute Force (using set)
// T.C = O(NlogN + N)
// S.C = O(N)



// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int i = 1;
        for(int j=1; j<nums.size(); j++) {
            if(nums[j] != nums[j-1]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};