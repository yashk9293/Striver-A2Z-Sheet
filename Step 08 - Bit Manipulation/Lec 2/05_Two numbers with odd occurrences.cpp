// Question Link :- https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1
// Question Link :- https://leetcode.com/problems/single-number-iii/
// Two numbers with odd occurrences


// Approach - 1 (hashing)
// T.C = O(n)
// S.C = O(n)
class Solution {
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        vector<long long int> ans;
        unordered_map<int, int> mpp;
        for(int i=0; i<N; i++) {
            mpp[Arr[i]]++;
        }
        for(auto it: mpp) {
            if(it.second%2 == 1) {
                ans.push_back(it.first);
            }
        }
        if(ans[0] < ans[1]) {
            return {ans[1], ans[0]};
        }
        return ans;
    }
};




// Approach - 2 (bit manipulation)
// T.C = O(n)
// S.C = O(1)
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N){
        // Step 1: Xor all the elements
        long xorr = 0;
        for(int i=0; i<N; i++) {
            xorr = xorr ^ Arr[i];
        }
        // Step 2: Find the rightmost set bit
        int rightMost = (xorr & xorr - 1) ^ xorr;

        // Step 3: Store elements with rightmost set bit set into b1 and 0 into b2
        long long int b1 = 0, b2 = 0;
        for(int i=0; i<N; i++){
            if(Arr[i] & rightMost) {
                b1 ^= Arr[i];
            } else {
                b2 ^= Arr[i];
            }
        }
        if(b1 > b2) {
            return {b1, b2};
        }
        return {b2, b1};
    }
};





/*
xorr can minimum be -2^31, so in line no. 43 (xorr - 1) can't be stored in int
So, we are taking xorr in long not int.
*/