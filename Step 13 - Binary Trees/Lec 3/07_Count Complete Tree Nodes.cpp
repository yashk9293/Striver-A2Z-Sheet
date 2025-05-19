// Question Link :- https://leetcode.com/problems/count-complete-tree-nodes/
// Count Complete Tree Nodes

// Approach - 1 (Recursive)
// T.C = O(N)
// S.C = O(height)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};



// Approach - 2 (InOrder)
// T.C = O(N)
// S.C = O(height)
class Solution {
public:
    void inorder(TreeNode* root, int &count) {
        if (root == NULL) {
            return;
        }
        count++;
        inorder(root->left, count);
        inorder(root->right, count);
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int count = 0;
        inorder(root, count);
        return count;
    }
};


// Approach - 3 (Optimal Solution)
// T.C = O(logN * logN) the height of the tree at any instance in complete binary tree can't exceed logN. 
// In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive 
// calls are made at most log N times (the height of the tree).

// S.C = O(height) Since the given tree is a complete binary tree, the height will always be log N.

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int heightLeft = 0, heightRight = 0;

        TreeNode *left = root, *right = root;

        while(left) {
            heightLeft++;
            left = left->left;
        }
        while(right) {
            heightRight++;
            right = right->right;
        }
        if(heightLeft == heightRight) {
            return pow(2, heightLeft) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};