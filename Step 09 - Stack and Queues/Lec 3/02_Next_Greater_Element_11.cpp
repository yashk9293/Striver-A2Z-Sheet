// Question Link :- https://leetcode.com/problems/next-greater-element-ii/
// Next Greater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();  
        
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
			st.push(nums[i]);
		}
        
        // apply NGR on nums
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};