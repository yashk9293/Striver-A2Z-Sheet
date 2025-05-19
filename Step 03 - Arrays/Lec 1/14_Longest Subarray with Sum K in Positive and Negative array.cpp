// Question Link - https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505

// T.C = O(n)
// S.C = O(n)
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i=0; i<n; i++) {
        sum += arr[i]; 
        if(sum == k) {
            maxi = i + 1; 
        }
        if(mpp.find(sum-k) != mpp.end()) {
            maxi = max(maxi, i - mpp[sum-k]); 
        }
        if (mpp.find(sum) == mpp.end()) {
            mpp[sum] = i;
        }
    }
    return maxi; 
}