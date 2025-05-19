// Question Link :- https://leetcode.com/problems/longest-happy-prefix/description/
// Longest Happy Prefix

// Brute Force (doube for loop)
// T.C = O(n^2)
// S.C = O(n)


// Optimal Solution
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    string longestPrefix(string s) {
        if(s.size() == 0) {
            return "";
        }
        vector<int> lps(s.size(), 0);
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
        return s.substr(0, pre);
    }
};