// Question Link :- https://leetcode.com/problems/longest-string-chain/
// Longest String Chain


// Memoization
// T.C = O(n^2)
// S.C = O(n^2)
class Solution {
public:
    int t[1001][1001];
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(m >= n || n-m != 1) {
            return false;
        }
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }

    int lis(vector<string>& words, int i, int prev) {
        if(i == words.size()) {
            return 0;
        }
        if(prev != -1 && t[i][prev] != -1) {
            return t[i][prev];
        }
        int take = 0;
        if(prev == -1 || predecessor(words[prev], words[i])) {
            take = 1 + lis(words, i+1, i);
        }
        int skip = lis(words, i+1, prev);
        
        if(prev != -1) {
            t[i][prev] =  max(take, skip);
        }
        return max(take, skip);
    }
    
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        sort(begin(words), end(words), myFunction); // You can select pairs in any order.
        return lis(words, 0, -1);
    }
};





// Tabulation
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(m >= n || n-m != 1) {
            return false;
        }
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }
    
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words), end(words), myFunction); //You can select pairs in any order.
        
        vector<int> t(n, 1);
        int maxL = 1;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(predecessor(words[j], words[i])) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        return maxL;  
    }
};