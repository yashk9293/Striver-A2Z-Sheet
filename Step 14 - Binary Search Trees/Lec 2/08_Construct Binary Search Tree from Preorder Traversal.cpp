// Question Link :- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
// Construct Binary Search Tree from Preorder Traversal


// Approach - 1 (inorder)
// T.C = O(nlogn) + O(n)
// S.C = O(n)
class Solution {
public:
    unordered_map<int, int> mpp;  // {node value, index}

    TreeNode* makeBST(vector<int>& preorder, int& idx, vector<int>& inorder, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int rootVal = preorder[idx];
        int mid = mpp[rootVal];
        idx++;

        TreeNode* node = new TreeNode(rootVal);
        node->left = makeBST(preorder, idx, inorder, l, mid-1);
        node->right = makeBST(preorder, idx, inorder, mid+1, r);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(begin(inorder), end(inorder));
        for(int i = 0; i<inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return makeBST(preorder, idx, inorder, 0, inorder.size()-1);
    }
};




// Approach - 2 (Recursion)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int maxi, int& idx){
        if(idx == preorder.size() || preorder[idx] > maxi) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        // left me jaate jaao aur root->val store krte jaao...
        root->left = solve(preorder, root->val, idx);
        root->right = solve(preorder, maxi, idx);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return solve(preorder, INT_MAX, idx);
    }
};