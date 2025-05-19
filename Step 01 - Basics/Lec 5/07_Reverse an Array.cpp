// Question Link :- 
// Reverse an Array

// Recursion
// T.C = O(n)
// S.C = O(n)  recursion stack
class Solution {
  public:
    void reverse(vector<int>&arr, int i, int j) {
        if(i >= j) {
            return;
        }
        swap(arr[i], arr[j]);
        reverse(arr, i+1, j-1);
    }
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        reverse(arr, 0, n-1);
    }
};




// Iterative
// T.C = O(n)
// S.C = O(1)
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int i=0, j = n-1;
        while(i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};



class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int i=0;
        while(i < n/2) {
            swap(arr[i], arr[n-i-1]);
            i++;
        }
    }
};