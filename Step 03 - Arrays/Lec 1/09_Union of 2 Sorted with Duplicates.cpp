// Question Link :- https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
// Union of 2 Sorted with Duplicates


// Appraoch 1 (Using unordered_map)
// T.C = O(n+m) + O((m+n)log(m+n))
// S.C = O(m+n)
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        unordered_map<int, int> freq;
        vector<int> result;
        for (int i=0; i<n; i++) {
            freq[a[i]]++;
        }
        for (int i=0; i<m; i++) {
            freq[b[i]]++;
        }
        for (auto & it: freq) {
            result.push_back(it.first);
        }
        sort(result.begin(), result.end());
        return result;
    }
};




// Approach 2 (Using unordered_set)
// T.C = O(n+m) + O((m+n)log(m+n))
// S.C = O(m+n)




// T.C = O(m+n)
// S.C = O(m+n)
class Solution {
  public:
    vector<int> findUnion(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), m = arr2.size();
        
        int i = 0, j = 0;
        vector<int> result;
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                if (result.size() == 0 || result.back() != arr1[i]) {
                    result.push_back(arr1[i]);
                }
                i++;
            } else {
                if (result.size() == 0 || result.back() != arr2[j]) {
                    result.push_back(arr2[j]);
                }
                j++;
            }
        }
        while (i<n) {  // if any element left in arr1
            if (result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
        }
        while (j<m) {  // if any elements left in arr2
            if (result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        }
        return result;
    }
};