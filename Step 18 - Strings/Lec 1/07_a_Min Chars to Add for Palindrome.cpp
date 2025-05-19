// Question Link :- https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1
// Min Chars to Add for Palindrome


// Brute Force [1010 /1115 Passed]
// T.C = O(n^2)
// S.C = O(n)
class Solution {
  public:
    int minChar(string& s) {
        int i = s.size() - 1;
        while(i) {
            if(s[0] == s[i]) {
                string s1 = s.substr(0, i+1);   // O(i+1) ~ O(n) in worst case
                string s2 = s1;    // O(i+1) ~ O(n) in worst case
                reverse(s2.begin(), s2.end());   // O(i+1) ~ O(n) in worst case
                if(s1 == s2) {    // O(i+1) ~ O(n) in worst case
                    break;
                }
            }
            i--;
        }
        return s.size()-i-1;
    }
};




// Optimal Solution (KMP)
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

    int minChar(string& s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        
        string str = s + '$' + revStr;
        int lppLen = lps(str);
        
        return s.size() - lppLen;   // original string length - lps
    }
};
