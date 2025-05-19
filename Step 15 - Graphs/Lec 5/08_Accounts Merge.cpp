// Question Link :- https://leetcode.com/problems/accounts-merge/
// Accounts Merge

// T.C = O(n*k*logk)
// S.C = O(n*k)
class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if(i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent != y_parent) {
            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);

        unordered_map<string, int> mpp; // map to track email to account index

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mpp.find(accounts[i][j]) == mpp.end()) {
                    mpp[accounts[i][j]] = i;
                } else {
                    dsu.Union(i, mpp[accounts[i][j]]);
                }
            }
        }
        // ab hmko us mail ko bhi same parent ko jodna hai jiska mail already kahi present hai..."John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],for this tc we have to merge this john00@mail.com with index 0;
        vector<vector<string>> mergemail(n);
        for (auto it : mpp) {
            string mail = it.first;
            int node = dsu.find(it.second);   // suppose it.second=3 aaya lekin 3 jo hai wo 1 ka child hai..so yaha pe node=1 hojayega..
            mergemail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i=0; i<n; i++) {
            if (mergemail[i].size() == 0) {
                continue;
            }
            // sort
            sort(mergemail[i].begin(), mergemail[i].end());
            vector<string> temp;
            // pushing name
            temp.push_back(accounts[i][0]);
            // now push emails
            for (auto it : mergemail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};