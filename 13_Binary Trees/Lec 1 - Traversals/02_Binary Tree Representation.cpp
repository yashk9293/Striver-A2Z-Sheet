// Question Link :- https://www.geeksforgeeks.org/problems/binary-tree-representation/1
// Binary Tree Representation


// Method 1 (Iterative)
// T.C = O(N)
// S.C = O(N)
class Solution{
public:
    void create_tree(node* root, vector<int> &vec){
        queue<node*> q;
        q.push(root);
        int i=1;
        while(!q.empty()) {
            node* temp = q.front();
            q.pop();
            if(i < vec.size()) {
                temp->left = newNode(vec[i]);
                q.push(temp->left);
                i++;
            }
            if(i < vec.size()) {
                temp->right = newNode(vec[i]);
                q.push(temp->right);
                i++;
            }
        }
    }
};




// Method 2 (Recursive)
// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    node* solve(node* root, const vector<int> &vec, int i) {
        if (i >= vec.size()) {
            return NULL;
        }
        if (root == NULL) {
            root = newNode(vec[i]);
        }
        if (2*i+1 < vec.size()) {
            root->left = solve(root->left, vec, 2*i+1);
        }
        if (2*i+2 < vec.size()) {
            root->right = solve(root->right, vec, 2*i+2);
        }
        return root;
    }

    void create_tree(node* root, const vector<int> &vec) {
        solve(root, vec, 0);
    }
};




