// Question Link :- 
// Minimum element in BST

// Approach - 1 (Recursion)
// T.C = O(N)
// S.C = O(N) -> recursive stack
class Solution {
  public:
    int minValue(Node* root) {
        if(root == NULL || root->left == NULL) {
            return root->data;
        }
        return minValue(root->left);
    }
};



// Approach - 2 (Iterative)
// T.C = O(N)
// S.C = O(1)
class Solution {
  public:
    int minValue(Node* root) {
        while(root->left != NULL) {
            root = root->left;
        }
        return root->data;
    }
};