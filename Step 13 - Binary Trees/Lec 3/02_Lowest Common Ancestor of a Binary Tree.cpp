// Question Link :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
// Lowest Common Ancestor of a Binary Tree

// T.C = O(N)
// S.C = O(height) -> auxiliary space
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        if (root == NULL) {
            return NULL;
        }
        if (root == n1 || root == n2) {
            return root;
        }
        TreeNode *leftAns = lowestCommonAncestor(root->left, n1, n2);
        TreeNode *rightAns = lowestCommonAncestor(root->right, n1, n2);

        if (rightAns == NULL) {
            return leftAns;
        }
        else if (leftAns == NULL) {
            return rightAns;
        }
        else {  // (leftAns != NULL && rightAns != NULL) -> both are not null, we found our result
            return root;
        }
    }
};