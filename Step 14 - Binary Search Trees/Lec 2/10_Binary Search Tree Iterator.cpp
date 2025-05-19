// Question Link :- https://leetcode.com/problems/binary-search-tree-iterator
// Binary Search Tree Iterator


// Brute Force
// We could have easily done this question by using inorder traversal and storing it in a vector 
// after that iterating every index of vector for next() value and if the index is equal to vector 
// size then hasnext() becomes false else it would be true.


// Optimal Approach
// T.C = O(1) -> there might be n no. of next() calls and there are n nodes so (n/n) ~ O(1)
// S.C = O(H)
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode *node) {
        while(node != NULL) {
            st.push(node);
            node = node->left;
        }
    }
};