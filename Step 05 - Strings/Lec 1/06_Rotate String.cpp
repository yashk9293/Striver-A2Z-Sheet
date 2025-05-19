// Question Link :- https://leetcode.com/problems/rotate-string
// Rotate String


// Brute Force
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }

        for(int i=0; i<s.size(); i++) {  // O(n)
            string temp = "";
            temp += s.substr(i, s.size());  // O(n)
            temp += s.substr(0, i);  // O(n) at worse case

            if(temp == goal) {  // O(n)
                return true;
            }
        }
        return false;
    }
};



// Optimized Approach
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }

        string extended = s + s;

        // Check if goal exists as a substring in extended string
        if (extended.find(goal) != string::npos) {
            return true;
        } 
        return false;
    }
};