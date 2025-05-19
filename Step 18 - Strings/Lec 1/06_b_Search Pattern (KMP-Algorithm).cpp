// Question Link :- https://www.geeksforgeeks.org/problems/search-pattern0205/1
// Search Pattern (KMP-Algorithm)

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

    vector<int> search(string& pat, string& txt) {
        vector<int> lps(pat.size(), 0);
        vector<int> answer;  // store all the occurences of pat
        lpsFind(lps, pat);
        int first = 0, second = 0;
        bool check = false;
        while(first < txt.size()) {
            // Match
            if(txt[first] == pat[second]) {
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
            // store answer
            if(second == pat.size()) {
                check = true;
                answer.push_back(first - second + 1);
                second = lps[second-1];  // Move back for next occurences
            }
        }
        if(!check) {
            answer.push_back(-1);
        }
        return answer;
    }
};