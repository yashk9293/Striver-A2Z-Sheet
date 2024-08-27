// Question Link :- https://www.naukri.com/code360/problems/tree-traversals_981269
// Preorder Inorder Postorder in One Traversal

// T.C = O(3N)
// S.C = O(4N)
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    if(root == NULL) {
        return ans;
    }
    vector<int> in, pre, post;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while(!st.empty()) {
        TreeNode* node = st.top().first;
        int cnt = st.top().second;
        st.pop();
        if(cnt == 1){
            pre.push_back(node->data);
            st.push({node, cnt + 1});
            if(node->left) st.push({node->left, 1});
        } else if(cnt == 2){
            in.push_back(node->data);
            st.push({node, cnt + 1});
            if(node->right) st.push({node->right, 1});
        } else {
            post.push_back(node->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}


// Output :-
// 1 2 3 4 5 6 7 
// 3 2 4 1 6 5 7 
// 3 4 2 6 7 5 1
