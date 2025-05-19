// Question Link :- https://leetcode.com/problems/binary-tree-postorder-traversal/
// Binary Tree Postorder Morris Traversal

// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->right == NULL) {
                ans.push_back(curr -> val);
                curr = curr->left;
            } else {
                TreeNode *temp = curr->right;
                while(temp->left != NULL && temp->left != curr) {
                    temp = temp->left;
                }
                if(temp->left == NULL){
                    ans.push_back(curr->val);
                    temp->left = root;
                    curr = curr->right;
                } else {
                    temp->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};