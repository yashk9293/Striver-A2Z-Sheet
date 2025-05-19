// Question Link - https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258
// Count Subarrays with XOR ‘K’

// Brute Force
// T.C = O(N^3)
// S.C = O(1)
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int xorr = 0;
            for (int k = i; k <= j; k++) {
                xorr = xorr ^ a[k];
            }
            if (xorr == k) {
                cnt++;
            }
        }
    }
    return cnt;
}




// Better Approach
// T.C = O(N^2)
// S.C = O(1)
int subarraysWithSumK(vector < int > a, int k) {
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {
            xorr = xorr ^ a[j];
            if (xorr == k) {
                cnt++;
            }
        }
    }
    return cnt;
}



// T.C = O(N logN)
// S.C = O(N)
#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > arr, int k) {
    int n = arr.size();
    unordered_map<int, int> mpp;
    int cnt = 0, xorr = 0;
    mpp[0] = 1;
    for(int i=0; i<n; i++) {
        xorr ^= arr[i];   
        cnt += mpp[xorr ^ k];
        mpp[xorr]++;
    }
    return cnt;
}