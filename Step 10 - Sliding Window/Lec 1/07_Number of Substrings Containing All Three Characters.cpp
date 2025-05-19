// Question Link :- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
// Number of Substrings Containing All Three Characters



// Brute Force Approach
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int a = 0, b = 0, c = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == 'a') a++;
                if (s[j] == 'b') b++;
                if (s[j] == 'c') c++;
                
                if (a > 0 && b > 0 && c > 0) {
                    count++;
                }
            }
        }
        return count;
    }
};




// Sliding Window Approach
// T.C = O(2n)
// S.C = O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int result = 0;
        unordered_map<char, int> mpp;

        int i = 0, j = 0;
        while(j < n) {
            mpp[s[j]]++;
            while(mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
                result += (n - j);

                mpp[s[i]]--;
                i++;
            }
            j++;
        }
        return result;
    }
};