// Question Link :- https://leetcode.com/problems/shortest-palindrome/
// Shortest Palindrome

// Brute Force (121 / 126 testcases passed)
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() == 0) {
            return "";
        }
        int i = s.size() - 1;
        while(i >= 0) {
            if(s[0] == s[i]) {
                string s1 = s.substr(0, i+1);
                string s2 = s1;
                reverse(s2.begin(), s2.end());
                if(s1 == s2) {
                    break;
                }
            }
            i--;
        }
        string rev = s.substr(i+1, s.size());
        reverse(rev.begin(), rev.end());
        return rev + s;
    }
};




// Optimal Solution
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int lps(string s) {
        vector<int> lps(s.size(), 0);
        int pre = 0, suff = 1;
        while(suff < s.size()) {
            if(s[pre] == s[suff]) {   // match
                lps[suff] = pre+1;
                pre++;
                suff++;
            } else {    // not match
                if(pre == 0) {
                    suff++;
                } else {
                   pre = lps[pre-1];
                }
            }
        }
        return lps[s.size()-1];
    }

    string shortestPalindrome(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());

        string str = s + '$' + revStr;
        int lppLen = lps(str);     // longest prefix palindrome length
        
        string rev = s.substr(lppLen, s.size());
        reverse(rev.begin(), rev.end());
        return rev + s;
    }
};