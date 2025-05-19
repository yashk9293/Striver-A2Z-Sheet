// Question Link - https://leetcode.com/problems/merge-sorted-array/
// Merge Sorted Array


// T.C = O(m+n)
// S.C = O(m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i=0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) {
            temp.push_back(nums1[i]);
            i++;
        }
        while(j < n) {
            temp.push_back(nums2[j]);
            j++;
        }
        for(int i=0; i<m+n; i++) {
            nums1[i] = temp[i];
        }
    }
};




// T.C = O(m+n)
// S.C = O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--; k--;
            }
            else {
                nums1[k] = nums2[j];
                j--; k--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
};