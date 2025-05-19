// Question Link :- https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1
// Postfix to Infix

// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;
        for(int i=0; i<exp.size(); i++) {         // Postfix se pre ya infix me karenge, toh sidha chalega
            char c = exp[i];
            if(c=='+' || c=='-' || c=='*' || c=='/') {
                string r = st.top();
                st.pop();
                string l = st.top();
                st.pop();
                st.push('('+ l + c + r +')');
            } else {
                st.push(string(1, c));
            }
        }
        if(st.empty()) {
            return "";
        } else {
            return st.top();
        }
    }
};