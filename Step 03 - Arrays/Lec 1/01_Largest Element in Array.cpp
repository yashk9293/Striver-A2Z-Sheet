// Question Link :- https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0
// Largest Element in Array


// T.C = O(nlogn)
// S.C = O(1)
class Solution {
  public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        return arr[n-1];
    }
};



// T.C = O(n)
// S.C = O(1)
class Solution {
  public:
    int largest(vector<int> &arr) {
        int n = arr.size();
        int maxi = arr[0];
        for (int i = 0; i < n; i++) {
            if (maxi < arr[i]) {
                maxi = arr[i];
            }
        }
        return maxi;
    }
};
