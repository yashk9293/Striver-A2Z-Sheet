//Question Link :- https://leetcode.com/problems/next-greater-element-i/
// Next Greater Element I

// There are no duplicates, all elements are unique

// T.C = O(m+n)
// S.C = O(m+n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)  {
        int n = nums1.size();  
        int m = nums2.size(); 
        
        vector<int> ans(m, -1);
        stack<int> st;
        
        // apply NGR on nums2
        for(int i=m-1; i>=0; i--) {
            while(!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(nums2[i]);
        }

        // then we will find the res for nums1
        vector<int> res(n, -1);
        unordered_map<int, int> mp;  // {element, idx}
        for(int i=0; i<m; i++) {
            mp[nums2[i]] = i;
        }
        for(int i=0; i<n; i++) {
            if(mp.find(nums1[i]) != mp.end()) {
                res[i] = ans[mp[nums1[i]]];
            }
        }
        return res;
    }
};