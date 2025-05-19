// Question Link :- https://www.naukri.com/code360/problems/longest-substring-with-at-most-k-distinct-characters_2221410
// Longest Substring with At Most K Distinct Characters
// Striver


// Brute Force
// T.C = O(n^2)
// S.C = O(k)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; ++j) {
                freq[s[j]]++;
                if (freq.size() <= k) {
                    maxLen = max(maxLen, j - i + 1);
                } else {
                    break; // early stop since adding more chars won't help
                }
            }
        }

        return maxLen;
    }
};



// same as previous ques
// T.C = O(n)
// S.C = O(n)
#include<bits/stdc++.h>
int kDistinctChars(int k, string &s){
    int i=0, j=0, maxlen=-1;
    map<char,int> mpp;
    while(j < s.size()) {
        mpp[s[j]]++;
        if(mpp.size() > k) {
            mpp[s[i]]--;
            if(mpp[s[i]] == 0) {
                mpp.erase(s[i]);
            }
            i++;
        }
        if(mpp.size() <= k) {
            maxlen = max(maxlen, j-i+1);
        }
        j++;
    }
    return maxlen;
}


