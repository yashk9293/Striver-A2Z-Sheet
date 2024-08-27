// Question Link :- https://www.naukri.com/code360/problems/tree-traversal_981269
// Tree Traversals

// T.C = O(3N)
// S.C = O(4N) + O(3N) -> 4 vector + 3 recursion stack
#include<bits/stdc++.h>

void inOrder(TreeNode* root, vector<int>& inn) {
    //base case
    if(root == NULL) {
        return;
    }
    inOrder(root->left, inn);
    inn.push_back(root->data);
    inOrder(root->right, inn);
}

void preOrder(TreeNode* root, vector<int>& pre) {
    //base case
    if(root == NULL) {
        return;
    }
    pre.push_back(root->data);
    preOrder(root->left, pre);
    preOrder(root->right, pre);
}

void postOrder(TreeNode* root, vector<int>& post) {
    //base case
    if(root == NULL) {
        return ;
    }
    postOrder(root->left, post);
    postOrder(root->right, post);
    post.push_back(root->data);
}


vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> inn, pre, post;
    vector<vector<int>> result;

    inOrder(root, inn);
    preOrder(root, pre);
    postOrder(root, post);

    result.push_back(inn);
    result.push_back(pre);
    result.push_back(post);
    return result;
}
