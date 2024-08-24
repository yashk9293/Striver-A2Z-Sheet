// Question Link :- https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
// Ceil in BST

// T.C = O(N)
// S.C = O(1)
int findCeil(Node* root, int input) {
    int ceil = -1;
    while(root != NULL) {
        if(root->data == input) {
            ceil = root->data;
            return ceil;
        }
        if(root->data > input) {
            ceil = root->data;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return ceil;
}
