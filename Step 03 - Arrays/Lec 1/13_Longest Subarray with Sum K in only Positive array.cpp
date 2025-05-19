// Question Link - https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
// Longest Subarray With Sum K in only positive array

// Better Solution
// T.C = O(n^2)
// S.C = O(1)
int longestSubarrayWithSumK(vector < int > a, long long k) {
    int n = a.size();
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        long long currentSum = 0;
        for(int j = i; j < n; ++j) {
            currentSum += a[j];
            if(currentSum == k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}




// OPTIMAL SOLUTION
// T.C = O(2n) not n^2
//The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the 
// inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the 
// inner loop does not run for n times rather it can run for n times in total. So, the time complexity 
// will be O(2*n) instead of O(n^2).

// S.C = O(1)
int longestSubarrayWithSumK(vector<int>& a, long long k) {
    int n = a.size();
    int i=0;
    int len = 0;
    long long sum = 0;
    for(int j=0; j<n; j++) {
        sum += a[j];
        while( sum > k) {
            sum -= a[i];
            i++;
        }
        if(sum == k) {
            len = max(len,j-i+1);
        }
    }
    return len;
}