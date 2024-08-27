// Question Link :- https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1
// Unique Binary Tree Requirements

// T.C = O(1)
// S.C = O(1)
class Solution {
public:
    bool isPossible(int a, int b) {
        if((a==2 || b==2) && a != b) {
            return true;
        }
        return false;
    }
};



// Inorder & Postorder -> true (unique)
// Inorder & Preorder -> true (unique)
// Preorder & Postorder -> false (not unique)