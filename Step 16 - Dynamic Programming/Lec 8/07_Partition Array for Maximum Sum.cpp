// Question Link :- https://leetcode.com/problems/partition-array-for-maximum-sum/
// Partition Array for Maximum Sum


// Recursion
// T.C. = O(k^n)
// S.C. = O(n)



// Memoization
// T.C. = O(n*k)
// S.C. = O(n)
class Solution {
public:
    int t[501];
    int solve(vector<int>& arr, int i, int n, int k) {
        if(i >= n) {
            return 0; 
        }
        if(t[i] != -1) {
            return t[i];
        }
        int ans = INT_MIN;
        int curr_max = INT_MIN;

        // jis index pe hai vnha se k size tak ka check kr rhe 
        // you may think that why min ? think about the case that, you have
        // not k element then the group must be less than k na, isliye ki out of bound na ho jaye
        for(int j=i; j<min(i+k, n); j++) {
            curr_max = max(arr[j], curr_max);
            // i se j tak subarray hai, tpj j+1 se recursion laga denge
            ans = max(ans, solve(arr, j+1, n, k) + (j-i+1)*curr_max);
        }
        return t[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, 0, n, k);
    }
};