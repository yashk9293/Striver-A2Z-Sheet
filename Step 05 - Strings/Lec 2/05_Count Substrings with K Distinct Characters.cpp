// Question Link :- https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1
// Count Substrings with K Distinct Characters


// Brute Force
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    int countSubstr(string& s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;  // or we can use unordered_map
            for (int j = i; j < n; j++) {
                st.insert(s[j]);  // O(1)
                if (st.size() == k) {
                    ans++;
                }
                if (st.size() > k) {
                    break;
                }
            }
        }
        return ans;
    }
};




// Optimized Approach
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int countSubstr(string& s, int k) {
        int n = s.size();
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        while (j < n) {
            mp[s[j]]++;
            if (mp.size() < k) {
                j++;
            }
            else if (mp.size() == k) {
                ans++;
                j++;
            }
            else {
                while (mp.size() > k) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                ans += j - i;
                j++;
            }
        }
        return ans;
    }
};



// OR [preferred]
class Solution {
public:
    int countAtMostK(string& s, int k) {
        int n = s.size();
        int i = 0, ans = 0;
        unordered_map<char, int> mp;

        for (int j = 0; j < n; ++j) {
            mp[s[j]]++;
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
            ans += j - i + 1; // all substrings ending at j and starting from i to j
        }
        return ans;
    }

    int countSubstr(string& s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};
