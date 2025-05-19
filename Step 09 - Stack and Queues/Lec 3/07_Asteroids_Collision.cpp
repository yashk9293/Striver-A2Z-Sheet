// Question Link :- https://leetcode.com/problems/asteroid-collision/
// Asteroid Collision

// T.C = O(N)
// S.C = O(N)

// Approach 1 (Using a stack)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int &a : asteroids) {
            while(!st.empty() && a < 0 && st.top() > 0) {
                int sum = a + st.top();
                if(sum < 0) {
                    st.pop();
                } else if(sum > 0) {
                    a = 0;
                } else {
                    st.pop();
                    a = 0;
                }
            }
            if(a != 0) {
                st.push(a);
            }
        }
        int s = st.size();
        vector<int> result(s);
        int i = s-1;
        while(!st.empty()) {
            result[i] = st.top();
            st.pop();
            i--;
        }
        // vector<int> result;
        // while(!st.empty()) {
        //     result.push_back(st.top());
        //     st.pop();
        // }
        // reverse(result.begin(), result.end());
        return result;
    }
};





// Approach 2 (Using vector as a stack)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;    // used as a stack
        for(int &a : asteroids) {
            while(!ans.empty() && a<0 && ans.back()>0) {   // collision hoga
                int sum = ans.back() + a;
                if(sum <0) {
                    ans.pop_back();
                } else if(sum > 0) {
                    a = 0;
                } else if (sum == 0) {
                    ans.pop_back();
                    a = 0;
                }
            }
            if(a != 0) {
                ans.push_back(a);
            }
        }
        return ans;
    }
};