// Question Link :- https://leetcode.com/problems/isomorphic-strings/
// Isomorphic Strings

// T.C = O(n)
// S.C = O(1) ,max 256 ASCII values can be there, so size of map will not exceed 256
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> mapST, mapTS;
        for (int i=0; i<s.length(); i++) {
            char ch1 = s[i], ch2 = t[i];
            if (mapST[ch1] && mapST[ch1] != ch2) {
                return false;
            }
            if (mapTS[ch2] && mapTS[ch2] != ch1) {
                return false;
            }
            mapST[ch1] = ch2;
            mapTS[ch2] = ch1;
        }
        return true;
    }
};