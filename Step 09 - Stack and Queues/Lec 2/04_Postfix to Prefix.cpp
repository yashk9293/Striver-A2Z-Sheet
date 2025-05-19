// Question Link :- https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1
// Postfix to Prefix

// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string>st;
        for(int i=0; i<post_exp.size(); i++){        // Postfix se pre ya infix me karenge, toh sidha chalega
            string c = "";
            c += post_exp[i];
            if(c=="+" || c=="-" || c=="*" || c=="/") {
                string r = st.top();
                st.pop();
                string l = st.top();
                st.pop();
                st.push(c + l + r);
            } else {
                st.push(c);
            }
        }
        return st.top();
    }
};