// Question Link :- https://leetcode.com/problems/recover-binary-search-tree
// Recover Binary Search Tree


// Brute Force
// T.C = O(n) + O(nlogn) + O(n) ~ O(nlogn)
// S.C = O(n)
class Solution {
public:
    void inOrder(vector<int>& ans, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inOrder(ans, root->left);
        ans.push_back(root->val);
        inOrder(ans, root->right);
    }

    void solve(int& i, TreeNode* root, const vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        // again do inorder to compare
        solve(i, root->left, ans);
        //swap
        if (root->val != ans[i]) {
            root->val = ans[i];
        }
        i++;
        solve(i, root->right, ans);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inOrder(ans, root);

        sort(begin(ans), end(ans));

        int i= 0;
        solve(i, root, ans);
    }
};





// Optimal Approach
// T.C = O(n)
// S.C = O(1) -> excluding recursion stack of O(H)
class Solution {
public:
    TreeNode *prev = NULL, *first = NULL, *second = NULL;
    void inOrder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left);
        if(prev != NULL && root->val < prev->val) {
            if(first == NULL) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        inOrder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inOrder(root);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};