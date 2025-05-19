// Question Link :- https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
// Longest Prefix Suffix


// Brute Force (doube for loop)
// T.C = O(n^2)
// S.C = O(n)


// Optimal Solution
// T.C = O(n)
// S.C = O(n)

class Solution {
  public:
    int lps(string s) {
        if(s.size() == 0) {
            return -1;
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
        return lps[s.size()-1];
    }
};