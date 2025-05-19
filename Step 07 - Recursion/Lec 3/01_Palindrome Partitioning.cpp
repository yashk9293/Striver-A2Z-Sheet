// Question Link :- https://leetcode.com/problems/palindrome-partitioning
// Palindrome Partitioning

// T.C = O(n*2^n)
// S.C = O(n)

// The time complexity of the algorithm for generating all possible palindromic partitioning is typically expressed as
// O(n * 2^n), where n is the length of the input string. This complexity arises because there can be 2^n possible partitions,
// and for each partition, we need to check if each substring is a palindrome, which takes O(n) time in the worst case.


class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void func(int i, vector<string> &path, string s, vector<vector<string>> &ans) {
        if(i == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int idx=i; idx<s.size(); idx++) {
            if(isPalindrome(s, i, idx)) {
                path.push_back(s.substr(i, idx - i + 1));
                func(idx+1, path, s, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0, path, s, ans);
        return ans;
    }
};