// Question Link :- https://leetcode.com/problems/symmetric-tree
// Symmetric Tree

// T.C = O(N)
// S.C = O(height)

class Solution {
public:
    bool check(TreeNode* node1, TreeNode* node2) {
        if(node1 == NULL && node2 == NULL) {
            return true;
        }
        // If only one of the nodes is NULL, they are not identical
        if(node1 == NULL || node2 == NULL) {
            return false;
        }
        return ((node1->val == node2->val) && check(node1->left, node2->right) && check(node1->right, node2->left));
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return check(root->left, root->right);
    }
};




class Solution {
public:
    bool check(TreeNode* node1, TreeNode* node2) {
        if(node1 == NULL && node2 == NULL) {
            return true;
        }
        // If only one of the nodes is NULL, they are not identical
        if(node1 == NULL || node2 == NULL) {
            return false;
        }
        
        bool left = check(node1->left, node2->right);
        bool right = check(node1->right, node2->left);
        bool value = node1->val == node2-> val;
        
        if(left && right && value) {
            return true;
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return check(root->left, root->right);
    }
};