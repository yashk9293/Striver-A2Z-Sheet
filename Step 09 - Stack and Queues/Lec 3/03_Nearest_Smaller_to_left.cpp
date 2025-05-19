// Question Link :- https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1
// Smallest number on left

// T.C = O(N)
// S.C = O(N)
class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if(!st.empty()) {
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }
};