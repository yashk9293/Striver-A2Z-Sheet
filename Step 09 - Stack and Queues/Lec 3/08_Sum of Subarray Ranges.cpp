// Question Link :- https://leetcode.com/problems/sum-of-subarray-ranges/
// Sum of Subarray Ranges

// T.C = O(n^2)
// S.C = O(1)
// Brute Force Approach (logic)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for(int i=0; i<n; i++){
            int maxi = nums[i];
            int mini = nums[i];
            for(int j=i; j<n; j++) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                res += maxi-mini;
            }
        }
        return res;
    }
};










// Using (nearest smaller left, nearest smaller right, nearest greater left, nearest greater right)
// NSL, NSR = Sum of SubArray Minimum (Leetcode 907)
// NGL, NGR = Sum of SubArray Maximum
// Sum of Subarray ranges = Sum of SubArray Maximum - Sum of SubArray Minimum

// T.C = O(n)
// S.C = O(n)
#define ll long long
class Solution {
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
    vector<int> _NGL(vector<int> &arr, int n) {
        vector<int> v(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;
    }
    vector<int> _NGR(vector<int> &arr, int n) {
        vector<int> v(n, n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                v[i] = st.top();
            }
            st.push(i);
        }
        return v;
    }

    ll sumSubarrayMaxs(vector<int> &arr) {
        int n = arr.size();
        vector<int> NGL = _NGL(arr, n);
        vector<int> NGR = _NGR(arr, n);

        ll count = 0;
        for (int i = 0; i < n; i++) {
            ll d1 = i - NGL[i];
            ll d2 = NGR[i] - i;

            count += d1 * d2 * arr[i];
        }
        return count;
    }

    ll sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> NSL = _NSL(arr, n);
        vector<int> NSR = _NSR(arr, n);
        
        ll count = 0;
        for (int i = 0; i < n; i++) {
            ll d1 = i - NSL[i];
            ll d2 = NSR[i] - i;

            count += d1 * d2 * arr[i];
        }
        return count;
    }

    long long subArrayRanges(vector<int> &nums) {
        ll totalMaxs = sumSubarrayMaxs(nums);
        ll totalMins = sumSubarrayMins(nums);
        return totalMaxs - totalMins;
    }
};