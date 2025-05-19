// Question Link :- https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
// Number of NGEs to the right

// T.C = O(N * q) + q.log(q) ~ O(N * q)
// S.C = O(q)

class Solution {
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> ans;
        for (int i = 0; i < queries; i++) {
            int ind = indices[i];
            if (ind == n - 1) {
                ans.push_back(0);
            }
            else {
                int cnt = 0;
                for (int j = ind + 1; j < n; j++) {
                    if (arr[ind] < arr[j]) {
                        cnt++;
                    }
                }
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};



// T.C = O(N + q)
// S.C = O(N + q)
class Solution{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> ans(n, 0);
        stack<int> asc;
        stack<int> desc;
        
        for(int i=n-1; i>=0; i--){
            // apply NGE
            // in asc stack we will store element in ascending order so that we easily get size of stack  
            while(!asc.empty() && asc.top() <= arr[i]) {
                desc.push(asc.top());
                asc.pop();
            }
            desc.push(arr[i]);
            ans[i] = asc.size();
            while(!desc.empty()) {
                asc.push(desc.top());
                desc.pop();
            }
        }
        // for(int i=0; i<ans.size(); i++) {
        //     cout << ans[i] << " ";
        // } 
        // cout << endl;
        for(int i=0; i<queries; i++) {
            indices[i] = ans[indices[i]];
        }
        return indices;
    }
};