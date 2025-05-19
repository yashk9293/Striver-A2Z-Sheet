// Question Link :- https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1
// Prefix to Postfix

// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string>st;
        for(int i=pre_exp.size()-1; i>=0; i--){   // Prefix se post ya infix me karenge, toh ulta chalega
            string c = "";
            c += pre_exp[i];
            if(c=="+" || c=="-" || c=="*" || c=="/") {
                string r = st.top();
                st.pop();
                string l = st.top();
                st.pop();
                st.push(r + l + c);
            } else {
                st.push(c);
            }
        }
        return st.top();
    }
};