// Question Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Longest Substring Without Repeating Characters

// Brute Force
// T.C = O(N^2)
// S.C = O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size()==0) {
            return 0;
        }
        int maxans = INT_MIN;
        unordered_set<char> set;
        for (int i = 0; i < str.length(); i++) {
            set.clear();
            for (int j = i; j < str.length(); j++) {
                if (set.find(str[j]) != set.end()) { // O(1)
                    break;
                }
                set.insert(str[j]);  // O(1)
                maxans = max(maxans, j-i+1);
            }
        }
        return maxans;
    }
};






// Optimal Solution
// T.C = O(N)
// S.C = O(256)  where 256 represents the number of ASCII characters.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int i=0, j=0;
        unordered_map<char, int> mpp;
        while(j < s.size()) {
            while(mpp.find(s[j]) != mpp.end()) {
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i++;
            }
            mpp[s[j]]++;
            len = max(len, j-i+1);
            j++;
        }
        return len;
    }
};