// Question Link :- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
// Find the Index of the First Occurrence in a String

// Brute Force
// T.C = O(n*m)
// S.C = O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        for(int i = 0; i <= m-n; i++) {   // haystack
            for(int j = 0; j < n; j++) {   // needle
                if(needle[j] != haystack[i+j]) {
                    break;
                }
                if(j == n-1) {
                    return i;
                }
            }
        }
        return -1;
    }
};




// Optimal Solution
// T.C = O(n+m)
// S.C = O(m)
class Solution {
public:
    void lpsFind(vector<int>& lps, string s) {
        int pre = 0, suff = 1;
        while(suff < s.size()) {
            if(s[pre] == s[suff]) {
                lps[suff] = pre+1;
                pre++;
                suff++;
            } else {
                if(pre == 0) {
                    suff++;
                } else {
                   pre = lps[pre-1];
                }  
            }
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        lpsFind(lps, needle);
        int first = 0, second = 0;
        while(first < haystack.size() && second < needle.size()) {
            // Match
            if(haystack[first] == needle[second]) {
                first++;
                second++;
            }
            // Not matched
            else {
                if(second == 0) {
                    first++;
                } else {
                    second = lps[second-1];
                }
            }
        }
        // Answer exist
        if(second == needle.size()) {
            return first - second;    // return first - needle.size();
        }
        return -1;
    }
};