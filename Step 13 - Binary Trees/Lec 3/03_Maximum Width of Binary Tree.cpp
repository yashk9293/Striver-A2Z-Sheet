// Question Link :- https://leetcode.com/problems/maximum-width-of-binary-tree
// Maximum Width of Binary Tree

// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long maxi=0;
        while(!q.empty()) {
            long long size = q.size();
            long long maxidx = q.back().second;
            long long minidx = q.front().second;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                q.pop();
                if(node->left) {
                    q.push({node->left, 2*idx+1});
                }
                if(node->right) {
                    q.push({node->right, 2*idx+2});
                }
            }
            maxi = max(maxi, maxidx - minidx + 1);
        }
        return maxi;
    }
};
