// Question Link :- https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1
// Sorted Array Search

// Linear Search
// T.C = O(n)
// S.C = O(1)
class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(arr[i] == k) {
                return true;
            }
        }
        return false;
    }
};




// Using set
// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        set<int> st;
        st.insert(arr.begin(), arr.end());
        if(st.count(k)) {
            return true;
        }
        return false;
    }
};




// Binary Search
// T.C = O(logn)
// S.C = O(1)
class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(arr[mid] == k) {
                return true;
            }
            else if(arr[mid] < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};