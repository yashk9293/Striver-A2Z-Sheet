// Question Link :- https://leetcode.com/problems/maximal-rectangle/description/
// Question Link :- https://practice.geeksforgeeks.org/problems/max-rectangle/1
// Maximal Rectangle

// T.C = O(m*n) + O(m*n) ~ O(m*n)
// S.C = O(m)
class Solution{
public:
    vector<int> _NSL(vector<int> &arr, int n) {
        stack<int> st;
        vector<int> v(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;
    }
    vector<int> _NSR(vector<int> &arr, int n) {
        stack<int> st;
        vector<int> v(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;
    }

    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> NSL = _NSL(heights, n);
        vector<int> NSR = _NSR(heights, n);

        int mah = INT_MIN;
        for (long long i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;
            int length = heights[i];
            mah = max(mah, width * length);       // taking max after finding area
        }
        return mah;
    }

    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int result = 0;
        vector<int> histogram(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    histogram[j] += 1;
                } else {
                    histogram[j] = 0;
                }
            }
            result = max(result, largestRectangleArea(histogram));
        }
        return result;
    }
};