// Question Link :- https://leetcode.com/problems/serialize-and-deserialize-binary-tree
// Serialize and Deserialize Binary Tree

// T.C = O(n)
// S.C = O(n)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                str += "null,";
            } else {
                str += to_string(node->val) + ",";
            }
            if(node != NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << str << endl;  // 1,2,3,null,null,4,5,null,null,null,null,
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return NULL;
        }
        // The goal is to break down this single string into individual node values 
        // (like "1", "2", "null", "3", etc.), which can then be processed to reconstruct the original tree.
        vector<string> nodes;
        string str = "";
        for(char &ch : data) {
            if(ch == ',') {
                nodes.push_back(str);
                str = "";
            } else {
                str += ch;
            }
        }
        for(int i=0; i<nodes.size(); i++) {
            cout << nodes[i] << " ";     //  1 2 3 null null 4 5 null null null null 
        }
        int idx = 0;
        TreeNode* root = new TreeNode(stoi(nodes[idx]));
        idx++;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(idx < nodes.size() && nodes[idx] != "null") {
                TreeNode* leftNode = new TreeNode(stoi(nodes[idx]));
                node->left = leftNode;
                q.push(leftNode);
            }
            idx++;

            if (idx < nodes.size() && nodes[idx] != "null") {
                TreeNode* rightNode = new TreeNode(stoi(nodes[idx]));
                node->right = rightNode;
                q.push(rightNode);
            }
            idx++;
        }
        return root;
    }
};