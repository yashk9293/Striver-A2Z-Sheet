// Question Link :- https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Rearrange Array Elements by Sign

// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int positive_idx = 0, negative_idx = 1;
        vector<int> temp(n);
        for(int &num : nums) {
            if(num >= 0) {
                temp[positive_idx] = num;
                positive_idx += 2;
            } else {
                temp[negative_idx] = num;
                negative_idx += 2;
            }
        }
        return temp;
    }
};