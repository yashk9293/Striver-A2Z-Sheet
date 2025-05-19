// Question Link :- https://leetcode.com/problems/sum-of-subarray-minimums/
// Sum of Subarray Minimums

//Approach-1 (Simple Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long result = 0;
        for(int i=0; i<n; i++) {
            int mini = arr[i];
            for(int j=i; j<n; j++) {
                mini = min(mini, arr[j]);
                result = (result + mini) % mod;
            }
        }
        return result;
    }
};






//Approach-2
//T.C : O(n)
//S.C : O(n)
typedef unsigned long long ll;
class Solution {
public:
    // NSL - Stores indices
    vector<int> _NSL(vector<int>& arr, int n) {
        vector<int> result(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {  // non strictly less
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(i);  // Push index instead of value
        }
        return result;
    }

    // NSR - Stores indices
    vector<int> _NSR(vector<int>& arr, int n) {
        vector<int> result(n, n); // Default is n, because if no NSR exists, it extends to end
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {  // strictly less
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(i); // Push index instead of value
        }
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = _NSL(arr, n); 
        vector<int> NSR = _NSR(arr, n);
        
        ll sum = 0;
        int mod = 1e9+7;
        for(int i = 0; i<n; i++) {
            ll d1 = i - NSL[i];     // distance to nearest smaller to left from i
            ll d2 = NSR[i] - i;     // distance to nearest smaller to right from i
            
            ll total_subarrays = d1*d2;         // ith element kitna baar minimum rahega
            ll sum_of_total_subarrays  = arr[i] * total_subarrays;
            
            sum  = (sum + sum_of_total_subarrays) % mod;
        }
        return sum;
    }
};





// we can do vice versa in NSL and NSP for putting '=' sign in condition to become non-strictly less
// this is used to avoid duplicates in the case of equal elements
// for example, if we have 2 1 2, then we will have 2 1 1 in NSL and 1 3 3 in NSR
// so, we will have 2 subarrays with 1 as minimum, and 1 subarray with 2 as minimum
// so, we will have 2*1 + 1*2 = 4 subarrays with 1 as minimum
// so, we will have 2*2 = 4 subarrays with 2 as minimum
// so, total = 4 + 4 = 8 subarrays