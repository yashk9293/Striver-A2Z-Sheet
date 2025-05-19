// Question Link :- https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
// Predecessor and Successor

// Approach - 1
// T.C = O(n)
// S.C = O(n)
// inorder Traversal, store elements in the vector/array
// find the key in the array, and then successor and predecessor of the key.


// Approach - 2 (Using 2 loop)
// T.C = O(H)
// S.C = O(1)
class Solution {
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        Node* temp = root;   // Initializing temporary node with head.
        while(temp != NULL) {
            if(temp->key > key) {
                suc = temp;
                temp = temp->left;
            } else {
               temp = temp->right;
            }
        }
        while(root != NULL) {
            if(root->key < key) {
                pre = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
};




// Approach - 3 (using Recursion)
// T.C = O(H)
// S.C = O(1)
class Solution {
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if(!root) {
            return;
        }
        if(root->key > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else if(root->key < key) {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        } else {
            findPreSuc(root->left, pre, suc, key);
            findPreSuc(root->right, pre, suc, key);
        }
    }
};