// Question Link :- https://www.geeksforgeeks.org/problems/children-sum-parent/1
// Children Sum in a Binary Tree

// T.C = O(N)
// S.C = O(N)
class Solution{
    public:
    int solve(Node *root) {
        if(root == NULL) {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) {
            return root->data;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left + right == root->data) {
            return root->data;
        }
        return -100;
    }
    
    int isSumProperty(Node *root) {
        int ans = solve(root);
        if(ans == root->data) {
            return true;
        }
        return false;
    }
};


// We are not returning -1 due to this type example test cases
// on returning -1, this test case will give 1, due to 5 coming from 5 side and -1 coming 
// from 2 side, therefore 5-1 = 4 which will give true(i.e., 1) which is WRONG.

// 4 5 2 N 5 3
// Output :- 0

//      4
//   5     2
// N   5 3   N