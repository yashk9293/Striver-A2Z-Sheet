// Question Link :- https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses
// Maximum Nesting Depth of the Parentheses


// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int openBrackets = 0;

        for (char &ch : s) {
            if (ch == '(') {
                openBrackets++;
            } else if (ch == ')') {
                openBrackets--;
            }
            
            result = max(result, openBrackets);
        }
        return result;
    }
};