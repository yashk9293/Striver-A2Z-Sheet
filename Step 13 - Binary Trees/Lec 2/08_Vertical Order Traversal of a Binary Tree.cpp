// Question Link :- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Vertical Order Traversal of a Binary Tree


// T.C = O(NlogN) where N represents the number of nodes in the Binary Tree.
// For BFS Traversal -> O(N) and for insertion into map O(logN). So O(NlogN)

// The outer loop runs for each unique vertical index (let's say there are V such verticals) -> O(V)

// The inner loop runs for each unique level index within a vertical (lets say there are
// L levels per vertical on average) -> O(L)

// For each level, the multiset of node values is traversed. Since the multiset might store up to 
// N nodes, inserting them into the vector col takes  O(N) operations in the worst case.

// So O(V*L*N) ~ O(N) for traversing

// S.C = O(N + N/2) -> map + queue(the maximum level of the tree which can be O(N/2) in the worst case of a balanced tree)


// Method - 1 (Iterative)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;  // {vertical, level, multinodes}
        queue<pair<TreeNode*, pair<int, int>>> q;  // {node, vertical, level}
        q.push({root, {0, 0}});  
        // BFS traversal
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* temp = p.first;
            int x = p.second.first;  // vertical
            int y = p.second.second; // level
            mp[x][y].insert(temp->val);  // mp[vertical][level] = nodes
            if(temp->left){
                q.push({temp->left, {x-1, y+1}});
            }
            if(temp->right){
                q.push({temp->right, {x+1, y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto x: mp) {  // x = int, map<int, multiset<int>>
            vector<int> col;
            for(auto y: x.second) {  // x.second = map<int, multiset<int>> and y = int, multiset<int>
                // col.insert(col.end(), y.second.begin(), y.second.end());
                for(auto z : y.second) {  // y.second = multiset<int> and z = int
                    col.push_back(z);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};






// Method - 2 (Recursive)
class Solution {
public:
    void traverse(TreeNode* node, int x, int y,  map<int, map<int, multiset<int>>>& mp) {
        if(node == NULL) {
            return;
        }
        mp[x][y].insert(node->val);   // mp[vertical][level] = nodes
        traverse(node->left, x-1, y+1, mp);
        traverse(node->right, x+1, y+1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;  // {vertical, level, multinodes}
        traverse(root, 0, 0, mp);  // {root, vertical, level, mp}
        
        vector<vector<int>> ans;
        // O(N), since each element in mp is visited once.
        for(auto x: mp) {  // x = int, map<int, multiset<int>>
            vector<int> col;
            for(auto y: x.second) {  // x.second = map<int, multiset<int>> and y = int, multiset<int>
                for(auto z : y.second) {  // y.second = multiset<int> and z = int
                    col.push_back(z);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};