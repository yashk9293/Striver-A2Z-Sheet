// Question Link :- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// All Nodes Distance K in Binary Tree


// T.C = O(N) + O(N)
// S.C = O(N)
class Solution {
public:
    // Step 1: Create a parent map
    void addParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp) {
        if(root == NULL) {
            return;
        }
        if(root->left) {
            mpp[root->left] = root;
            addParent(root->left, mpp);
        }
        if(root->right) {
            mpp[root->right] = root;
            addParent(root->right, mpp);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;  // node -> parent
        addParent(root, mpp);

        // Step 2: Perform BFS from the target node
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        while (!q.empty()) {
            int size = q.size();
            if (k == 0) {
                break;
            }
            // Process all nodes at the current level
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                // Traverse left child
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                // Traverse right child
                if (node->right && !visited[node->right] ) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                // Traverse parent - node should be present in mpp and parent should not be visited
                if (mpp.find(node) != mpp.end() && !visited[mpp[node]]) {
                    q.push(mpp[node]);    // parent ko q me daale
                    visited[mpp[node]] = true;  // parent visited
                }
            }
            k--;
        }
        vector<int> result;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
        return result;
    }
};
