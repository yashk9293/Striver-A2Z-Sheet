// Question Link :- https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
// Root to Leaf Paths

// T.C = O(N)
// S.C = O(N)
class Solution {
  public:
    void solve(Node* root, vector<int>& temp, vector<vector<int>>& result) {
        if(root == NULL) {
            return;
        }
        temp.push_back(root->data);
        if(root->left == NULL && root->right == NULL) {
            result.push_back(temp);
        }
        solve(root->left, temp, result);
        solve(root->right, temp, result);
        temp.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int>temp;
        solve(root, temp, result);
        return result;
    }
};






// Question Link :- https://leetcode.com/problems/binary-tree-paths
// Binary Tree Paths

// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    void solve(TreeNode* root, string temp, vector<string>& result) {   // string passed by value, because we are passing (temp + "->")
        if(root == NULL) {
            return;
        }
        temp += to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            result.push_back(temp);
        }
        solve(root->left, temp + "->", result);
        solve(root->right, temp + "->", result);
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string temp = "";
        solve(root, temp, result);
        return result;
    }
};
