// Question Link :- https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
// Print Longest Increasing Subsequence


// T.C = O(n^2)
// S.C = O(n)
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int lastIdx = 0;
        int maxL = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j] + 1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        lastIdx = i;
                    }
                }
            }
        }
        vector<int> result;
        while(lastIdx >= 0) {
            result.push_back(nums[lastIdx]);
            lastIdx = prev_idx[lastIdx];
        }
        
        reverse(result.begin(), result.end());   // we want result in increasing order
        return result;
    }
};