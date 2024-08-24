// Question Link :- https://www.geeksforgeeks.org/problems/floor-in-bst/1
// Floor in BST

// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int floor(Node* root, int input) {
        int floorAns = -1;
        while(root != NULL) {
            if(root->data == input) {
                floorAns = root->data;
                return floorAns;
            }
            if(root->data < input) {
                floorAns = root->data;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return floorAns;
    }
};