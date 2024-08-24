// Question Link :- https://leetcode.com/problems/kth-smallest-element-in-a-bst
// Kth Smallest Element in a BST

// Approach - 1 (Recursive InOrder)
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    void solve(TreeNode* root, vector<int>&ans, int k){
        if(root == NULL) {
            return;
        }
        solve(root->left, ans, k);
        ans.push_back(root->val);
        solve(root->right, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        solve(root, ans, k);
        return ans[k-1];
    }
};




// Approach - 2
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    void solve(TreeNode* root, int& k, int& ans) {
        if(root == NULL) {
            return;
        }
        solve(root->left, k, ans);
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }
        solve(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        solve(root, k, ans);
        return ans;
    }
};