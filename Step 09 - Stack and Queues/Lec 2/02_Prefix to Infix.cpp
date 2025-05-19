// Question Link :- https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
// Prefix to Infix

// T.C = O(n)
// S.C = O(n)

class Solution {
  public:
    string preToInfix(string pre_exp) {
        int len = pre_exp.length();
        stack<string>st;
        for(int i = len - 1; i >= 0; i--) {       // Prefix se post ya infix me karenge, toh ulta chalega
            string c = "";
            c += pre_exp[i];
            if(c=="+" || c=="-" || c=="*" || c=="/") {
                string r = st.top();
                st.pop();
                string l = st.top();
                st.pop();
                st.push('('+ r + c + l +')');
            } else {
                st.push(c);
            }
        }
        return st.top();
    }
};