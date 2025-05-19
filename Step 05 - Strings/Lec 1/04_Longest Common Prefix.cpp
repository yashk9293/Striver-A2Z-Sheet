// Question Link :- https://leetcode.com/problems/longest-common-prefix/
// Longest Common Prefix


// Better Approach
// T.C = O(nlogn)
// S.C = O(l) ~ O(1)  // where l is the length of common prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[n - 1];

        string result = "";
        for(int i=0; i<first.size(); i++) {
            if(first[i] != last[i]) {
                break;
            }
            result.push_back(first[i]);
        }
        return result;
    }
};



// Optimal Approach
// T.C = O(n*l) (where l is the length of the first string)
// S.C = O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < n; j++) {
                if (strs[j].size() <= i || strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

