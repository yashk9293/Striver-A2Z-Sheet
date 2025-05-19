// Question Link :- https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// Array Leaders


// Brute Force
// T.C = O(N^2)
// S.C = O(N)
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=i+1; j<n; j++) {
                if(arr[i] <= arr[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};



// T.C = O(N)
// S.C = O(1)
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int maxi = 0;
        for(int i=n-1; i>=0; i--) {
            // for test case like 61 61 17, output is 61 61 17
            if(arr[i] >= maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};