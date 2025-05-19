// Question Link :- https://leetcode.com/problems/remove-outermost-parentheses/
// Remove Outermost Parentheses

// Note :- Given a valid parentheses string s

// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        stack<char> st;
        string result;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                if(!st.empty()) {
                    result.push_back(s[i]);
                }
                st.push(s[i]);
            } 
            else {
                st.pop();
                if(!st.empty()) {
                    result.push_back(s[i]);
                }
            }
        }
        return result;
    }
};

// st.empty() -> push into stack, don't add into result
// !st.empty() -> push into stack, add into result




// Optimised Approach
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int balance = 0;
        string result;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                if(balance > 0) {
                    result.push_back(s[i]);
                }
                balance++;
            } 
            else {
                balance--;
                if(balance > 0) {
                    result.push_back(s[i]);
                }
            }
        }
        return result;
    }
};
